#include<iostream>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
using namespace std;
char startgame()
{
	char P1_marker;
	cout<<endl<<"\t\t\t\t\t   TIC   TAC  TOE  GAME "<<endl<<endl;
	cout<<"\t\t\t\t\t\t    |     |    "<<endl;
	cout<<"\t\t\t\t\t\t  1 |  2  |  3 "<<endl;
	cout<<"\t\t\t\t\t\t____|_____|____"<<endl;
	cout<<"\t\t\t\t\t\t    |     |    "<<endl;
	cout<<"\t\t\t\t\t\t  4 |  5  |  6 "<<endl;
	cout<<"\t\t\t\t\t\t____|_____|____"<<endl;
	cout<<"\t\t\t\t\t\t    |     |    "<<endl;	
	cout<<"\t\t\t\t\t\t  7 |  8  |  9 "<<endl;
	cout<<"\t\t\t\t\t\t    |     |    "<<endl;
	cout<<endl<<"Player one (you)! Choose your marker (O or X) to play the game"<<endl;
  	cin>>P1_marker;
  	return P1_marker;
}
int  get_user_input()
{
	int slot;
	cout<<endl<<" It's  player 1 (your)'s   turn "<<endl;
	cout<<"Enter your slot from(1 to 9) ";
    cin>>slot;
    cout<<endl;
	while(slot<1 || slot > 9)
      {
  		cout<<"This is invalid input,please try another in the range of 1 to 9 "<<endl;
	    cin>>slot;	
      }
    return slot;
}
void display_countdown()
{

    int sec=5;
	cout<<endl<<"COUNTDOWN"<<endl;
	sleep(1);
	for(int i = sec; i>0; i--)
	  {
	 	cout<<"   "<<i<< " second left "<<endl;
		sleep(1);
		system("CLS");
	  }
}

int  get_comp_input ()
{
	int slot;
	cout<<" It's   player 2 (computer)'s  turn "<<endl<<endl;
  	srand(time(0));
    slot=(rand()%9)+1;
	return slot;
}
void  place_marker(int &row,int &col,int slot)
{
	row=slot/3;
	if(slot%3==0)
	 {
		row=(slot/3)-1;
		col=2;
     }
	else
	 {
		col=(slot%3)-1;
	 }
}

void update_array(char grid[][3],char current_marker,int slot,bool user_turn)
{
	int row=0,col=0;
    place_marker(row,col,slot);
    if(grid[row][col] != 'x' &&  grid[row][col] != 'X' &&  grid[row][col] != 'o' &&  grid[row][col] != 'O')
    {
    	 grid[row][col]=current_marker;
	}
	else
	{
	   cout<<"This slot is occupied"<<endl;
 	   while(grid[row][col] == 'x' ||  grid[row][col] == 'X' ||  grid[row][col] == 'o' ||  grid[row][col] == 'O')
	    {
		  if(user_turn==true)
		   {
		   	    cout<<"Oops ! Please Enter another "<<endl;
	            slot=get_user_input();
			  	place_marker(row,col,slot);
		   }
		  else 
		   {
			    srand(time(0));
	            slot=(rand()%9)+1;
			    place_marker(row,col,slot);
			    if(grid[row][col]!= 'x' &&  grid[row][col] != 'X' &&  grid[row][col] != 'o' &&  grid[row][col] != 'O')
			     {
			          display_countdown();	
				 }
	       }
        }
       grid[row][col]=current_marker;
    }

}

void display_array( char grid[][3])
{	
    cout<<"\t\t\t SAMPLE INPUT  \t\t\t\t\tPLAYERS  ENTERED HERE   "<<endl<<endl;																		
	cout<<"\t\t\t    |     |    \t\t\t\t\t    |     |    "<<endl;
	cout<<"\t\t\t  1 |  2  |  3 \t\t\t\t\t  "<<grid[0][0]<<" |  "<<grid[0][1]<<"  |  "<<grid[0][2]<<endl;
	cout<<"\t\t\t____|_____|____\t\t\t\t\t____|_____|____"<<endl;
	cout<<"\t\t\t    |     |    \t\t\t\t\t    |     |    "<<endl;
	cout<<"\t\t\t  4 |  5  |  6 \t\t\t\t\t  "<<grid[1][0]<<" |  "<<grid[1][1]<<"  |  "<<grid[1][2]<<endl;
	cout<<"\t\t\t____|_____|____\t\t\t\t\t____|_____|____"<<endl;
	cout<<"\t\t\t    |     |    \t\t\t\t\t    |     |    "<<endl;		
	cout<<"\t\t\t  7 |  8  |  9 \t\t\t\t\t  "<<grid[2][0]<<" |  "<<grid[2][1]<<"  |  "<<grid[2][2]<<endl;
	cout<<"\t\t\t    |     |    \t\t\t\t\t    |     |    "<<endl;												   
																	
}

