// left side -> max elements
// right side -> min elements
// left.size() == right.size() + 1 (Always) else readjust

priority_queue<int> left;
priority_queue<int,vector<int>,greater<int>> right;

MedianFinder() {
    
}

void addNum(int num) {
    if(left.size() == 0 || left.top() > num){
        left.push(num);
    }
    else{
        right.push(num);
    }

    if(left.size() > right.size() + 1){
        right.push(left.top());
        left.pop();
    }
    else if(right.size() > left.size()){
        left.push(right.top());
        right.pop();
    }
}

double findMedian() {
    if((left.size() + right.size()) % 2 != 0){
        return (double)left.top();
    }
    return (double)(left.top() + right.top()) / (double)2.0;
}