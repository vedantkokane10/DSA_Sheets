// Question = Leetcode - 347

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int,int> mp;
    for(auto x:nums){
        mp[x]++;
    }

    vector<vector<int>> freq(nums.size() + 1);
    for(auto x:mp){
        freq[x.second].push_back(x.first);
    }


    for(int i=nums.size();i>0;i--){
        for(auto x:freq[i]){
            if(ans.size() == k){
                break;
            }
            ans.push_back(x);
        }
    }

    return ans;
}