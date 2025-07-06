// Question = Leetcode - 125

bool isPalindrome(string s) {
    string str = "";
    for(auto x:s){
        if(x >= 'a' && x <= 'z'){
            str += x;
        }
        else if(x >= 'A' && x <= 'Z'){
            str += tolower(x);
        }
        else if(x >= '0' && x <= '9'){
            str += x;
        }
    }

    int left = 0, right = str.size()-1;
    while(left <= right){
        if(str[left] != str[right]){
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}