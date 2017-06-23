#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;
/**
 思路：从0-9，a-z，A-Z中随机选取6个字符
 */
class Solution {
private:
    unordered_map<string, string> short2long, long2short;
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long2short.find(longUrl) != long2short.end())
            return long2short[longUrl];

        string randStr = "";
        for (int i = 0; i < 6; i++)
            randStr.push_back(dict[rand() % 62]);

        while (long2short.find(randStr) != long2short.end())
            randStr[rand() % 6] = dict[rand() % 62];

        long2short[longUrl] = randStr;
        short2long[randStr] = longUrl;

        return "http://tinyurl.com/" + randStr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string randStr = shortUrl.substr(shortUrl.find_last_of('/') + 1);
        return short2long[randStr];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {
     Solution solution;
     solution.decode(solution.encode(url));
    return 0;
}
