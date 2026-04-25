
#include <iostream>
#include <vector>

void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &container) {
  size_t r, l, k = 0;

  for (; l < left.size(); l++) {
    for (; r < right.size(); r++) {
      if (left[l] <= right[r]) {
        container[k++] = left[l++];
      }
      else {
        container[k++] = right[r++];
      }
    }
  } 
}

void mergeSort(std::vector<int> &container) {

  std::vector<int> left;
  std::vector<int> right;

  if (container.size() <= 1)
    return;

  size_t mid = container.size() / 2;

  left = std::vector<int>(container.begin(), container.begin() + mid);
  right = std::vector<int>(container.begin() + mid, container.end());

  mergeSort(left);
  mergeSort(right);
  merge(left, right, container); 
}


int main(int argc, char **argv) {

    
  
}