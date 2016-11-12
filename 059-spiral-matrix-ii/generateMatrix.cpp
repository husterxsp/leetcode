#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ret;
int a[1000][1000];

vector<vector<int>> generateMatrix(int n) {
    int k=0;
    int x=0,y=0;
    k = a[0][0] = 1;
    while (k<n*n) {
        // 此处的tmp 是为了避免次while循环无法结束。
        // 本地调试没有问题但是leecode超时，故在此加了一个tmp, 之后可以AC。原因不详。
        // 另外此算法参照《算法竞赛入门经典》(薄)程序3-3蛇型数组
        int tmp = k;
        while(y+1<n && !a[x][y+1]){
            a[x][++y] = ++k;
        }
        while(x+1<n && !a[x+1][y]){
            a[++x][y] = ++k;
        }
        while(y-1>=0 && !a[x][y-1]){
            a[x][--y] = ++k;
        }
        while(x-1>=0 && !a[x-1][y]){
            a[--x][y] = ++k;
        }
        if(tmp == k){
            k++;
        }
    }
    
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int j=0;j<n;j++){
            tmp.push_back(a[i][j]);
        }
        ret.push_back(tmp);
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    generateMatrix(n);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[0].size();j++){
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}