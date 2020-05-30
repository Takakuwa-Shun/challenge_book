#include <iostream>

const long MAX_N = 1000000;
long cnt = 0, res = 0, a, b, prime_num[MAX_N];
bool isPrime[MAX_N+1];

// n以下の素数の数を求める。蟻本p.112
int sieve(long n) {
  switch (n) {
  case 1:
    return 0;
  case 2:
    return 1;
  default:
    for (long i=0; i<=n; i+=2) {
      isPrime[i] = false;
    }
    for (long i=3; i<=n; i+=2) {
      isPrime[i] = true;
    }
    isPrime[1] = false;
    isPrime[2] = true;
    prime_num[cnt++] = 2;
    for (long i=3; i<=n; i+=2) {
      if (isPrime[i]) {
        prime_num[cnt++] = i;
        for (long j = 2 * i; j<=n; j += i) {
          isPrime[j] = false;
        }
      }
    }
    return cnt;
  }
}

// a以上b未満の素数の数を求める
long solve() {
  long start = a % 2 == 0 ? a+1 : a;
  for (long i=start; i<b; i+=2) {
    bool prime = true;
    for (int j=1; j<cnt; j++) {
      if (i % prime_num[j] == 0) {
        prime = false;
        break;
      }
    }
    if (prime) res++;
  }
  return res;
}

int main() {
	scanf("%ld %ld", &a, &b);
	sieve(MAX_N);
  if (b <= MAX_N) {
    for (int i=0; i<cnt; i++) {
      if (a <= prime_num[i] && prime_num[i] < b) {
        printf("%ld ", prime_num[i]);
        res++;
      }
    }
    printf("%ld", res);
  } else {
  	printf("%ld", solve());
  }
	return 0;
}