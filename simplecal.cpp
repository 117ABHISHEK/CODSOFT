#include<string>
#include<sstream>
#include<iostream>
using namespace std;
class cal{
    float a,b;
    string eq;
    char op;
    

    public:

    void getin(){
        cout<<"\n\t\t------------------------------------------------------ ";
        cout<<"\n\t\t Give Input as exit or EXIT for end it";
        cout<<"\n\t\tEnter the eqvation :- ";
        getline(cin,eq);
         if(eq=="exit" || eq=="EXIT"){
            exit(0);
        }
        stringstream ss(eq);
        ss>> a >>op >>b;

       
    }

    float calculus(){
      switch (op) {
            case '+':
                return a + b;
                break;
            case '-':
                return a - b;
                break;
            case '*':
                return a * b;
                break;
            case '/':
                if (b != 0) {
                    return a / b;
                } else {
                    cout<< "\n\t\tError: Division by zero!";
                    getin();
                }
                break;
            default:
                cout << "\n\t\tError: Invalid operator!";
                getin();
                break;
        }
    }

    void mid(){

        cout<<"\n\t\t The ans of the Eq is : "<<eq<<" = "<<calculus();
    }

    void wel(){
         system("CLS");
         cout<<"\n\t\t==================== Simple Calculater ====================";
         cout<<"\n\t\t ========== -:INSTRUCTIONS :- ==========";
         cout<<"\n\t\t 1. This is a Simple Calculater Which can only Perform simple Addition,";
         cout<<"\n\t\t     Substrction, Multiplication and Division";
         cout<<"\n\t\t 2. This is case sencetive to use proper inputs otherwise it will give wrong output";
         cout<<"\n\t\t     Don't use brakets like (), []\n\t\t";
    }

    cal(){
        wel();
        while(1){
            getin();
            calculus();
            mid();
        }
    }

};
int main(){
    cal n;
}