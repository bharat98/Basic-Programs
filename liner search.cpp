#include<iostream>
#include<algorithm>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)
int main(){
  int array[10]={1,2,3,4,5,5,7,8,9,10};
  int n = sizeof(array)/sizeof(array[0]);
  //loop(i,n) cin>>array[i];

  int key;
  cin>>key;
  int count=0;
  loop(i,n){
    if(key == array[i]){
      cout<<"Element "<<key<<" found at "<<i+1<<" position";
      count++;
      break;
    }
  }
  if (count==0) cout<<"Element not found";
  return 0;
}

-----------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<algorithm>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)

int linear(int a[],int n,int key){
  int count=0;
  loop(i,n){
    if(key == a[i]){
      cout<<"Element "<<key<<" found at "<<i+1<<" position";
      count++;
      break;
    }
  }
    if (count==0) cout<<"Element not found";
  }

int main(){
  int array[10]={1,2,3,4,5,5,7,8,9,10};
  int n = sizeof(array)/sizeof(array[0]);
  //loop(i,n) cin>>array[i];

  int key;
  cin>>key;
  linear(array,n,key);
  return 0;
}
