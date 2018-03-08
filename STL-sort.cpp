#include<iostream>
#include<algorithm>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)

int main(){
  int array[10];
  int n= sizeof(array)/sizeof(array[0]);
  cout<<"Enter 10 elements :"<<endl;
  loop(i,n) cin>>array[i];
  
  sort(array,array+n);
  
  loop(i,n) cout<<array[i]<<" ";
  return 0;
}
