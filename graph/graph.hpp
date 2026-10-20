#pragma once

#include <vector>

struct Edge {
  int to;
  long long cost;
  Edge() = default;
  Edge(int t, long long c = 1) : to(t), cost(c) {}
};

class Graph {
  private:
    int n;
    std::vector<std::vector<Edge>> g;
  public:
    Graph() = default;
    explicit Graph(int n_) : n(n_), g(n_) {}
    int size() { return n; }
    int size() const { return n; }
    void add_edge(int from, int to, long long cost = 1) {
        g[from].emplace_back(to, cost);
    }
    void add_undirected(int u, int v, long long cost = 1) {
        add_edge(u, v, cost);
        add_edge(v, u, cost);
    }
    std::vector<Edge> operator[](int i) const { return g[i]; }
    std::vector<Edge> &operator[](int i) { return g[i]; }
};

using G = Graph;
