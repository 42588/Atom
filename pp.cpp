#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
          int right=nums.size()-1;
          int left=0;
          if(nums.size()==1){
            if(nums[right]==target){
              return true;
            }
            else return false;
          }
          else{
          while(nums[left]<=nums[right]){
              if(left<right){
                  left++;
                  right--;
              }
          }  //Í»±äµãÔÚleft
          int temp=left;
          left=0;
          right=nums.size()-1;
          while(left<=right){
              int middle=left+(right-left)/2;
              if(nums[middle]==target){
                  return true;
              }
              else if(nums[middle]>nums[temp]){
                  right=middle-1;
              }
              else if(nums[middle]<nums[temp]){
                  left=middle+1;
              }
              else if(nums[middle]==nums[temp]){
                if(nums[middle]==target){
                    return true;
                }
                if(nums[middle]>target){
                  right=middle-1;
                }
                else if(nums[middle]<target)
                  {
                  left=middle+1;
                  }
        }

      }
          return false;
    }
  }
};
int main(){
  vector<int> *Data= new vector<int>{1,0,1,1,1};
  int data;
  cin>>data;
  Solution *so=new Solution();
  int a=so->search(*Data,data);
  cout<<a<<endl;
  return 0;
}
