#pragma once

#include <unordered_map>

using namespace std;

template<typename T>
struct DynamicUnionFind{
    unordered_map<long long, long long> m;
    DynamicUnionFind() = default;

    long long data(long long k){
        auto it = m.find(k);
        return it == m.end() ? m[k] = -1 : it->second;
    }
    long long find(long long k){
        int n = data(k);
        return n < 0 ? k : m[k] = find(n);
    }
    bool unite(long long x, long long y){
        x = find(x), y = find(y);
        if(x == y)return false;
        auto itx = m.find(x), ity = m.find(y);
        if(itx->second > ity->second)swap(itx, ity), swap(x, y);
        itx->second += ity->second;
        ity->second = x;
        return true;
    }
    template <typename F>
    bool unite(long long x, long long y, const F& f){
        x = find(x), y = find(y);
        if(x == y)return false;
        auto itx = m.find(x), ity = m.find(y);
        if(itx->second > ity->second)swap(itx, ity), swap(x, y);
        itx->second += ity->second;
        ity->second = x;
        f(x, y);
        return true;
    }
    long long size(long long k){ return -data(find(k)); }
    bool same(long long x, long long y){ return find(x) == find(y); }
    void clear() { m.clear(); }
};
