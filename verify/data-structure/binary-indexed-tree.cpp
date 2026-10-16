// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum
#include <iostream>

using namespace std;

#include "data-structure/binary-indexed-tree.hpp"

void solve(){
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for(auto &i : a)cin >> i;
    BIT<long long> ft(a);
    while(q--){
        int t, p, l, r;
        long long x;
        cin >> t;
        if(t){
            cin >> l >> r;
            cout << ft.sum(l, r) << endl;
        }else{
            cin >> p >> x;
            ft.add(p, x);
        }
    }
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
