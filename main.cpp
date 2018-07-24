#include<stdio.h>

#include<conio.h>

#include<windows.h>

#include<time.h>

#include<string>

#include<iostream>

#include<stdlib.h>

#include<fstream>

using namespace std;


int a[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};

char player='O',Option[20],name[2][20];

int n=1,x=0,o=0,d=0,ex=0,m=1,q,random;
int onlyx=0,onlyo=0,onld=0,mode;


void delay(unsigned int mseconds)

{

    clock_t goal = mseconds + clock();

    while (goal > clock());

}

void Reset1(){

    a[0]=' ';a[1]=' ';a[2]=' ';a[3]=' ';a[4]=' ';a[5]=' ';a[6]=' ';a[7]=' ';a[8]=' ';

    player='O';

    n=1;ex=0;

}

void Reset(){

    Reset1();

    x=0;o=0;d=0;

}

void Board(){

    printf("%s vs %s",name[0],name[1]);

    printf("\t\tEnter 17936688 To Resign From Game\n\n");

    printf("\t\t              1|2|3\n\t\tDummy Board   4|5|6\n\t\t              7|8|9\n\n");

    printf("-->%s\n\n",Option);

    printf("       |       |       \n");

    printf("   %c   |   %c   |   %c   \n",a[0],a[1],a[2]);

    printf("       |       |       \n");

    printf(" ------+-------+------");

        printf("\t\t%c-------%c-------%c----------%c\n",218,194,194,191);

    printf("       |       |       ");

        printf("\t\t|   X   |   O   |   Draw   | \n");

    printf("   %c   |   %c   |   %c   ",a[3],a[4],a[5]);

        printf("\t\t%c-------%c-------%c----------%c\n",195,197,197,180);

    printf("       |       |       ");

        printf("\t\t| %3d   | %3d   |  %3d     |\n",x,o,d);

    printf(" ------+-------+------");

        printf("\t\t%c-------%c-------%c----------%c\n",192,193,193,217);

    printf("       |       |      \n");

    printf("   %c   |   %c   |   %c   \n",a[6],a[7],a[8]);

    printf("       |       |       \n");

}

int PrintAndGets(string s){
    cout<<s;
    int num=0,ch,n=1;
    do{
        ch = getch();
        if(ch>=49 && ch<=57 && n<=8){//1 Ascii code is 49 and 9 Ascii code is 57
            cout<<(char)ch;
            num = num * 10 + ( ch - 48 );
            n++;
        }
        if(ch==8 && num){//Ascii code for back space is 8
            if(num)
                num = num / 10 ;
            system("cls");
            if(n>1)
                n--;
            Board();
            cout<<"\n";
            printf("==>%s ",name[q]);
            if(num)
                cout<<" "<<s<<num;
            else
                cout<<" "<<s;
        }
        if(ch==13) {//Ascii code for enter is 13
            if(num)
                break;
        }
    }while(1);
    cout<<"\n\n";
    return num;
}

void Input(){

    int C;

    ABD:

    printf("\n==>%s ",name[q]);

    C = PrintAndGets("Enter Your Choice:");

    if(C != 17936688){
    if(!(C > 0 && C < 10)){
        system("cls");

        Board();

        Input();
    }
    }

    fflush(stdin);

    switch(C)

    {

    case 17936688:

        ex = -1;

        break;

    case 1:

        if(a[0]==' ')

        {

        a[0]=player;}

        else{

            printf("Already Full \n");

            getch();

            system("cls");

            Board();

            Input();

            }

        break;

    case 2:

        if(a[1]==' ')

            a[1]=player;

        else{

            printf("Already Full \n");

            getch();

            system("cls");

            Board();

            Input();

            }

        break;

    case 3:

        if(a[2]==' ')

            a[2]=player;

        else{

            printf("Already Full \n");

            getch();

            system("cls");

            Board();

            Input();

            }

        break;

    case 4:

        if(a[3]==' ')

            a[3]=player;

        else{

            printf("Already Full\n");

            getch();

            system("cls");

            Board();

            Input();

            }

        break;

    case 5:

        if(a[4]==' ')

            a[4]=player;

        else{

            printf("Already Full  \n");

            getch();

            system("cls");

            Board();

            Input();

            }

        break;

    case 6:

        if(a[5]==' ')

            a[5]=player;

        else{

            printf("Already Full \n");

            getch();

            system("cls");

            Board();

            Input();

            }

        break;

    case 7:

        if(a[6]==' ')

            a[6]=player;

        else{

            printf("Already Full \n");

            getch();

            system("cls");

            Board();

            Input();

            }

        break;

    case 8:

        if(a[7]==' ')

            a[7]=player;

        else{

            printf("Already Full \n");

            getch();

            system("cls");

            Board();

            Input();

            }

        break;

    case 9:

        if(a[8]==' ')

            a[8]=player;

        else{

            printf("Already Full \n");

            getch();

            system("cls");

            Board();

            Input();}

        break;

    }

}

int Win(){

    if(a[0]!=' ' && a[0]==a[1] && a[1]==a[2])

        return 1;

    else if(a[3]!=' ' && a[3]==a[4] && a[4]==a[5])

        return 1;

    else if(a[6]!=' ' && a[6]==a[7] && a[7]==a[8])

        return 1;

    else if(a[0]!=' ' && a[0]==a[4] && a[4]==a[8])

        return 1;

    else if(a[2]!=' ' && a[2]==a[4] && a[4]==a[6])

        return 1;

    else if(a[0]!=' ' && a[0]==a[3] && a[3]==a[6])

        return 1;

    else if(a[1]!=' ' && a[1]==a[4] && a[4]==a[7])

        return 1;

    else if(a[2]!=' ' && a[2]==a[5] && a[5]==a[8])

        return 1;

    else if(a[0]!=' ' && a[1]!=' ' && a[2]!=' '&& a[3]!=' ' && a[4]!=' ' && a[5]!=' ' &&a[6]!=' ' && a[7]!=' ' && a[8]!=' ')

        return 0;

}

void ChangePlayer(){

    if(player=='O' && q==0)

        {

            player='X';

            q=1;

        }

   else

    {

        player='O';

        q=0;

    }

}

void CornerCase(){

    if(a[0]==' ')

        {

            a[0]=player;

            n++;

        }

        else if(a[8]==' ')

        {

            a[8]=player;

            n++;

        }

        else if(a[2]==' ')

        {

            a[2]=player;

            n++;

        }

        else if(a[6]==' ')

        {

            a[6]=player;

            n++;

        }

}

void Pc3_1(){

    if(a[2]=='X' && a[1]==a[2] )

       {

           a[4]=player;

           n++;

       }

    else if(a[5]=='X' && a[1]==a[5])

       {

           a[4]=player;

           n++;

       }

    else if(a[7]=='X' && a[1]==a[7])

       {

           a[4]=player;

           n++;

       }

    else if(a[4]=='X' && a[1]==a[4])

       {

           a[7]=player;

           n++;

       }

    else if(a[3]=='X' && a[1]==a[3])

       {

           a[4]=player;

           n++;

       }

    else if(a[6]=='X' && a[1]==a[6])

       {

           a[4]=player;

           n++;

       }

}

void Pc3_2(){

    if(a[1]=='X' && a[2]==a[1] )

       {

           a[8]=player;

           n++;

       }

    else if(a[3]=='X'  && a[2]==a[3])

       {

           a[4]=player;

           n++;

       }

    else if(a[4]=='X' && a[2]==a[4])

       {

           a[6]=player;

           n++;

       }

       else if(a[5]=='X' && a[2]==a[5])

       {

           a[4]=player;

           n++;

       }

       else if(a[6]=='X' && a[2]==a[6])

       {

           a[4]=player;

           n++;

       }

       else if(a[7]=='X' && a[2]==a[7])

       {

           a[4]=player;

           n++;

       }

}

void Pc3_3(){

    if(a[1]=='X' && a[5]==a[1] )

       {

           a[4]=player;

           n++;

       }

    else if(a[2]=='X' && a[5]==a[2] )

       {

           a[4]=player;

           n++;

       }

    else if(a[3]=='X' && a[5]==a[3] )

       {

           a[4]=player;

           n++;

       }

    else if(a[4]=='X' && a[5]==a[4] )

       {

           a[3]=player;

           n++;

       }

    else if(a[6]=='X' && a[5]==a[6] )

       {

           a[4]=player;

           n++;

       }

    else if(a[7]=='X' && a[5]==a[7] )

       {

           a[4]=player;

           n++;

       }

}

void Pc3_4(){

    if(a[1]=='X' && a[8]==a[1] )

       {

           a[6]=player;

           n++;

       }

    else if(a[3]=='X' && a[8]==a[3] )

       {

           a[1]=player;

           n++;

       }

    else if(a[4]=='X' && a[8]==a[4] )

       {

           a[1]=player;

           n++;

       }

    else if(a[5]=='X' && a[8]==a[5] )

       {

           a[1]=player;

           n++;

       }

    else if(a[6]=='X' && a[8]==a[6] )

       {

           a[1]=player;

           n++;

       }

    else if(a[7]=='X' && a[8]==a[7] )

       {

           a[1]=player;

           n++;

       }

}

