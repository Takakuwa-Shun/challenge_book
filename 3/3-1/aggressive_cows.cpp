#include <iostream>
#include <climits>

const int MAX_N = 100000;
int N, M, X[MAX_N];

// 可能かどうか
bool check(int dist) {
  int last = 0;
  for (int i=1; i<M; i++) {
    int cur = last + 1;
    while (cur < N && X[cur] - X[last] < dist) {
      cur++;
    }
    if (cur == N) return false;
    last = cur;
  }
  return true;
}

int solve() {
  std::sort(X, X+N);
  int lb = 0, ub = INT_MAX;
  while (ub - lb > 1) {
    int mid = (lb + ub) /2;
    if (check(mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  return lb;
}

int main() {
	std::scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    std::scanf("%d", &X[i]);
  }
	std::printf("%d", solve());
	return 0;
}