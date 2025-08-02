#include <algorithm>
#include <iostream>
#include <vector>

int recursive_binary_search(std::vector<int> vector, int left_boundary,
                            int right_boundary, int target) {
  if (left_boundary > right_boundary) {
    return -1;
  }
  int middle = left_boundary + (right_boundary - left_boundary) / 2;
  if (vector[middle] == target) {
    return middle;
  } else if (vector[middle] < target) {
    return recursive_binary_search(vector, middle + 1, right_boundary, target);
  } else {
    return recursive_binary_search(vector, left_boundary, middle - 1, target);
  }
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
  std::cout << recursive_binary_search(vector, 0, vector.size() - 1, target)
            << '\n';
  return 0;
}
