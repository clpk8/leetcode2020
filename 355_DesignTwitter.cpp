//
// Created by Chunbin lin on 6/14/20.
//

class Twitter {
private:
    const int size = 10;
    int time;
    // user: {tweet: {time: tweetId}}
    unordered_map<int, deque<pair<int, int>>> user_tweets;

    // user:followers
    unordered_map<int, set<int>> user_followers;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        //O(1)
        auto& tweets = user_tweets[userId];
        if (tweets.size() == size)
            tweets.pop_front();
        tweets.emplace_back(++time, tweetId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> feeds(begin(user_tweets[userId]),
                                     end(user_tweets[userId]));
        for (int uid : user_followers[userId])
            feeds.insert(end(feeds),
                         begin(user_tweets[uid]),
                         end(user_tweets[uid]));
        std::sort(rbegin(feeds), rend(feeds));
        vector<int> recentFeeds;
        int minSize = (size > feeds.size() ? feeds.size() : size);
        for (int i = 0; i < minSize; i++) {
            recentFeeds.push_back(feeds[i].second);
        }
        return recentFeeds;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        user_followers[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        user_followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */