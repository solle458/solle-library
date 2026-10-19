// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/shortest_path

#include <iostream>
#include <vector>
#include <queue>

#include "graph/graph.hpp"

using namespace std;

void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    G g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }
    vector<long long> dist(n, (1LL<<62)), par(n, -1);
    dist[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0LL, s});
    while(!pq.empty()){
        auto [c, u] = pq.top();
        pq.pop();
        if(dist[u] != c)continue;
        for(auto &e : g[u]){
            if(e.cost + c < dist[e.to]){
                dist[e.to] = e.cost + c;
                par[e.to] = u;
                pq.push({e.cost + c, e.to});
            }
        }
    }
    if(dist[t] == (1LL<<62)){
        cout << -1 << endl;
        return;
    }
    int now = t;
    vector<pair<int, int>> path;
    while(now != s){
        path.emplace_back(par[now], now);
        now = par[now];
    }
    reverse(path.begin(), path.end());
    cout << dist[t] << " " << path.size() << endl;
    for(auto [u, v] : path)cout << u << " " << v << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
