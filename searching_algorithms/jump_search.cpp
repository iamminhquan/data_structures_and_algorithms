#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int jump_search(std::vector<int> vector, int target) {
  int length = (int)vector.size();
  int step = (int)std::sqrt(length);
  int previous = 0;
  while (vector[std::min(step, length) - 1] < target) {
    previous = step;
    step = step + (int)std::sqrt(length);
    if (previous >= length) {
      return -1;
    }
  }
  while (vector[previous] < target) {
    previous = previous + 1;
    if (previous == std::min(step, length)) {
      return -1;
    }
  }
  return vector[previous] == target ? previous : -1;
}

int main(void) {
  int length;
  std::cin >> length;
  std::vector<int> vector(length);
  for (int i = 0; i < length; ++i) {
    std::cin >> vector[i];
  }
  std::sort(vector.begin(), vector.end(), std::less<int>());
  for (int i = 0; i < length; ++i) {
    std::cout << vector[i] << ' ';
  }
  std::cout << '\n';
  int target;
  std::cin >> target;
  std::cout << jump_search(vector, target) << '\n';
  return 0;
}
