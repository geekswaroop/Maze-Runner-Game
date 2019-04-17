#include <iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

const char WIDTH = 74, HEIGHT = 24; //the dimensions of the fixed maze which is given
unsigned char player ='0'; //this will be the symbol of the player

int posX,posY;
unsigned char action;           //variable used to take input from user

void playerAction();                //logic function used to change the maze depending on the input from the user

struct trolls
{
    char symbol;
    bool active;
    int x;
    int y;
    int prevx;
    int prevy;
};
trolls enemy1;
trolls enemy2;
trolls enemy3;
unsigned char maze[HEIGHT][WIDTH]={
{"#########################################################################"},
{"#   #               #               #           #                   #   #"},
{"#   #   #########   #   #####   #########   #####   #####   #####   #   #"},
{"#               #       #   #           #           #   #   #       #   #"},
{"#########   #   #########   #########   #####   #   #   #   #########   #"},
{"#       #   #               #           #   #   #   #   #           #   #"},
{"#   #   #############   #   #   #########   #####   #   #########   #   #"},
{"#   #               #   #   #       #           #           #       #   #"},
{"#   #############   #####   #####   #   #####   #########   #   #####   #"},
{"#           #       #   #       #   #       #           #   #           #"},
{"#   #####   #####   #   #####   #   #########   #   #   #   #############"},
{"#       #       #   #   #       #       #       #   #   #       #       #"},
{"#############   #   #   #   #########   #   #####   #   #####   #####   #"},
{"#           #   #           #       #   #       #   #       #           #"},
{"#   #####   #   #########   #####   #   #####   #####   #############   #"},
{"#   #       #           #           #       #   #   #               #   #"},
{"#   #   #########   #   #####   #########   #   #   #############   #   #"},
{"#   #           #   #   #   #   #           #               #   #       #"},
{"#   #########   #   #   #   #####   #########   #########   #   #########"},
{"#   #       #   #   #           #           #   #       #               #"},
{"#   #   #####   #####   #####   #########   #####   #   #########   #   #"},
{"#   #                   #           #               #               #   #"},
{"# X #####################################################################"} };//hardoded maze


int main()
{
        while(1)        //a while loop till a proper player position is found
        {
          srand(time(0));
          posX=rand()%73;//while using rand() function, use appropriate libraries
          posY=rand()%23;
          if(maze[posY][posX]=='#')
            continue;
          else
            break;
        }

         action='p';     //initializing with a dummy variable
   while(action!='Q'||'q')
   {
       cout<<"Control player using WASD"<<endl;
       cout<<endl;
       maze[posY][posX]=player;

       for(int y=0;y<HEIGHT;y++)            //prints the maze each time the input is not q
       {
           cout<<endl;
           for(int x=0;x<WIDTH;x++)
           {
               cout<<maze[y][x];
           }

       }


       //1st troll
           //trolls enemy1;
           enemy1.symbol='Z';
           enemy1.active=true;

           while(1)        //a while loop till a proper troll position is found
        {
          srand(time(0));
          enemy1.x=rand()%73;//while using rand() function, use appropriate libraries
          enemy1.y=rand()%23;
          if(maze[enemy1.y][enemy1.x]=='#')
            continue;
          else
            break;
        }
           maze[enemy1.y][enemy1.x]=enemy1.symbol;
           enemy1.prevx=enemy1.x;
           enemy1.prevy=enemy1.y;
          // maze[enemy1.prevy][enemy1.prevx]=' ';

            //2nd troll
          
           enemy2.symbol='Z';
           enemy2.active=true;

           while(1)        //a while loop till a proper troll position is found
        {
          srand(time(0));
          enemy2.x=rand()%73;//while using rand() function, use appropriate libraries
          enemy2.y=rand()%23;
          if(maze[enemy2.y][enemy2.x]=='#')
            continue;
          else
            break;
        }
           maze[enemy2.y][enemy2.x]=enemy2.symbol;
           enemy2.prevx=enemy2.x;
           enemy2.prevy=enemy2.y;

          
                //3rd troll
         
           enemy3.symbol='Z';
           enemy3.active=true;

           while(1)        //a while loop till a proper troll position is found
        {
          srand(time(0));
          enemy3.x=rand()%73;//while using rand() function, use appropriate libraries
          enemy3.y=rand()%23;
          if(maze[enemy3.y][enemy3.x]=='#')
            continue;
          else
            break;
        }
           maze[enemy3.y][enemy3.x]=enemy3.symbol;
           enemy3.prevx=enemy3.x;
           enemy3.prevy=enemy3.y;



       playerAction();


       if (maze[posY][posX]=='X')
       {cout<<"You did it!!"<<endl; return 0;}
   }
   return 0;
}
void playerAction()
{
    printf("\nAction: ");
    scanf("%c",&action);
    int prevposX=posX;  //variables which keep track of the previous position so as to put a space instead of it
    int prevposY=posY;
    unsigned char space={32};
    switch(action)  //switch case to toggle between WASD
    {
        case 'a':{
                if(maze[posY][posX-1]!='#' && posX-1<74 && posY<24 )
                {
                    posX--;
                    maze[prevposY][prevposX]=space;
                     maze[enemy1.prevy][enemy1.prevx]=' ';
					 maze[enemy2.prevy][enemy2.prevx]=' ';
					 maze[enemy3.prevy][enemy3.prevx]=' ';
                }
                    system("cls");
                        break;

        }
        case 'd':{
                if(maze[posY][posX+1]!='#'&& posX<74 && posY+1<24)
                {
                    posX++;
                    maze[prevposY][prevposX]=space; maze[enemy1.prevy][enemy1.prevx]=' ';
					maze[enemy2.prevy][enemy2.prevx]=' ';
					maze[enemy3.prevy][enemy3.prevx]=' ';
				}
                    system("cls");
                        break;

        }
        case 's':{
                if(maze[posY+1][posX]!='#'&& posX<74 && posY+1<24)
                {
                    posY++;
                    maze[prevposY][prevposX]=space; maze[enemy1.prevy][enemy1.prevx]=' ';
					maze[enemy2.prevy][enemy2.prevx]=' ';
					maze[enemy3.prevy][enemy3.prevx]=' ';
				}
                    system("cls");
                        break;

        }
        case 'w':{
                if(maze[posY-1][posX]!='#'&& posX<74 && posY-1<24)
                {
                    posY--;
                    maze[prevposY][prevposX]=space; maze[enemy1.prevy][enemy1.prevx]=' ';
					maze[enemy2.prevy][enemy2.prevx]=' ';
					maze[enemy3.prevy][enemy3.prevx]=' ';
				}
                    system("cls");
                        break;

        }
        default:
            {
                printf("incorrect action\n");
                break;
            }


    }

}
