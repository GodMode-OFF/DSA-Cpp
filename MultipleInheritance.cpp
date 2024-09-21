#include<iostream>
using namespace std;

class Tech{
    public:
    string language;
    void specialisation(){
        cout<<"I excel in this language: " <<language<<"\n"; 
    }
};

class Hacker{
    public:
    string OS;
    void System(){
        cout<<"The Operating System I use the most is: "<< OS<<"\n";
    }
};

class WebD:public Tech, public Hacker{
    public:
    string frontbackend;
    WebD(string language, string OS, string frontbackend){
        this->language = language;
        this->OS = OS;
        this->frontbackend = frontbackend;
    }
    void display(){
        specialisation();
        System();
        cout<<"I specialise in "<< frontbackend;
    }
};


int main(){
    WebD A1("C++", "Kali Linux", "Frontend");
    A1.display();
}
