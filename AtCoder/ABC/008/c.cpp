
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
const int MAX_N = 1e2 + 1;

int N;

bool state[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< int > C(N);
  REP(i, N)
    cin >> C[i];

  double ans = 0.0;
  REP(i, N) {
    int target = C[i];
    int cnt = 0;
    REP(j, N) {
      if (i == j) continue;
      if (target % C[j] == 0) cnt++;
    }
    int bias = !(cnt & 1);
    ans += (double)(cnt + 1 + bias) / (double)(2 * (cnt + 1));
    //  printf("%.7f\n", ans);
  }

  printf("%.7f\n", ans);
  //cout << ans << endl;

  return 0;
}

