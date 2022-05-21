#include<iostream>
#include<map>
using namespace std;
class Solution{
public:
  string intToRoman(int num) {
        map<int,string> imap;
        imap.insert(pair<int,string>(1,"I"));
        imap.insert(pair<int,string>(4,"IV"));
        imap.insert(pair<int,string>(5,"V"));
        imap.insert(pair<int,string>(9,"IX"));
        imap.insert(pair<int,string>(10,"X"));
        imap.insert(pair<int,string>(40,"XL"));
        imap.insert(pair<int,string>(50,"L"));
        imap.insert(pair<int,string>(90,"XC"));
        imap.insert(pair<int,string>(100,"C"));
        imap.insert(pair<int,string>(400,"CD"));
        imap.insert(pair<int,string>(500,"D"));
        imap.insert(pair<int,string>(900,"CM"));
        imap.insert(pair<int,string>(1000,"M"));
        string result;
        //˼·�����϶����߽��м�����������num��ȥImap�����ֵ��ֱ��������
        //����ʱ�����������Ӧֵ�����ַ���
        //ֱ��num������

        for(auto iter=imap.rbegin();iter!=imap.rend();iter++)
        {
          while (num >= iter->first) {
                          num -= iter->first;
                          result += iter->second;
                      }
                      if (num == 0) {
                          break;
                      }//�ڵ�ǰ�Ĵ�С�����϶������м�����ֱ�����Ĵ�СΪ0

        }
        return result;
    }
};
/*
    ����I��Ӧ1
       IV��Ӧ4
       V��Ӧ5
       IX��Ӧ9
       X��Ӧ10
       XL��Ӧ40
       L��Ӧ50
       XC��Ӧ90
       C��Ӧ100
       CD��Ӧ400
       D��Ӧ500
       CM��Ӧ900
       M��Ӧ1000
*/
