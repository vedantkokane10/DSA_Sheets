int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> p1;
    for(auto x:nums){
        p1.push(x);
    }

    while(k > 1){
        p1.pop();
        k--;
    }
    return p1.top();
}