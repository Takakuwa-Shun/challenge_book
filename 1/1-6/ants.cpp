#include <iostream>
using namespace std;

int L;

int calMin(int a) {
  return  a < L - a ? a : L - a;
}

int calMax(int a) {
  return  a < L - a ? L - a : a;
}

int main() {
  int n, min = 0, max = 0;
  cin >> L >> n;
  int x[n];
  for (int i=0; i<n; i++) {
    cin >> x[i];
    int m = calMin(x[i]);
    int M = calMax(x[i]);
    if (min < m) {
      min = m;
    }
    if (max < M) {
      max = M;
    }
  }
  cout << "min = " << min << endl;
  cout << "max = " << max << endl;

  return 0;
}