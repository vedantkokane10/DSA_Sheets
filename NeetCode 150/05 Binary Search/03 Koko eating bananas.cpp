/*
    if noOfBananasCanEat per hour is 4
    3,6,7,11
    3 4 4 4
      2 3 4
          3
            -> 8 (total hours)

    if noOfBananasCanEat per hour is 30
    30 11 23 4 20
    30 11 23 4 20 -> 5 (total hours)

*/

bool isPossible(int noOfBananasCanEat, vector<int>& piles, int hours){
    long long hoursTakenToEatBananas = 0;
    for(auto x:piles){
        hoursTakenToEatBananas += (x / noOfBananasCanEat);
        if((x % noOfBananasCanEat) != 0){
            hoursTakenToEatBananas++;
        }
        if(hoursTakenToEatBananas > hours){
            cout<<noOfBananasCanEat<<endl;
            return 0;
        }
    }
    return 1;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int start = 1;
    int end = 0;
    for(auto x:piles){
        end = max(end,x);
    }
    int ans = end;
    while(start <= end){
        int mid = (start+end)/2;
        if(isPossible(mid,piles,h) == 1){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}