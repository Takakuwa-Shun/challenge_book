#include <iostream>

const int MAX_N = 1000000;
int cnt = 0, prime_num[MAX_N];
bool isPrime[MAX_N+1];

// n以下の素数の数を求める。蟻本p.112
int sieve(int n) {
  switch (n) {
  case 1:
    return 0;
  case 2:
    return 1;
  default:
    for (int i=0; i<=n; i+=2) {
      isPrime[i] = false;
    }
    for (int i=3; i<=n; i+=2) {
      isPrime[i] = true;
    }
    isPrime[1] = false;
    isPrime[2] = true;
    prime_num[cnt++] = 2;
    for (int i=3; i<=n; i+=2) {
      if (isPrime[i]) {
        prime_num[cnt++] = i;
        for (int j = 2 * i; j<=n; j += i) {
          isPrime[j] = false;
        }
      }
    }
    // for (int i=0; i<cnt; i++) {
    //   printf("%d ", prime_num[i]);
    // }
    return cnt;
  }
}

int main() {
  int n;
	scanf("%d", &n);
  printf("%d", sieve(n));
	return 0;
}