#include<iostream>
using namespace std;


int main(){
    string pali;
    int Larr[26] = {0};
    int Uarr[26] = {0};
    cout<<"Enter your palindromic string: ";
    cin>> pali;
    int N = pali.size();
    int Lindex = 0, Uindex = 0, odd = 0, count = 0; 
    
    for(int i = 0; i < N; i++){
        if (pali[i] >= 'A' && pali[i] <= 'Z') {
            Uindex = pali[i] - 'A';
            Uarr[Uindex]++;
            }   
        else{
            Lindex = pali[i] - 'a';
            Larr[Lindex]++;
        }
    }
    for(int i = 0; i < 26; i++){
        if(Larr[i] % 2 == 0){
            count += Larr[i];
        }else{
            count += Larr[i] - 1;
            odd = 1;       
        }
        if(Uarr[i] % 2 == 0){
            count += Uarr[i];
        }else{
            count += Uarr[i] - 1;
            odd = 1;       
        }
    }
    cout<< "The longest palindrome you can create is " <<count + odd<<" characters long";
}
