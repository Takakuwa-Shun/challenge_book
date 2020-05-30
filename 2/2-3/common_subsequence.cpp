#include <iostream>
#include <string>
using namespace std;

const int MAX_NM = 1000;
int n, m, dp[MAX_NM + 1][MAX_NM + 1];
string s, t;

int search(int i, int j) {
  if (dp[i][j] > 0) {
    return dp[i][j];
  }

  if (i == n || j == m) {
    dp[i][j] = 0;
  } else {
    char si = s[i];
    int l = t.find_first_of(si, j);

    if (l == string::npos) {
      dp[i][j] = search(i+1, j);
    } else {
      dp[i][j] = max(search(i+1, l + 1) + 1, search(i+1, j));
    }
  }
  return dp[i][j];
}

int main() {
  cin >> n >> m >> s >> t;
  memset(dp, -1, sizeof(dp));
  cout << search(0, 0);
	return 0;
}