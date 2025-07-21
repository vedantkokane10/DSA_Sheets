// Question = Leetcode - 76


string minWindow(string s, string t) {
    if(s == t){
        return s;
    }
    int minLen = INT_MAX;
    unordered_map<char,int> mp, window;
    for(auto x:t){
        mp[x]++;
    }
    string ans = "";
    int i=0,j=0;
    int cnt = 0;
    int startIndex = -1;
    while(j < s.size()){
        window[s[j]]++;
        if(mp.count(s[j]) && mp[s[j]] == window[s[j]]){
            cnt++;
        }
        while(cnt == mp.size()){
            int currentLength = j-i+1;
            if(minLen > currentLength){
                minLen = currentLength;
                startIndex = i;
            }
            window[s[i]]--;
            if(mp.count(s[i]) && window[s[i]] < mp[s[i]]){
                cnt--;
            }
            
            i++;
        }
        j++;
    }
    if(startIndex == -1){
        return "";
    }
    if(minLen == 0){
        ans = s.substr(startIndex);
        return ans;
    }
    ans = s.substr(startIndex,minLen);
    return ans;
}