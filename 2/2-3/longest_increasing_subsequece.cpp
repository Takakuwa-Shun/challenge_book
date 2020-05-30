#include <iostream>
using namespace std;

const int MAX_N = 1000, MAX_A = 1000000;
int n, a[MAX_N + 1], dp[MAX_N + 1];


int findMin(int end) {
  int maxDp = 0;
  int dpA = MAX_A + 1;
  int res = 0;
  for (int i=0; i<end; i++) {
    if (a[i] < a[end]) {
      if ((maxDp == dp[i] && a[i] < dpA) || (maxDp < dp[i])) {
        maxDp = dp[i];
        dpA = a[i];
        res = i;
      }
    }
  }
  return res;
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) {
    cin >> a[i];
  }
  cout << "----------" << endl;
  for (int i=0; i<n; i++) {
    int l = findMin(i+1);
    cout << l << endl;
    dp[i+1] = dp[l] + 1;
  }
  cout << "----------" << endl;
  for (int i=0; i<=n; i++) {
    cout << dp[i] << endl;
  }
  int res = 0;
  for (int i=0; i<=n; i++) {
    res = max(res, dp[i]);
  }
  cout << endl << res << endl;
	return 0;
}