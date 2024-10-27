#include<iostream>
using namespace std;

class Queue{
    private:
    int *arr;
    int rear;
    int front;
    int size;
    public:
    Queue(int n){
        arr = new int[n]; 
        front = -1;
        rear = -1;
        size = n;
    }
    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return rear == size - 1;
    }
    void push(int x){
        if(isEmpty()){
            front = 0;
            rear = 0;
            arr[0] = x;
        }
        else if(isFull()){
            cout<<"Queue Overflow";
            return;
        }
        else{
            rear = rear + 1;
            arr[rear] = x;
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Queue Underflow";
        }
        else{
            if(front == rear){
                front = -1;
                rear = -1;
            }
            else{
                front = front + 1;
            }
        }
    }
    int start(){
        if(isEmpty()){
            cout<<"Queue is Empty";
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    
};

int main(){
    
}
