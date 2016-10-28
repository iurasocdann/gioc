#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;

struct player {
  int x;
  int y;
}p;

char a[100][100]={ "#########0##########"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"0                  #"
                  ,"#                  #"
                  ,"#                  0"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"################0###"};
char player = '@';

bool findp(){
   for(int i=0;i<16;i++)
      for(int j=0;j<20;j++){
         if (a[i][j]=='@'){
            p.x = i;
            p.y = j;
            return 1;
         }
      }
      return 0;
}

int validare(int i){
   switch (i){
   case 1:
      if(a[p.x-1][p.y]=='#'){
         return 0;
      }
      else if (a[p.x-1][p.y]=='0') return 2;
      break;
   case 2:
   if(a[p.x+1][p.y]=='#'){
      return 0;
   }
   else if (a[p.x+1][p.y]=='0') return 2;
   break;
   case 3:
   if(a[p.x][p.y-1]=='#'){
      return 0;
   }
   else if (a[p.x][p.y-1]=='0') return 2;
   break;
   case 4:
   if(a[p.x][p.y+1]=='#'){
      return 0;
   }
   else if (a[p.x][p.y+1]=='0') return 2;
   break;
   }
   return 1;
}
void afisare()
{
   for(int i=0;i<16;i++)
      {for(int j=0;j<20;j++)
         cout<<a[i][j];
    cout<<endl;}
}

void start()
{
   a[2][3]=player;
   afisare();
}

void up()
{
   if(findp()){
      if(validare(1)==1){
      char aux;
      system("cls");
      aux = a[p.x-1][p.y];
      a[p.x-1][p.y] = a[p.x][p.y];
      a[p.x][p.y] = aux;
      afisare();
   }
   else if (validare(1)==2) {cout<<"Garda crede ca ne-a luat banii de cuie"; exit(1) ;
   }
   else {cout<<"lul";}
   }
   else {
      cout<<"fuck";
      exit(0);
   }
}
void dw()
{
   if(findp()){
      if(validare(2)==1){
      char aux;
      system("cls");
      aux = a[p.x+1][p.y];
      a[p.x+1][p.y] = a[p.x][p.y];
      a[p.x][p.y] = aux;
      afisare();
   }
   else if (validare(2)==2) {cout<<"Garda crede ca poate intra cu Loganul pe geam"; exit(1) ;
   }
   else {cout<<"lul";}
   }
   else {
      cout<<"fuck";
      exit(0);
   }
}
void left()
{
   if(findp()){
      if(validare(3)==1){
      char aux;
      system("cls");
      aux = a[p.x][p.y-1];
      a[p.x][p.y-1] = a[p.x][p.y];
      a[p.x][p.y] = aux;
      afisare();
   }
   else if (validare(3)==2) {cout<<"Garda crede ca ne-a furat strada"; exit(1) ;
   }
   else {cout<<"lul";}
   }
   else {
      cout<<"fuck";
      exit(0);
   }
}
void right()
{
   if(findp()){
      if(validare(4)==1){
      char aux;
      system("cls");
      aux = a[p.x][p.y+1];
      a[p.x][p.y+1] = a[p.x][p.y];
      a[p.x][p.y] = aux;
      afisare();
   }
   else if (validare(4)==2) {cout<<"Garda crede ca maria e o fata"; exit(1) ;
   }
   else {cout<<"lul";}
   }
   else {
      cout<<"fuck";
      exit(0);
   }
}

int main()
{
   start();
    int c = 0;
    while(1)
    {
        c = 0;

        switch((c=getch())) {
        case KEY_UP:
            up();
            break;
        case KEY_DOWN:
            dw();
            break;
        case KEY_LEFT:
            left();
            break;
        case KEY_RIGHT:
            right();
            break;
        default:
            break;
        }

    }
    return 0;
}
