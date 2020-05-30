#include <iostream>

const int MAX_N = 10000;
int N, K;
double L[MAX_N], mean = 0;

double solve() {
  double start = 0;
  double end = mean;
  while (end - start >= 0.01) {
    double mid = (start + end) / 2;
    int cnt = 0; 
    for (int i=0; i<N; i++) {
      cnt += L[i] / mid;
    }
    if (cnt < K) {
      end = mid;
    } else {
      start = mid;
    }
  }
  return start;
}

int main() {
	std::scanf("%d %d", &N, &K);
  for (int i=0; i<N; i++) {
    std::scanf("%lf", &L[i]);
    mean += L[i];
  }
  mean /= K;
	std::printf("\n%.2lf", solve());
	return 0;
}