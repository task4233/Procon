#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cmath>
#include <cfloat>
#include <set>
#include <map>

// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 3e5 + 1;

// init/input
#define int int64
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...) type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T &t) {cin>>t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First &first, Rest&...rest) {cin>>first;MACRO_VAR_Scan(rest...);}
#define VEC(type, c, n) vector<type> c(n);for(auto &&i:c)cin>>i;

// out
#define OUT(dist) cout<<(dist);
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<endl;
#define zero(n) cout<<setfill('0')<<right<<setw(n)
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

// 1 2 2 1
// 0 1 1 0 + 1
// 1 + 1 = 2
//
// 3 1 2 3 1
// 2 0 1 2 0 + 1
// 2 + 2 + 1 = 5
//
// 4 23 75 0 23 96 50 100
// 0 19 71 0 19 92 46 96 + 4
// 0 0 52 0 0 73 27 77 + 23
// 0 0 25 0 0 46 0 50 + 50
// l or rが0の時の最小値を求める
// 左から順に0にしていけば良い


signed main() {
  INIT;
	VAR(int, n);
	VEC(int, h, n);

	int ans = 0;
	REP(l, n) {
		while(h[l]>0) {
			int r;
			for(r=l;r<n;++r){
				// 区間の終わり
				if(h[r]==0) break;
			}
			FOR(i,l,){
				--h[i];
			}
			++ans;
		}
	}

	OUT(ans)BR;
	
  return 0;
}
