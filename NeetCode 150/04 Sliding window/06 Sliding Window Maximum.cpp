// Question = Leetcode - 239

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<pair<int,int>> dq;
    vector<int> ans;
    int i=0, j=0;
    while(j < nums.size()){
        while(!dq.empty() && nums[j] > dq.back().second){
            dq.pop_back();
        }
        dq.push_back({j,nums[j]});
        if(j - i + 1 == k){
            if(dq.front().first > i){
                ans.push_back(dq.front().second);
                i++;
            }
            else{
                ans.push_back(dq.front().second);
                dq.pop_front();
                i++;
            }
            
        }
        j++;
    }
    return ans;
}