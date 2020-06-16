#include <iostream>
#include <set>
#include <map>

const int MAX_P = 1000000;
int P, a[MAX_P];
std::set<int> content;
std::map<int, int> checkMap;

int solve() {
  int s = 0, t = 0, res = P;
  while (true) {
    while (t < P && checkMap.size() < content.size()) {
      std::map<int, int>::iterator it = checkMap.find(a[t]);
      if (it == checkMap.end()) {
        checkMap.insert(std::make_pair(a[t], 1));
      } else {
        it->second++;
      }
      t++;
    }
    if (checkMap.size() < content.size()) break;
    res = std::min(res, t-s);
    std::map<int, int>::iterator it = checkMap.find(a[s]);
    if (it->second == 1) {
      checkMap.erase(it);
    } else {
      it->second--;
    }
  }
  return res;
}

int main() {
	std::scanf("%d", &P);
  for (int i=0; i<P; i++) {
    std::scanf("%d", &a[i]);
    content.insert(a[i]);
  }
	std::printf("\n%d", solve());
	return 0;
}