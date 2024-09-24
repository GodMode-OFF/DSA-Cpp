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

void PrintNodes(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

}

int main(){
    Node* head = NULL;
    Node* temp = NULL;
    int arr[] = {1,3,5,7,9};
    for(int i = 0; i < 5; i++){
        Node* nod = new Node(arr[i]);
        if(head == NULL){
            head = nod;
            temp = head;
        }else{
            temp->next = nod;
            temp = temp->next;
        }
    }
    PrintNodes(head);
}
