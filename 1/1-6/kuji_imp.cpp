#include <iostream>
using namespace std;

const int MAX_N = 1000;
int n, m, k[MAX_N], kk[MAX_N*MAX_N];

bool binary_search(int x) {
  int begin = 0;
  int end = n*n;
  while (end - begin > 1)
  {
    int l = (end + begin) / 2;
    if (kk[l] == x) return true;
    if (kk[l] <= x) {
      begin = l + 1;
    } else {
      end = l;
    }
  }
  return false;
}

int main() {
  cin >> n >> m;
  for (int i=0; i<n; i++) {
    cin >> k[i];
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      kk[i*n + j] = k[i]  k[j];
    }
  }
  sort(kk, kk+n*n);

  for (int i=0; i<n*n; i++) {
    if (binary_search(m - kk[i])) {
      cout << "Yes";
      return 0;
    }
  }

  cout << "No";
  return 0;
}