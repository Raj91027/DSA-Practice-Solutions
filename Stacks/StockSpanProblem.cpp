/*
Input: arr[] = [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]
Explanation: Traversing the given input span 100 is greater than equal to 100 and 
there are no more elements behind it so the span is 1, 
80 is greater than equal to 80 and smaller than 100 so the span is 1, 
60 is greater than equal to 60 and smaller than 80 so the span is 1, 
70 is greater than equal to 60,70 and smaller than 80 so the span is 2 and so on. 
 Hence the output will be 1 1 1 2 1 4 6.
*/

/*
[Naive Approach] Using Nested Loop – O(n^2) Time and O(1) Space
The idea is to use nested loops, where the outer loop iterates through the array to process each stock price. 
For each day, the inner loop moves leftward in the array, comparing previous prices and increasing the span 
count until a higher price is found or the beginning of the array is reached.

Algorithm:
Create an array span[] to store the span values.
Traverse the input array arr[] from left to right.
For each element arr[i], initialize the span value as 1.
Traverse the array arr[] from i-1 to 0, until a price greater than or equal to arr[i] is found.
Increment the span value for each day.
Store the span value in the span[] array.
Repeat the above steps for all elements in the array.
Return the span[] array.


*/

// C++ program to find the stock span values
// using the naive approach
#include <iostream>
#include <vector>
using namespace std;

// Function to find the stock span values

vector<int> stockSpan(vector<int> arr) {
    int n = arr.size();
    vector<int> span(n, 0);

    // Traverse the input array
    for (int i = 0; i < n; i++) {
        span[i] = 1;
        // Traverse the array from i-1 to 0
        for (int j = i - 1; j >= 0; j--) {
            // If the price is greater than or equal to arr[i]
            if (arr[j] <= arr[i]) {
                span[i]++;
            }
            else {
                break;
            }
        }
    }

    return span;
}

int main() {
    vector<int> arr = { 100, 80, 60, 70, 60, 75, 85 };
    vector<int> span = stockSpan(arr);

    for (int i = 0; i < span.size(); i++) {
        cout << span[i] << " ";
    }

    return 0;
}

/*
[Expected Approach] Using Stack – O(n) Time and O(n) Space
The idea is to use a stack to find the span of stock prices. 
For each day, we remove indices from the stack while the current price is greater than or equal 
to the price at the top of the stack, as those day’s prices cannot influence the span. 


If the stack becomes empty, it means all previous prices are smaller, and the span is the current day index plus one. 
Otherwise, the span is the difference between the current index and the top of the stack, which represents the last higher price’s index.

Algorithm:
Create a stack to store the indices of the stock prices.
Create an array span[] to store the span values.
Traverse the input array arr[] from left to right.
While the stack is not empty and the price at the top of the stack is less than or equal to the current price, pop the stack.
If the stack is empty, the span value is i+1.
Otherwise, the span value is i minus the top of the stack.
Push the current index i onto the stack.
Repeat the above steps for all elements in the array.
Return the span[] array.

*/

// C++ program to find the stock span values
// using the stack approach 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to find the stock span values
vector<int> stockSpan(vector<int> arr) {
    int n = arr.size();
    vector<int> span(n, 0);
    stack<int> st;

    // Push the first element's index onto the stack
    st.push(0);
    span[0] = 1;

    // Traverse the input array
    for (int i = 1; i < n; i++) {
        // Pop elements from the stack while the stack is not empty
        // and the price at the top of the stack is less than or equal to arr[i]
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        // If the stack is empty, the span value is i+1
        span[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // Push the current index onto the stack
        st.push(i);
    }

    return span;
}

int main() {
    vector<int> arr = { 100, 80, 60, 70, 60, 75, 85 };
    vector<int> span = stockSpan(arr);

    for (int i = 0; i < span.size(); i++) {
        cout << span[i] << " ";
    }

    return 0;
}

//Output: 1 1 1 2 1 4 6
//Explanation: The stock span values for the given input are 1 1 1 2 1 4 6.

//Time Complexity: O(n)
//Space Complexity: O(n)
