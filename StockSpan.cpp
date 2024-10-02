#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }
        
        if (st.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - st.top();
        }
        
        st.push(i);
    }
    
    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = stockSpan(prices);
    
    cout << "Prices: ";
    for (int price : prices) {
        cout << price << " ";
    }
    cout << endl;
    
    cout << "Span: ";
    for (int s : result) {
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}
