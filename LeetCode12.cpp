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
        //思路，不断对两者进行减法操作，将num减去Imap的最大值，直到大于零
        //将此时大于零的数对应值存入字符串
        //直到num等于零

        for(auto iter=imap.rbegin();iter!=imap.rend();iter++)
        {
          while (num >= iter->first) {
                          num -= iter->first;
                          result += iter->second;
                      }
                      if (num == 0) {
                          break;
                      }//在当前的大小，不断对他进行减法，直到他的大小为0

        }
        return result;
    }
};
/*
    其中I对应1
       IV对应4
       V对应5
       IX对应9
       X对应10
       XL对应40
       L对应50
       XC对应90
       C对应100
       CD对应400
       D对应500
       CM对应900
       M对应1000
*/
