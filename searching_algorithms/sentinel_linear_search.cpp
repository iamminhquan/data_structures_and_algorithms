#include <iostream>
#include <vector>

int sentinel_linear_search(std::vector<int> vector, int target) {
  int index = 0;
  int length = vector.size();
  vector.resize(length + 1);
  vector[length] = target;
  while (vector[index] != target) {
    index = index + 1;
  }
  if (index == length) {
    return -1;
  }
  return index;
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
  std::cout << sentinel_linear_search(vector, target) << '\n';
  return 0;
}