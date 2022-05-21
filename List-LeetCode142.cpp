#include<iostream>
using namespace std;
class Solution{
  struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(nullptr){}
  };
  ListNode * HaveNode(ListNode* head){
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast!=nullptr&&fast->next!=nullptr){
      fast=fast->next->next;
      slow!=slow->next;
      if(fast==slow){
        fast=head;
        while(fast!=slow){
          slow=slow->next;
          fast=fast->next;
        }
        return slow->next;
      }
    }
    return nullptr;
  }
};
int main(){
  return 0;
}