bool  is_there_a_winner(char grid[][3])
{
  	for (int i=0;i<3;i++)
  	{
  	  if((grid[i][0]=='x'||grid[i][0]=='X') && (grid[i][1] == 'x'|| grid[i][1]=='X')
		 && (grid[i][2]== 'x' || grid[i][2]== 'X'))
	  		{
	  			return true;
			}
	 if((grid[i][0]=='o'||grid[i][0]=='O') && (grid[i][1] == 'o'|| grid[i][1]=='O')
		 && (grid[i][2]== 'o' || grid[i][2]== 'O'))
		    {
		    	return true;
			}
		
		 
	if((grid[0][i]=='x' || grid[0][i]=='X') && (grid[1][i]=='x' || grid[1][i]=='X')
	  	 && (grid[2][i]=='x'  || grid[2][i]=='X'))
			{
				return true;
			}
			
	if((grid[0][i]=='o' || grid[0][i]=='O') && (grid[1][i]=='o' || grid[1][i]=='O')
	  	 && (grid[2][i]=='o'  || grid[2][i]=='O'))
			{
				return true;
			}
	}
	
	if ((grid[0][0]== 'x' || grid[0][0]== 'X') && (grid[1][1]=='x' || grid[1][1]== 'X') 
    	&& (grid[2][2]== 'x' || grid[2][2]=='X'))
	   {
		return true;
	   }
	if ((grid[0][0]== 'o' || grid[0][0]== 'O') && (grid[1][1]=='o' || grid[1][1]== 'O') 
    	&& (grid[2][2]== 'o' || grid[2][2]=='O'))
	   {
		return true;
	   }
	else
	if ((grid[0][2]=='x' ||  grid[0][2]=='X') && (grid[1][1]=='x' || grid[1][1]=='X' )
	 && grid[2][0]=='x' ||grid[2][0]=='X')
	{
		return true;
	}
	if ((grid[0][2]=='o' ||  grid[0][2]=='O') && (grid[1][1]=='o' || grid[1][1]=='O' )
	 && grid[2][0]=='o' ||grid[2][0]=='O')
	{
		return true;
	}
	else
	return false;
}

void swap(char &current_marker,int &current_player,bool &user_turn)
{
	   if(current_marker=='x' || current_marker=='X')
		   {
		   	 current_marker='o';
		   }
	   else
		   {
		     current_marker='x';
		   }
	   
	   if(current_player==1)
		   {
			 current_player=2;
			 user_turn=false;
		   }
	   else
		   {
		   	 current_player=1;
		   	 user_turn=true;
		   }
}
void game_result(int player_won)
{
		
		if(player_won==1)	
			{
			   cout<<"Player "<<player_won <<" (YOU) won.Congratulations!"<<endl;
			}
		else 
		if(player_won==2)
			{
			   cout<<"Player"<<player_won<<" (COMPUTER) won.Congratulations!"<<endl;
			}
		else
		if(player_won==0)
			{
			   cout<<"DRAW!"<<endl;
			} 		
}


int main()
{
	char grid[3][3];
    char current_marker,again;
    int slot,player_won,current_player;
    bool user_turn,game_finished;
	do
      {
      	user_turn=true;
      	current_player=1;
      	game_finished=false;
      	int i=0;
      	player_won=0;
		grid[0][0]=' ';  	grid[0][1]=' ';  	grid[0][2]=' ';
		grid[1][0]=' ';  	grid[1][1]=' ';  	grid[1][2]=' ';
		grid[2][0]=' ';	    grid[2][1]=' ';	    grid[2][2]=' ';
		current_marker=startgame();
		do
		 {
			if (user_turn==true)
				{
				   
				   slot=get_user_input ();
				}
			else
				{
				 
         	       display_countdown();
				   slot=get_comp_input ();
				}
		    update_array( grid,current_marker,slot,user_turn);
			display_array(grid);
			if(is_there_a_winner(grid)==true)
			    {
				    player_won=current_player;
				    break;
			    }
			swap(current_marker, current_player,user_turn);
			i++;
			if(i==9)
			{
				game_finished=true;
			}
		}
		while(game_finished==false);
		
	    game_result(player_won);
		cout<<"Do you want to play again(y or n)?";
		cin>>again;
      }
	while(again=='y' || again=='Y');
	cout<<"Thank you!"<<endl;
	return 0;
}
