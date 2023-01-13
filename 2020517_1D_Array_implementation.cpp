#include<iostream>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
using namespace std;
char startgame(char grid[],int size)
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
  	while(P1_marker != 'x' && P1_marker != 'X' && P1_marker != 'o' && P1_marker != 'O' )
  	{
  	  cout<<"Invalid input ,please choose o or x "<<endl;
	  cin>>P1_marker;	
	}
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
	 	cout<<"   "<<i<< " seconds left "<<endl;
		sleep(1);
		system("CLS");
	  }
}

int  get_comp_input ()
{
    int slot;
	cout<<" It's   player 2 (computer)'s  turn "<<endl<<endl;;
  	srand(time(0));
    slot=(rand()%9)+1;
	return slot;
}
void update_array(char grid[],int size,char current_marker,int slot,bool user_turn)
{
	 if(grid[slot-1] != 'x' &&  grid[slot-1] != 'X' &&  grid[slot-1] != 'o' &&  grid[slot-1] != 'O')
      {
    	 grid[slot-1]=current_marker;
	  }
	 else 
	 {
	   cout<<"This slot is occupied"<<endl;
    	while(grid[slot-1] == 'x' || grid[slot-1] == 'X' || grid[slot-1] == 'o' ||  grid[slot-1] == 'O')
	  {
		if(user_turn==true)
		 {
		 	cout<<"Oops!Please  Enter another"<<endl;
		    slot=get_user_input();
		 }
		else 
		 {
		     srand(time(0));
	         slot=(rand()%9)+1;
			 if(grid[slot-1]!= 'x' &&  grid[slot-1] != 'X' &&  grid[slot-1] != 'o' &&  grid[slot-1] != 'O')
			     {
			          display_countdown();	
				 }
	     }
      }
      grid[slot-1]=current_marker;
     }
}

void display_array( char grid[],int size)
{
	cout<<"\t\t SAMPLE INPUT   \t\t\t\t\tPLAYERS ENTERED HERE  "<<endl<<endl;
   	cout<<"\t\t    |     |     \t\t\t\t\t    |     |    "<<endl;
	cout<<"\t\t 1  |  2  |  3  \t\t\t\t\t  "<<grid[0]<<" |  "<<grid[1]<<"  |  "<<grid[2]<<endl;
	cout<<"\t\t____|_____|_____\t\t\t\t\t____|_____|____"<<endl;
	cout<<"\t\t    |     |     \t\t\t\t\t    |     |    "<<endl;
	cout<<"\t\t  4 |  5  |  6  \t\t\t\t\t  "<<grid[3]<<" |  "<<grid[4]<<"  |  "<<grid[5]<<endl;
	cout<<"\t\t____|_____|_____\t\t\t\t\t____|_____|____"<<endl;
	cout<<"\t\t    |     |     \t\t\t\t\t    |     |    "<<endl;	
	cout<<"\t\t  7 |  8  |  9  \t\t\t\t\t  "<<grid[6]<<" |  "<<grid[7]<<"  |  "<<grid[8]<<endl;
	cout<<"\t\t    |     |     \t\t\t\t\t    |     |    "<<endl;
}
bool  is_there_a_winner(char grid[],int size)
{
  	    if((grid[0]== 'x' || grid[0]== 'X') && (grid[1]=='x' || grid[1]=='X') && (grid[2]=='x' || grid[2]=='X'))
	  		{
	  			return true;
			}
		else if((grid[0]== 'o' || grid[0]== 'O') && (grid[1]=='o' || grid[1]=='O') && (grid[2]=='o' || grid[2]=='O'))
			{
				return true;
			}
		else if((grid[3]== 'x' || grid[3]== 'X') && (grid[4]=='x' || grid[4]=='X') && (grid[5]=='x' || grid[5]=='X'))
	  		{
	  			return true;
			}
		else if((grid[3]== 'o' || grid[3]== 'O') && (grid[4]=='o' || grid[4]=='O') && (grid[5]=='o' || grid[5]=='O'))
			{
				return true;
			}
		else if((grid[6]== 'x' || grid[6]== 'X') && (grid[7]=='x' || grid[7]=='X') && (grid[8]=='x' || grid[8]=='X'))
	  		{
	  			return true;
			}
		else if((grid[6]== 'o' || grid[6]== 'O') && (grid[7]=='o' || grid[7]=='O') && (grid[8]=='o' || grid[8]=='O'))
			{
				return true;
			} 
		else if((grid[1]== 'x' || grid[0]== 'X') && (grid[4]=='x' || grid[4]=='X') && (grid[7]=='x' || grid[7]=='X'))
	  		{
	  			return true;
			}
		else if((grid[1]== 'o' || grid[0]== 'O') && (grid[4]=='o' || grid[4]=='O') && (grid[7]=='o' || grid[7]=='O'))
			{
				return true;
			}
		else if((grid[0]== 'x' || grid[0]== 'X') && (grid[3]=='x' || grid[3]=='X') && (grid[6]=='x' || grid[6]=='X'))
	  		{
	  			return true;
			}
		else if((grid[0]== 'o' || grid[0]== 'O') && (grid[3]=='o' || grid[3]=='O') && (grid[6]=='o' || grid[6]=='O'))
			{
				return true;
			}
		
	    else if((grid[2]== 'x' || grid[2]== 'X') && (grid[5]=='x' || grid[5]=='X') && (grid[8]=='x' || grid[8]=='X'))
	  		{
	  			return true;
			}
		else if((grid[2]== 'o' || grid[2]== 'O') && (grid[5]=='o' || grid[5]=='O') && (grid[8]=='o' || grid[8]=='O'))
			{
				return true;
			}
        else if((grid[0]== 'x' || grid[0]== 'X') && (grid[4]=='x' || grid[4]=='X') && (grid[8]=='x' || grid[8]=='X'))
	  		{
	  			return true;
			}
		else if((grid[0]== 'o' || grid[0]== 'O') && (grid[4]=='o' || grid[4]=='O') && (grid[8]=='o' || grid[8]=='O'))
			{
				return true;
			}
        else if((grid[2]== 'x' || grid[2]== 'X') && (grid[4]=='x' || grid[4]=='X') && (grid[6]=='x' || grid[6]=='X'))
	  		{
	  			return true;
			}
		else if((grid[2]== 'o' || grid[2]== 'O') && (grid[4]=='o' || grid[4]=='O') && (grid[6]=='o' || grid[6]=='O'))
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
	char grid[9];
	char current_marker,again;
    int slot,player_won,current_player=1;
    bool user_turn=true;
    bool game_finished;
    
    do
     {  
        game_finished=false;
        int i=0;
     	player_won=0;
     	grid[0]=' '; 	grid[1]=' ';  	grid[2]=' '; 
     	grid[3]=' '; 	grid[4]=' '; 	grid[5]=' '; 
     	grid[6]=' '; 	grid[7]=' '; 	grid[8]=' ';
     	current_marker=startgame(grid,9);
    
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
		    update_array(grid,9,current_marker,slot,user_turn);
			display_array(grid,9);
			if(is_there_a_winner(grid,9)==true)
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
