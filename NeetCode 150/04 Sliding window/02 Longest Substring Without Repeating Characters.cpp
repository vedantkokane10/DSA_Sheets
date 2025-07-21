// Question = Leetcode - 3

int lengthOfLongestSubstring(string s) {
    int i=0;
    int j=0;
    unordered_map<char,int> mp;
    int ans = 0;
    while(j < s.size()){
        if(mp.find(s[j]) != mp.end()){
            i = max(i, mp[s[j]]);
        }
        int currentLength = j-i+1;
        ans = max(ans,currentLength);
        mp[s[j]] = j+1;
        j++;
    }
    return ans;
}