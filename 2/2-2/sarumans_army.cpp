#include <iostream>
using namespace std;

const int MAX_N = 1000;
int N, R, X[MAX_N], cnt = 0;

int main() {
  cin >> N >> R;
  for (int i=0; i<N; i++) {
    cin >> X[i];
  }
  sort(X, X + N);
  int firstPoint = -1;
  int cover = -1;
  for (int i=0; i<N; i++) {
    if (cover < X[i]) {
      if (firstPoint == -1) {
        firstPoint = X[i];
      } else if (firstPoint + R < X[i]) {
        cover = X[i-1] + R;
        if (cover < X[i]) {
          firstPoint = X[i];
        } else {
          firstPoint = -1;
        }
        cnt++;
      }
    }
  }
  if (firstPoint != -1) {
    cout << X[N-1] << endl;
    cnt++;
  }

  cout << cnt << endl;
	return 0;
}