#include <bits/stdc++.h>
using namespace std;

void fill_bord_with(char arr[][8])//fill board with # ;
{
for(int i=0;i<8;i++)
   for(int j=0;j<8;j++)
    arr[i][j]='-';
}
void output_bord(char arr[][8])//output board ;
{
cout<<"The board \n";
 for(int i=0;i<8;i++){
   for(int j=0;j<8;j++)
    cout<<arr[i][j]<<" ";
    cout<<endl;}
}
void output_avliable_position(char arr[][8])//output avaliable points ;
{
 cout<<"Avaliable Positions : \n";
 for(int i=7;i>=0;i--){
   for(int j=0;j<8;j++)
    {
     if(i==7&&arr[i][j]=='-')
          cout<<"("<<8-i<<","<<j+1<<")"<<"   ";
     else if(i<7&&arr[i][j]=='-'&&arr[i+1][j]!='-')
          cout<<"("<<8-i<<","<<j+1<<")"<<"   ";
    }
   }
 cout<<endl<<endl;
}

void read_x_y(char bord[][8],short x,short y,bool p1,bool p2)
{
  if(p1&&bord[8-x][--y]=='-')bord[8-x][y]='O';
  else if(p2&&bord[8-x][--y]=='-' )bord[8-x][y]='Z';
}

bool correct_points(char arr[][8],short x,short y)
{
   if(x==1&&arr[7][--y]=='-')return true;
   if(arr[8-x][--y]=='-'&&arr[9-x][y]!='-')return true;

 return false;
}

bool connect_four(char bord[][8],char s)
{//fn to win
  for(int i=7;i>=0;i--)
    for(int j=0;j<8;j++)
  {
   if(bord[i][j]==s&&bord[i-1][j]==s&&bord[i-2][j]==s&&bord[i-3][j]==s)//left
        return true;
   if(bord[i][j]==s&&bord[i+1][j]==s&&bord[i+2][j]==s&&bord[i+3][j]==s)//right
        return true;
   if(bord[i][j]==s&&bord[i][j-1]==s&&bord[i][j-2]==s&&bord[i][j-3]==s)//dwon
        return true;
   if(bord[i][j]==s&&bord[i][j+1]==s&&bord[i][j+2]==s&&bord[i][j+3]==s)//up
        return true;
   if(bord[i][j]==s&&bord[i+1][j+1]==s&&bord[i+2][j+2]==s&&bord[i+3][j+3]==s)//up-right
        return true;
   if(bord[i][j]==s&&bord[i+1][j-1]==s&&bord[i+2][j-2]==s&&bord[i+3][j-3]==s)//up-left
        return true;
  if(bord[i][j]==s&&bord[i-1][j-1]==s&&bord[i-2][j-2]==s&&bord[i-3][j-3]==s)//dwon-left
        return true;
   if(bord[i][j]==s&&bord[i-1][j+1]==s&&bord[i-2][j+2]==s&&bord[i-3][j+3]==s)//dwon-right
        return true;
  }

return false;
}
void convert_connect(char bord[][8],char s){
    for(int i=7;i>=0;i--)
    for(int j=0;j<8;j++)
      {
       if(bord[i][j]==s&&bord[i-1][j]==s&&bord[i-2][j]==s&&bord[i-3][j]==s)//left
            {bord[i][j]='+';bord[i-1][j]='+';bord[i-2][j]='+';bord[i-3][j]='+';}

       if(bord[i][j]==s&&bord[i+1][j]==s&&bord[i+2][j]==s&&bord[i+3][j]==s)//right
            {bord[i][j]='+';bord[i+1][j]='+';bord[i+2][j]='+';bord[i+3][j]='+';}

       if(bord[i][j]==s&&bord[i][j-1]==s&&bord[i][j-2]==s&&bord[i][j-3]==s)//dwon
            {bord[i][j]='+';bord[i][j-1]='+';bord[i][j-2]='+';bord[i][j-3]='+';}//dwon

       if(bord[i][j]==s&&bord[i][j+1]==s&&bord[i][j+2]==s&&bord[i][j+3]==s)//up
            {bord[i][j]='+';bord[i][j+1]='+';bord[i][j+2]='+';bord[i][j+3]='+';}

       if(bord[i][j]==s&&bord[i+1][j+1]==s&&bord[i+2][j+2]==s&&bord[i+3][j+3]==s)//up-right
            {bord[i][j]='/';bord[i+1][j+1]='/';bord[i+2][j+2]='/';bord[i+3][j+3]='/';}//up-right

       if(bord[i][j]==s&&bord[i+1][j-1]==s&&bord[i+2][j-2]==s&&bord[i+3][j-3]==s)//up-left
            {bord[i][j]='\\';bord[i+1][j-1]='\\';bord[i+2][j-2]='\\';bord[i+3][j-3]='\\';}//up-left

       if(bord[i][j]==s&&bord[i-1][j-1]==s&&bord[i-2][j-2]==s&&bord[i-3][j-3]==s)//dwon-left
            {bord[i][j]='\\';bord[i-1][j-1]='\\';bord[i-2][j-2]='\\';bord[i-3][j-3]='\\';}//dwon-left

       if(bord[i][j]==s&&bord[i-1][j+1]==s&&bord[i-2][j+2]==s&&bord[i-3][j+3]==s)//dwon-right
            {bord[i][j]='/';bord[i-1][j+1]='/';bord[i-2][j+2]='/';bord[i-3][j+3]='/';}//dwon-right
    }
}

void Win_player(char bord[][8],char s,bool p1,bool p2,string player1,string player2)
{
    if(connect_four(bord,s)&&p1){
       //convert_connect(bord,s);
       output_bord(bord);
       cout<<"Player N1 is Win\n"<<"Congratulation! : "<<player1<<endl;
    }
    if(connect_four(bord,s)&&p2){
       //convert_connect(bord,s);
       output_bord(bord);
       cout<<"Player N2 is Win\n"<<"Congratulation! : "<<player2<<endl;
    }
}

int main()
{
char bord[8][8];
fill_bord_with(bord);//fill the board wwith # ;

string player1,player2;
cout<<"Enter the name of Player N1 : ";
getline(cin,player1);
cout<<"\nEnter the name of Player N2 : ";
getline(cin,player2);
cout<<endl;
bool p1=true,p2=false;//for turns
char s;
short count=0;
while(true){
        count++;
    output_bord(bord); //output the board
    output_avliable_position(bord); //output avaliable positions ;
    short x,y;
    if(p1)cout<<"Player N1 turn ('O'): ";
    else cout<<"Player N2 turn ('Z'): ";
    cin>>x>>y;
    if(correct_points(bord,x,y))// check the points ;
    {
        read_x_y(bord,x,y,p1,p2);
    }
    else if(!correct_points(bord,x,y))
    {
     while(true){
         cout<<"Invalid Input ,please try again : ";
         cin>>x>>y;
         if(correct_points(bord,x,y))// check the points ;
            {read_x_y(bord,x,y,p1,p2);break;}
       }//end while
    }// end else
    if(p1)s='O';else s='Z';

    Win_player(bord,s,p1,p2,player1,player2);

    if(p1){p1=false,p2=true;}//change the players
    else{p1=true,p2=false;}

    if(count==64)
    {cout<<"OOPS! No Win!";break;}
}//end while



    return 0;
}
