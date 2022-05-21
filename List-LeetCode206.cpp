//问题描述：
//不使用多的内存申请将链表反转
#include<iostream>
using namespace std;
class Solution {
  struct ListNode{
    int val;
    ListNode * next;
    ListNode(int val):val(val),next(nullptr){}
  };
public:
     ListNode* reverseList(ListNode* head) {
     ListNode* Cal=head;
     ListNode* temp;
     ListNode* Pre=nullptr;
     while(Cal){
       temp=Cal->next;
       Cal->next=Pre;
       Pre=Cal;
       Cal=temp;
     }
return Pre;
    }
};
