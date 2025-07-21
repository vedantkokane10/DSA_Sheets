// Question = Leetcode - 287


int findDuplicate(vector<int>& nums) {
    for(auto x:nums){
        int index = abs(x) - 1;
        if(nums[index] < 0){
            return abs(x);
        }
        nums[index] = nums[index] * (-1);
    }
    return -1;
}