// Question = Leetcode - 49

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for(auto x:strs){
        vector<int> chars(26,0);
        string str = "";
        for(auto y:x){
            chars[y - 'a']++;
        }
        for(int i=0;i<26;i++){
            str = str + to_string(chars[i]);
        }
        cout<<str<<endl;
        mp[str].push_back(x);
    }
    vector<vector<string>> ans;
    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
}