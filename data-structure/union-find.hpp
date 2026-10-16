#pragma once

#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
  private:
      int size_;
      vector<int> data_;
  public:
      UnionFind(int size) : size_(size) {
          data_.assign(size_, -1);
      }
      int find(int a){
          if(data_[a] < 0)return a;
          return data_[a] = find(data_[a]);
      }
      bool same(int a, int b){
          return find(a) == find(b);
      }
      void merge(int a, int b){
          int la = find(a), lb = find(b);
          if(la == lb)return;
          if(-data_[la] < -data_[lb])swap(la, lb);
          data_[la] += data_[lb];
          data_[lb] = la;
          return;
      }
      int size(int a){
          return -data_[find(a)];
      }
};
