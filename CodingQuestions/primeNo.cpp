#include<iostream>

using namespace std;

int main(){

    int n;
    int flag=0;

    cout<<"Enter number to check:"<<endl;

    cin>>n;

    for(int i=2; i*i <= n; i++){
        if(n %i==0){
            cout<<"It is not prime"<<endl;
            flag=1;
            break;
        }
      
    }
    if(flag==0)
        cout<<"it is a prime number"<<endl;

    return 0;
}