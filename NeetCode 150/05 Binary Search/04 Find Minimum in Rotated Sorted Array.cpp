int findMin(vector<int>& nums) {
    int start=0, end=nums.size()-1;

    while(start < end){
        int mid = (start + end)/ 2;
        if(nums[mid] > nums[end]){
            start = mid+1;
        }
        else if(nums[mid] < nums[end]){
            end = mid;
        }
    }
    return nums[start];
}

/*
4,5,6,7,0,1,2

1) s=0, mid=3, e=6, 
    4     7     2  } nums[mid] > nums[end] => that means smallest element on right side
2) s=4, mid=5, e=6
    0    1     2   } nums[mid] < nums[end] => that means smallest element on ;eft side
3) s=4, e=4 mid = 4
    0    0   0     } start == end so end  
*/