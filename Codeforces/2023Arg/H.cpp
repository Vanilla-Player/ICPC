// https://codeforces.com/gym/104603/problem/H
#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define fore(i, a, b) for (int i = a, gmat = b; i < gmat; ++i)
#define FIN ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mst(a, v) memset((a), (v), sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull solve(vector<vector<ull>> ass) {
  ull N = ass.size();

  vector<tuple<ull, ull, ull>> l;
  fore(i, 0, N) {
    fore(j, 0, N) {
      l.push_back({ass[i][j], i, j});
    }
  }

  sort(ALL(l));

  vector<ull> ver_dob(N);
  vector<ull> hor_dob(N);

  ull ans = 0;

  for (ll k = N * N - 1; k >= 0; k--) {
    auto [a, i, j] = l[k];

    ull aux = hor_dob[i];

    ull cambio = ver_dob[j] + 1; // Cambio horizontal
    hor_dob[i] = max(cambio, hor_dob[i]);

    ans = max(cambio, ans);


    cambio = aux + 1; //  Cambio Vertical
    ver_dob[j] = max(cambio,ver_dob[j]);

    ans = max(cambio,ans);
  }

  return ans;
}

int main() {
  FIN;

  ull N;
  cin >> N;
  vector<vector<ull>> ass(N, vector<ull>(N));
  for (auto& as : ass) {
    for (ull& a : as) {
      cin >> a;
      a--;
    }
  }

  cout << solve(ass) << '\n';

  return 0;
}