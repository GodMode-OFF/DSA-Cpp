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

class Stack{
    public:
    Node* top;
    int size;
    Stack(){
        top = NULL;
        size = 0;
    }
    void push(int value){
        Node* temp = new Node(value);
        if(temp == NULL){
            cout<<"Stack overflow.\n";
            return;
        }
        
        temp->next = top;
        top = temp;
        cout<<"Pushed "<< value<< " in Stack.\n";
        size++;
    }
    void pop(){
        if(top == NULL){
            cout<<"Stack underflow. \n";
            return;
        }else{
            Node* temp = top;
            cout<<"Popped "<< temp->data<< " from Stack.\n";
            top = top->next;
            delete temp;
            size--;
        }    
    }
    int peek(){
        if(top == NULL){
            cout<<"Stack is empty. \n";
            return -1;
        }else{
            return top->data;
        }
    }
    bool isEmpty(){
        return top == NULL;
    }
    int isSize(){
        return size;
    }
};




int main(){
    Stack S;
    S.push(3);
    S.push(5);
    S.pop();
    cout << "Top of stack: " << S.peek() << "\n";
    cout << "Stack size: " << S.isSize() << "\n";
}
