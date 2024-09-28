#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;
    public:
    
    Stack(int s){
        size = s;
        top = -1;
        arr = new int[s];
    }
    
    void push(int value){
        if(top == size-1){
            cout<<"Stack overflow.\n";
            return;
        }else{
            top++;
            arr[top] = value;
            cout<<"Pushed "<<value<<" into the Stack.\n";
        }
    }
    void pop(){
        if(top == -1){
            cout<<"Stack underflow.\n";
            return;
        }else{
            cout<<"Popped "<< arr[top]<<" from the Stack. \n";
            top--;
        }
    }
    int peek(){
         if(top == -1){
            cout<<"Stack is empty.\n";
            return -1;
        }else{
            return arr[top];
        }
    }
    bool isEmpty(){
        return top == -1;
    }
    int isSize(){
        return top + 1;
    }
};

int main(){
    Stack S(5);
    S.push(1);
    S.pop();
    cout<<S.peek();
}
