// 参照URL: https://github.com/Iakatsuki/cp-templates/blob/main/cpp/graph/dijkstra.cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <class T> using vc = vector<T>;
using vi = vc<int>;
using vl = vc<ll>;
template <class T> using vv = vc<vc<T>>;
using vvi = vv<int>;
using vvl = vv<ll>;
using P = pair<ll, ll>;
template <class T> using pq = priority_queue<T, vc<T>>;               // 大きい順
template <class T> using pq_g = priority_queue<T, vc<T>, greater<T>>; // 小さい順

const int INF = 1e9;
const ll INF_ll = 1LL << 60;
vl dx = {1, 0, -1, 0}; // vl dx = {1,1,0,-1,-1,-1,0,1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define drep(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

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

// INF_LLで初期化のstartからのdistと復元用のprev(-1で初期化)を返す
pair<vl, vl> dijkstra(const vv<P> &G, int N, int start) {
    vl dist(N, INF_ll);
    vl prev(N, -1);
    dist[start] = 0;
    pq_g<P> Q;
    Q.push(P(0, start));
    while (!Q.empty()) {
        int d_pos, pos;
        tie(d_pos, pos) = Q.top();
        Q.pop();

        if (d_pos > dist[pos]) continue;

        rep(i, G[pos].size()) {
            int nex = G[pos][i].first;
            int cost = G[pos][i].second;
            if (dist[nex] > dist[pos] + cost) {
                dist[nex] = dist[pos] + cost;
                prev[nex] = pos;
                Q.push(P(dist[nex], nex));
            }
        }
    }
    return pair<vl, vl>(dist, prev);
}

vl reconstruct_path(const vl &prev, int N, int target) {
    int pos = target;
    vl path;
    path.reserve(N);
    while (pos != -1) {
        path.emplace_back(pos);
        pos = prev[pos];
    }
    reverse(all(path));
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, s;
    cin >> N >> M;
    s = 0;
    vv<P> G(N);
    rep1(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(P(b, c));
        G[b].push_back(P(a, c));
    }
    vl dist, prev;
    tie(dist, prev) = dijkstra(G, N, s);
    if (prev[N - 1] == -1) dame;
    vl path = reconstruct_path(prev, N, N - 1);
    rep(i, path.size()) {
        if (i != 0) cout << " ";
        cout << path[i] + 1;
    }
    cout << endl;
    return 0;
}