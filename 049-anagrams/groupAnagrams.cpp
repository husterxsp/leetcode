#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 解法1，超时
bool equalString(string a, string b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a==b){
        return true;
    }else {
        return false;
    }
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ret = {{""}};
    if(!strs.size()){
        return ret;
    }
    ret[0][0]=strs[0];
    for(int i=1;i<strs.size();i++){
        bool hasFind = false;
        for(int j=0;j<ret.size();j++){
            if(equalString(strs[i], ret[j][0])){
                hasFind = true;
                ret[j].push_back(strs[i]);
                break;
            }
        }
        if(!hasFind){
            ret.push_back({strs[i]});
        }
    }
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout << ret[i][j];
        }
        cout << endl;
    }
    return ret;
}
// 解法2，
// 一次遍历并排序，AC
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<int>> myMap;
    
    for(int i=0;i<strs.size();i++){
        string key = strs[i];
        
        sort(key.begin(), key.end());
        myMap[key].push_back(i);
    }
    vector<vector<string>> ret;
    for(map<string, vector<int>>::iterator it=myMap.begin();it != myMap.end();it++){
        vector<string> tmp;
        for(int i=0;i<it->second.size();i++){
            tmp.push_back(strs[it->second[i]]);
        }
        ret.push_back(tmp);
    }
    return ret;
}
int main()
{
    vector<string> a = {"", ""};
    cout << groupAnagrams(a).size();
    
    return 0;
}

