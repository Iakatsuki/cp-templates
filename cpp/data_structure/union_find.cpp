// 参照URL: https://github.com/Iakatsuki/cp-templates/blob/main/cpp/data_structure/union_find.cpp
#include <bits/stdc++.h>
using namespace std;

template <typename Int = int> struct dsu {
    static_assert(std::is_integral_v<Int>, "Index type must be integral");
    vector<Int> p;
    explicit dsu(Int n) : p(n, -1) {}
    Int find(Int x) {
        while (p[x] >= 0) {
            if (p[p[x]] >= 0) p[x] = p[p[x]]; // path halving
            x = p[x];
        }
        return x;
    }
    bool merge(Int a, Int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (p[a] > p[b]) swap(a, b);
        p[a] += p[b];
        p[b] = a;
        return true;
    }
    Int size(Int x) { return -p[find(x)]; }
    bool same(Int a, Int b) { return find(a) == find(b); }
};

int main() {
    dsu<int> uni(3);                              // 3個の要素
    uni.merge(0, 1);                              // 0と1を同じグループにする
    cout << (uni.find(0) == uni.find(1)) << endl; // 0と1が同じグループか
    cout << (uni.find(1) == uni.find(2)) << endl; // 1と2が同じグループか
    return 0;
}
