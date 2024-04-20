void insertAtBottom(stack<int> &s , int num){
    if(s.empty()){
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    insertAtBottom(s,num);

    s.push(n);
}

void reverseStack(stack<int> &stack) {
    
    //base case

    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, num);


}