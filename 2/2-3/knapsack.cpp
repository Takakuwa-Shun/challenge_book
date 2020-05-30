#include <iostream>
using namespace std;

const int MAX_N = 100, MAX_W = 10000;
int n, w[MAX_N], v[MAX_N], W, dp[MAX_N + 1][MAX_W + 1];

int select(int idx, int remaining) {
  if (dp[idx][remaining] != -1) {
    return dp[idx][remaining];
  }

  if (idx == n) {
    dp[idx][remaining] = 0;
  } else {
    if (remaining < w[idx]) {
      dp[idx][remaining] = select(idx + 1, remaining);
    } else {
      dp[idx][remaining] = max(select(idx + 1, remaining - w[idx]) + v[idx], select(idx + 1, remaining));
    }
  }
  return dp[idx][remaining];
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> w[i] >> v[i];
  }
  cin >> W;
  for (int i=0; i<n; i++) {
    for (int j=0; j<W; j++) {
      dp[i][j] = -1;
    }
  }
  int val = select(0, W);
  printf("%d", W);
	return 0;
}