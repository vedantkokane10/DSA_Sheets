// Question = NeetCode platform - Encode and Decode Strings

string encode(vector<string>& strs) {
    string ans = "";
    for(auto x:strs){
        int len = x.size();
        string str = "(" + to_string(len) + ")" + x ;
        ans += str;
    }
    return ans;
}

vector<string> decode(string s) {
    vector<string> ans;
    cout<<s<<endl;
    int i=0;
    while(i < s.size()){
        string strLen = "";
        if(s[i] == '('){
            i++;
            while(s[i] != ')'){
                strLen += s[i];
                i++;
            }
            i++;
        }
        int len = stoi(strLen);
        string str = s.substr(i,len);
        ans.push_back(str);
        i = i + len;
    }
    return ans;
}