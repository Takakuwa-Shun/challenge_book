#include <iostream>
#include <queue>
using namespace std;

class Comp {
public:
  bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second > p2.second;
  }
};

priority_queue<
  pair<int, int>,
  vector< pair<int, int> >,
  Comp
 > que;

const int MAX_N = 100000;
int n, s[MAX_N], t[MAX_N], now = 0, cnt = 0;

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> s[i];
  }
  for (int i=0; i<n; i++) {
    cin >> t[i];
  }
  for (int i=0; i<n; i++) {
    pair<int, int> p = make_pair(s[i], t[i]);
    que.push(p);
  }

  while(que.size()) {
    pair<int, int> p = que.top();
    que.pop();
    if (now < p.first) {
      now = p.second;
      cnt++;
      printf("%d\n", p.first);
    }
  }
  printf("%d\n", cnt);
  return 0;
}