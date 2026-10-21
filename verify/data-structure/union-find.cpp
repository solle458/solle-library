// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/unionfind
#include <iostream>

#include "data-structure/union-find.hpp"

using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if(t){
            if(uf.same(u, v))cout << 1 << endl;
            else cout << 0 << endl;
        }else uf.merge(u, v);
    }
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}

