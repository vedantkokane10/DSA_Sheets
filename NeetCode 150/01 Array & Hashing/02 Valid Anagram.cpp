// Question = Leetcode - 242

bool isAnagram(string s, string t) {
    if(s.size() != t.size()){
        return 0;
    }

    unordered_map<char,int> mp1, mp2;
    for(auto x:s){
        mp1[x]++;
    }
    for(auto x:t){
        mp2[x]++;
    }

    for(auto x:mp1){
        if(x.second != mp2[x.first]){
            return 0;
        }
    }

    return 1;
}