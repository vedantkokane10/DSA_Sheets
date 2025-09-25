int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> mp;
    for(auto x:tasks){
        mp[x]++;
    }
    priority_queue<pair<int,char>> p1;
    for(auto x:mp){
        p1.push({x.second,x.first});
    }
    int time = 0;

    while(!p1.empty()){
        vector<pair<int,char>> temp;
        int cycle = 0;
        for(int i=0;i<=n;i++){
            if(!p1.empty()){
                int frequency = p1.top().first;
                char element = p1.top().second;
                p1.pop();
                frequency--;
                if(frequency > 0){
                    temp.push_back({frequency,element});
                }
            }
            else{
                if(temp.size() == 0){
                    break;
                }
            }
            cycle++;
        }
        for(auto x:temp){
            p1.push(x);
        }
        time += cycle;
        
    }
    return time;
}

/*
B C D A A A A G

A - 4
B - 1
C - 1
D - 1
G - 1

k=1

_ => idle

A B A C A D A _  
1 2 3 4 5 6 7 8


*/