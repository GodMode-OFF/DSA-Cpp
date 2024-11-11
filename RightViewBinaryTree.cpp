
#include <iostream>
#include<queue>
using namespace std;

void LeftView(Node *root){
    queue<Node*>q;
    vector<int>ans;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        ans.push_back(q.front()->data);
        while(n--){
            Node *temp = q.front();
            q.pop();
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
        
    }
    return ans;
}

int main() {

    return 0;
}
