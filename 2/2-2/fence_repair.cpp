#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 20000;
int N, L[MAX_N], cost = 0;

priority_queue<
  int,
  vector<int>,
  greater<int>
> que;

int main() {
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> L[i];
    que.push(L[i]);
  }
  while(que.size() >= 2) {
    int L1 = que.top();
    que.pop();
    int L2 = que.top();
    que.pop();
    int sum = L1 + L2;
    cost += sum;
    que.push(sum);
  }
  cout << cost << endl;
	return 0;
}