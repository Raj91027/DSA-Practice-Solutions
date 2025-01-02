#include<iostream>

using namespace std;

int main(){

    int n;
    cout<<"Enter number upto which fibo series to print"<<endl;

    cin>>n;

    int f1=0, f2=1, f_next;

    cout<<"The fobo series is:"<<endl;
    

    for(int i=0; i<n; i++){
        cout<<f1<<" ";
        f_next = f1+f2;
        f1 = f2;
        f2= f_next;
    }
}