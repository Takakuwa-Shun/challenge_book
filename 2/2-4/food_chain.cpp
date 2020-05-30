#include <iostream>
using namespace std;

// 蟻本P.84
struct UnionFind
{
	// 問題によって変える。
	static const int MAX_N = 150000;
	
	int n, A, B, C,
	par[MAX_N], // 親の値　par[i] = iのとき、iは親
	rank[MAX_N]; // 木のランク（深さ)

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

int N, K;
UnionFind unionFind;

bool checkInvalidNum(const int x, const int y) {
	return x >= N || y >= N || x < 0 || y < 0;  
}

int main() {
	cin >> N >> K;
	unionFind = UnionFind(N * 3);
	int cnt = 0;
	for (int i=0; i<K; i++) {
		int type, x, y;
		scanf("%d %d %d", &type, &x, &y);
		x--;
		y--;

		if (checkInvalidNum(x, y)) {
			cnt++;
			continue;
		}
		if (type == 1) {
			if (unionFind.same(x,y+N) || unionFind.same(x, y+2*N)) {
				cnt++;
			} else {
				unionFind.unite(x, y);
				unionFind.unite(x+N, y+N);
				unionFind.unite(x+2*N, y+2*N);
			}
		} else {
			if (unionFind.same(x,y) || unionFind.same(x, y+2*N)) {
				cnt++;
			} else {
				unionFind.unite(x, y+N);
				unionFind.unite(x+N, y+2*N);
				unionFind.unite(x+2*N, y);
			}
		}
  }
	printf("%d", cnt);
	return 0;
}
