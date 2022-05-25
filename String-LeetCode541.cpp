#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
////////////////关键点：找到空格
////////////////关键技术双指针

//start:
        int i = 0;
        int j = 0;
            for(;j<s.length();j++){///
                if(s[j]==' '){
                   reverse(s.begin()+i,s.begin()+j);
                   i=j+1;
                }
                }
            reverse(s.begin()+i,s.begin()+j);
        return s;
    }
};
//注意s.length返回的是无符号数，因此存在一个类型转换
