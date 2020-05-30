#include <iostream>
#include <algorithm>
typedef long long ll;

const int MAX_N = 8;
int n, x[MAX_N], y[MAX_N], min = 0;

ll solve() {
  ll min = 0;
  std::sort(x, x+n);
  std::sort(y, y+n);

  for (int i=0; i<n; i++) {
    min += (ll)x[i] * y[n-1-i];
  }
  return min;
}

int main() {
	scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &x[i]);
  }
  for (int i=0; i<n; i++) {
    scanf("%d", &y[i]);
  }
	printf("\n%lld", solve());
	return 0;
}