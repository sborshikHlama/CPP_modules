#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <sys/time.h>
#include <cmath>

static int g_comparisons = 0;

struct IntComp {
    bool operator()(int a, int b) const { ++g_comparisons; return a < b; }
};

static int maxComparisons(int n) {
    int sum = 0;
    for (int k = 1; k <= n; ++k)
        sum += static_cast<int>(ceil(log2(3.0 * k / 4.0)));
    return sum;
}

// Returns 0-indexed pend positions to insert in Jacobsthal order (high to low
// within each group), ensuring every binary search range is 2^k-1 elements.
static std::vector<size_t> insertionOrder(size_t n) {
    std::vector<size_t> order;
    size_t prevJ = 1;
    long currJ = 3, lastJ = 1;
    while (order.size() < n) {
        size_t hi = (size_t)std::min(currJ, (long)(n + 1));
        for (size_t b = hi; b > prevJ && order.size() < n; --b)
            order.push_back(b - 2);
        prevJ = hi;
        long next = currJ + 2 * lastJ; lastJ = currJ; currJ = next;
    }
    return order;
}

static size_t lowerBoundBlockPositionVec(const std::vector<int>& chain,
                                         int value,
                                         size_t limit,
                                         size_t pairLevel) {
    size_t lo = 0, hi = limit;
    while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        ++g_comparisons;
        if (chain[(mid + 1) * pairLevel - 1] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

static size_t lowerBoundBlockPositionDeq(const std::deque<int>& chain,
                                         int value,
                                         size_t limit,
                                         size_t pairLevel) {
    size_t lo = 0, hi = limit;
    while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        ++g_comparisons;
        if (chain[(mid + 1) * pairLevel - 1] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

static void fordJohnsonVec(std::vector<int>& arr, size_t activeSize, size_t pairLevel) {
    size_t blocksCount = activeSize / pairLevel;
    if (blocksCount <= 1) return;

    size_t pairsCount  = blocksCount / 2;
    bool hasStray  = (blocksCount % 2 == 1);

    // Step 1: sort each adjacent block-pair so left winner ≤ right winner
    for (size_t pairIndx = 0; pairIndx < pairsCount; ++pairIndx) {

        // index:      0    1       2    3         4    5       6    7          8    9     10   11
        // arr:      [ e0][ e1]   [ e2][ e3]     [ e4][ e5]  [ e6][ e7]      [ e8][ e9]   [e10][e11]
        //          \__block0__/ \__block1__/   \__block2__/ \__block3__/   \__block4__/ \__block5__/
        //          \_______pair 0___________/  \______pair 1___________/   \______pair 2___________/

        // pairIdx=0:  leftBlockStart = 2*0*2 = 0    rightBlockStart = (2*0+1)*2 = 2
        // pairIdx=1:  leftBlockStart = 2*1*2 = 4    rightBlockStart = (2*1+1)*2 = 6
        // pairIdx=2:  leftBlockStart = 2*2*2 = 8    rightBlockStart = (2*2+1)*2 = 10

        size_t leftBlockStart = 2 * pairIndx * pairLevel;
        size_t rightBlockStart = (2 * pairIndx + 1) * pairLevel;
        ++g_comparisons;
        if (arr[leftBlockStart + pairLevel - 1] > arr[rightBlockStart + pairLevel - 1])
            for (size_t j = 0; j < pairLevel; ++j)
                std::swap(arr[leftBlockStart + j], arr[rightBlockStart + j]);
    }

    // Step 2: recursively sort meta-pairs (each pair treated as one 2*step block)
    fordJohnsonVec(arr, pairsCount * 2 * pairLevel, pairLevel * 2);

    // Step 3: main chain = b1 (loser of pair 0) + all winner blocks
    std::vector<int> mainChain;
    mainChain.reserve(activeSize);

    // insert b1 (loser of pair 0) to main chain
    mainChain.insert(mainChain.end(), arr.begin(), arr.begin() + pairLevel);
    for (size_t pairIndx = 0; pairIndx < pairsCount; ++pairIndx) {
        // same as rightBlockStart
        size_t winnerStart = (2 * pairIndx + 1) * pairLevel; 
        mainChain.insert(mainChain.end(), arr.begin() + winnerStart, arr.begin() + winnerStart + pairLevel);
    }

    // Collect pend blocks (losers of pairs 1..pairsCount-1) and companion positions
    // pairsCount - 1, because b1 was sent to main chain
    size_t pendCount = pairsCount - 1;
    std::vector<int> pendFlat;
    std::vector<size_t> companionPositions;
    pendFlat.reserve(pendCount * pairLevel);
    companionPositions.reserve(pendCount);

    // start from 1, because b1 was sent to main chain
    for (size_t pairIndx = 1; pairIndx < pairsCount; ++pairIndx) {
        size_t loserStart = 2 * pairIndx * pairLevel;
        pendFlat.insert(pendFlat.end(), arr.begin() + loserStart, arr.begin() + loserStart + pairLevel);
        companionPositions.push_back(pairIndx + 1);
    }

    // Step 4: insert pend blocks (+ stray) in Jacobsthal order
    size_t pendTotal = pendCount + (hasStray ? 1 : 0);
    std::vector<size_t> order = insertionOrder(pendTotal);

    for (size_t k = 0; k < order.size(); ++k) {
        size_t i = order[k];
        std::vector<int> tempBlock;
        size_t searchBorder = mainChain.size() / pairLevel;

        if (i < pendCount) {
            tempBlock.assign(pendFlat.begin() + i * pairLevel,
                       pendFlat.begin() + (i + 1) * pairLevel);
            searchBorder = companionPositions[i];
        } else {
            size_t strayStart = 2 * pairsCount * pairLevel;
            tempBlock.assign(arr.begin() + strayStart,
                       arr.begin() + strayStart + pairLevel);
        }

        // Binary search for insertion position by block winner
        int val = tempBlock.back();
        size_t lo = lowerBoundBlockPositionVec(mainChain, val, searchBorder, pairLevel);
        mainChain.insert(mainChain.begin() + lo * pairLevel, tempBlock.begin(), tempBlock.end());
        for (size_t posIndex = 0; posIndex < companionPositions.size(); ++posIndex) {
            if (companionPositions[posIndex] >= lo)
                ++companionPositions[posIndex];
        }
    }

    std::copy(mainChain.begin(), mainChain.end(), arr.begin());
}

static void fordJohnson(std::vector<int>& arr) {
    if (arr.size() <= 1) return;
    fordJohnsonVec(arr, arr.size(), 1);
}

// ── Ford-Johnson for std::deque ───────────────────────────────────────────────
static void fordJohnsonDeq(std::deque<int>& arr, size_t activeSize, size_t pairLevel) {
    size_t blocksCount = activeSize / pairLevel;
    if (blocksCount <= 1) return;

    size_t pairsCount  = blocksCount / 2;
    bool hasStray  = (blocksCount % 2 == 1);

    for (size_t pairIdx = 0; pairIdx < pairsCount; ++pairIdx) {
        size_t leftBlockStart = 2 * pairIdx * pairLevel;
        size_t rightBlockStart = (2 * pairIdx + 1) * pairLevel;
        ++g_comparisons;
        if (arr[leftBlockStart + pairLevel - 1] > arr[rightBlockStart + pairLevel - 1])
            for (size_t j = 0; j < pairLevel; ++j)
                std::swap(arr[leftBlockStart + j], arr[rightBlockStart + j]);
    }

    fordJohnsonDeq(arr, pairsCount * 2 * pairLevel, pairLevel * 2);

    std::deque<int> chain;
    for (size_t j = 0; j < pairLevel; ++j)
        chain.push_back(arr[j]);
    for (size_t pairIdx = 0; pairIdx < pairsCount; ++pairIdx) {
        size_t winnerStart = (2 * pairIdx + 1) * pairLevel;
        for (size_t j = 0; j < pairLevel; ++j)
            chain.push_back(arr[winnerStart + j]);
    }

    size_t pendCount = pairsCount - 1;
    std::vector<int> pendFlat;
    std::vector<size_t> companionPositions;
    pendFlat.reserve(pendCount * pairLevel);
    companionPositions.reserve(pendCount);
    for (size_t pairIdx = 1; pairIdx < pairsCount; ++pairIdx) {
        size_t leftBlockStart = 2 * pairIdx * pairLevel;
        for (size_t j = 0; j < pairLevel; ++j)
            pendFlat.push_back(arr[leftBlockStart + j]);
        companionPositions.push_back(pairIdx + 1);
    }

    size_t pendTotal = pendCount + (hasStray ? 1 : 0);
    std::vector<size_t> order = insertionOrder(pendTotal);

    for (size_t k = 0; k < order.size(); ++k) {
        size_t i = order[k];
        std::vector<int> blk;
        size_t searchBorder = chain.size() / pairLevel;

        if (i < pendCount) {
            blk.assign(pendFlat.begin() + i * pairLevel,
                       pendFlat.begin() + (i + 1) * pairLevel);
            searchBorder = companionPositions[i];
        } else {
            size_t strayStart = 2 * pairsCount * pairLevel;
            for (size_t j = 0; j < pairLevel; ++j)
                blk.push_back(arr[strayStart + j]);
        }

        int val = blk.back();
        size_t lo = lowerBoundBlockPositionDeq(chain, val, searchBorder, pairLevel);
        chain.insert(chain.begin() + lo * pairLevel, blk.begin(), blk.end());
        for (size_t posIndex = 0; posIndex < companionPositions.size(); ++posIndex) {
            if (companionPositions[posIndex] >= lo)
                ++companionPositions[posIndex];
        }
    }

    for (size_t i = 0; i < activeSize; ++i)
        arr[i] = chain[i];
}

static void fordJohnson(std::deque<int>& arr) {
    if (arr.size() <= 1) return;
    fordJohnsonDeq(arr, arr.size(), 1);
}

// ── PmergeMe ──────────────────────────────────────────────────────────────────

PmergeMe::PmergeMe(const std::string& input) {
    std::stringstream ss(input);
    std::string token;
    std::vector<int> raw;

    while (ss >> token) {
        for (size_t i = 0; i < token.size(); ++i)
            if (!isdigit(token[i]))
                throw std::runtime_error("Error");
        long val = std::atol(token.c_str());
        if (val < 0 || val > 2147483647L)
            throw std::runtime_error("Error");
        raw.push_back(static_cast<int>(val));
    }
    if (raw.empty())
        throw std::runtime_error("Error");

    std::cout << "Before:";
    for (size_t i = 0; i < raw.size(); ++i)
        std::cout << " " << raw[i];
    std::cout << std::endl;

    struct timeval t0, t1, t2, t3;

    g_comparisons = 0;
    _vec.assign(raw.begin(), raw.end());
    gettimeofday(&t0, NULL);
    fordJohnson(_vec);
    gettimeofday(&t1, NULL);
    double vecTime = (t1.tv_sec - t0.tv_sec) * 1e6 + (t1.tv_usec - t0.tv_usec);
    int vecCmp = g_comparisons;

    g_comparisons = 0;
    _deq.assign(raw.begin(), raw.end());
    gettimeofday(&t2, NULL);
    fordJohnson(_deq);
    gettimeofday(&t3, NULL);
    double deqTime = (t3.tv_sec - t2.tv_sec) * 1e6 + (t3.tv_usec - t2.tv_usec);
    int deqCmp = g_comparisons;

    int maxCmp = maxComparisons(static_cast<int>(raw.size()));

    std::cout << "After:";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << " " << _vec[i];
    std::cout << std::endl;

    std::cout << "Time to process a range of " << raw.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << vecTime
              << " us [Comparisons: " << vecCmp << " / max: " << maxCmp << "]" << std::endl;
    std::cout << "Time to process a range of " << raw.size()
              << " elements with std::deque  : "
              << std::fixed << std::setprecision(5) << deqTime
              << " us [Comparisons: " << deqCmp << " / max: " << maxCmp << "]" << std::endl;
    std::cout << "Number of comparisons: " << vecCmp << std::endl;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}
