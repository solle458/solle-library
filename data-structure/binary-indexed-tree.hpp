#pragma once

#include <vector>
#include <cassert>

template <typename T>
class BIT{
  private:
    int size_;
    std::vector<T> data_;

    void build(std::vector<T> &data){
        for(int i = 0; i < (int)data.size(); i++){
            add(i, data[i]);
        }
    }

  public:
    BIT() = default;
    BIT(int size) : size_(size+1) { data_.assign(size_, T{}); }
    BIT(std::vector<T> data) {
        size_ = (int)data.size() + 1; // 1-index
        data_.assign(size_, T{});
        build(data);
    }

    void add(int idx, T x){
        for(int i = idx+1; i < size_; i += (i & -i)) data_[i] += x;
    }
    T sum(int l, int r){
        std::assert(l <= r);
        return sum(r-1) - sum(l-1);
    }
    T sum(int idx){
	    if(idx < 0)return T{};
        T res{};
        for(int i = idx+1; i > 0; i -= (i & -i)) res += data_[i];
        return res;
    }
    int lower_bound(T key){
        if(key < 0){
            return 0;
        }else{
            int x = 0, r = 1;
            while(r < size_) r = r << 1;
            for(int len = r; len > 0; len = len >> 1){
                if(x + len < size_ and data_[x + len] < key){
                    key -= data_[x + len];
                    x += len;
                }
            }
            return x;
        }
    }
    int upper_bound(T key){
        if(key < 0){
            return 0;
        }else{
            int x = 0, r = 1;
            while(r < size_) r = r << 1;
            for(int len = r; len > 0; len = len >> 1){
                if(x + len < size_ and data_[x + len] <= key){
                    key -= data_[x + len];
                    x += len;
                }
            }
            return x;
        }
    }
};
