// 参照URL: https://github.com/Iakatsuki/cp-templates/blob/main/cpp/data_structure/segment_tree.cpp
#include <algorithm>
#include <concepts>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

template <typename T, typename M> // typeとモノイド
class SegmentTree {
private:
    int n;    // 元の要素数
    int size; // 2の冪乗に揃えた葉の数
    std::vector<T> tree;
    M op; // 二項演算オブジェクト

public:
    // サイズ指定コンストラクタ
    explicit SegmentTree(int n_) : n(n_) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, M::identity());
    }

    // 配列からの構築コンストラクタ (O(N) 構築)
    explicit SegmentTree(const std::vector<T> &v) : SegmentTree(v.size()) {
        for (int i = 0; i < n; ++i) {
            tree[size + i] = v[i];
        }
        for (int i = size - 1; i > 0; --i) {
            tree[i] = op(tree[2 * i], tree[2 * i + 1]);
        }
    }

    // 点更新: O(log N)
    void update(int idx, T val) {
        idx += size;
        tree[idx] = val;
        while (idx > 1) {
            idx >>= 1;
            tree[idx] = op(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    // 区間取得 [l, r): 半開区間 O(log N)
    T query(int l, int r) const {
        T res_left = M::identity();
        T res_right = M::identity();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) res_left = op(res_left, tree[l++]);
            if (r & 1) res_right = op(tree[--r], res_right);
            l >>= 1;
            r >>= 1;
        }
        return op(res_left, res_right);
    }

    // 点取得: O(1)
    T operator[](int idx) const { return tree[size + idx]; }
};

struct RSQ {
    static constexpr int identity() { return 0; }
    int operator()(int a, int b) const { return a + b; }
};

// int型最大値クエリ(単位元0の場合)
struct RMQ {
    static constexpr int identity() { return 0; }
    int operator()(int a, int b) const { return max(a, b); }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<int, RMQ> tree(N);
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        int pos, x;
        int l, r;
        if (type == 1) {
            cin >> pos >> x;
            pos--;
            tree.update(pos, x);
        } else if (type == 2) {
            cin >> l >> r;
            l--;
            r--;
            cout << tree.query(l, r) << endl;
        }
    }

    return 0;
}