#include <iostream>
using namespace std;

const int MAX_N = 1000;
int n, G[MAX_N][MAX_N], color[MAX_N];

int dfs(int i, int c) {
  color[i] = c;

  for (int j=0; j<n; j++) {
    if (G[i][j] == 1) {
      if (color[j] == -1) {
        int newColor = c == 0 ? 1 : 0;
        if (!dfs(j, newColor)) {
          return false;
        }
      } else if (color[j] == c) {
        return false;
      }
    }
  }
  return true;
}

bool solve() {
  for (int i=0; i<n; i++) {
    if (color[i] == -1) {
      if (!dfs(i, 0)) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      G[i][j] = 0;
    }
    color[i] = -1;
  }
  for (int i=0; i<n; i++) {
    int num;
    scanf("%d", &num);
    for (int j=0; j<num; j++) {
      int col;
      scanf("%d", &col);
      G[i][col] = 1;
      G[col][i] = 1;
    }
  }
  // for (int i=0; i<n; i++) {
  //   for (int j=0; j<n; j++) {
  //     printf("%d ", G[i][j]);
  //   }
  //   printf("\n");
  // }
  if (solve()) {
    printf("%s\n", "Yes");
  } else {
    printf("%s\n", "No");
  }
	return 0;
}