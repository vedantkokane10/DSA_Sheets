// userTweetMapping => {userId, tweetId}
//        first   vector  
unordered_map<int,vector<pair<int,int>>> userTweetMapping;

// userFollowerMapping => {user, followers}
unordered_map<int,unordered_set<int>> userFollowerMapping;

int timeStamp = 0;
Twitter() {
    
}

void postTweet(int userId, int tweetId) {
    userTweetMapping[userId].push_back({timeStamp,tweetId});
    timeStamp++;
}

vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int,int>> p1;
    for(auto x:userTweetMapping[userId]){
        p1.push(x);
    }

    for(auto user:userFollowerMapping[userId]){
        for(auto x:userTweetMapping[user]){
            p1.push(x);
        }
    }

    vector<int> ans;
    while(!p1.empty() && ans.size() < 10){
        ans.push_back(p1.top().second);
        p1.pop();
    }
    return ans;
    
}

void follow(int followerId, int followeeId) {
    userFollowerMapping[followerId].insert(followeeId);
}

void unfollow(int followerId, int followeeId) {
    userFollowerMapping[followerId].erase(followeeId);
}