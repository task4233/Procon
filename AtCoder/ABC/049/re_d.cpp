#include <bits/stdc++.h>
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

struct UnionFind {
  vector< int > par;
  UnionFind(int n = 1) {
    init(n);
  }

  void init(int n = 1) {
    par.resize(n);
    for(int i = 0; i < n; i++)
      par[i] = -1;
  }
  
  int root(int n) {
    if (par[n] < 0) return n;
    return par[n] = root(par[n]);
  }

  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;

    return true;
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

	int getSize(int x){
		return -(par[root(x)]);
	}
};

signed main() {
  INIT;
	VAR(int,n,k,l);

	UnionFind uf_train(2*n+1);
	REP(i,k){
		VAR(int,p,q);
		uf_train.merge(p-1,q-1);
	}
	UnionFind uf_road(2*n+1);
	REP(i,l){
		VAR(int,r,s);
		uf_road.merge(r-1,s-1);
	}

	map<pair<int,int>,int> cnt;
	REP(i,n){
		++cnt[make_pair(uf_train.root(i),uf_road.root(i))];
	}

	int isFirst = true;
	REP(i,n){
		if(isFirst) isFirst = false;
		else SP;
		OUT(cnt[make_pair(uf_train.root(i),uf_road.root(i))]);
	}
	BR;
  
  return 0;
}
