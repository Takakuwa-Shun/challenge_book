#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {int from, to, cost; };
const int MAX_V = 1000, MAX_E = 20000;
Edge edge[MAX_E];
int V, E, dist[MAX_V];
bool update = true;

// 蟻本 P.95
void bellmanford(int s) {
  for(int k=0; k<V; k++) {
    update = false;
    for (int i=0; i<E; i++) {
      Edge e = edge[i];
      if (dist[e.from] != INT_MAX && dist[e.from] + e.cost < dist[e.to]) {
        dist[e.to] = dist[e.from] + e.cost;
        update = true;
      }
    }
  }
}

int shortestPath(int s) {
  std::fill(dist, dist+V, INT_MAX);
  dist[s] = 0;
  bellmanford(s);
  return dist[V-1];
}

bool find_negative_loop(int s) {
  std::fill(dist, dist+V, 0);
  bellmanford(s);
  return update;
}

int main() {
  int N, ML, MD;
	scanf("%d %d %d", &N, &ML, &MD);
  V = N;
  E = N - 1 + ML + MD;
  for (int i=0; i<N-1; i++) {
    Edge e = {i+1, i, 0};
    edge[i] = e;
  }
  for (int i=0; i<ML; i++) {
    int AL, BL, DL;
    scanf("%d %d %d", &AL, &BL, &DL);
    Edge e = {AL-1, BL-1, DL};
    edge[i+N-1] = e;
  }
  for (int i=0; i<MD; i++) {
    int AD, BD, DD;
    scanf("%d %d %d", &AD, &BD, &DD);
    Edge e = {BD-1, AD-1, -DD};
    edge[i+N-1+ML] = e;
  }
  if(find_negative_loop(0)) {
	  printf("-1\n");
    return 0;
  }

  int res = shortestPath(0);
  if (res == INT_MAX) {
	  printf("-2\n");
  } else {
	  printf("%d\n", res);
  }
	return 0;
}