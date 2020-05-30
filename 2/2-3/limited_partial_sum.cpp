#include <iostream>
using namespace std;

const int MAX_N = 100, MAX_K = 100000;
int n, K, a[MAX_N], m[MAX_N], dp[MAX_K + 1];

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  for (int i=0; i<n; i++) {
    cin >> m[i];
  }
  cin >> K;
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<=K; j++) {
      if (dp[j] >= 0) {
        dp[j] = m[i];
      } else if (j < a[i] || dp[j - a[i]] <= 0) {
        dp[j] = -1;
      } else {
        dp[j] = dp[j - a[i]] - 1;
      }
    }
  }
  if (dp[K] >= 0) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
	return 0;
}