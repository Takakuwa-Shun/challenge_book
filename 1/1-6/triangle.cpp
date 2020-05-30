#include <iostream>
using namespace std;

int calCircumference(int a, int b, int c) {
  if ((a + b > c) && (a + c > b) && (b + c > a)) {
    return a + b + c;
  }
  return 0;
}

int main() {
  int N, len = 0;
  cin >> N;
  int a[N];
  for (int i=0; i<N; i++) {
    cin >> a[i];
  }
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      for (int k=j+1; k<N; k++) {
        int result = calCircumference(a[i], a[j], a[k]);
        if (len < result) {
          len = result;
        }
      }
    }
  }
  cout << len;
  return 0;
}