// Question = Leetcode - 567


bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        vector<int> mp1(26), mp2(26);
        for(auto x:s1){
            mp1[x-'a']++;
        }
        int i=0, j=0;
        while(j < s2.size()){
            mp2[s2[j]-'a']++;
            if(j-i+1 == k){
                if(mp1 == mp2){
                    return 1;
                }
                mp2[s2[i] - 'a']--;
                i++;
            }
            j++;
        }
        return 0;
    }