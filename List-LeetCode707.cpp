//��Ŀ������
/*
��������࣬ʵ�������ӿ�
��������ǰ�����ڵ�
��ȡ��INDEX���ڵ����ֵ
����������ڵ�
��INDEX�ڵ�ǰ�����ڵ�
ɾ��INDEX���ڵ�
��ӡ����
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
  //size�������С��_dummyHead�������ͷ�ڵ�
public:
  //��ʼ������
  MyLinkedList(){
    //�ڴ˶���һ������ͷ�ڵ�
    _dummyHead =new LinkedNode(0);
    _size=0;
  }
  //��ȡindexλ�õ���ֵ�������ֵ�Ƿ��򷵻�-1
  //index�Ǵ�0��ʼ�ģ�0����ͷ�ڵ�
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
  //��������ǰ�����һ���ڵ㣬������ɺ��²���Ľڵ�Ϊ����ͷ�ڵ�
  void AddAtHead(int val){
    LinkedNode* NewNode=new LinkedNode(val);
    NewNode->Next=_dummyHead->Next;
    _dummyHead->Next=NewNode;
    _size++;

  }
  //����������λ�����һ���ڵ�
  void AddEnd(int val){
    LinkedNode* NewNode=new LinkedNode(val);
    LinkedNode* Cur=_dummyHead;
    while(Cur->Next!=nullptr){
      Cur=Cur->Next;
    }
    Cur->Next=NewNode;
    _size++;
  }
  //��index֮ǰ��ӽڵ�
  //���indexΪ0����ô�²���Ľڵ�Ϊ�����ͷ�ڵ�
  //���index��������ĳ��ȣ���˵���²���Ľڵ�Ϊβ�ڵ�
  //�����������ڵ㳤���򷵻ؿ�
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
  //ɾ��indexλ�õĽڵ㣬���index���ڵ�������Ľڵ㳤����ֱ�ӷ���
  //index��0��ʼ
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
  //////////��ӡ����
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
