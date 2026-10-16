#pragma once

#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

template <class T, auto op, auto e>
class SegTree {
  private:
    int size_ = 1;
    vector<T> data_;
    void build(vector<T> &data){
        for(int i = 0; i < (int)data.size(); i++)data_[size_/2 + i] = data[i];
        for(int i = size_/2 - 1; i >= 0; i--)data_[i] = op(data_[i*2 + 1], data_[i*2 + 2]);
    }
  public:
    SegTree() = default;
    SegTree(int size) {
        while(size > size_)size_ <<= 1;
        size_ *= 2;
        size_--;
        data_.assign(size_, e());
    }
    SegTree(vector<T> &data) {
        int size = (int)data.size();
        while(size > size_)size_ <<= 1;
        size_ *= 2;
        size_--;
        data_.assign(size_, e());
        build(data);
    }
    void update(int idx){
        if(idx == 0) return;
        int p = (idx - 1)/2;
        int l = p*2 + 1, r = p*2 + 2;
        data_[p] = op(data_[l], data_[r]);
        update(p);
    }
    T get(int idx){
        assert(0 <= idx and idx + size_/2 < size_);
        return data_[size_/2 + idx];
    }
    void set(int idx, T x){
        assert(0 <= idx and idx + size_/2 < size_);
        data_[size_/2 + idx] = x;
        update(size_/2 + idx);
    }
    T prod(int l, int r){
        assert(0 <= l and l <= r and r <= size_/2 + 1);
        if(l == r)return e();
        T res = e();
        // [mn, mx)
        auto down = [&](auto self, int mn, int mx, int idx){
            int len = (mx - mn)/2, idxL = idx*2 + 1, idxR = idx*2 + 2;
            pair<int, int> segL = {mn, mn+len}, segR = {mn+len, mx};
            if(r <= mn or mx <= l)return;
            if(l <= mn and mx <= r)res = op(res, data_[idx]);
            else{
                self(self, segL.first, segL.second, idxL);
                self(self, segR.first, segR.second, idxR);
            }
        };
        down(down, 0, size_/2 + 1, 0);
        return res;
    }
    template <bool (*f)(T)>
    int max_right(int l){
        return max_right(l, [](T x){ return f(x); });
    }
    template <class F>
    int max_right(int l, F f) {
        assert(0 <= l && l <= size_ / 2 + 1);
        assert(f(e()));
        int ok = l, ng = size_ / 2 + 1 + 1;  // 探索範囲は r ∈ [l, leaves]
        // 最大の r (l <= r <= leaves) s.t. f(prod(l, r))
        int leaves = size_ / 2 + 1;
        ok = l;
        ng = leaves + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (f(prod(l, mid))) ok = mid;
            else ng = mid;
        }
        return ok;
    }
};

long long segtree_op_min(long long a, long long b) { return min(a, b); }
long long segtree_e_min() { return (1LL << 62); }
long long segtree_op_max(long long a, long long b) { return max(a, b); }
long long segtree_e_max() { return -(1LL << 62); }
long long segtree_op_sum(long long a, long long b) { return a + b; }
long long segtree_e_sum() { return 0LL; }

using RangeMin = SegTree<long long, segtree_op_min, segtree_e_min>;
using RangeMax = SegTree<long long, segtree_op_max, segtree_e_max>;
using RangeSum = SegTree<long long, segtree_op_sum, segtree_e_sum>;
