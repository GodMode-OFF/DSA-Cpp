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

int main(){
    int arr[] = {1,2,3,4,5};
    NODE *Head;
    Head = NULL;
    for(int i = 0; i < 5; i++){
        if(Head == NULL){
            Head = new NODE(arr[i]);
        }else{
            NODE *temp;
            temp = new NODE(arr[i]);
            temp -> next = Head;
            Head = temp;
        }
    }
    NODE *temp = Head;
    while(temp != NULL){
        cout<<temp->data<< " ";
        temp = temp->next;
    }
}
