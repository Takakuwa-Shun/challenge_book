#include <iostream>

const int MAX_N = 5000;
int N, M, K;
bool cow[MAX_N];

void solve() {
}

int main() {
	std::scanf("%d", &N);
  std::string s;
  std::cin >> s;
  for (int i=0; i<N; i++) {
    if (s[i] == 'F') {
      cow[i] = true;
    } else {
      cow[i] = false;
    }
  }
	solve();
	std::printf("\nK = %d, M = %d", K, M);
	return 0;
}