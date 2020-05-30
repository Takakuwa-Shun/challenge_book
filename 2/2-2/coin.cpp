#include <iostream>
using namespace std;

int c[6], A, result = 0;

int calcCnt(int cnt, int val, int remaining) {
  int quotient = remaining / val;
  cout << quotient << endl;
  if (quotient > cnt) {
    result += cnt;
    return remaining - (cnt * val);
  } else {
    result += quotient;
    return remaining - (quotient * val);
  }
}

int main() {
  cin >> c[0] >> c[1] >> c[2] >> c[3] >> c[4] >> c[5] >> A;
  int val[6] = {1, 5, 10, 50, 100, 500};
  int remaining = A;
  for (int i=5; i>0; i--) {
    remaining = calcCnt(c[i], val[i], remaining);
    if (remaining == 0) break;
  }
  cout << result << endl;
}