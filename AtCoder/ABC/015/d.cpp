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
const int MAX_N = 55;
const int MAX_W = 1e4 + 1;

int dp[MAX_N][MAX_N][MAX_W];
int W, N, K;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> W >> N >> K;
  vector< int > w(N), v(N);
  REP(i, N)
    cin >> w[i] >> v[i];

  REP(ni, N) {
    REP(ki, K + 1) {
      REP(wi, W + 1) {
	if (wi + w[ni] <= W) {
	  dp[ni + 1][ki + 1][wi + w[ni]] = max(dp[ni][ki][wi] + value, dp[ni][ki + 1][wi + w[ni]]);
	}
	dp[ni + 1][ki][wi] = max(dp[ni + 1][ki][wi], dp[ni][ki][wi]);
       
      }
    }
  }

  return 0;
}

