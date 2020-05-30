#include <iostream>
#include <queue>
using namespace std;

struct Point {
  int x;
  int y;
  int cnt;
};

const int MAX_N = 100;
int N, M, cnt = 0;
char maze[MAX_N][MAX_N];
bool checked[MAX_N][MAX_N];
queue<Point> que;


bool isCandidate(int i, int j) {
  if (i<0 || j<0 || i>=N || j>=M || checked[i][j]) {
    return false;
  }
  checked[i][j] = true;
  return maze[i][j] != '#';
}

bool check(int i, int j, int cnt) {
  if (isCandidate(i, j)) {
    if (maze[i][j] == 'G') return true;
    Point p = {i, j, cnt + 1};
    que.push(p);
  }
  return false;
}

bool bfs(int i, int j, int cnt) {
  checked[i][j] = true;
  if (check(i-1, j, cnt)) return true;
  if (check(i+1, j, cnt)) return true;
  if (check(i, j-1, cnt)) return true;
  if (check(i, j+1, cnt)) return true;
  return false;
}

int main() {
  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cin >> maze[i][j];
      checked[i][j] = false;
      if (maze[i][j] == 'S') {
        Point p = {i, j, 0};
        que.push(p);
      }
    }
  }
  while(!que.empty()) {
    Point p = que.front();
    que.pop();
    if (bfs(p.x, p.y, p.cnt)) {
      cout << (p.cnt + 1) << endl;
      break;
    }
  }
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cout << maze[i][j];
    }
    cout << endl;
  }
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cout << checked[i][j];
    }
    cout << endl;
  }
  return 0;
}