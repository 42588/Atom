#include<iostream>
using namespace std;
class Solution {
public:
  string intToRoman(int num) {

        string result;
        //思路，不断对两者进行减法操作，将num减去Imap的最大值，直到大于零
        //将此时大于零的数对应值存入字符串
        //直到num等于零
        int key[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string value[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        for(int i=12;i>=0;i--){
            while(num>=key[i]){
                num-=key[i];
                result+=value[i];
                if(num==0){
                    break;
                }
            }
        }
        return result;
    }
};
