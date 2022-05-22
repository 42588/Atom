#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> >v;
//���ص�����
    sort(nums.begin(),nums.end());
//�򵥵�����
    for(int i=0;i<(int)nums.size();i++){

      if(nums[i]>0) return v;//�����һ���ʹ���0������ľͲ��ÿ���

      if(i>0&&nums[i]==nums[i-1]) continue;//ȥ��

      int Left=i+1;
      int Right=(int)nums.size()-1;//˫ָ��

      while(Left<Right){

        if(nums[i]+nums[Left]+nums[Right]<0){
//С��0�Ļ���ߵ�ָ������
          Left++;

        }
        else if(nums[i]+nums[Left]+nums[Right]>0){
//����0�Ļ��ұߵ�ָ������
          Right--;

        }
       else if(nums[i]+nums[Left]+nums[Right]==0){
//����0�Ļ��Ҿͽ����������Ž�����
          v.push_back(vector<int>{nums[i],nums[Left],nums[Right]});

        while(Left<Right&&nums[Right]==nums[Right-1]){
//��rightȥ��
          Right--;

        }
        while(Left<Right&&nums[Left]==nums[Left+1]){
//��leftȥ��
          Left++;

        }
        //ȥ�غ���ߵ�ָ������
                      Left++;
                      Right--;//Ϊʲô������Ҫ--���ҵ�left++֮�����������ĺͿ϶��ʹ���0�ˣ���ʱ�Ҷ�������--�ͱ������ٴ�ȥ�����ж�
      }
    }
    }
    return v;
  }
};
