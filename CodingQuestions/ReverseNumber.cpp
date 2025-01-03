#include<iostream>

using namespace std;

int main() {

    int num;
    cout<<"Enter number to reverse"<<endl;
    cin>>num;

    int rev=0;

    while(num>0){
        int rem = num%10;
        rev = (rev*10)+rem;
        num = num/10;
    }

    cout<<"The reversed number is:"<<rev<<endl;

    return 0;
}