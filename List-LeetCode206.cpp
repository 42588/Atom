//����������
//��ʹ�ö���ڴ����뽫����ת
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
