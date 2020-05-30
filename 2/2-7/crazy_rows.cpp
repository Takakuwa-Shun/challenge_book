#include <iostream>

const int MAX_N = 40;
int N, rows[MAX_N];

int swapAll(int i, int j) {
  for(int k = j; k>i; k--) {
    std::swap(rows[k], rows[k-1]);
  }
  return j-i;
}

int solve() {
  int cnt = 0;
  for (int i=0; i<N; i++) {
    if (rows[i] > i+1) {
      for (int j=i+1; j<N; j++) {
        if (rows[j] <= i+1) {
          cnt += swapAll(i, j);
          break;
        }
      }
    }
  }
  return cnt;
}

int main() {
	std::scanf("%d", &N);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      int k;
      std::scanf("%d", &k);
      if (k == 1) rows[i] = j + 1;
    }
  }
  for (int i=0; i<N; i++) {
    std::printf("%d ", rows[i]);
  }
	std::printf("\n%d", solve());
	return 0;
}