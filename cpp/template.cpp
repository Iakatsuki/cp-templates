// 参照URL: https://github.com/Iakatsuki/cp-templates/blob/main/cpp/template.cpp
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using ll = long long;
using lll = __int128;

template <class T> using vc = vector<T>;
using vi = vc<int>;
using vl = vc<ll>;
template <class T> using vv = vc<vc<T>>;
using vvi = vv<int>;
using vvl = vv<ll>;
using vvvi = vc<vvi>;
using vvvl = vc<vvl>;
using vs = vc<string>;
using pll = pair<ll, ll>;
template <class T> using pq = priority_queue<T, vc<T>>; // 大きい順
template <class T>
using pq_g = priority_queue<T, vc<T>, greater<T>>; // 小さい順

const int INF = 1e9;
const ll INF_ll = 1LL << 60;
vl dx = {1, 0, -1, 0}; // vl dx = {1,1,0,-1,-1,-1,0,1};
vl dy = {0, 1, 0, -1}; // vl dx = {0,1,1,1,0,-1,-1,-1};

#define pop_cnt(s) ll(popcount(uint64_t(s)))

#define next_p(v) next_permutation(v.begin(), v.end())

using ld = long double;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define drep(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define drep1(i, n) for (int i = (int)(n); i >= 1; i--)
#define nfor(i, s, n)                                                          \
  for (ll i = s; i < (ll)(n); i++)  // i=s,s+1...n-1 ノーマルfor
#define fore(c, s) for (auto c : s) // for_each

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define YN                                                                     \
  { cout << "Yes" << endl; }                                                   \
  else {                                                                       \
    cout << "No" << endl;                                                      \
  }
#define dame cout << -1 << endl
#define vc_unique(v) v.erase(unique(v.begin(), v.end()), v.end());

template <class T> istream &operator>>(istream &i, vc<T> &v) {
  rep(j, size(v)) i >> v[j];
  return i;
}

bool out_grid(ll i, ll j, ll h, ll w) { // trueならcontinueする
  return (!(0 <= i && i < h && 0 <= j && j < w));
}

ll gcd(ll A, ll B) { return __gcd(A, B); }

ll lcm(ll A, ll B) {
  if (A == 0 || B == 0)
    return 0;
  ll g = __gcd(A, B);
  __int128 t = (__int128)(A / g) * B;
  return (ll)t;
}

ll nc2(ll x) { return x * (x - 1) / 2; }
ll nc3(ll x) { return x * (x - 1) * (x - 2) / 6; }

#define vc_cout(v)                                                             \
  {                                                                            \
    ll n = size(v);                                                            \
    rep(i, n) cout << v[i] << endl;                                            \
  } // 一次元配列を出力する

#define vv_cout(v)                                                             \
  {                                                                            \
    ll n = size(v);                                                            \
    rep(i, n) {                                                                \
      rep(j, size(v[i])) {                                                     \
        if (j != 0)                                                            \
          cout << " ";                                                         \
        cout << v[i][j];                                                       \
      }                                                                        \
      cout << endl;                                                            \
    }                                                                          \
  }

// 基本：小数点以下桁数を一括指定
#define PREC(n) cout << fixed << setprecision(n)

// よく使う桁数をマクロ化
#define PREC6 cout << fixed << setprecision(6)
#define PREC10 cout << fixed << setprecision(10)
#define PREC15 cout << fixed << setprecision(15)

// 値をそのまま出力する用
#define OUTF6(x) (cout << fixed << setprecision(6) << (x) << '\n')
#define OUTF10(x) (cout << fixed << setprecision(10) << (x) << '\n')

// const int mint = 998244353;
// const int mint = 1000000007;
using mint = modint1000000007;

/*
考察するところ

 */

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  return 0;
}