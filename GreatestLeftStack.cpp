int main(){
    stack<int>st;
    vector<int>ans(n, -1);
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
}
