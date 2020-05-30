#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 10000;
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > distQue;
priority_queue< pair<int, int> > supplyQue;
int N, L, P, A[MAX_N];

int main() {
  cin >> N >> L >> P;
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  for (int i=0; i<N; i++) {
    int B;
    cin >> B;
    distQue.push(make_pair(A[i], B));
  }
  cout << endl;
  printf("(%d, %d), ", distQue.top().first, distQue.top().second);

  int cnt = 0;
  for (int i=1; i<=L; i++) {
    P--;
    pair<int, int> p = distQue.top();
    if (i == p.first) {
      distQue.pop();
      supplyQue.push(make_pair(p.second, p.first));
    }

    if (P == 0) {
      if (supplyQue.empty()) {
        cout << -1;
        return 0;
      } else {
        pair<int, int> p2 = supplyQue.top();
        supplyQue.pop();
        P += p2.second;
        cnt++;
      }
    }
  }
  cout << cnt;
	return 0;
}