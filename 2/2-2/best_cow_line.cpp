#include <iostream>
using namespace std;

string s, t;

// 同じの時が考慮されていない。 1文字ではなく、文字列で比較。SとSの反転文字列S'
bool check(const char f, const char b) {
  return f < b;
}

int main() {
  cin >> s;
  while (s.size())
  {
    if (check(s.front(), s.back())) {
      t.push_back(s.front());
      s.erase(0, 1);
    } else {
      t.push_back(s.back());
      s.pop_back();
    }
  }
  cout << t << endl;
	return 0;
}