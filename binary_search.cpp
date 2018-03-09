#include<iostream>
#include<algorithm>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)

int main(){
    int array[10];
    int n = sizeof(array)/sizeof(array[0]);
    cout<<"Enter "<<n<<" numbers :"<<endl;
    loop(i,n) cin>>array[i];

    int value = binary_search(array,array+n,2);
    cout<<value;
    return 0;
}
