
#include <iostream>
using namespace std;

int main() {
    int inp_num = 16;
    if(inp_num<1){
        cout<<"Not in power of 2";
    }else{
        while(inp_num!=1){
            if(inp_num%2==1){
                cout<<"Trash Number";
                break;
            }else{
                inp_num = inp_num / 2;
            }
        }
    }

    return 0;
}
