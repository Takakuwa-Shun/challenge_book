#include <iostream>
// #include <cmath>
using namespace std;

int x1, x2, y1, y2;

int solve() {
  if (x1 - x2 == 0) {
    return std::abs(y1 - y2) + 1;
  }
  int cnt = 0;
  float sx = x1 < x2 ? x1 : x2;
  float lx = x1 < x2 ? x2 : x1;
  for (float i=sx+1; i<lx; i++) {
    float y = ((float)(y1 - y2) / (float)(x1 - x2)) * i + (float)(x1 * y2 - x2 * y1) / (float)(x1 - x2);
    printf("%f\n", y);
    if (y == (int)y) {
      cnt++;
    }
  }

  return cnt;
}

int gcd(const int a, const int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	// int cnt = solve();
	int cnt = gcd(abs(x1 - x2), abs(y1-y2)) -1;
  printf("%d\n", cnt);
	return 0;
}