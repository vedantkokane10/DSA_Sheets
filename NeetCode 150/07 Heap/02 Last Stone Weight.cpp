int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p1;
        for(auto x:stones){
            p1.push(x);
        }
        while(p1.size() > 1){
            int x = p1.top();
            p1.pop();
            int y = p1.top();
            p1.pop();
            cout<<x<<" "<<y<<endl;
            if(x == y){
                continue;
            }
            else{
                int minElement = min(x,y);
                int maxElement = max(x,y);
                int diff = maxElement - minElement;
                //cout<<x<<" "<<y<<" "<<diff<<endl;
                p1.push(diff);
            }
        }
        if(p1.size() == 1){
            return p1.top();
        }
        return 0;
    }