void Pc3_5(){

    if(a[1]=='X' && a[7]==a[1] )

       {

           a[4]=player;

           n++;

       }

    else if(a[2]=='X' && a[7]==a[2] )

       {

           a[4]=player;

           n++;

       }

    else if(a[3]=='X' && a[7]==a[3] )

       {

           a[4]=player;

           n++;

       }

    else if(a[4]=='X' && a[7]==a[4] )

       {

           a[1]=player;

           n++;

       }

    else if(a[5]=='X' && a[7]==a[5] )

       {

           a[4]=player;

           n++;

       }

    else if(a[6]=='X' && a[7]==a[6] )

       {

           a[4]=player;

           n++;

       }

}

void Pc3_6(){

    if(a[1]=='X' && a[6]==a[1] )

       {

           a[4]=player;

           n++;

       }

    else if(a[2]=='X' && a[6]==a[2] )

       {

           a[4]=player;

           n++;

       }

    else if(a[3]=='X' && a[6]==a[3] && a[8]=='O')

       {

           a[4]=player;

           n++;

       }

    else if(a[4]=='X' && a[6]==a[4] )

       {

           a[2]=player;

           n++;

       }

    else if(a[5]=='X' && a[6]==a[5] )

       {

           a[4]=player;

           n++;

       }

    else if(a[7]=='X' && a[6]==a[7] )

       {

           a[4]=player;

           n++;

       }

}

void Pc3_7(){

    if(a[1]=='X' && a[3]==a[1] )

       {

           a[4]=player;

           n++;

       }

    else if(a[2]=='X' && a[3]==a[2] )

       {

           a[4]=player;

           n++;

       }

    else if(a[4]=='X' && a[3]==a[4] )

       {

           a[5]=player;

           n++;

       }

    else if(a[6]=='X' && a[3]==a[4] )

       {

           a[1]=player;

           n++;

       }

    else if(a[7]=='X' && a[3]==a[7] )

       {

           a[4]=player;

           n++;

       }

    else if(a[5]=='X' && a[3]==a[5] )

       {

           a[4]=player;

           n++;

       }

}

void Pc3_8(){

    if(a[1]=='X' && a[4]==a[1] )

       {

           a[7]=player;

           n++;

       }

    else if(a[2]=='X' && a[4]==a[2] )

       {

           a[6]=player;

           n++;

       }

    else if(a[3]=='X' && a[4]==a[3] )

       {

           a[5]=player;

           n++;

       }

    else if(a[5]=='X' && a[4]==a[5] )

       {

           a[3]=player;

           n++;

       }

    else if(a[6]=='X' && a[4]==a[6] )

       {

           a[2]=player;

           n++;

       }

    else if(a[7]=='X' && a[4]==a[7] )

       {

           a[1]=player;

           n++;

       }

}

void Pc4_1(){

    if(a[1]=='X' && a[2]==a[4])

    {

        a[7]=player;

        n++;

    }

    else if(a[3]=='X' && a[2]==a[4] && a[6]=='O')

    {

        a[7]=player;

        n++;

    }

    else if(a[5]=='X' && a[2]==a[4]  && a[6]=='O')

    {

        a[7]=player;

        n++;

    }

    else if(a[7]=='X' && a[2]==a[4] && a[6]=='O')

    {

        a[3]=player;

        n++;

    }

    else if(a[1]=='X' && a[4]==a[5])

    {

        a[6]=player;

        n++;

    }

    else if(a[2]=='X' && a[4]==a[5])

    {

        a[6]=player;

        n++;

    }

    else if(a[6]=='X' && a[4]==a[5] && a[3]==a[0])

    {

        a[2]=player;

        n++;

    }

    else if(a[7]=='X' && a[4]==a[5] && a[1]=='O')

    {

        a[2]=player;

        n++;

    }

}

void Pc4_2(){

    if(a[6]=='X' && a[1]==a[4] && a[7]=='O')

    {

        a[2]=player;

        n++;

    }

    else if(a[2]=='X' && a[1]==a[4] )

    {

        a[6]=player;

        n++;

    }

    else if(a[3]=='X' && a[1]==a[4] && a[7]=='O')

    {

        a[6]=player;

        n++;

    }

    else if(a[5]=='X' && a[1]==a[4])

    {

        a[6]=player;

        n++;

    }

    else if(a[1]=='X' && a[3]==a[4] && a[5]==a[8])

    {

        a[2]=player;

        n++;

    }

    else if(a[2]=='X' && a[3]==a[4])

    {

        a[6]=player;

        n++;

    }

    else if(a[6]=='X' && a[3]==a[4] && a[5]=='O')

    {

        a[2]=player;

        n++;

    }

    else if(a[7]=='X' && a[3]==a[4])

    {

        a[2]=player;

        n++;

    }

    else if(a[2]=='X' && a[7]==a[4] && a[1]=='O')

    {

        a[6]=player;

        n++;

    }

    else if(a[3]=='X' && a[7]==a[4])

    {

        a[2]=player;

        n++;

    }

    else if(a[5]=='X' && a[7]==a[4] && a[3]=='O')

    {

        a[6]=player;

        n++;

    }

    else if(a[6]=='X' && a[7]==a[4] && a[1]=='O')

    {

        a[2]=player;

        n++;

    }

    else if(a[1]=='X' && a[6]==a[4])

    {

        a[5]=player;

        n++;

    }

    else if(a[3]=='X' && a[6]==a[4])

    {

        a[5]=player;

        n++;

    }

    else if(a[5]=='X' && a[6]==a[4] && a[2]=='O' && a[3]==' ')

    {

        a[1]=player;

        n++;

    }

    else if(a[7]=='X' && a[6]==a[4] && a[2]=='O')

    {

        a[1]=player;

        n++;

    }

    else if(a[1]=='X' && a[8]==a[4] && a[3]=='O')

    {

        a[7]=player;

        n++;

    }

    else if(a[3]=='X' && a[8]==a[4])

    {

        a[1]=player;

        n++;

    }

    else if(a[5]=='X' && a[8]==a[4])

    {

        a[1]=player;

        n++;

    }

    else if(a[6]=='X' && a[8]==a[4])

    {

        a[1]=player;

        n++;

    }

    else if(a[7]=='X' && a[8]==a[4])

    {

        a[1]=player;

        n++;

    }

}

void Pc4_3(){

    if(a[3]=='X' && a[8]=='X')

        a[4]=player;

    else if(a[5]=='X' && a[8]=='X')

        a[4]=player;

    else if(a[7]=='X' && a[8]=='X')

        a[4]=player;

    else if(a[4]=='X' && a[8]=='X')

        a[3]=player;

}

void Pc5(){

    if(a[5]==' ' && a[1]=='X')

        a[5]=player;

    else if(a[3]==' ' && a[1]=='X')

        a[3]=player;

    else if(a[1]==' ' && a[3]=='X')

        a[1]=player;

    else if(a[7]==' ' && a[3]=='X')

        a[7]=player;

    else if(a[1]==' ' && a[4]=='X')

        a[1]=player;

    else if(a[7]==' ' && a[4]=='X')

        a[7]=player;

    else if(a[1]==' ' && a[4]=='X')

        a[1]=player;

    else if(a[7]==' ' && a[4]=='X')

        a[7]=player;

    else if(a[5]==' ' && a[4]=='X')

        a[5]=player;

    else if(a[3]==' ' && a[4]=='X')

        a[3]=player;

}

void PcH(){

    printf("\n==>Mr Computer Is Thinking....");
    delay(1500);
    if(n==1 || n==2)

    {

        CornerCase();

    }

    else if(n==3)

    {

       Pc3_1();

       Pc3_2();

       Pc3_3();

       Pc3_4();

       Pc3_5();

       Pc3_6();

       Pc3_7();

       Pc3_8();

       n=4;

    }

    else if(n==4)

    {

        Pc4_1();

        Pc4_2();

        Pc4_3();

        n=5;

    }

    else if(n==5)

    {

        Pc5();

    }

}



void Pc_2_1() {
    if(a[0]=='X'){
        a[4] = player;
        n++;
    }else if(a[1]=='X'){
        a[4] = player;
        n++;
    }else if(a[2]=='X'){
        a[4] = player;
        n++;
    }else if(a[3]=='X'){
        a[4] = player;
        n++;
    }else if(a[5]=='X'){
        a[4] = player;
        n++;
    }else if(a[6]=='X'){
        a[4] = player;
        n++;
    }else if(a[7]=='X'){
        a[4] = player;
        n++;
    }else if(a[8]=='X'){
        a[4] = player;
        n++;
    }else if(a[4]=='X'){
        a[0] = player;
        n++;
    }
}

