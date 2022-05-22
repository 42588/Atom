#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> >v;
//返回的数组
    sort(nums.begin(),nums.end());
//简单的排序
    for(int i=0;i<(int)nums.size();i++){

      if(nums[i]>0) return v;//如果第一个就大于0；后面的就不用看了

      if(i>0&&nums[i]==nums[i-1]) continue;//去重

      int Left=i+1;
      int Right=(int)nums.size()-1;//双指针

      while(Left<Right){

        if(nums[i]+nums[Left]+nums[Right]<0){
//小于0的话左边的指针右移
          Left++;

        }
        else if(nums[i]+nums[Left]+nums[Right]>0){
//大于0的话右边的指针左移
          Right--;

        }
       else if(nums[i]+nums[Left]+nums[Right]==0){
//等于0的话我就将这三个数放进容器
          v.push_back(vector<int>{nums[i],nums[Left],nums[Right]});

        while(Left<Right&&nums[Right]==nums[Right-1]){
//对right去重
          Right--;

        }
        while(Left<Right&&nums[Left]==nums[Left+1]){
//对left去重
          Left++;

        }
        //去重后左边的指针右移
                      Left++;
                      Right--;//为什么我这里要--，我的left++之后，这三个数的和肯定就大于0了，此时我对他进行--就避免了再次去进行判断
      }
    }
    }
    return v;
  }
};
