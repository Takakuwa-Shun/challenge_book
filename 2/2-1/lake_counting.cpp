#include <iostream>
using namespace std;

const int MAX_NM = 100;
int result = 0, height, width;
char garden[MAX_NM][MAX_NM];
int countGarden[MAX_NM][MAX_NM];

bool check(int i, int j) {
  if (i < 0 || i >= height || j < 0 || j >= width
  ) {
    return false;
  }
  return countGarden[i][j] > 0;
}

int search(int i, int j) {
  int count = result + 1;
  for (int dx=-1; dx<=1; dx++) {
    for (int dy=-1; dy<=1; dy++) {
      if (check(i+dx, j+dy)) {
        count = min(countGarden[i+dx][j+dy], count);
      }
    }
  }
  if (count == result + 1) {
    result += 1;
  }
  return count;
}

int main() {
  cin >> height >> width;
  for (int i=0; i<height; i++) {
    for (int j=0; j<width; j++) {
      cin >> garden[i][j];
      countGarden[i][j] = -1;
    }
  }
  for (int i=0; i<height; i++) {
    for (int j=0; j<width; j++) {
      if (garden[i][j] == 'w') {
        countGarden[i][j] = search(i, j);
      }
    }
  }
  for (int i=0; i<height; i++) {
    for (int j=0; j<width; j++) {
      cout << countGarden[i][j];
    }
    cout << endl;
  }
  cout << result << endl;
}