#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;


int sm[575][575];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N, M, Q);
  REP(i, M) {
    CIN(L, R);
    // L--; R--;
    sm[1][R]++;
    sm[L + 1][R]--;
  }

  REP(i, N) {
    REP(j, N) {

      sm[i + 1][j + 1] += sm[i][j + 1];
      sm[i + 1][j + 1] += sm[i + 1][j];
      sm[i + 1][j + 1] -= sm[i][j];
      // debug(sm[i + 1][j + 1]);
    }
  }

  
  
  REP(i, Q) {
    CIN(p, q);
    // p--; q--;
    cout << sm[p][q] << endl;
  }
  
  return 0;
}

