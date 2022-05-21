// https://leetcode.cn/problems/search-in-rotated-sorted-array/solution/c-by-di-la-ke-hai-shang-de-lian-yi-w8x3/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() >5000 && nums.size() < 1){
            return -1;
        }
        int end = nums.size() - 1;
        int start = 0;
        while(end >= start){
            if(nums[start] == target){
                return start;
            }
            if(nums[end] == target){
                return end;
            }

            int size = end - start + 1;
            if(size > 2){
                int mid = start +  size / 2;
                if((nums[mid] > target && nums[start] > target && nums[mid] < nums[start])
                || (nums[mid] < target && nums[start] < target && nums[mid] < nums[start])
                || (nums[mid] > target && nums[start] < target && nums[mid] > nums[start])
                )
                {
                    end = mid;
                }
                else{
                    start = mid;
                }
            }
            else{
                return -1;
            }
        }
        return -1;
    }
};
