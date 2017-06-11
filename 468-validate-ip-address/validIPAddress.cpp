#include <iostream>
#include <vector>

#include <sstream>

using namespace std;
string validIPAddress(string IP) {
    stringstream ss(IP);
    string segment;
    vector<string> seglist;
    char splitChar = IP.find(":") != string::npos ? ':' : '.';
    while(getline(ss, segment, splitChar)) {
        seglist.push_back(segment);
    }
    if (IP.back() == splitChar) return "Neither";
    string ret;
    int n = seglist.size();
    if (n == 4) {
        for (auto str : seglist) {
            if (str.size() == 0 || str.size() > 3) return "Neither";
            if (str.size() > 1 && str[0] == '0') return "Neither";
            int cur = 0;
            for (auto c : str) {
                if (c < '0' || c > '9') return "Neither";
                cur = cur * 10 + c - '0';
            }
            if (cur > 255) return "Neither";
        }
        return "IPv4";
    }
    else if (n == 8) {
        for (auto str : seglist) {
            if (str.size() == 0 || str.size() > 4) return "Neither";
            for (auto c : str) {
                c = tolower(c);
                if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f')) return "Neither";
            }
        }
        return "IPv6";
    }

    return "Neither";
}
int main () {
    cout << stoi("-123asd") << endl;
    cout << validIPAddress("2001:") << endl;
    return 0;
}
