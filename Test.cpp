#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> vector={1,2,3,4,5,6};
  for(int i=0;i<vector.size();i++){
    cout<<vector[i]<<endl;
  }
  cout<<*vector.begin()<<endl;
  cout<<*(vector.end()-1);
  return 0;
}
