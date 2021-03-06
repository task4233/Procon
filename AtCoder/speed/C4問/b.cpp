// ------------------------------------
// Date:2018/ 3/25
// Problem:C - Together b.cpp
//
// ------------------------------------

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

static const int MOD = 1e9 + 7;
static const int MAX_N = 1e5 + 101;

int N;

ll cnt[MAX_N];

int main()
{
  fill_n(cnt, MAX_N, 0);
  scanf("%d", &N);
  vector< int > a(N);
  REP(i, N) {
    scanf("%d", &a[i]);
    if (a[i] > 0) cnt[a[i] - 1]++;
    cnt[a[i]]++;
    cnt[a[i] + 1]++;
  }

  ll ans = -1ll;
  REP(i, MAX_N) {
    ans = max(ans, cnt[i]);
  }

  cout << ans << endl; 
  
  return 0;
}

