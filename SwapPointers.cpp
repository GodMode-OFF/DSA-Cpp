#include<iostream>
using namespace std;


void swap(int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main(){
    int first = 10;
    int second = 20;
    cout<<first<<" "<<second<<"\n";
    swap(&first, &second);
    cout<<first<< " "<<second;
    return 0;
}
