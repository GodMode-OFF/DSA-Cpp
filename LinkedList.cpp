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
    Node* temp = NULL;
    int arr[] = {1,2,3,4};
    for(int i = 0; i < 4; i++){
        if(head == NULL){
            head = new Node(1);
        }
        else{
            temp = new Node(arr[i]);
            temp -> next = head;
            head = temp;
            
        }
    }
    Node* preent;
    preent = head;
    while(preent != NULL){
        cout<<preent->data;
        preent = preent->next;
    }
}
