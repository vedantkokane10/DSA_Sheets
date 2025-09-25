vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>>  ans;
    priority_queue<pair<double,vector<int>>, vector<pair<double,vector<int>>>, greater<pair<double,vector<int>>>> p1;
    for(auto arr:points){
        int x = arr[0];
        int y = arr[1];
        int xSquare = arr[0] * arr[0];
        int ySquare = arr[1] * arr[1];
        int diff = xSquare+ySquare;
        double distance = sqrt(diff);
        p1.push({distance,{x,y}});
    }

    while(k > 0){
        ans.push_back(p1.top().second);
        p1.pop();
        k--;
    }

    return ans;
}