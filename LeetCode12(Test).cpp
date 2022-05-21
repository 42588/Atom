#include<iostream>
using namespace std;
class Solution {
public:
  string intToRoman(int num) {

        string result;
        //˼·�����϶����߽��м�����������num��ȥImap�����ֵ��ֱ��������
        //����ʱ�����������Ӧֵ�����ַ���
        //ֱ��num������
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
