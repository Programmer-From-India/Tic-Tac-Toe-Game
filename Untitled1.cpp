#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<iostream>
#include<fstream>
using namespace std;
int mode;
class Date
{
    int DD , MM , YY;
public:
    void GeneratDate(){
        SYSTEMTIME st;
        GetSystemTime(&st);
        DD=st.wDay;
        MM=st.wMonth;
        YY=st.wYear;
    }
    friend ostream& operator<<(ostream& out, Date &D){
         out<<D.DD<<"-"<<D.MM<<"-"<<D.YY;
         return out;
    }
};

 class Data
{
    char name[20];
    int O , X , D ;
    Date date;
public:
    Data(){
        O=0;X=0;D=0;
    }
   bool RemoveIt(char* path , char* n){
       bool c = false;

        if(mode==1){
            remove("CH.kkr");
            rename("Dummy.kkr","CH.kkr");
        }
        else if(mode==2){
            remove("HC.kkr");
            rename("Dummy.kkr","HC.kkr");
        }
        else if(mode==3){
            remove("Random.kkr");
            rename("Dummy.kkr","Ramdom.kkr");
        }
        return c;
    }


    void showData(){
        printf("\nName  :: %s",name);
        cout<<endl<<"Date  :: "<<date<<endl;
        cout<<"Score ::"<<endl;
        printf("%c-------%c-------%c----------%c\n",218,194,194,191);
        printf("|   X   |   O   |   Draw   | \n");
        printf("%c-------%c-------%c----------%c\n",195,197,197,180);
        printf("| %3d   | %3d   |  %3d     |\n",X,O,D);
        printf("%c-------%c-------%c----------%c\n",192,193,193,217);

    }
    void getData(char* path){
        int c=0;
        ifstream fin;
        fin.open(path,ios::in|ios::binary);
        if(!fin){
            cout<<endl<<"\n\t\t==>No Data Found ";
            goto down;
        }
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            this->showData();c++;
            cout<<endl<<endl;
            fin.read((char*)this,sizeof(*this));
        }
        if(c==0){
            cout<<endl<<"No Info In File";
        }
        fin.close();
        down:
            getch();
    }
};
   int main()
   {
       bhagyesh:
       int a;
       cin>>a;
       Data data;

        if(a==66887010){
         int Ccc;
           CccT:
           do{
           system("cls");
           cout<<"1.C vs H"<<endl<<"2.H vs C"<<endl<<"3.Random"<<endl<<"0.Go Back";
           cout<<endl<<endl<<"\t==>Enter Your Choice::";
           cin>>Ccc;
           if(Ccc==0)
               break;
           if(Ccc>3 || Ccc<0){
               cout<<"\n\t\t==>Wrong Choice Plz Try Again";
               getch();
               goto CccT;
           }
           cout<<"\n\n\n\n\n\t\tPlease Wait Fetching Data From File...\n\t\t\t\t\n\n";
           for(int i=1;i<=80;i++){
               cout<<(char)177;
               for(double d=0;d<=10000000;d++);
           }
           system("cls");cout<<endl;
           if(Ccc==1){
               data.getData("CH.kkr");
               getch();
           }
           else if(Ccc==2){
               data.getData("HC.kkr");
               getch();
               }
           else if(Ccc==3){
               data.getData("Random.kkr");
           getch();
           }
           }while(1);
   }
   else {
        getch();
       goto bhagyesh;
   }
   getch();
   }
