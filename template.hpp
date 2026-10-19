using namespace std;

template<class T, class S>
inline bool chmax(T &a, S &b){
    if(a >= b)return false;
    a = b;
    return true;
}


template<class T, class S>
inline bool chmin(T &a, S &b){
    if(a <= b)return false;
    a = b;
    return true;
}
