// Question = Leetcode - 167


vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while(left < right){
        int sum = nums[left] + nums[right];
        if(sum == target){
            return {left+1, right+1};
        }
        else if(sum > target){
            right--;
        }
        else{
            left++;
        }
    }
    return {-1,-1};
}