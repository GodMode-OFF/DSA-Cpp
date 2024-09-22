#include<iostream>
using namespace std;

class NODE{
    public:
    int data;
    NODE *next;
    
    NODE(int value){
        data = value;
        next = NULL;
    }
    
    void display(){
        cout<<data<< " " << next;
    }
};

NODE *CreateLinkedList(int arr[], int index, int size){
    if(index == size){
        return NULL;
    }
    else{
        NODE* temp = new NODE(arr[index]);
        temp -> next = CreateLinkedList(arr, index + 1, size);
        return temp;
    }
}

int main(){
    NODE* HEAD;
    HEAD = NULL;
    int arr[] = {1,2,3,4,5};
    HEAD = CreateLinkedList(arr, 0, 5);
    
 NODE *temp = HEAD;
    while(temp != NULL){
        cout<<temp->data<< " ";
        temp = temp->next;
    }
}