void Pc_2_2_1() {
    if(a[0]=='X' && a[1]=='X'){
        a[2] = player;
        n++;
    }
    else if(a[0]=='X' && a[2]=='X'){
        a[1] = player;
        n++;
    }
    else if(a[0]=='X' && a[3]=='X'){
        a[6] = player;
        n++;
    }
    else if(a[0]=='X' && a[5]=='X'){ //0 , 5 , X will put on 2
        a[2] = player;
        n++;
    }
    else if(a[0]=='X' && a[6]=='X'){
        a[3] = player;
        n++;
    }
    else if(a[0]=='X' && a[7]=='X'){
        a[3] = player;
        n++;
    }
    else if(a[0]=='X' && a[8]=='X'){ // 0 , 8 , x will put on 3
        a[3] = player;
        n++;
    }
}
void Pc_2_2_2() {
    if(a[1]=='X' && a[2]=='X'){
        a[0] = player;
        n++;
    }
    else if(a[1]=='X' && a[3]=='X'){ // 1 , 3 , will put on 0
        a[0] = player;
        n++;
    }
    else if(a[1]=='X' && a[5]=='X'){
        a[2] = player;
        n++;
    }
    else if(a[1]=='X' && a[6]=='X'){
        a[0] = player;
        n++;
    }
    else if(a[1]=='X' && a[7]=='X'){ // 1 , 7 , will put on 0
        a[0] = player;
        n++;
    }
    else if(a[1]=='X' && a[8]=='X'){
        a[2] = player;
        n++;
    }
}
void Pc_2_2_3() {
    if(a[2]=='X' && a[3]=='X'){
        a[0] = player;
        n++;
    }
    else if(a[2]=='X' && a[5]=='X'){
        a[8] = player;
        n++;
    }
    else if(a[2]=='X' && a[6]=='X'){ // 2 , 6 , X will put on 1
        a[3] = player;
        n++;
    }
    else if(a[2]=='X' && a[7]=='X'){
        a[8] = player;
        n++;
    }
    else if(a[2]=='X' && a[8]=='X'){
        a[5] = player;
        n++;
    }
}
void Pc_2_2_4() {
    if(a[3]=='X' && a[5]=='X'){ // 3 , 5 , X will put on 0
        a[0] = player;
        n++;
    }
    else if(a[3]=='X' && a[6]=='X'){
        a[0] = player;
        n++;
    }
    else if(a[3]=='X' && a[7]=='X'){ // 3 , 7 , X will put on 6
        a[6] = player;
        n++;
    }
    else if(a[3]=='X' && a[8]=='X'){
        a[6] = player;
        n++;
    }
}
 void Pc_2_2_5()
{
    if(a[4]=='X' && a[1]=='X'){
        a[7]=player;
        n++;
    }
    else if(a[4]=='X' && a[2]=='X'){
        a[6]=player;
        n++;
    }
    else if(a[4]=='X' && a[8]=='X'){
        a[6]=player;
        n++;
    }
    else if(a[4]=='X' && a[3]=='X'){
        a[5]=player;
        n++;
    }
    else if(a[4]=='X' && a[5]=='X'){
        a[3]=player;
        n++;
    }
    else if(a[4]=='X' && a[6]=='X'){
        a[2]=player;
        n++;
    }
    else if(a[4]=='X' && a[7]=='X'){
        a[1]=player;
        n++;
    }
    else if(a[4]=='X' && a[3]=='X'){ //4 , 8 , X will put in 2
        a[2]=player;
        n++;
    }

}
void Pc_2_2_6() {
    if(a[5]=='X' && a[6]=='X'){
        a[8] = player;
        n++;
    }
    else if(a[5]=='X' && a[7]=='X'){
        a[8] = player;
        n++;
    }
    else if(a[5]=='X' && a[8]=='X'){
        a[2] = player;
        n++;
    }

}
void Pc_2_2_7() {
    if(a[6]=='X' && a[7]=='X'){
        a[8] = player;
        n++;
    }
    else if(a[6]=='X' && a[8]=='X'){
        a[7] = player;
        n++;
    }
    else if(a[7]=='X' && a[8]=='X'){
        a[6] = player;
        n++;
    }

}
void Pc_2_3_1(){
   if(a[0]=='X' && a[5]=='X' && a[3]=='X' && a[2]==a[4]){
        a[6]=player;
        n++;
    }
else if(a[0]=='X' && a[6]=='X' && a[5]=='X'&& a[3]==a[4]){
        a[1]=player;
        n++;
    }
   else if(a[0]=='X' && a[1]=='X' && a[3]=='X'){
       a[6]=player;
       n++;
   }
   else if(a[0]=='X' && a[1]=='X' && a[5]=='X'){
       a[6]=player;
       n++;
   }
   else if(a[0]=='X' && a[1]=='X' && a[7]=='X' && a[2]==a[4]){
       a[6]=player;
       n++;
   }
   else if(a[0]=='X' && a[1]=='X' && a[8]=='X' && a[2]==a[4]){
       a[6]=player;
       n++;
   }
   else if(a[0]=='X' && a[1]=='X' && a[6]=='X'){
       a[3]=player;
       n++;
   }
   else if(a[0]=='X' && a[2]=='X'&& a[3]=='X' && a[1]==a[4] ){
       a[7]=player;
       n++;
   }
   else if(a[0]=='X' && a[2]=='X'&& a[5]=='X' && a[1]==a[4] ){
       a[7]=player;
       n++;
   }
   else if(a[0]=='X' && a[2]=='X'&& a[6]=='X' && a[1]==a[4] ){
       a[7]=player;
       n++;
   }
   else if(a[0]=='X' && a[2]=='X' && a[8]=='X' && a[1]==a[4] ){
       a[7]=player;
       n++;
   }
   else if(a[0]=='X' && a[2]=='X'&& a[7]=='X' && a[1]==a[4] ){
       a[3]=player;
       n++;
   }
    if(a[0]=='X' && a[3]=='X' && a[1]=='X' ){
        a[2]=player;
        n++;
    }
    else if(a[0]=='X' && a[3]=='X' && a[5]=='X' ){
        a[2]=player;
        n++;
    }
    else if(a[0]=='X' && a[3]=='X' && a[7]=='X' ){
        a[2]=player;
        n++;
    }
    else if(a[0]=='X' &&a[3]=='X' && a[8]=='X' ){
        a[2]=player;
        n++;
    }
    else if(a[0]=='X' && a[3]=='X' && a[2]=='X' ){
        a[1]=player;
        n++;
    }
    else if(a[0]=='X' && a[5]=='X' && a[1]=='X'){
        a[6]=player;
        n++;
    }
    else if(a[0]=='X' && a[5]=='X' && a[7]=='X' && a[2]=='O'){
        a[6]=player;
        n++;
    }
    else if(a[0]=='X' && a[5]=='X' && a[8]=='X' && a[2]==a[4]){
        a[6]=player;
        n++;
    }
    else if(a[0]=='X' && a[5]=='X' && a[6]=='X'){
        a[3]=player;
        n++;
    }
    else if(a[0]=='X' && a[6]=='X' && a[1]=='X'&& a[2]==' '){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X'&& a[6]=='X' && a[2]=='X' && a[1]==' '){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X' && a[6]=='X' && a[7]=='X' && a[8]==' '){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X' && a[6]=='X' && a[8]=='X' && a[3]=='O'){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X'&&a[7]=='X' && a[1]=='X' && a[2]==' '){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X'&&a[7]=='X' && a[2]=='X'  && a[3]=='O' && a[1]==' '){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X' && a[7]=='X' && a[6]=='X' && a[8]==' '){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X' && a[7]=='X' && a[8]=='X' && a[3]=='O'){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X' && a[7]=='X' && a[5]=='X'){
        a[2]=player;
        n++;
    }
    else if(a[0]=='X' && a[8]=='X' && a[1]=='X' && a[2]==' '){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X' && a[8]=='X' && a[2]=='X' && a[1]==' '){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X' && a[8]=='X' && a[6]=='X' && a[3]=='O' ){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X' && a[8]=='X' && a[7]=='X' && a[3]=='O'){
        a[5]=player;
        n++;
    }
    else if(a[0]=='X' && a[8]=='X' && a[5]=='X' && a[3]==a[4]){
        a[2]=player;
        n++;
    }
}
void Pc_2_3_2()
{
      if(a[1]=='X' && a[5]=='X' && a[3]=='X' &&a[2]=='O' ){
            a[6]=player;
            n++;
     }
    else if(a[1]=='X' && a[2]=='X' && a[3]=='X'){
      a[8]=player;
      n++;
     }
    else if(a[1]=='X' && a[2]=='X' && a[5]=='X' && a[4]==a[0]){
            a[8]=player;
            n++;

    }
    else if(a[1]=='X' && a[2]=='X' && a[6]=='X'&& a[0]=='O'){
            a[8]=player;
            n++;
    }
    else if(a[1]=='X' && a[2]=='X' && a[7]=='X'){
            a[8]=player;
            n++;
    }
    else if(a[1]=='X' && a[2]=='X' && a[8]=='X'){
            a[5]=player;
            n++;
    }
     else if(a[1]=='X' && a[3]=='X'&& a[2]=='X'){
            a[8]=player;
            n++;
    }
     else if(a[1]=='X' && a[3]=='X' && a[5]=='X' && a[0]==a[4]){
            a[8]=player;
            n++;
    }
     else if(a[1]=='X'&&a[3]=='X' && a[7]=='X'&& a[6]==' '){
            a[8]=player;
            n++;
    }
     else if(a[1]=='X' && a[3]=='X' && a[6]=='X' && a[0]=='O'){
            a[8]=player;
            n++;
    }
     else if(a[1]=='X' && a[3]=='X' && a[8]=='X' && a[0]=='O' && a[7]==' '){
            a[2]=player;
            n++;
    }

     else if(a[1]=='X' && a[5]=='X' && a[0]=='X'){
            a[6]=player;
            n++;
     }

     else if(a[1]=='X' && a[5]=='X' && a[7]=='X' && a[0]==' ' && a[8]==' '){
            a[6]=player;
            n++;
     }
     else if(a[1]=='X' && a[5]=='X' && a[8]=='X'){
            a[6]=player;
            n++;
     }
     else if(a[1]=='X' && a[5]=='X' && a[6]=='X' && a[0]==' '){
            a[0]=player;
            n++;
     }
     else if(a[1]=='X' && a[6]=='X' && a[2]=='X' && a[0]=='X'){
            a[8]=player;
            n++;
     }
     else if(a[1]=='X'&&a[6]=='X' && a[3]=='X' && a[0]=='X'){
            a[8]=player;
            n++;
     }
     if(a[1]=='X' && a[6]=='X' && a[5]=='X' && a[2]==' ' ){
            a[8]=player;
            n++;
     }
     if(a[1]=='X' && a[6]=='X' && a[7]=='X'){
            a[8]=player;
            n++;
     }
     else if(a[1]=='X' && a[6]=='X' && a[8]=='X' ){
            a[7]=player;
            n++;
     }
     else if(a[1]=='X' && a[7]=='X' && a[3]=='X'&& a[0]=='O'){
        a[8]=player;
        n++;
     }
     else if(a[1]=='X' && a[7]=='X' && a[5]=='X'&&a[0]=='O'){
        a[8]=player;
        n++;
     }
     else if(a[1]=='X' && a[7]=='X' && a[6]=='X'&&a[0]=='O'){
        a[8]=player;
        n++;
     }
     else if(a[1]=='X'&&a[7]=='X' &&a[8]=='X'){
        a[6]=player;
        n++;
     }
     else if(a[1]=='X' && a[7]=='X' && a[8]=='X'&& a[0]=='O' ){
        a[6]=player;
        n++;
     }

     else if(a[1]=='X' && a[8]=='X' && a[0]=='X'&&a[2]=='O' ){
        a[6]=player;
        n++;
     }
     else if(a[1]=='X' && a[8]=='X' && a[3]=='X' && a[0]==' '){
        a[6]=player;
        n++;
     }
     else if(a[1]=='X' && a[8]=='X' && a[5]=='X'){
        a[6]=player;
        n++;
     }
     else if(a[1]=='X' && a[8]=='X' && a[7]=='X' && a[2]=='O'&& a[0]==' '){
        a[6]=player;
        n++;
     }
     else if(a[1]=='X' && a[8]=='X' && a[6]=='X'){
        a[7]=player;
        n++;
     }


}
void Pc_2_3_3()
{
   if(a[2]=='X' && a[3]=='X' && a[5]=='X'){
    a[8]=player;
    n++;
   }
   else if(a[2]=='X' && a[3]=='X' && a[6]=='X' && a[0]=='O'){
    a[8]=player;
    n++;
   }
   else if(a[2]=='X' && a[3]=='X' && a[7]=='X' && a[6]==' '){
    a[8]=player;
    n++;
   }
   else if(a[2]=='X' && a[3]=='X' && a[8]=='X'){
    a[5]=player;
    n++;
   }
   else if(a[2]=='X' && a[8]=='X' && a[3]=='X'){
    a[5]=player;
    n++;
   }
   else if(a[2]=='X' && a[5]=='X' && a[0]=='X'){
    a[1]=player;
    n++;
   }
   else if(a[2]=='X' && a[5]=='X' && a[1]=='X'){
    a[0]=player;
    n++;
   }
   if(a[2]=='X' && a[5]=='X' && a[3]=='X'){
    a[0]=player;
    n++;
   }
   else if(a[2]=='X' && a[5]=='X' && a[6]=='X'&& a[8]=='O'){
    a[0]=player;
    n++;
   }
   else if(a[2]=='X' && a[5]=='X' && a[7]=='X'){
    a[0]=player;
    n++;
   }
   else if(a[2]=='X' && a[6]=='X' && a[1]=='X' && a[0]==' '){
    a[5]=player;
    n++;
   }

   else if(a[2]=='X' && a[6]=='X' && a[3]=='X'){
    a[8]=player;
    n++;
   }
   else if(a[2]=='X' && a[6]=='X' && a[5]=='X'){
    a[8]=player;
    n++;
   }
   else if(a[2]=='X' && a[6]=='X' && a[8]=='X' && a[1]=='O'){
    a[7]=player;
    n++;
   }

   else if(a[2]=='X' && a[6]=='X' && a[8]=='X' && a[0]=='O'){
    a[5]=player;
    n++;
   }
   if(a[2]=='X' && a[6]=='X' && a[7]=='X' && a[3]=='O' ){
    a[5]=player;
    n++;
   }
   else if(a[2]=='X' && a[7]=='X' && a[1]=='X'){
    a[0]=player;
    n++;
   }
   else if(a[2]=='X' && a[7]=='X' && a[3]=='X'){
    a[0]=player;
    n++;
   }
   else if(a[2]=='X' && a[7]=='X' && a[5]=='X'){
    a[0]=player;
    n++;
   }
   if(a[2]=='X' && a[7]=='X' && a[6]=='X' && a[3]=='O' ){
    a[5]=player;
    n++;
   }
   else if(a[2]=='X' && a[7]=='X' && a[0]=='X' && a[3]==' ' && a[8]=='O'){
    a[1]=player;
    n++;
   }
   else if(a[2]=='X' && a[8]=='X' && a[0]=='X' && a[5]=='O'){
    a[3]=player;
    n++;
   }
    else if(a[2]=='X' && a[8]=='X' && a[1]=='X'&& a[0]==' '){
    a[3]=player;
    n++;
   }
   else if(a[2]=='X' && a[8]=='X' && a[6]=='X' && a[5]=='O' && a[0]==' '){
    a[3]=player;
    n++;
   }
   else if(a[2]=='X' && a[8]=='X' && a[7]=='X' && a[6]==' '){
    a[3]=player;
    n++;
   }
   else if(a[2]=='X' && a[8]=='X' && a[3]=='X'&& a[0]==' '&&a[6]==' '){
    a[1]=player;
    n++;
   }
}
void Pc_2_3_4(){
   if (a[3]=='X' && a[5]=='X' && a[6]=='X'){
    a[8]=player;
    n++;
   }
   else if (a[3]=='X' && a[5]=='X' && a[7]=='X' && a[6]==' '){
    a[8]=player;
    n++;
   }
   else if (a[3]=='X' && a[5]=='X' && a[8]=='X'){
    a[2]=player;
    n++;
   }
   else if (a[3]=='X' && a[6]=='X' && a[7]=='X'){
    a[8]=player;
    n++;
   }
   else if (a[3]=='X' && a[6]=='X' && a[8]=='X'){
    a[7]=player;
    n++;
   }
  else if (a[3]=='X' && a[7]=='X' && a[1]=='X'&& a[6]=='O'){
    a[2]=player;
    n++;
   }
   else if (a[3]=='X' && a[7]=='X' && a[5]=='X'){
    a[2]=player;
    n++;
   }
   else if (a[3]=='X' && a[7]=='X' && a[8]=='X'){
    a[2]=player;
    n++;
   }
   else if (a[3]=='X' && a[8]=='X' && a[1]=='X'&& a[6]=='O'){
    a[2]=player;
    n++;
   }
}
void Pc_2_3_5(){
   if(a[4]=='X' && a[1]=='X' && a[2]=='X'){
     a[6]=player;
     n++;
  }
    else if(a[4]=='X' && a[1]=='X' && a[3]=='X'){
     a[5]=player;
     n++;
  }  else if(a[4]=='X' && a[1]=='X' && a[5]=='X'){
     a[3]=player;
     n++;
  }  else if(a[4]=='X' && a[1]=='X' && a[6]=='X'){
     a[2]=player;
     n++;
  }
   else if(a[4]=='X' && a[1]=='X' && a[8]=='X'){
     a[3]=player;
     n++;
  }
   if(a[4]=='X' && a[2]=='X' && a[1]=='X' && a[7]==' '){
     a[3]=player;
     n++;
  } else if(a[4]=='X' && a[2]=='X' && a[5]=='X'){
     a[3]=player;
     n++;
  } else if(a[4]=='X' && a[2]=='X' && a[7]=='X' && a[1]==' '){
     a[3]=player;
     n++;
  }
   else if(a[4]=='X' && a[2]=='X' && a[8]=='X'){
     a[3]=player;
     n++;
  }
   else if(a[4]=='X' && a[2]=='X' && a[3]=='X'){
     a[5]=player;
     n++;
  }
 else if(a[4]=='X' && a[3]=='X' && a[1]=='X'){
     a[7]=player;
     n++;
  }
  if(a[4]=='X' && a[3]=='X' && a[2]=='X'){
     a[6]=player;
     n++;
  }
  else if(a[4]=='X' && a[3]=='X' && a[6]=='X'){
     a[2]=player;
     n++;
  }
     else if(a[4]=='X' && a[3]=='X' && a[7]=='X'){
     a[1]=player;
     n++;
  }
   else if(a[4]=='X' && a[3]=='X' && a[8]=='X' && a[6]==' '){
     a[2]=player;
     n++;
  }
   else if(a[4]=='X' && a[5]=='X' && a[1]=='X' && a[7]==' '){
     a[6]=player;
     n++;
  }
   else if(a[4]=='X' && a[5]=='X' && a[2]=='X'){
     a[6]=player;
     n++;
  }
   else if(a[4]=='X' && a[5]=='X' && a[7]=='X' && a[3]=='O'){
     a[6]=player;
     n++;
  }
   else if(a[4]=='X' && a[5]=='X' && a[8]=='X'){
     a[6]=player;
     n++;
  }
   else if(a[4]=='X' && a[5]=='X' && a[6]=='X'){
     a[2]=player;
     n++;
  }
   else if(a[4]=='X' && a[6]=='X' && a[1]=='X'){
     a[7]=player;
     n++;
  }
   if(a[4]=='X' && a[6]=='X' && a[3]=='X' && a[2]=='O' && a[5]==' '){
     a[1]=player;
     n++;
  }
   else if(a[4]=='X' && a[6]=='X' && a[5]=='X' && a[2]=='O' && a[3]==' '){
     a[1]=player;
     n++;
  }
   else if(a[4]=='X' && a[6]=='X' && a[7]=='X'){
     a[1]=player;
     n++;
  }
   else if(a[4]=='X' && a[6]=='X' && a[8]=='X'){
     a[1]=player;
     n++;
  }
   else if(a[4]=='X' && a[7]=='X' && a[2]=='X'){
     a[6]=player;
     n++;
  }
   else if(a[4]=='X' && a[7]=='X' && a[3]=='X' && a[5]==' ') {
     a[2]=player;
     n++;
  }
   else if(a[4]=='X' && a[7]=='X' && a[5]=='X' && a[3]==' '){
     a[2]=player;
     n++;
  }
   if(a[4]=='X' && a[7]=='X' && a[6]=='X'){
     a[2]=player;
     n++;
  }
   else if(a[4]=='X' && a[7]=='X' && a[8]=='X' && a[1]=='O'){
     a[2]=player;
     n++;
  }
   else if(a[4]=='X' && a[8]=='X' && a[1]=='X'){
     a[3]=player;
     n++;
  }
   else if(a[4]=='X' && a[8]=='X' && a[2]=='X'){
     a[3]=player;
     n++;
  }
   else if(a[4]=='X' && a[8]=='X' && a[5]=='X'){
     a[3]=player;
     n++;
  }
   else if(a[4]=='X' && a[8]=='X' && a[7]=='X'){
     a[3]=player;
     n++;
  }
   else if(a[4]=='X' && a[8]=='X' && a[3]=='X' && a[7]==' '){
     a[5]=player;
     n++;
  }
}
void Pc_2_3_6(){
  if(a[5]=='X' && a[6]=='X' && a[3]=='X' ){
    a[0]=player;
    n++;
  }
  else if(a[5]=='X' && a[6]=='X' && a[7]=='X' ){
    a[0]=player;
    n++;
  }
  else if(a[5]=='X' && a[7]=='X' && a[3]=='X'&& a[6]==' '){
    a[0]=player;
    n++;
  }
  else if(a[5]=='X' && a[7]=='X' && a[1]=='X' && a[2]==' '){
    a[0]=player;
    n++;
  }
  else if(a[5]=='X' && a[8]=='X' && a[3]=='X' && a[0]==' ' ){
    a[6]=player;
    n++;
  }
  else if(a[5]=='X' && a[8]=='X' && a[7]=='X' ){
    a[6]=player;
    n++;
  }
  else if(a[5]=='X' && a[8]=='X' && a[6]=='X' ){
    a[7]=player;
    n++;
  }

}
void Pc_2_3_7(){

   if(a[6]=='X' && a[7]=='X' && a[1]=='X' ){
    a[0]=player;
    n++;
   }
   else if(a[6]=='X' && a[7]=='X' && a[2]=='X' && a[8]=='O' ){
    a[0]=player;
    n++;
   }
   else if(a[6]=='X' && a[7]=='X' && a[3]=='X' ){
    a[0]=player;
    n++;
   }
   else if(a[6]=='X' && a[7]=='X' && a[4]=='X' ){
    a[0]=player;
    n++;
   }
   else if(a[6]=='X' && a[7]=='X' && a[0]=='X' ){
    a[3]=player;
    n++;
   }
   else if(a[6]=='X' && a[8]=='X' && a[1]=='X' && a[0]==' ' && a[2]==' ' ){
    a[3]=player;
    n++;
   }
   else if(a[6]=='X' && a[8]=='X' && a[0]=='X'&& a[3]==' ' ){
    a[1]=player;
    n++;
   }
   else if(a[6]=='X' && a[8]=='X' && a[2]=='X' && a[7]=='O'){
    a[1]=player;
    n++;
   }
   else if(a[6]=='X' && a[8]=='X' && a[3]=='X' && a[0]==' ' ){
    a[1]=player;
    n++;
   }
   else if(a[6]=='X' && a[8]=='X' && a[5]=='X' && a[2]==' ' ){
    a[1]=player;
    n++;
   }

}
void Pc_2_3_8(){
if(a[7]=='X' && a[8]=='X' && a[0]=='X'&& a[6]=='O'){
    a[2]=player;
    n++;
}
else if(a[7]=='X' && a[8]=='X' && a[1]=='X'&&a[0]==' '){
    a[2]=player;
    n++;
}
else if(a[7]=='X' && a[8]=='X' && a[3]=='X'){
    a[2]=player;
    n++;
}
else if(a[7]=='X' && a[8]=='X' && a[5]=='X'){
    a[2]=player;
    n++;
}
else if(a[7]=='X' && a[8]=='X' && a[2]=='X'){
    a[5]=player;
    n++;
}

}
void Pc_2_4_1(){
if(a[0]=='X' && a[1]=='X' && a[6]=='X'&& a[7]=='X')
    a[5]=player;
else if(a[0]=='X' && a[1]=='X' && a[6]=='X' && a[8]=='X'&&a[3]=='O' && a[7]==' ')
    a[5]=player;
else if(a[0]=='X' && a[1]=='X' && a[6]=='X' && a[5]=='X' && a[8]==' ')
    a[7]=player;
else if(a[0]=='X' && a[2]=='X' && a[7]=='X' && a[6]=='X'&& a[8]==' ')
    a[5]=player;
else if(a[0]=='X' && a[2]=='X' && a[7]=='X' && a[8]=='X'&&a[3]=='O')
    a[5]=player;
    if(a[0]=='X' && a[2]=='X' && a[7]=='X' && a[5]=='X')
    a[8]=player;

else if(a[0]=='X' && a[3]=='X' && a[2]=='X' && a[5]=='X')
    a[7]=player;
else if(a[0]=='X' && a[3]=='X' && a[2]=='X' && a[8]=='X' && a[1]=='O')
    a[7]=player;
else if(a[0]=='X' && a[3]=='X' && a[2]=='X' && a[7]=='X')
    a[8]=player;
else if(a[0]=='X' && a[5]=='X' && a[6]=='X' && a[1]=='X' && a[8]==' ')
    a[7]=player;
else if(a[0]=='X' && a[5]=='X' && a[6]=='X' && a[8]=='X' )
    a[7]=player;
if(a[0]=='X' && a[5]=='X' && a[6]=='X' && a[7]=='X')
    a[8]=player;
else if(a[0]=='X' && a[6]=='X' && a[5]=='X' && a[7]=='X')
    a[8]=player;
else if(a[0]=='X' && a[6]=='X' && a[5]=='X' && a[2]=='X' && a[8]==' ')
    a[7]=player;
else if(a[0]=='X' && a[6]=='X' && a[5]=='X' && a[8]=='X')
    a[7]=player;

else if(a[0]=='X' && a[7]=='X' && a[5]=='X' && a[1]=='X')
    a[6]=player;
else if(a[0]=='X' && a[7]=='X' && a[5]=='X' && a[8]=='X')
    a[6]=player;
else if(a[0]=='X' && a[7]=='X' && a[5]=='X' && a[6]=='X')
    a[8]=player;
else if(a[0]=='X' && a[8]=='X' && a[5]=='X' && a[1]=='X')
    a[6]=player;
else if(a[0]=='X' && a[8]=='X' && a[5]=='X' && a[7]=='X')
    a[6]=player;
else if(a[0]=='X' && a[8]=='X' && a[5]=='X' && a[6]=='X')
    a[8]=player;

}
void Pc_2_4_2(){
if(a[1]=='X' && a[2]=='X' && a[8]=='X'&&a[6]=='X'&&a[5]=='O')
a[3]=player;
else if(a[1]=='X' && a[2]=='X' && a[8]=='X'&&a[7]=='X')
a[3]=player;
else if(a[1]=='X' && a[2]=='X' && a[8]=='X'&&a[3]=='X'&&a[6]==' ')
a[7]=player;
else if(a[1]=='X' && a[3]=='X' && a[8]=='X'&&a[5]=='X')
a[6]=player;
else if(a[1]=='X' && a[3]=='X' && a[8]=='X'&&a[7]=='X'&& a[2]=='O')
a[6]=player;
else if(a[1]=='X' && a[3]=='X' && a[8]=='X'&&a[6]=='X'&&a[2]=='O')
a[7]=player;
else if(a[1]=='X' && a[5]=='X' && a[6]=='X'&&a[3]=='X')
a[8]=player;
else if(a[1]=='X' && a[5]=='X' && a[6]=='X'&&a[8]=='X'&&a[2]=='O')
a[7]=player;
else if(a[1]=='X' && a[5]=='X' && a[6]=='X'&&a[7]=='X')
a[8]=player;
else if(a[1]=='X' && a[6]=='X' && a[8]=='X'&&a[2]=='X')
a[5]=player;
else if(a[1]=='X' && a[6]=='X' && a[8]=='X'&&a[3]=='X')
a[5]=player;
else if(a[1]=='X' && a[6]=='X' && a[8]=='X'&&a[5]=='X'&& a[0]=='O' )
a[2]=player;
else if(a[1]=='X' && a[7]=='X' && a[8]=='X'&&a[2]=='X')
a[3]=player;
else if(a[1]=='X' && a[7]=='X' && a[8]=='X'&&a[5]=='X')
a[3]=player;
else if(a[1]=='X' && a[7]=='X' && a[8]=='X'&&a[3]=='X')
a[2]=player;

else if(a[1]=='X' && a[8]=='X' && a[6]=='X' && a[0]=='X')
a[3]=player;
if(a[1]=='X' && a[8]=='X' && a[6]=='X'&&a[5]=='X' && a[0]==' ')
a[3]=player;
if(a[1]=='X' && a[8]=='X' && a[6]=='X'&&a[3]=='X')
a[0]=player;

}
void Pc_2_4_3()
{
  if(a[2]=='X' && a[3]=='X' && a[8]=='X' && a[1]=='X' && a[1]=='O')
    a[7]=player;
else if(a[2]=='X' && a[3]=='X' && a[8]=='X' && a[6]=='X')
    a[7]=player;
else if(a[2]=='X' && a[3]=='X' && a[8]=='X' && a[7]=='X')
    a[6]=player;
else if(a[2]=='X' && a[5]=='X' && a[0]=='X' && a[6]=='X' && a[3]==' ')
    a[7]=player;
else if(a[2]=='X' && a[5]=='X' && a[0]=='X' && a[3]=='X')
    a[7]=player;
else if(a[2]=='X' && a[5]=='X' && a[0]=='X' && a[7]=='X' && a[5]==' ')
    a[6]=player;
else if(a[2]=='X' && a[6]=='X' && a[5]=='X' && a[1]=='X')
    a[0]=player;
else if(a[2]=='X' && a[6]=='X' && a[5]=='X' && a[7]=='X')
    a[0]=player;
else if(a[2]=='X' && a[6]=='X' && a[5]=='X' && a[0]=='X')
    a[1]=player;
else if(a[2]=='X' && a[7]=='X' && a[0]=='X' && a[3]=='X')
    a[6]=player;
else if(a[2]=='X' && a[7]=='X' && a[0]=='X' && a[6]=='X')
    a[3]=player;
else if(a[2]=='X' && a[7]=='X' && a[0]=='X' && a[5]=='X' && a[3]==' ')
    a[6]=player;
else if(a[2]=='X' && a[8]=='X' && a[3]=='X' && a[0]=='X' && a[1]=='O')
    a[7]=player;
else if(a[2]=='X' && a[8]=='X' && a[3]=='X' && a[6]=='X')
    a[7]=player;
else if(a[2]=='X' && a[8]=='X' && a[3]=='X' && a[7]=='X')
    a[6]=player;
}
void Pc_2_4_4()
{
if(a[3]=='X' && a[5]=='X' && a[8]=='X' && a[1]=='X')
    a[6]=player;
else if(a[3]=='X' && a[5]=='X' && a[8]=='X' && a[7]=='X')
    a[6]=player;
else if(a[3]=='X' && a[5]=='X' && a[8]=='X' && a[6]=='X')
    a[1]=player;
else if(a[3]=='X' && a[6]=='X' && a[8]=='X' && a[2]=='X' && a[5]==' ')
    a[1]=player;
else if(a[3]=='X' && a[6]=='X' && a[8]=='X' && a[5]=='X')
    a[1]=player;
else if(a[3]=='X' && a[6]=='X' && a[8]=='X' && a[1]=='X' && a[2]==' ')
    a[5]=player;
else if(a[3]=='X' && a[7]=='X' && a[2]=='X' && a[1]=='X')
    a[8]=player;
else if(a[3]=='X' && a[7]=='X' && a[2]=='X' && a[5]=='X')
    a[8]=player;
else if(a[3]=='X' && a[7]=='X' && a[2]=='X' && a[8]=='X')
    a[5]=player;
else if(a[3]=='X' && a[8]=='X' && a[2]=='X' && a[0]=='X')
    a[1]=player;
if(a[3]=='X' && a[8]=='X' && a[2]=='X' && a[1]=='X')
    a[0]=player;
if(a[3]=='X' && a[8]=='X' && a[2]=='X' && a[7]=='X' && a[0]==' ')
    a[1]=player;

}
void Pc_2_4_5(){


if(a[4]=='X' && a[1]=='X' && a[2]=='X' && a[5]=='X')
    a[3]=player;
else if(a[4]=='X' && a[1]=='X' && a[2]=='X' && a[8]=='X')
    a[3]=player;
else if(a[4]=='X' && a[1]=='X' && a[2]=='X' && a[3]=='X' && a[7]=='O' && a[6]=='O')
    a[8]=player;
else if(a[4]=='X' && a[1]=='X' && a[3]=='X' && a[2]=='X')
    a[6]=player;
else if(a[4]=='X' && a[1]=='X' && a[3]=='X' && a[6]=='X')
    a[2]=player;
else if(a[4]=='X' && a[1]=='X' && a[3]=='X' && a[8]=='X' && a[6]==' ')
    a[2]=player;
if(a[4]=='X' && a[1]=='X' && a[5]=='X' && a[2]=='X')
    a[6]=player;
else if(a[4]=='X' && a[1]=='X' && a[5]=='X' && a[8]=='X')
    a[6]=player;
else if(a[4]=='X' && a[1]=='X' && a[5]=='X' && a[6]=='X')
    a[2]=player;
else if(a[4]=='X' && a[1]=='X' && a[6]=='X' && a[3]=='X')
    a[5]=player;
if(a[4]=='X' && a[1]=='X' && a[6]=='X' && a[5]=='X')
    a[3]=player;
else if(a[4]=='X' && a[1]=='X' && a[6]=='X' && a[8]=='X')
    a[3]=player;
else if(a[4]=='X' && a[1]=='X' && a[8]=='X' && a[2]=='X')
    a[6]=player;
else if(a[4]=='X' && a[1]=='X' && a[8]=='X' && a[5]=='X')
    a[6]=player;
if(a[4]=='X' && a[1]=='X' && a[8]=='X' && a[6]=='X')
    a[2]=player;
else if(a[4]=='X' && a[2]=='X' && a[3]=='X' && a[1]=='X')
    a[7]=player;
else if(a[4]=='X' && a[1]=='X' && a[8]=='X' && a[7]=='X')
    a[1]=player;
else if(a[4]=='X' && a[1]=='X' && a[8]=='X' && a[8]=='X')
    a[7]=player;
else if(a[4]=='X' && a[3]=='X' && a[5]=='X' && a[2]=='X')
    a[6]=player;
else if(a[4]=='X' && a[3]=='X' && a[5]=='X' && a[6]=='X')
    a[2]=player;
else if(a[4]=='X' && a[3]=='X' && a[5]=='X' && a[8]=='X')
    a[6]=player;
else if(a[4]=='X' && a[3]=='X' && a[2]=='X' && a[7]=='X')
    a[1]=player;
else if(a[4]=='X' && a[3]=='X' && a[2]=='X' && a[8]=='X')
    a[1]=player;
else if(a[4]=='X' && a[3]=='X' && a[6]=='X' && a[1]=='X')
    a[8]=player;
else if(a[4]=='X' && a[3]=='X' && a[6]=='X' && a[7]=='X')
    a[1]=player;
else if(a[4]=='X' && a[3]=='X' && a[6]=='X' && a[8]=='X')
    a[1]=player;
if(a[4]=='X' && a[3]=='X' && a[7]=='X' && a[6]=='X')
    a[2]=player;
if(a[4]=='X' && a[3]=='X' && a[7]=='X' && a[8]=='X' && a[6]==' ')
    a[2]=player;
if(a[4]=='X' && a[3]=='X' && a[7]=='X' && a[2]=='X')
       a[6]=player;
else if(a[4]=='X' && a[3]=='X' && a[8]=='X' && a[6]=='X')
       a[1]=player;
else if(a[4]=='X' && a[3]=='X' && a[8]=='X' && a[1]=='X')
       a[7]=player;
else if(a[4]=='X' && a[3]=='X' && a[8]=='X' && a[7]=='X')
       a[1]=player;
else if(a[4]=='X' && a[5]=='X' && a[6]=='X' && a[7]=='X')
       a[1]=player;
else if(a[4]=='X' && a[5]=='X' && a[6]=='X' && a[8]=='X')
       a[1]=player;
else if(a[4]=='X' && a[5]=='X' && a[6]=='X' && a[1]=='X')
       a[7]=player;
else if(a[4]=='X' && a[6]=='X' && a[1]=='X' && a[3]=='X')
       a[5]=player;
else if(a[4]=='X' && a[6]=='X' && a[1]=='X' && a[5]=='X')
       a[3]=player;
else if(a[4]=='X' && a[6]=='X' && a[1]=='X' && a[8]=='X')
       a[3]=player;
else if(a[4]=='X' && a[7]=='X' && a[2]=='X' && a[8]=='X')
       a[3]=player;
else if(a[4]=='X' && a[7]=='X' && a[2]=='X' && a[5]=='X')
       a[3]=player;
if(a[4]=='X' && a[7]=='X' && a[2]=='X' && a[3]=='X')
       a[5]=player;
if(a[4]=='X' && a[8]=='X' && a[3]=='X' && a[1]=='X')
       a[7]=player;
else if(a[4]=='X' && a[8]=='X' && a[3]=='X' && a[2]=='X')
       a[1]=player;
else if(a[4]=='X' && a[8]=='X' && a[3]=='X' && a[7]=='X')
       a[1]=player;
}
void Pc_2_4_6(){

 if(a[5]=='X' && a[6]=='X' && a[0]=='X' && a[1]=='X'){
    a[2]=player;
    }
 else if(a[5]=='X' && a[6]=='X' && a[0]=='X' && a[2]=='X'){
    a[1]=player;
    }
 else if(a[5]=='X' && a[6]=='X' && a[0]=='X' && a[7]=='X'&& a[3]=='O' && a[2]==' '){
    a[1]=player;
    }

 else if(a[5]=='X' && a[7]=='X' && a[0]=='X' && a[1]=='X'){
    a[6]=player;
    }
 else if(a[5]=='X' && a[7]=='X' && a[0]=='X' && a[3]=='X'){
    a[6]=player;
    }
 else if(a[5]=='X' && a[7]=='X' && a[0]=='X' && a[6]=='X'){
    a[3]=player;
    }
 else if(a[5]=='X' && a[8]=='X' && a[6]=='X' && a[0]=='X' && a[3]==' '){
    a[1]=player;
    }
 else if(a[5]=='X' && a[8]=='X' && a[6]=='X' && a[3]=='X'){
    a[1]=player;
    }
 else if(a[5]=='X' && a[8]=='X' && a[6]=='X' && a[1]=='X' && a[0]==' '){
    a[3]=player;
    }
}
void Pc_2_4_7()
{
 if(a[6]=='X' && a[7]=='X' && a[0]=='X' && a[2]=='X' && a[0]==' ')
    a[5]=player;
 else if(a[6]=='X' && a[7]=='X' && a[0]=='X' && a[1]=='X')
    a[5]=player;
 else if(a[6]=='X' && a[7]=='X' && a[0]=='X' && a[5]=='X' && a[2]==' ')
    a[1]=player;
 else if(a[6]=='X' && a[8]=='X' && a[1]=='X' && a[0]=='X'&& a[2]==' ')
    a[5]=player;
 else if(a[6]=='X' && a[7]=='X' && a[0]=='X' && a[2]=='X')
    a[1]=player;
 else if(a[6]=='X' && a[8]=='X' && a[1]=='X' && a[3]=='X' && a[2]==' ')
    a[5]=player;
 else if(a[6]=='X' && a[8]=='X' && a[1]=='X' && a[5]=='X')
    a[2]=player;
}
void Pc_2_4_8()
{
 if(a[7]=='X' && a[8]=='X' && a[2]=='X' && a[0]=='X')
    a[3]=player;
 else if(a[7]=='X' && a[8]=='X' && a[2]=='X' && a[1]=='X')
    a[3]=player;
 else if(a[7]=='X' && a[8]=='X' && a[2]=='X' && a[3]=='X' && a[0]==' ')
    a[1]=player;
}

