#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct UnionFind
{
	// 問題によって変える。
	static const int MAX_N = 10000;
	
	int n,
	par[MAX_N], // 親の値　par[i] = iのとき、iは親
	rank[MAX_N]; // 木のランク（深さ）

	UnionFind(): n(MAX_N){};
	UnionFind(const int n): n(n) {
		init(n);
	};

	void init(const int nn) {
		n = nn;
		for (int i=0; i<nn; i++) {
			par[i] = i;
			rank[i] = 0;
  	}
	}

	// xの親の値を返す
	int find(const int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	};

	// xとyが同じ親か判別する
	bool same(const int x, const int y) {
		return find(x) == find(y);
	};

	// xとyの属する集合を併合
	void unite(const int x, const int y) {
		int px = find(x);
		int py = find(y);
		if (px == py) return;
		
		if (rank[px] < rank[py]) {
			par[px] = py;
		} else {
			par[py] = px;
			if (rank[px] == rank[py]) rank[px]++; 
		}
	}
};

struct Edge {int u, v, cost; };

const int MAX_E = 1000;
int V, E, res = 0;
Edge edge[MAX_E];

// コストが低い順
bool comp(const Edge& e1, const Edge& e2) {
	return e1.cost < e2.cost;
}

// 蟻本P.101
int kruskal() {
	int res = 0;
  UnionFind unionFind(V);
	std::sort(edge, edge+E, comp);
	for (int i=0; i<E; i++) {
		Edge e = edge[i];
		if (!unionFind.same(e.u, e.v)) {
			unionFind.unite(e.u, e.v);
			res += e.cost;
		}
  }
	return res;
}

void solve() {
  int res = kruskal();
  printf("%d", (V * 10000 + res));
}

int main() {
  int N, M;
	scanf("%d %d %d", &N, &M, &E);
  V = N + M;
  for (int i=0; i<E; i++) {
    scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost);
    edge[i].cost *= -1;
    edge[i].v += N;
  }
  solve();
	return 0;
}