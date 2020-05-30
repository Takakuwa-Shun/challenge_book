#include <iostream>
using namespace std;

const int MAX_N = 20;
int n, k, a[MAX_N];

bool search(int sum, int idx) {
  if (sum == k) {
    return true;
  }
  if (idx < n) {
    return search(sum + a[idx], idx+1) ? true : search(sum, idx+1);
  }
  return false;
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  cin >> k;
  bool found = search(0, 0);
  if (found) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}