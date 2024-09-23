#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int value){
        data = value;
        next = NULL;
    }
};


int main(){
    Node* head = NULL;
    int arr[] = {1,2,3,4};
    int pos = 3;
    int val = 12;
    Node* tail = NULL;
    for(int i = 0; i < 4; i++){
        if(head == NULL){
            head = new Node(arr[i]);
            tail = head;
        }
        else{
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }
    
    Node* temp = head;
    pos--;
    while(pos--){
        temp = temp->next;
    }
    Node* temp2 = new Node(val);
    temp2->next = temp->next;
    temp->next = temp2;

    Node* preent = head;
    while(preent != NULL){
        cout<<preent->data<<" ";
        preent = preent->next;
    }
}
