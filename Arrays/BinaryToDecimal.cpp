#include <iostream>
#include <math.h>
using namespace std;

int BinaryToDecimal(int n)
{
    int ans=0,i=0;
    while(n!=0)
    {
        int digit = n %10;
        if(digit == 1)
            ans = ans + pow(2,i);
        n = n/10;
        i++;
    }
    return ans;
}

int main()
{
    int n,ans,newAns;
    cin>>n;
    
    if(n<0)
    {
        ans = BinaryToDecimal(-n);
        newAns = (-ans);
    }
    else{
        newAns = BinaryToDecimal(n);
    }
    
    cout<<newAns;
}
