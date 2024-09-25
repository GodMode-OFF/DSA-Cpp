#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int value){
        data = value;
        prev = NULL;
        next = NULL;
    }
};


int main(){
    Node* head = NULL;
    if(head == NULL){
        head = new Node(50);
    }
    else{
        Node* temp = new Node(5);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    Node* trav = head;
    while(trav){
        cout<<trav->data;
        trav = trav->next;
    }
}
