#include<iostream>
using namespace std;

class Customer{
    string name;
    int acc_num, balance;
    public:
    
    static int total_customer;
    static int total_balance;
        Customer(string a, int b, int c){
            name = a;
            acc_num = b;
            balance = c;
            total_customer++;
            total_balance += c;
    }
    void displayTotal(){
        cout<<total_customer;
    }
};

int Customer::total_customer = 0;
int Customer::total_balance = 0;

int main(){
    Customer A1("Tabish", 1, 1000);
    Customer A2("Ahmad", 2, 2000);
    cout<<Customer::total_customer;
}
