#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Twitter {
public:
    struct Tweet {
        int time;
        int id;
        Tweet(int time, int id) : time(time), id(id) {}
    };

    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;

    int time = 0;
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        // follow 自己
        follow(userId, userId);
        tweets[userId].emplace_back(time++, tweetId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;

        // 此处可以用map 或者优先队列priority_queue，他们都会自动排序
        // 还有自己构建堆heap?
        map<int, int> top10;
        for (auto id : following[userId]) {
            for (auto tweet : tweets[id]) {
                // 此处的条件不写 >= 10,因为之后的比较中可能一直都是10
                // top10.size() > 10 只在map的size还没达到10的时候起作用，达到10以后就没作用了。
                if (!top10.empty() && top10.begin()->first > tweet.time && top10.size() > 10) break;

                top10.insert({tweet.time, tweet.id});

                if (top10.size() > 10) top10.erase(top10.begin());
            }
        }
        for (auto it = top10.rbegin(); it != top10.rend(); ++it) {
            ret.push_back(it->second);
        }
        return ret;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        // 这里还需要加判断？
        following[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main() {
    Twitter obj = Twitter();
    obj.postTweet(1, 5);
    obj.follow(1, 2);
    obj.postTweet(2, 6);
    obj.getNewsFeed(1);
    return 0;
}
