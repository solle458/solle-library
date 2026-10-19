#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    int from, to;
    long long cost;
};

class Graph{
  private:
    int size_;
    vector<Edge> g_;
  public:
    Graph() = default;
    Graph(int size) : size_(size) {}
    void add_edge(int idx, Edge &e)g_[e.from].emplace_back(e);
    void add_edge(int idx, int from, int to)g_[from].emplace_back(from, to);
    istream &operator>>(istream &in){
        int from, to;
        long long cost
        in >> from >> to >> cost;
        g_[from].emplace_back(from, to, cost);
    }
    ostream &operator<<(ostream &out){
        for(auto &e : g_){
            for(auto &[f, t, c] : e)out << t << " ";
            out << endl;
        }
    }
    Edge &operator[](int idx) return g_[i];
}

using G = Graph;
