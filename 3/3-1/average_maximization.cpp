#include <iostream>
#include <float.h>
#include <stdio.h>

const int MAX_N = 10000;
int n, k, w[MAX_N], v[MAX_N];
double y[MAX_N];

// 単位重さあたりの価値がx以上になるのを選ぶことができる
bool check(double x) {
  for (int i=0; i<n; i++) {
    y[i] = v[i] - x * w[i];
  }
  std::sort(y, y+n);
  double sum = 0;
  for (int i=0; i<k; i++) {
    sum += y[n-1-i];
  }
  return sum >= 0;
}

double solve() {
  double lb = 0, ub = 1000000;
  for (int i=0; i<100; i++) {
    double mid = (lb + ub) / 2;
    if (check(mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  return ub;
}

int main() {
	std::scanf("%d %d", &n, &k);
  for (int i=0; i<n; i++) {
    std::scanf("%d %d", &w[i], &v[i]);
  }
	std::printf("\n%.2f", solve());
	return 0;
}