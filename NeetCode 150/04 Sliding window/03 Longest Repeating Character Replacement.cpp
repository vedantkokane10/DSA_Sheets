// Question = Leetcode - 424

int characterReplacement(string s, int k) {
    int n = s.size();
    int i=0,j=0;
    unordered_map<char,int> mp;
    int maxFreq = 0;
    int ans = 0;
    while(j < n){
        mp[s[j]]++;
        maxFreq = max(maxFreq, mp[s[j]]);
        int noOfReplacements = (j-i+1) - maxFreq;
        if(noOfReplacements <= k){
            ans = max(ans,j-i+1);
        }
        else{
            mp[s[i]]--;
            i++;
        }

        j++;
    }

    return ans;
}