#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;

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

int check(ll N, ll b, ll S) {
  ll sm = 0ll;
  // debug(sm);
  while (N != 0) {
    sm += N % b;
    N -= N % b;
    N /= b;
    // debug(N);
  }
  // debug(sm);
  return S == sm;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LCIN(N, S);
  if (S == 1) {
    cout << N << endl;
    return 0;
  }

  FOR(bi, 2, sqrt(N + 1)) {
    if (check(N, bi, S)) {
      cout << bi << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}

