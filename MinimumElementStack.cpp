#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(3);
    minStack.push(5);
    cout << minStack.getMin() << endl; // 3
    minStack.push(2);
    minStack.push(1);
    cout << minStack.getMin() << endl; // 1
    minStack.pop();
    cout << minStack.getMin() << endl; // 2
    minStack.pop();
    cout << minStack.top() << endl;     // 5
    cout << minStack.getMin() << endl; // 3
    return 0;
}
