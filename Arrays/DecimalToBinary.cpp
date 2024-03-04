#include <iostream>
#include <math.h>
using namespace std;

int DecimalToBinary(int n)
{
    int ans=0,i=0;
    while(n!=0)
    {
        int bit = n&1;
        n = n>>1;
        ans = bit*pow(10,i++)+ans;
    }
    return ans;
}

int main()
{
    int n, ans,newAns;
    cin>>n;
    
    if(n<0)
    {
        ans = DecimalToBinary(-n);
        newAns = ((~ans)+1);
    }
    else{
        newAns = DecimalToBinary(n);
    }
    cout<<newAns;
}