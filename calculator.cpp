#include<iostream>
using namespace std;

int main(){
   
    int cont;
    double num1,num2;
    char ch;
    do
    {
        cout<<"\nMenu:-\n";
        cout<<"1. Addition\n2. Subtraction\n3. multipication\n4. dividation"<<"\n:- ";
        cin>>cont;// choice of operation
    

        cout<<"Enter the two number"<<endl;
        cin>>num1>>num2;
        switch (cont)
        {
        case 1:
            cout<<"result:: "<<num1+num2<<endl; 
            break;
        case 2:
            cout<<"result:: "<<num1-num2<<endl; 
            break;
        case 3:
            cout<<"result:: "<<num1*num2<<endl; 
            break;
        case 4:
            if(num2!=0)
            cout<<"result:: "<<num1/num2<<endl;
            else
            cout<<"Syntax error"<<endl;
            break;
        default:
            cout<<"Invalid choice:";
            break;
        }
        cout<<"\nDo you want to continue (y/n)::"<<endl;
        cin>>ch;
    } while (ch == 'y' || ch == 'Y');
    
    return 0;
}