#include <algorithm>
#include <iostream>
#include <vector>

int binary_search(std::vector<int> vector, int target) {
  int left_boundary = 0;
  int right_boundary = vector.size() - 1;
  do {
    int middle = left_boundary + (right_boundary - left_boundary) / 2;
    if (vector[middle] == target) {
      return middle;
    } else if (vector[middle] < target) {
      left_boundary = middle + 1;
    } else {
      right_boundary = middle - 1;
    }
  } while (left_boundary <= right_boundary);
  return -1;
}

int main(void) {
  int length;
  std::cin >> length;
  std::vector<int> vector(length);
  for (int i = 0; i < length; ++i) {
    std::cin >> vector[i];
  }
  std::sort(vector.begin(), vector.end());
  for (int i = 0; i < length; ++i) {
    std::cout << vector[i] << ' ';
  }
  int target;
  std::cin >> target;
  std::cout << binary_search(vector, target) << '\n';
  return 0;
}
