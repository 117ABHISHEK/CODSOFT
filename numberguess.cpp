#include<windows.h>
#include<ctime>
#include<iostream>
using namespace std;

class game{
    int gennum=0,level=0,num=0,flag=0;
    string name;

    public:
    int gen(){
        srand(time(0));
        gennum=1+(rand()%level);
    }

     void player(){
        cout<<"\n\t\t ========== -:INSTRUCTIONS :- ==========";
        cout<<"\n\t\t  1. This game works on it's inputs so use the inputs as given\n\t\t in instruction";
        cout<<"\n\t\t  2. In this game you get chance to guess number so guess it in given chances..";
        cout<<"\n\t\t      You can lose chances by wrong guess (Even after wrong input..)\n";
        cout<<"\n\t\t========================================================";
        cout<<"\n\t\t Enter Your Name  :-";
        cin>>name;
        
    }

    int plevel(){
        a:
        cout<<"\n\t\t Enter the Level";
        cout<<"\n\t\t 1. Easy (between 0 to 10)";
        cout<<"\n\t\t 2. Mid (between 0 to 50)";
        cout<<"\n\t\t 3. Hard (between 0 to 100)\n\t\t :-";
        cin>>level;
        switch(level){
            case 1: level=10;
                    flag=3;
            break;
            case 2: level=50;
                    flag=10;
            break;
            case 3: level=100;
                    flag=20;
            break;
            default :cout<<"\n\t\tWrong Input";
                    goto a;
            break;        
        }
    }
    void lcheck(){
        if( level==10 && (num<0 || num>10)){
            cout<<"\n\t\twrong Input.. you need to guess between 0 to 10";
        }else if( level==50 && (num<0 || num>50)){
            cout<<"\n\t\twrong Input.. you need to guess between 0 to 50";
        }else if ( level==100 && (num<0 || num>100)){
            cout<<"\n\t\twrong Input.. you need to guess between 0 to 100";
        } 
    }

    void play(){
        while(1){
            cout<<"\n\t\t====== Now You Have only "<<flag<<" chances to guess =====\n\t\t  ";
            cout<<"\n\t\tEnter the number : ";
            cin>>num;
            flag--;
            if(num<=0 || num>=level){
                lcheck();
            }else{ 
                if(gennum==num){
                    cout<<"\n\t\tperfect Guess... \n\t\t ======================= You Win ========================";
                    break;                              
                }else if(gennum<num){
                    cout<<"\n\t\t Good but Not perfect guess...\n\t\t Your are Closer But your guess Number is big..";
                    cout<<"\n\t\t--------------------------------------------------------";
                }else if(gennum >num){
                    cout<<"\n\t\t Good but Not perfect guess...\n\t\t Your are Closer But your guess Number is small..";
                    cout<<"\n\t\t--------------------------------------------------------";
                }
            }
            if(flag==0){
                cout<<"\n\t\t\t    || The Number is "<<gennum<<" ||";
                cout<<"\n\t\t====================== You Lose =======================";
                break;
            }       
        }    
    }

    game(){
    system("CLS");
    cout<<"\n\t\t====================  Welcome Number Guess Game ====================";
    player();
    cout<<"\n\t\t========================================================";
    plevel();
    cout<<"\n\t\t========================================================";
    system("CLS");
    cout<<"\n\t\t========================================================";
    gen();
    play();
    cout<<"\n\t\t========================================================";
    }
};
int main(){
    game p1;
}