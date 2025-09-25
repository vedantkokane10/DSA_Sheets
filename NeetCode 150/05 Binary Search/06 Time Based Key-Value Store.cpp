unordered_map<string,vector<pair<int,string>>> mp;
TimeMap() {
    
}

void set(string key, string value, int timestamp) {
    mp[key].push_back({timestamp,value});
}

string get(string key, int timestamp) {
    const vector<pair<int, string>>& arr = mp[key];
    int start = 0;
    int end = arr.size()-1;
    string ans = "";
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid].first <= timestamp){
            ans = arr[mid].second;
            start = mid+1;
        }
        else{
            end = mid-1;
        }

    }
    return ans;
}