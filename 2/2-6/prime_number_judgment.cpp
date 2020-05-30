#include <iostream>
using namespace std;

int n;

bool solve() {
  if (n % 2 == 0) {
    return false;
  }
  for (int i=3; i*i<=n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return n != 1;
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