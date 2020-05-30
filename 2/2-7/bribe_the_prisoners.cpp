#include <iostream>

const int MAX_Q = 100;
int P, Q, A[MAX_Q];

int divide(int i, int j) {
  int mid = -1;
  int midDist = INT_MAX;
  int base = (i + j) / 2;
  for (int k=0; k<Q; k++) {
    if (A[k] < i) continue;
    if (j < A[k]) break;
    int before = A[k] - i;
    int after = j - A[k];
    int diff = before < after ? after : before;
    if (diff < midDist) {
      midDist = diff;
      mid = k;
    }
  }
  if (mid == -1) return 0;
  std::printf("(%d %d %d), ", base, A[mid], j-i);
  return divide(i, A[mid]-1) + divide(A[mid]+1, j) + j-i;
}

int main() {
	std::scanf("%d %d", &P, &Q);
  for (int i=0; i<Q; i++) {
    std::scanf("%d", &A[i]);
  }
  std::sort(A, A+Q);
  // for (int i=0; i<Q; i++) {
	//   std::printf("%d ", A[i]);
  // }
	std::printf("\n%d", divide(1, P));
	return 0;
}