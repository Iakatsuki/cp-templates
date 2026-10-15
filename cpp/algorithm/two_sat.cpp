// 参照URL: https://github.com/Iakatsuki/cp-templates/blob/main/cpp/algorithm/two_sat.cpp
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

class SCC {
    int n;
    vector<vector<int>> g;

    int now_ord;
    int group_count;
    vector<int> ord, low;
    vector<int> group_id; // 各頂点が属する強連結成分のID
    vector<bool> in_stack;
    stack<int> st;

    void dfs(int v) {
        ord[v] = now_ord;
        low[v] = now_ord;
        now_ord++;
        st.push(v);
        in_stack[v] = true;

        for (int to : g[v]) {
            if (ord[to] == -1) {
                dfs(to);
                low[v] = min(low[v], low[to]);
            } else if (in_stack[to]) {
                low[v] = min(low[v], ord[to]);
            }
        }

        // v が属するSCCの根である場合
        if (low[v] == ord[v]) {
            while (true) {
                int u = st.top();
                st.pop();
                in_stack[u] = false;
                group_id[u] = group_count; // IDを割り当てる
                if (u == v) break;
            }
            group_count++;
        }
    }

public:
    SCC(int n) : n(n), g(n) {}

    void add_edge(int from, int to) { g[from].push_back(to); }

    // 各頂点のグループIDと、全体のグループ数を返す
    // トポロジカル順（トポロジカルソートで上流にある成分ほどIDが小さくなる）で出力
    pair<int, vector<int>> get_scc() {
        now_ord = 0;
        group_count = 0;
        ord.assign(n, -1);
        low.assign(n, 0);
        group_id.assign(n, -1);
        in_stack.assign(n, false);

        for (int i = 0; i < n; ++i) {
            if (ord[i] == -1) dfs(i);
        }

        // DFS実行時点では葉（下流）から順にIDが0, 1, 2...と採番されるため、
        // トポロジカル順（上流が0）にするためにIDを反転させる
        for (int i = 0; i < n; ++i) {
            group_id[i] = group_count - 1 - group_id[i];
        }

        return {group_count, group_id};
    }

    // ACLの scc() 関数のように [ [頂点群], [頂点群], ... ]
    // の形式で抽出するヘルパー
    vector<vector<int>> groups() {
        auto [k, ids] = get_scc();
        vector<vector<int>> result(k);
        for (int i = 0; i < n; ++i) {
            result[ids[i]].push_back(i);
        }
        return result;
    }
};

int neg(int a, int N) { return (a + N) % (2 * N); }

int main() {
    int N, M;
    cin >> N >> M;
    SCC scc(2 * N);
    rep(i, M) {
        int a, b;
        char x, y;
        cin >> a >> x >> b >> y;
        a--;
        b--;
        if (x == 'W') a = neg(a, N);
        if (y == 'W') b = neg(b, N);
        scc.add_edge(neg(a, N), b);
        scc.add_edge(neg(b, N), a);
    }
    int n_v;
    vector<int> id;
    tie(n_v, id) = scc.get_scc();
    for (int i = 0; i < N; i++) {
        if (id[i] == id[neg(i, N)]) {
            cout << -1 << endl;
            return 0;
        }
    }
    vvi comp = scc.groups();
    vector<bool> tf(2 * N, false);
    drep(i, n_v) {
        for (auto v : comp[i]) {
            if (!tf[neg(v, N)]) {
                tf[v] = true;
            } else {
                tf[v] = false;
            }
        }
    }
    rep(i, N) {
        if (tf[i]) {
            cout << 'V' << endl;
        } else {
            cout << 'W' << endl;
        }
    }

    return 0;
}
