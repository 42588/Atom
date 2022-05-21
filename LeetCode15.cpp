#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
public:
  vector<vector<int> > threeSum(vector<int>& nums){
  vector<vector<int> > result;  //�������淵�ص�����
  sort(nums.begin(),nums.end());//��������м򵥵�����
  for(int i=0;i<(int)nums.size();i++){
    if(nums[i]>0){
      return result;
    }
    if(i>0&&nums[i]==nums[i-1]){
      continue;//Ӧ�õȼ���i++
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
            if(nums[i]>0) break;        // 1¥����ָ���������if����������ǰ��ֹѭ��
            int left = i+1, right = nums.size()-1;
            while(left< right){

                // ת��Ϊlong long����ӷ����������
                long long y = static_cast<long long>(nums[i]);
                long long x = static_cast<long long>(nums[left]);
                long long z = static_cast<long long>(nums[right]);
                if(x + y >0-z)
                    right--;
                else if(x + y <0-z)
                    left++;
                else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // ��ͬ��left��right��Ӧ���ٴγ��֣��������
                    while(left<right&&nums[left]==nums[left+1])
                        left++;
                    while(left<right&&nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                }
            }
            // ����nums[i]��Ϊ��һ�����ظ�����
            while(i+1<nums.size()&&nums[i] == nums[i+1])
                i++;
            i++;
        }
        return ans;
    }
};

class Solution {
    //��������ָ�룬��֤���������е�ÿһ�����
    //��ͼ�����
    public List<List<Integer>> threeSum(int[] nums) {
        //����һ�������
        List<List<Integer>> res = new ArrayList<>();
        //����ĳ���
        int len = nums.length;
        //��ǰ����ĳ���Ϊ�գ����߳���С��3ʱ��ֱ���˳�
        if(nums == null || len <3){
            return res;
        }
        //�������������
        Arrays.sort(nums);
        //���������е�ÿһ��Ԫ��
        for(int i = 0; i<len;i++){
            //�����������ʼԪ�ش���0����ֱ���˳�
            //ԭ�򣬴�ʱ����Ϊ��������飬��С����������0�ˣ�����֮�Ϳ϶�����0
            if(nums[i]>0){
                break;
            }
            //ȥ�أ�����ʼ��ֵ����ǰһ��Ԫ�أ���ô�õ��Ľ�������ǰһ����ͬ
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i +1;
            int r = len-1;
            //�� l ������ rʱ�ͼ�������
            while(l<r){
                //�������������
                int sum = nums[i] + nums[l] + nums[r];
                //�������0���������Ӧ������λ�õ�ֵ����������
                if(sum==0){
                    // �������Ľ�������뵽�������
                    res.add(Arrays.asList(nums[i], nums[l], nums[r]));
                    //�ڽ���ָ�����ָ���ƶ���ʱ���ȶ�����ָ���ֵ�������ж�
                    //����ظ���ֱ��������
                    //ȥ�أ���Ϊ i ���䣬����ʱ lȡ������ֵ��ǰһ������ͬ�����Բ����ڼ��㣬ֱ����
                    while(l < r && nums[l] == nums[l+1]) {
                        l++;
                    }
                    //ȥ�أ���Ϊ i���䣬����ʱ r ȡ������ֵ��ǰһ����ͬ�����Բ����ڼ���
                    while(l< r && nums[r] == nums[r-1]){
                        r--;
                    }
                    //�� ��ָ�����ƣ�����ָ�����ơ�
                    l++;
                    r--;
                    //������С��0������ָ������
                }else if(sum < 0){
                    l++;
                    //����������0������ָ������
                }else if(sum > 0){
                    r--;
                }
            }
        }
        return res;
    }
}
