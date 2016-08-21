#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
// 解法1
// int strStr(string haystack, string needle) {
//     if(needle.length() == 0){
//         return 0;
//     }
//     if (haystack.length() < needle.length()) {
//         return -1;
//     }
//     int i, j;
//     for(i=0;i<haystack.length()-needle.length()+1;i++){
//         for(j=0;j<needle.length();j++){
//             if(haystack[i+j] != needle[j]){
//                 break;
//             }
//         }
//         if(j == needle.length()){
//             return i;
//         }
//     }
//     return -1;
// }

// 解法2，问题待解决
// vector<int> KMPpreprocess(string str) {
//     int n = str.length();
//     vector<int> match(n, -1);
//     int j = -1;
//     for(int i=1; i<n; i++) {
//         while(j>=0 && str[i]!=str[j+1]){
//             j = match[j];
//         }
//         if(str[i]==str[j+1]) {
//             j++;
//         }
//         match[i] = j;
//     }
//     return match;
// }

// int strStr(string haystack, string needle) {
//     int i, j, m = haystack.length(), n = needle.length();
//     vector<int> match = KMPpreprocess(needle);
//     if(m < n){
//         return -1;
//     }
//     if(n == 0){
//         return 0;
//     }
//     j = -1;
//     for(i=0; i<m; i++) {
//         while(j>=0 && haystack[i]!=needle[j+1]) j = match[j];
//         if(haystack[i]==needle[j+1]) j++;
//         if(j==n-1) return (i-n+1);
//     }
//     return -1;
// }

int main(){
    cout << strStr("abb", "abaaa");
    return 0;
}