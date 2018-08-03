#include<iostream>
using namespace std;
int main (){
    int n,i,a,b,T;
    cin>>T;
    for(i=0;i<T;i++){
        cin>>n;
        b=n/2;
        a=n-b;
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}