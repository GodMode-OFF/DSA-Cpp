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

Node* LinkedList(int arr[], int index, int size){
    if(index == size){
        return NULL;
    }else{
        Node* temp = new Node(arr[index]);
        temp -> next = LinkedList(arr, index + 1, size);
        return temp;
    }
}


int main(){
    Node* Head;
    int arr[] = {5,4,3,2,1};
    Head = NULL;
    Head = LinkedList(arr, 0, 5);
    Node* temp = Head;
    while(temp != NULL){
        cout<<temp->data<< " ";
        temp = temp->next;
    }
}
