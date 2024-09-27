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
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            break;
        }
        if(fast != NULL || fast->next != NULL){
            return 0;
        }
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        while(slow->next != fast){
            slow = slow->next;
        }
        slow->next = NULL;
    }
}
