#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
////////////////�ؼ��㣺�ҵ��ո�
////////////////�ؼ�����˫ָ��

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
//ע��s.length���ص����޷���������˴���һ������ת��
