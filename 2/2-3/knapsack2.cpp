#include <iostream>
using namespace std;

const int MAX_W = 1000000000, MAX_N = 100, MAX_V = 100, MAX_VSUM = MAX_N * MAX_V;
int n, W, w[MAX_N + 1], v[MAX_N + 1] , dp[MAX_N + 1][MAX_VSUM + 1];

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> w[i] >> v[i];
  }
  // w[0] = 0;
  // v[0] = 0;
  cin >> W;

  // for (int j=1; j<=MAX_VSUM; j++) {
  //   dp[0][j] = INT_MAX;
  // }
  fill(dp[0], dp[0] + MAX_VSUM + 1, INT_MAX);
  dp[0][0] = 0;

  for (int i=0; i<n; i++) {
    for (int j=0; j<=MAX_VSUM; j++) {
      if (j < v[i]) {
        dp[i+1][j] = dp[i][j];
      } else {
        dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]] + w[i]);
      }
    }
  }

  int maxV = 0;
  for (int j=0; j<=MAX_VSUM; j++) {
    if (dp[n][j] <= W) {
      maxV = j; 
    }
  }
  cout << endl << maxV << endl;

  for (int i=0; i<=n; i++) {
    cout << dp[i][0] << endl;
  }

	return 0;
}