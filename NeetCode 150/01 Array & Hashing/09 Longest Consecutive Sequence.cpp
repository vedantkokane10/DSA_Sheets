// Question = Leetcode - 128

int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0){
        return 0;
    }
    unordered_set<int> mp(nums.begin(),nums.end());
    int mx = 1;
    for(auto x:mp){
        if(mp.find(x-1) == mp.end()){
            int cnt = 1;
            int element = x+1;
            while(mp.find(element) != mp.end()){
                cnt++;
                element++;
            }
            mx = max(mx,cnt);
        }
    }
    return mx;
}