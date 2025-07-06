// Question = Leetcode - 42


int trap(vector<int>& height) {
    int n = height.size();
    vector<int> leftMax(n);
    vector<int> RightMax(n);

    int currentMax = height[0];
    for(int i=0;i<n;i++){
        currentMax = max(currentMax, height[i]);
        leftMax[i] = currentMax;
    }
    currentMax = height[n-1];
    for(int i=n-1;i>=0;i--){
        currentMax = max(currentMax, height[i]);
        RightMax[i] = currentMax;
    }


    int ans = 0;
    for(int i=0;i<n;i++){
        ans += max(0,min(leftMax[i],RightMax[i]) - height[i]);
    }

    return ans;
}