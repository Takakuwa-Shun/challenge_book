#include <iostream>

const int MAX_N = 100000;
int n, S, a[MAX_N];

int solve() {
  int s = 0, t = 0, sum = 0, res = n + 1;
  while (true) {
    while (t < n && sum < S) {
      sum += a[t++];
    }
    if (sum < S) break; 
    res = std::min(res, t-s);
    sum -= a[s++];
  }
  if (res > n) return 0;
  return res;
}

int main() {
	std::scanf("%d %d", &n, &S);
  for (int i=0; i<n; i++) {
    std::scanf("%d", &a[i]);
  }
	std::printf("%d", solve());
	return 0;
}