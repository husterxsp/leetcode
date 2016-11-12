#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, double> myMap;
map<int, double>::iterator it;

// 二分，以及注意保存中间值
double myPow(double x, int n) {
    double ret;
    if(n == 1){
        return x;
    }
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 1/(x*myPow(x, -n-1));
    }
    
    it = myMap.find(n);
    if(it != myMap.end()){
        return it->second;
    }
    
    if(n%2 == 0){
        ret = myPow(x, n/2)*myPow(x, n/2);
    } else {
        ret = x*myPow(x, n/2)*myPow(x, n/2);
    }
//    myMap.insert(pair<int, double>(n, ret));
    myMap[n] = ret;
    return ret;
}

int main(){
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n);
    return 0;
}
