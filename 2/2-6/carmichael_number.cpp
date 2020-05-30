#include <iostream>

const int MAX_N = 65000;
int n;

bool isPrimeNumber() {
  for (int i=3; i*i <= n; i+=2) {
    if (n % i == 0) return false;
  }
  return true;
}

bool solve() {
  if (isPrimeNumber()) return false;

  // 以下、nは素数でない
  for (long x=2; x < n; x++) {
    long mods[n-1];
    mods[0] = x;
    int i = 0;
    int m = 1;
    while (m*2 <= n) {
      i++;
      m *= 2;
      mods[i] = (mods[i-1] * mods[i-1]) % n;
    }
    long mod = mods[i];
    while (m <= n) {
      mods[i] = (mods[i-1] * mods[i-1]) % n;
      i++;
      m *= 2;
    }
    if (mod != (x%n)) return false; 
  }
  return true;
}

int main() {
	scanf("%d", &n);
	if (solve()) {
  	printf("yes");
  } else {
  	printf("no");
  }
	return 0;
}