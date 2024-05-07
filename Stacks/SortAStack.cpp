#include <bits/stdc++.h> 
void sortedStack(stack<int> &s , int num){
    if(s.empty() || s.top()<num){
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    sortedStack(s,num);

    s.push(n);
}

void sortStack(stack<int> &stack)
{
	 if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    sortStack(stack);

    sortedStack(stack, num);
}