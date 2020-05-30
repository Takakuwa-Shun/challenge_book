#include <iostream>
#include <algorithm>
#include <vector>

const int MAX_N = 1000000;
int n, k;
std::vector<int> a;

int solve() {
  std::vector<int>::iterator it = std::lower_bound(a.begin(), a.end(), k);
  return std::distance(a.begin(), it);
}

int main() {
	std::scanf("%d", &n);
  for (int i=0; i<n; i++) {
    int x;
    std::scanf("%d", &x);
    a.push_back(x);
  }
	std::scanf("%d", &k);
	std::printf("%d", solve());
	return 0;
}