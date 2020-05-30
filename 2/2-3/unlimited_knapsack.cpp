#include <iostream>
using namespace std;

const int MAX_W = 10000, MAX_N = 100;
int n, w[MAX_N], v[MAX_N], dp[MAX_W + 1], W;

int search(int remaining) {
  if (dp[remaining] != -1) {
    return dp[remaining];
  }

  for (int i=0; i<n; i++) {
    if (remaining - w[i] >= 0) {
      dp[remaining] = max(dp[remaining], search(remaining - w[i]) + v[i]);
    }
  }
  return dp[remaining];
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> w[i] >> v[i];
  }
  cin >> W;
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  cout << search(W);
	return 0;
}