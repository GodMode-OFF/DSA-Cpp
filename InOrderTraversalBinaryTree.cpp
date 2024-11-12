vector<int>InOrder(Node *root){
    stack<Node*>s;
    vector<int>visited;
    vector<int>ans;
    visited.push_back(0);
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        bool flag = visited.top();
        visited.pop();
        if(flag==0){
            if(temp->right){
                s.push(temp->right);
                visited.push(0);
            }
            s.push(temp);
            visited.push(1);
            if(temp->left){
                s.push(temp->left);
                visited.push(0);
            }
        }
        else{
            ans.push_back(temp->data);
        }
    }
}
