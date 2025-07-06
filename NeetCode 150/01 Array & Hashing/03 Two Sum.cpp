// Question = Leetcode - 1

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        int remainingValue = target - nums[i];
        if(mp.find(remainingValue) != mp.end()){
            return {mp[remainingValue],i};
        }
        mp[nums[i]] = i;
    }

    return {-1,-1};
}