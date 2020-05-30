#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

struct Edge { int from, to, cost;};

const int MAX_N = 5000, MAX_R = 100000;
int N, R, len = 0, dist[MAX_N], dist2[MAX_N];
vector<Edge> G[MAX_N];
priority_queue<P, vector<P>, greater<P> > que;

void dijkstra(int s) {
  fill(dist, dist + N, INT_MAX);
  fill(dist2, dist2 + N, INT_MAX);
  dist[s] = 0;

  P p = make_pair(0, 0);
  que.push(p);

  while (que.size()) {
    P p = que.top();
    que.pop();
    int V = p.second;
    if (dist2[V] < p.first) continue;
    for (int i=0; i<G[V].size(); i++) {
      Edge e = G[V][i];
      int d2 = dist[e.from] + e.cost;
      if (d2 < dist[e.to]) {
        swap(dist[e.to], d2);
        que.push(P(dist[e.to], e.to));
      }
      if (d2 < dist2[e.to] && dist[e.to] < d2) {
        dist2[e.to] = d2;
        que.push(P(dist2[e.to], e.to));
      }
    }
  }
}

void solve() {
  dijkstra(0);
  len = dist2[N-1];
}

int main() {
	scanf("%d %d", &N, &R);
  for (int i=0; i<R; i++) {
    int from, to, cost;
	  scanf("%d %d %d", &from, &to, &cost);
    Edge e = {from-1, to-1, cost};
    G[from-1].push_back(e);
  }
  for (int i=0; i<N; i++) {
    for (int j=0; j<G[i].size(); j++) {
	    printf("(%d, %d, %d), ", G[i][j].from, G[i][j].to, G[i][j].cost);
    }
    printf("\n");
  }
  solve();

  for (int i=0; i<N; i++) {
    printf("%d ", dist[i]);
  }
  printf("\n");
  for (int i=0; i<N; i++) {
    printf("%d ", dist2[i]);
  }
  printf("\n");
	printf("%d", len);
	return 0;
}