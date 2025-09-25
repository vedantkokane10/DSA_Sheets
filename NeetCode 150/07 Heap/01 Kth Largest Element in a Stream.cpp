int k;
priority_queue<int, vector<int>, greater<int>> p1;
KthLargest(int k, vector<int>& nums) {
    this->k = k;
    for(auto x:nums){
        p1.push(x);
        if(p1.size() > k){
            p1.pop();
        }
    }

}

int add(int val) {
    p1.push(val);
    if(p1.size() > k){
        p1.pop();
    }
    return p1.top();
}