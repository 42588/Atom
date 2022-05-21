#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
public:
  vector<vector<int> > threeSum(vector<int>& nums){
  vector<vector<int> > result;  //用来储存返回的数组
  sort(nums.begin(),nums.end());//对数组进行简单的排序
  for(int i=0;i<(int)nums.size();i++){
    if(nums[i]>0){
      return result;
    }
    if(i>0&&nums[i]==nums[i-1]){
      continue;//应该等价于i++
    }
    int Left=i+1;
    int Right=nums.size()-1;
    while(Right>Left){
      if(nums[i]+nums[Left]+nums[Right]>0){
        Right--;
      }
      else if(nums[i]+nums[Left]+nums[Right]<0){
        Left++;
      }
      else if(nums[i]+nums[Left]+nums[Right]==0){
        result.push_back(vector<int>{nums[i],nums[Left],nums[Right]});

      while(Right>Left&&nums[Right]==nums[Right-1]){
        Right--;
      }
      while(Right>Left&&nums[Left]==nums[Left+1]){
        Left++;
      }
      Right--;
      Left++;
    }
  }
  }
  return result;
  }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(), nums.end());
        if(nums[0]>0) return ans;
        int i = 0;
        while(i<nums.size()){
            if(nums[i]>0) break;        // 1楼网友指正，将这个if语句放这里提前终止循环
            int left = i+1, right = nums.size()-1;
            while(left< right){

                // 转换为long long避免加法过程中溢出
                long long y = static_cast<long long>(nums[i]);
                long long x = static_cast<long long>(nums[left]);
                long long z = static_cast<long long>(nums[right]);
                if(x + y >0-z)
                    right--;
                else if(x + y <0-z)
                    left++;
                else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // 相同的left和right不应该再次出现，因此跳过
                    while(left<right&&nums[left]==nums[left+1])
                        left++;
                    while(left<right&&nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                }
            }
            // 避免nums[i]作为第一个数重复出现
            while(i+1<nums.size()&&nums[i] == nums[i+1])
                i++;
            i++;
        }
        return ans;
    }
};

class Solution {
    //定义三个指针，保证遍历数组中的每一个结果
    //画图，解答
    public List<List<Integer>> threeSum(int[] nums) {
        //定义一个结果集
        List<List<Integer>> res = new ArrayList<>();
        //数组的长度
        int len = nums.length;
        //当前数组的长度为空，或者长度小于3时，直接退出
        if(nums == null || len <3){
            return res;
        }
        //将数组进行排序
        Arrays.sort(nums);
        //遍历数组中的每一个元素
        for(int i = 0; i<len;i++){
            //如果遍历的起始元素大于0，就直接退出
            //原因，此时数组为有序的数组，最小的数都大于0了，三数之和肯定大于0
            if(nums[i]>0){
                break;
            }
            //去重，当起始的值等于前一个元素，那么得到的结果将会和前一次相同
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i +1;
            int r = len-1;
            //当 l 不等于 r时就继续遍历
            while(l<r){
                //将三数进行相加
                int sum = nums[i] + nums[l] + nums[r];
                //如果等于0，将结果对应的索引位置的值加入结果集中
                if(sum==0){
                    // 将三数的结果集加入到结果集中
                    res.add(Arrays.asList(nums[i], nums[l], nums[r]));
                    //在将左指针和右指针移动的时候，先对左右指针的值，进行判断
                    //如果重复，直接跳过。
                    //去重，因为 i 不变，当此时 l取的数的值与前一个数相同，所以不用在计算，直接跳
                    while(l < r && nums[l] == nums[l+1]) {
                        l++;
                    }
                    //去重，因为 i不变，当此时 r 取的数的值与前一个相同，所以不用在计算
                    while(l< r && nums[r] == nums[r-1]){
                        r--;
                    }
                    //将 左指针右移，将右指针左移。
                    l++;
                    r--;
                    //如果结果小于0，将左指针右移
                }else if(sum < 0){
                    l++;
                    //如果结果大于0，将右指针左移
                }else if(sum > 0){
                    r--;
                }
            }
        }
        return res;
    }
}
