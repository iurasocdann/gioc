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

char a[100][100]={ "####################"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"#                  #"
                  ,"####################"};
char player = '@';

bool findp()
{
   for(int i=0;i<20;i++)
      for(int j=0;j<20;j++){
         if (a[i][j]=='@'){
            p.x = i;
            p.y = j;
            return 1;
         }
      }
      return 0;
}
bool validare(int i)
{
   switch (i){
   case 1:
      if(a[p.x-1][p.y]=='#'){
            return 0;
        }
      break;
   case 2:
       if(a[p.x+1][p.y]=='#'){
          return 0;
       }
       break;
   case 3:
       if(a[p.x][p.y-1]=='#'){
          return 0;
       }
       break;
   case 4:
       if(a[p.x][p.y+1]=='#'){
          return 0;
       }
       break;
   }
   return 1;
}
void afisare()
{
   for(int i=0;i<20;i++)
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
      if(validare(1)){
      char aux;
      system("cls");
      aux = a[p.x-1][p.y];
      a[p.x-1][p.y] = a[p.x][p.y];
      a[p.x][p.y] = aux;
      afisare();
   }
   else {cout<<"lul";}
   }
   else {
      cout<"lol";
      exit(0);
   }
}
void dw()
{
   if(findp()){
      if(validare(2)){
      char aux;
      system("cls");
      aux = a[p.x+1][p.y];
      a[p.x+1][p.y] = a[p.x][p.y];
      a[p.x][p.y] = aux;
      afisare();
   }
   else {cout<<"lul";}
   }
   else {
      cout<<"Lol";
      exit(0);
   }
}
void left()
{
   if(findp()){
      if(validare(3)){
      char aux;
      system("cls");
      aux = a[p.x][p.y-1];
      a[p.x][p.y-1] = a[p.x][p.y];
      a[p.x][p.y] = aux;
      afisare();
   }
   else {cout<<"lul";}
   }
   else {
      cout<<"lol";
      exit(0);
   }
}
void right()
{
    if(findp()){
        if(validare(4))
        {
            char aux;
            system("cls");
            aux = a[p.x][p.y+1];
            a[p.x][p.y+1] = a[p.x][p.y];
            a[p.x][p.y] = aux;
            afisare();
        }
        else {cout<<"lul";}
   }
   else {
      cout<<"lol";
      exit(0);
   }
}

int main()
{
    start();
    while(1)
    {
        char c = 0;
        switch(c=getch()){
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
