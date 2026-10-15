// 参照URL: https://github.com/Iakatsuki/cp-templates/blob/main/cpp/math/factorial.cpp
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
template <class T> using V = vector<T>;
using pii = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()

const int INF = 1e9;
const ll INF_ll = 1LL << 60;

const int INF = 1e9;
const ll INF_ll = 1LL << 60;

const ll mod = 1000000007;

// オーバーフローに注意
ll power(ll a, int b) {
    ll p = a, answer = 1;
    while (b > 0) {
        if (b & 1) answer = (answer * p);
        p = (p * p);
        b >>= 1;
    }
    return answer;
}

ll mod_pow(ll a, ll b, ll m) {
    ll p = a % m, answer = 1;
    while (b > 0) {
        if (b & 1) answer = (answer * p) % m;
        p = (p * p) % m;
        b >>= 1;
    }
    return answer;
}

ll factorial(int n) {
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

ll mod_factorial(int n, ll mod) {
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * i) % mod;
    }
    return ans;
}

// 1からnの階乗までをvector<long long>(n+1)で返す関数
vl factorial_vec(int n) {
    vl f(n + 1);
    f.at(0) = 1;
    for (int i = 1; i <= n; i++) {
        f.at(i) = f.at(i - 1) * i;
    }
    return f;
}

vl mod_factorial_vec(int n, ll m) {
    vl f(n + 1);
    f.at(0) = 1;
    for (int i = 1; i <= n; i++) {
        f.at(i) = (f.at(i - 1) * i) % m;
    }
    return f;
}

// mは素数で
ll mod_division(ll a, ll b, ll m) { return (a * mod_pow(b, m - 2, m)) % m; }

ll mod_combination(ll n, ll r, ll m) {
    vl f(n + 1);
    f.at(0) = 1;
    for (int i = 1; i <= n; i++) {
        f.at(i) = (f.at(i - 1) * i) % m;
    }
    ll a = f.at(n);
    ll b = (f.at(r) * f.at(n - r)) % m;
    return mod_division(a, b, m);
}

/*
n<=r
mは素数で
*/
ll mod_combination(ll n, ll r, ll m, const vl &factorial) {
    // 分子aを求める
    ll a = factorial.at(n);
    // 分母bを求める
    ll b = (factorial.at(r) * factorial.at(n - r)) % m;
    return mod_division(a, b, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, r;
    cin >> n >> r;
    vl mod_facto = mod_factorial_vec(n, mod);

    cout << mod_combination(n, r, mod, mod_facto) << endl;
    return 0;
}