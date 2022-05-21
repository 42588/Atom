//题目描述：
/*
设计链表类，实现六个接口
在链表最前面插入节点
获取第INDEX个节点的数值
在链表后插入节点
在INDEX节点前面插入节点
删除INDEX个节点
打印链表
*/
#include<iostream>
using namespace std;
class MyLinkedList{
public:
  struct LinkedNode{
    int Val;
    LinkedNode* Next;
    LinkedNode(int val):Val(val),Next(nullptr){}
  };
private:
  int _size;
  LinkedNode* _dummyHead;
  //size是链表大小，_dummyHead是链表的头节点
public:
  //初始化链表
  MyLinkedList(){
    //在此定义一个虚拟头节点
    _dummyHead =new LinkedNode(0);
    _size=0;
  }
  //获取index位置的数值，如果数值非法则返回-1
  //index是从0开始的，0代表头节点
  int Get(int index){
    if((index>_size-1)||(index<0)){
      return -1;
    }
    LinkedNode* Cur=_dummyHead->Next;
    while(index--){
      Cur=Cur->Next;
    }
    return Cur->Val;
  }
  //在链表最前面插入一个节点，插入完成后，新插入的节点为链表头节点
  void AddAtHead(int val){
    LinkedNode* NewNode=new LinkedNode(val);
    NewNode->Next=_dummyHead->Next;
    _dummyHead->Next=NewNode;
    _size++;

  }
  //在链表最后的位置添加一个节点
  void AddEnd(int val){
    LinkedNode* NewNode=new LinkedNode(val);
    LinkedNode* Cur=_dummyHead;
    while(Cur->Next!=nullptr){
      Cur=Cur->Next;
    }
    Cur->Next=NewNode;
    _size++;
  }
  //在index之前添加节点
  //如果index为0，那么新插入的节点为链表的头节点
  //如果index等于链表的长度，则说明新插入的节点为尾节点
  //如果大于链表节点长度则返回空
  void AddAtIndex(int index,int val){
    if(index>_size){
      return ;
    }
    LinkedNode* newNode=new LinkedNode(val);
    LinkedNode* cur=_dummyHead;
    while(index--){
      cur=cur->Next;
    }
    newNode->Next=cur->Next;
    cur->Next=newNode;
    _size++;
  }
  //删除index位置的节点，如果index大于等于链表的节点长度则直接返回
  //index从0开始
  void DeleteAtIndex(int index){
    if(index>=_size||index<0){
      return ;
    }
    LinkedNode* cur=_dummyHead;
    while(index--){
      cur=cur->Next;
    }
    LinkedNode* temp=cur->Next;
    cur->Next=cur->Next->Next;
    delete temp;
    _size--;
  }
  //////////打印链表
  void PrintLinkedList(){
    LinkedNode* cur=_dummyHead;
    while(cur->Next!=nullptr){
      cout<<cur->Val<<" ";
      cur=cur->Next;
    }
    cout<<endl;
  }
};
int main(){

  return 0;
}
