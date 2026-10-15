// 参照URL: https://github.com/Iakatsuki/cp-templates/blob/main/cpp/algorithm/binary_search.cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lll = __int128;

template <class T> using vc = vector<T>;
using vi = vc<int>;
using vl = vc<ll>;
template <class T> using vv = vc<vc<T>>;
using vvi = vv<int>;
using vvl = vv<ll>;
using vs = vc<string>;
using P = pair<ll, ll>;

const int INF = 1e9;
const ll INF_ll = 1LL << 60;
vl dx = {1, 0, -1, 0}; // vl dx = {1,1,0,-1,-1,-1,0,1};
vl dy = {0, 1, 0, -1}; // vl dx = {0,1,1,1,0,-1,-1,-1};

using ld = long double;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define drep(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define drep1(i, n) for (int i = (int)(n); i >= 1; i--)
#define nfor(i, s, n) for (ll i = s; i < (ll)(n); i++)        // i=s,s+1...n-1 ノーマルfor
#define dfor(i, s, n) for (ll i = (s) - 1; i >= (ll)(n); i--) // s-1スタートでnまで落ちる
#define fore(c, s) for (auto c : s)                           // for_each

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define YN                                                                                         \
    { cout << "Yes" << endl; }                                                                     \
    else {                                                                                         \
        cout << "No" << endl;                                                                      \
    }
#define dame cout << -1 << endl
#define vc_unique(v) v.erase(unique(v.begin(), v.end()), v.end());

bool out_grid(ll i, ll j, ll h, ll w) { // trueならcontinueする
    return (!(0 <= i && i < h && 0 <= j && j < w));
}

ll nc2(ll x) { return x * (x - 1) / 2; }
ll nc3(ll x) { return x * (x - 1) * (x - 2) / 6; }

// const int mint = 998244353;
// const int mint = 1000000007;

bool check(ll x, const vl &A, int N, int D) {
    ll lt = 0;
    ll ld = 0;
    rep(i, N) {
        lt += A[i];
        if (lt > x) {
            ld++;
            lt = A[i];
        }
    }
    if (lt != 0) ld++;
    return ld <= D;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, D;
    cin >> N >> D;
    vl A(N);
    rep(i, N) { cin >> A[i]; }
    int mv = *max_element(all(A));
    // 答えで二分探索
    // checkは単調
    // checkを満たす最小値
    ll left = mv - 1, right = INF_ll;
    while (right - left > 1) {
        ll mid = (left + right + 1) / 2;

        if (check(mid, A, N, D)) right = mid;
        else
            left = mid;
    }
    cout << right << endl;
    return 0;
}
