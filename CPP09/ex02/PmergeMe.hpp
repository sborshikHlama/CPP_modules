#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cfloat>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <ctime>

typedef std::pair<int, int> Pair;

class PmergeMe {

private:
  std::vector<int> _vec;
  std::deque<int>  _deq;

  void _printSequence(const std::string &prefix,
                      const std::vector<int> &nums) const;
  void _printTime(size_t size, const std::string &containerName,
                  double time) const;

  template <typename T>
  double _timeAndSolve(T &container, const std::vector<int> &raw_nums) {
    clock_t start = clock();
    container.assign(raw_nums.begin(), raw_nums.end());
    this->solve(container);
    clock_t end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
  }


public:
  PmergeMe(const std::string &s);
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);

  std::vector<int> &getVec();
  std::deque<int> &getDeq();

  template <typename T> void solve(T &container);

};

long _generateJacobsthal(long n);
std::vector<size_t> _generateInsertionOrder(size_t size);

template <typename T>
void sortPairs(T &pairs) {
  if (pairs.size() <= 1)
    return;

  size_t mid = pairs.size() / 2;

  T left(pairs.begin(), pairs.begin() + mid);
  T right(pairs.begin() + mid, pairs.end());

  sortPairs(left);
  sortPairs(right);

  /* Merge by pair.second. */
  size_t l = 0, r = 0, i = 0;
  while (l < left.size() && r < right.size()) {
    if (left[l].second <= right[r].second)
      pairs[i++] = left[l++];
    else
      pairs[i++] = right[r++];
  }
  while (l < left.size()) pairs[i++] = left[l++];
  while (r < right.size()) pairs[i++] = right[r++];
}

template <typename IntContainer, typename PairContainer>
void buildChains(const PairContainer &pairs,
                 IntContainer &mainChain,
                 IntContainer &pending) {
  mainChain.push_back(pairs[0].first);
  for (size_t i = 0; i < pairs.size(); i++) {
    mainChain.push_back(pairs[i].second);
    if (i != 0)
      pending.push_back(pairs[i].first);
  }
}

template <typename IntContainer, typename PairContainer>
void insertPending(IntContainer &mainChain, const IntContainer &pending,
                   const PairContainer &pairs) {

  std::vector<size_t> insertionOrder = _generateInsertionOrder(pending.size());

  for (size_t i = 0; i < insertionOrder.size(); i++) {
    size_t index = insertionOrder[i];
    int value = pending[index];

    typename IntContainer::iterator it_limit = std::lower_bound(
        mainChain.begin(), mainChain.end(), pairs[index + 1].second);

    typename IntContainer::iterator pos = std::lower_bound(
        mainChain.begin(), it_limit, value);

    mainChain.insert(pos, value);
  }
}

template <typename IntContainer>
void insertStraggler(IntContainer &mainChain, int straggler) {

  typename IntContainer::iterator pos = std::lower_bound(
      mainChain.begin(), mainChain.end(), straggler);
  mainChain.insert(pos, straggler);
}

template <typename IntContainer, typename PairContainer>
int makePairs(IntContainer &nums, PairContainer &pairs, bool &hasStraggler) {
  
  hasStraggler = (nums.size() % 2 == 1);
  int straggler = 0;
  if (hasStraggler) {
    straggler = nums.back();
    nums.pop_back();
  }

  for (size_t i = 0; i < nums.size(); i += 2) {
    int first = nums[i];
    int second = nums[i + 1];

    if (first > second)
      std::swap(first, second);

    pairs.push_back(std::make_pair(first, second));
  }

  return straggler;
}

template <typename T>
void PmergeMe::solve(T &container) {
  if (container.size() <= 1)
    return;

  std::vector<Pair> pairs;
  bool hasStraggler;
  int straggler = makePairs(container, pairs, hasStraggler);

  sortPairs(pairs);

  T mainChain;
  T pending;
  buildChains(pairs, mainChain, pending);

  insertPending(mainChain, pending, pairs);

  if (hasStraggler)
    insertStraggler(mainChain, straggler);

  container = mainChain;
}


#endif
