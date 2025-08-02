#include <iostream>
#include <vector>

int linear_search(std::vector<int> vector, int target) {
  int length = vector.size();
  for (int i = 0; i < length; ++i) {
    if (vector.at(i) == target) {
      return i;
    }
  }
  return -1;
}

int main(void) {
  int length;
  std::cin >> length;
  std::vector<int> vector(length);
  for (int i = 0; i < length; ++i) {
    std::cin >> vector[i];
  }
  int target;
  std::cin >> target;
  std::cout << linear_search(vector, target) << '\n';
  return 0;
}