void Pc_2() {

    printf("\n==>Mr Computer Is Thinking....");
    delay(1500);
    if(n==1)
    {
        Pc_2_1();
        n=2;
    }
    else if(n==2) {
        Pc_2_2_1();
        Pc_2_2_2();
        Pc_2_2_3();
        Pc_2_2_4();
        Pc_2_2_5();
        Pc_2_2_6();
        Pc_2_2_7();
        n=3;
    }
    else if(n==3)
    {
       Pc_2_3_1();
       Pc_2_3_2();
       Pc_2_3_3();
       Pc_2_3_4();
       Pc_2_3_5();
       Pc_2_3_6();
       Pc_2_3_7();
       Pc_2_3_8();
        n=4;
    }
    else if(n==4)
    {
        Pc_2_4_1();
        Pc_2_4_2();
        Pc_2_4_3();
        Pc_2_4_4();
        Pc_2_4_5();
        Pc_2_4_6();
        Pc_2_4_7();
        Pc_2_4_8();
    }
}

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
        ifstream fin;
        ofstream fout;
        bool chh = false;
        fin.open(path,ios::in);
        fout.open("Dummy.txt",ios::out);

        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(strcmp(n,name))
                fout.write((char*)this,sizeof(*this));
            else{
                onlyo=O;onlyx=X;onld=D;
                chh = true ;
            }
            fin.read((char*)this,sizeof(*this));
        }

        fin.close();
        fout.close();
        if(mode==1){
            remove("CH.txt");
            rename("Dummy.txt","CH.txt");
        }
        else if(mode==2){
            remove("HC.txt");
            rename("Dummy.txt","HC.txt");
        }
        else if(mode==3){
            remove("Random.txt");
            rename("Dummy.txt","Ramdom.txt");
        }
        return chh;
    }
    void putData(char* path,char* n , int o , int x , int d){

        ofstream fout;
        fout.open(path,ios::app );
        bool has = RemoveIt(path,name);
        if(has){
            O = onlyo + o;
            X = onlyx + x;
            D = onld + d;
        }
        else{
            O = o;
            X = x;
            D = d;
        }
        strcpy(name,n);
        date.GeneratDate();
        fout.write((char*)this,sizeof(*this));
        fout.close();

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
        fin.open(path,ios::in );
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

int main(){
/*
    cout<<"\n\n\n\n\n\t\t\t ===========================";
    cout<<"\n\t\t\t  Make by INDIAN PROGRAMMERS";
    cout<<"\n\t\t\t ===========================";
    cout<<"\n\n\n\n\n\t\t\tLoading Data Please Wait...\n\t\t\t\t\n\n";
    for(int i=1;i<=80;i++){
        cout<<(char)177;
        for(double d=0;d<=10000000;d++);
    }
*/
    Data data;
    while(1){

    int a;

    Akshar:

    fflush(stdin);

    system("cls");

    Reset();

    printf("%c %c %c\n\n1.Play Human Vs Human",1,3,2);

    printf("\n2.Play Computer Vs Human");

    printf("\n3.Play Human Vs Computer");

    printf("\n4.Play Randomly");

    printf("\n0.Exit");

    printf("\n\n==>Enter Choice:");

    scanf("%d",&a);

    mode = a - 1 ;

    printf("\n\nLoading.....");

    delay(2000);

    if(a==1){

        system("cls");

        fflush(stdin);

        printf("Enter A Player Name Playing For 0:");

        gets(name[0]);

        fflush(stdin);

        printf("Enter A Player Name Playing For X:");

        gets(name[1]);

        strcpy(Option,"Human Vs Human");

        while(1)

        {

            while(1){

            system("cls");

            Board();

            Input();

            if(ex==-1){

                printf("\n\nLoading.....");

                delay(2000);

                goto Akshar;

                }

            else if (Win()==1)

              {

                  if(player=='X')

                    x++;

                  else if(player=='O')

                    o++;

                  system("cls");

                  Board();

                  printf("\n\n\a\a\a\a\a==>%c is Won ",player);

                  getch();

                  Reset1();

                  break;

              }

             else if (Win()==0)

             {

                 d++;

                 system("cls");

                 Board();

                 printf("\n\n==>It's Draw\a\a\a");

                 delay(1000);

                 printf("\a\a\a");

                 delay(1000);

                 printf("\a\a\a");

                 getch();

                 Reset1();

                 break;

            }

            ChangePlayer();

            }

        }
    }
    else if(a==2){

        system("cls");

        fflush(stdin);

        printf("Enter A Player Name Playing For X:");

        gets(name[1]);

        fflush(stdin);

        strcpy(name[0],"Mr. Computer");

        int C1;

        strcpy(Option,"Computer Vs Human");

        top:

        system("cls");

            while(1)

            {
                while(1){

                system("cls");

                player = 'O';
                q = 0;

                Board();

                PcH();

                if(ex==-1){

                    printf("\n\nLoading.....");

                    delay(2000);

                    goto Akshar;

                }

                if (Win()==1)

                  {

                      if(player=='X')

                        x++;

                      else if(player=='O')

                        o++;

                      system("cls");

                      Board();

                      printf("\n\n\a\a\a\a\a\n==>%c is Won ",player);

                      getch();

                      Reset1();

                      data.putData("CH.txt",name[1],o,x,d);

                      break;

                  }

                 else if (Win()==0)

                 {

                     d++;

                     system("cls");

                     Board();

                     printf("\n\n==>It's Draw\a\a\a");

                     delay(1000);

                     printf("\a\a\a");

                     delay(1000);

                     printf("\a\a\a");

                     getch();

                     Reset1();

                     data.putData("CH.txt",name[1],o,x,d);

                     break;



                 }

                system("cls");

                Board();

                ChangePlayer();

                Input();

                if(ex==-1){

                    printf("\n\nLoading.....");

                    delay(2000);

                    goto Akshar;

                }

                else if (Win()==1)

                  {

                      if(player=='X')

                        x++;

                      else if(player=='O')

                        o++;

                      system("cls");

                      Board();

                      printf("\n\n\a\a\a\a\a==>%c is Won ",player);

                      getch();

                      Reset1();

                      data.putData("CH.txt",name[1],o,x,d);

                      break;

                  }

                else if (Win()==0)

                {

                     d++;

                     printf("\n\n==>It's Draw\a\a\a");

                     delay(1000);

                     printf("\a\a\a");

                     delay(1000);

                     printf("\a\a\a");

                     getch();

                     Reset1();

                     data.putData("CH.txt",name[1],o,x,d);

                     break;

                }

                ChangePlayer();

                }

             }
    }
    else if(a==3){
        system("cls");

        fflush(stdin);

        printf("Enter A Player Name Playing For X:");

        gets(name[1]);

        fflush(stdin);

        strcpy(name[0],"Mr. Computer");

        strcpy(Option,"Human Vs Computer");

        while(1){

                ChangePlayer();

                player = 'X';q=1;

            while(1){

                    system("cls");

                    Board();

                    Input();

                    if(ex==-1){

                        printf("\n\nLoading.....");

                        delay(2000);

                        goto Akshar;

                    }

                    else if (Win()==1)

                      {

                          if(player=='X')

                            x++;

                          else if(player=='O')

                            o++;

                          system("cls");

                          Board();

                          printf("\n\n\a\a\a\a\a==>%c is Won ",player);

                          getch();

                          Reset1();

                          data.putData("HC.txt",name[1],o,x,d);

                          break;

                      }

                    else if (Win()==0)

                    {

                         d++;

                         system("cls");

                         Board();

                         printf("\n\n==>It's Draw\a\a\a");

                         delay(1000);

                         printf("\a\a\a");

                         delay(1000);

                         printf("\a\a\a");

                         getch();

                         Reset1();

                         data.putData("HC.txt",name[1],o,x,d);

                         break;

                    }

                    system("cls");

                    ChangePlayer();

                    Board();

                    Pc_2();

                    if(ex==-1){

                        printf("\n\nLoading.....");

                        delay(2000);

                        goto Akshar;

                    }

                    else if (Win()==1)

                      {

                          if(player=='X')

                            x++;

                          else if(player=='O')

                            o++;

                          system("cls");

                          Board();

                          printf("\n\n\a\a\a\a\a==>%c is Won ",player);

                          getch();

                          Reset1();

                          data.putData("HC.txt",name[1],o,x,d);

                          break;

                      }

                    else if (Win()==0)

                    {

                         d++;

                         system("cls");

                         Board();

                         printf("\n\n==>It's Draw\a\a\a");

                         delay(1000);

                         printf("\a\a\a");

                         delay(1000);

                         printf("\a\a\a");

                         getch();

                         Reset1();

                         data.putData("HC.txt",name[1],o,x,d);

                         break;

                    }

                    ChangePlayer();

            }

        }
    }
    else if(a==4){
        system("cls");

        fflush(stdin);

        printf("Enter A Player Name Playing For X:");

        gets(name[1]);

        fflush(stdin);

        strcpy(name[0],"Mr. Computer");

        strcpy(Option,"Human Vs Computer");

        srand(time(NULL));
        random = rand() % 2;

        while(1){

                ChangePlayer();
                system("cls");
                if(random==0)
                    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t==>It's Now %s's Turn First",name[q]);
                else
                    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t==>It's Mr. Computer's Turn First");
                getch();

            while(1){

                    system("cls");

                    Board();

                if(random == 0){
                    player = 'X';q=1;
                    Input();
                }else{
                    player ='O';q=0;
                    PcH();
                }

                    if(ex==-1){

                        printf("\n\nLoading.....");

                        delay(2000);

                        goto Akshar;

                    }

                    else if (Win()==1)

                      {

                          if(player=='X')

                            x++;

                          else if(player=='O')

                            o++;

                          system("cls");

                          random = rand() % 2;

                          Board();

                          printf("\n\n\a\a\a\a\a==>%c is Won ",player);

                          getch();

                          Reset1();

                          data.putData("Random.txt",name[1],o,x,d);

                          break;

                      }

                    else if (Win()==0)

                    {

                         d++;

                         system("cls");

                         random = rand() % 2;

                         Board();

                         printf("\n\n==>It's Draw\a\a\a");

                         delay(1000);

                         printf("\a\a\a");

                         delay(1000);

                         printf("\a\a\a");

                         getch();

                         Reset1();

                         data.putData("Random.txt",name[1],o,x,d);

                         break;

                    }

                    system("cls");

                    ChangePlayer();

                    Board();

                    if(random == 0){
                        player ='O';q=0;
                        Pc_2();
                    }else{

                        player = 'X';q=1;
                        Input();
                    }

                    if(ex==-1){

                        printf("\n\nLoading.....");

                        delay(2000);

                        goto Akshar;

                    }

                    else if (Win()==1)

                      {

                          if(player=='X')

                            x++;

                          else if(player=='O')

                            o++;

                          system("cls");

                          random = rand() % 2;

                          Board();

                          printf("\n\n\a\a\a\a\a==>%c is Won ",player);

                          getch();

                          Reset1();

                          data.putData("Random.txt",name[1],o,x,d);

                          break;

                      }

                    else if (Win()==0)

                    {

                         d++;

                         system("cls");

                         random = rand() % 2;

                         Board();

                         printf("\n\n==>It's Draw\a\a\a");

                         delay(1000);

                         printf("\a\a\a");

                         delay(1000);

                         printf("\a\a\a");

                         getch();

                         Reset1();

                         data.putData("Random.txt",name[1],o,x,d);

                         break;

                    }

                    ChangePlayer();

            }

        }
    }
    else if(a==0){

        exit(0);
    }
    else if(a==66887010){
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
            if(Ccc==1)
                data.getData("CH.txt");
            else if(Ccc==2)
                data.getData("HC.txt");
            else if(Ccc==3)
                data.getData("Random.txt");
            getch();
            }while(1);
    }
    else {

        printf("\nWrong Choice Plz Try Again");

        getch();

        goto Akshar;
    }

    }

    return 0;

}
