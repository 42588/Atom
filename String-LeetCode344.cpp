#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
      for(int i=0, j=s.size()-1;i<(int)s.size()/2;i++,j--){
        int temp=s[i];
        s[i]=s[j];
        s[j]=temp;
      }
  }
};
