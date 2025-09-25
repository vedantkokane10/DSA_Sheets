// Sliding Window Patterns (Vedant's while(j < n) style)
#include <bits/stdc++.h>
using namespace std;

// 1. Fixed-size Window: Max Sum of Subarray Size k
void maxSumFixedSize(vector<int>& arr, int k) {
    int i = 0, j = 0, sum = 0, maxSum = INT_MIN;
    while (j < arr.size()) {
        sum += arr[j];
        if (j - i + 1 == k) {
            maxSum = max(maxSum, sum);
            sum -= arr[i];
            i++;
        }
        j++;
    }
    cout << "Max Sum: " << maxSum << endl;
}

// 2. Variable-size Window: Min Subarray Length with Sum >= target
void minSubarrayLen(vector<int>& arr, int target) {
    int i = 0, j = 0, sum = 0, minLen = INT_MAX;
    while (j < arr.size()) {
        sum += arr[j];
        while (sum >= target) {
            minLen = min(minLen, j - i + 1);
            sum -= arr[i];
            i++;
        }
        j++;
    }
    cout << "Min Length: " << (minLen == INT_MAX ? 0 : minLen) << endl;
}

// 3. Longest Substring with K Distinct Characters
void longestKDistinct(string s, int k) {
    int i = 0, j = 0, maxLen = 0;
    unordered_map<char, int> freq;
    while (j < s.length()) {
        freq[s[j]]++;
        while (freq.size() > k) {
            freq[s[i]]--;
            if (freq[s[i]] == 0) freq.erase(s[i]);
            i++;
        }
        maxLen = max(maxLen, j - i + 1);
        j++;
    }
    cout << "Max Length with " << k << " distinct: " << maxLen << endl;
}

// 4. Longest Substring Without Repeating Characters
void longestNoRepeat(string s) {
    int i = 0, j = 0, maxLen = 0;
    unordered_map<char, int> freq;
    while (j < s.length()) {
        freq[s[j]]++;
        while (freq[s[j]] > 1) {
            freq[s[i]]--;
            i++;
        }
        maxLen = max(maxLen, j - i + 1);
        j++;
    }
    cout << "Max Length (no repeat): " << maxLen << endl;
}

// 5. Check Inclusion / Anagram Match
bool checkInclusion(string s1, string s2) {
    vector<int> freq1(26), freq2(26);
    for (char c : s1) freq1[c - 'a']++;
    int i = 0, j = 0, k = s1.length();
    while (j < s2.length()) {
        freq2[s2[j] - 'a']++;
        if (j - i + 1 == k) {
            if (freq1 == freq2) return true;
            freq2[s2[i] - 'a']--;
            i++;
        }
        j++;
    }
    return false;
}

// 6. Max in Each Window of Size k (Deque)
void maxInWindow(vector<int>& arr, int k) {
    deque<int> dq;
    int i = 0, j = 0;
    vector<int> res;
    while (j < arr.size()) {
        while (!dq.empty() && dq.back() < arr[j]) dq.pop_back();
        dq.push_back(arr[j]);
        if (j - i + 1 == k) {
            res.push_back(dq.front());
            if (arr[i] == dq.front()) dq.pop_front();
            i++;
        }
        j++;
    }
    cout << "Max in each window: ";
    for (int x : res) cout << x << " ";
    cout << endl;
}

// 7. Count Distinct Elements in Window of Size k
void countDistinctWindow(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int i = 0, j = 0;
    vector<int> res;
    while (j < arr.size()) {
        freq[arr[j]]++;
        if (j - i + 1 == k) {
            res.push_back(freq.size());
            freq[arr[i]]--;
            if (freq[arr[i]] == 0) freq.erase(arr[i]);
            i++;
        }
        j++;
    }
    cout << "Distinct counts: ";
    for (int x : res) cout << x << " ";
    cout << endl;
}

// 8. Longest Subarray with Sum Exactly K
void longestSubarraySumK(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;
    for (int j = 0; j < nums.size(); j++) {
        sum += nums[j];
        if (sum == k) maxLen = j + 1;
        if (mp.find(sum - k) != mp.end()) {
            maxLen = max(maxLen, j - mp[sum - k]);
        }
        if (mp.find(sum) == mp.end()) mp[sum] = j;
    }
    cout << "Longest subarray with sum == k: " << maxLen << endl;
}

// 9. Binary Subarrays With Sum
int binarySubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> count;
    count[0] = 1;
    int sum = 0, res = 0;
    for (int x : nums) {
        sum += x;
        res += count[sum - goal];
        count[sum]++;
    }
    return res;
}

// 10. Max Consecutive Ones III (At most k zero flips)
int longestOnes(vector<int>& nums, int k) {
    int i = 0, j = 0, zeros = 0, maxLen = 0;
    while (j < nums.size()) {
        if (nums[j] == 0) zeros++;
        while (zeros > k) {
            if (nums[i] == 0) zeros--;
            i++;
        }
        maxLen = max(maxLen, j - i + 1);
        j++;
    }
    return maxLen;
}

// 11. Minimum Window Substring
string minWindow(string s, string t) {
    unordered_map<char, int> freq;
    for (char c : t) freq[c]++;
    int required = freq.size(), formed = 0, i = 0, j = 0;
    unordered_map<char, int> window;
    int minLen = INT_MAX, start = 0;

    while (j < s.size()) {
        window[s[j]]++;
        if (freq.count(s[j]) && window[s[j]] == freq[s[j]]) {
            formed++;
        }
        while (i <= j && formed == required) {
            if (j - i + 1 < minLen) {
                minLen = j - i + 1;
                start = i;
            }
            window[s[i]]--;
            if (freq.count(s[i]) && window[s[i]] < freq[s[i]]) {
                formed--;
            }
            i++;
        }
        j++;
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

// Example usage
int main() {
    vector<int> arr = {1, 2, 3, 1, 4, 2, 3};
    string s = "abcba";

    maxSumFixedSize(arr, 3);
    minSubarrayLen(arr, 7);
    longestKDistinct(s, 2);
    longestNoRepeat(s);
    cout << boolalpha << checkInclusion("ab", "eidbaooo") << endl;
    maxInWindow(arr, 3);
    countDistinctWindow(arr, 3);

    vector<int> nums = {1, 2, 1, 1, 1};
    longestSubarraySumK(nums, 3);
    cout << binarySubarraysWithSum(nums, 3) << endl;
    cout << longestOnes(nums, 1) << endl;
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;

    return 0;
}
