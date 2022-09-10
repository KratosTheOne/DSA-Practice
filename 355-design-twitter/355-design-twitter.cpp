//T.C & S.C -> O(n)

class Twitter {
public:
    unordered_map<int, unordered_set<int>> followers;
    stack<pair<int, int>> tweets;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        
        tweets.push({userId, tweetId});
        followers[userId].insert(userId);
        
    }
    
    vector<int> getNewsFeed(int userId) {
        
        int i = 0;
        
        vector<int> ans;
        
        stack<pair<int, int>> temp;
        
        while(!tweets.empty() && i < 10)
        {
            pair<int, int> next = tweets.top();
            
            if(followers[userId].find(next.first) != followers[userId].end())
            {
                ans.push_back(next.second);
                i++;
            }
            
            tweets.pop();
            temp.push(next);
        }
        
        while(!temp.empty())
        {
            pair<int, int> next = temp.top();
            tweets.push(next);
            temp.pop();
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        
        followers[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        
        followers[followerId].erase(followeeId);
        
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