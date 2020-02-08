#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row=0,column=0;
char turn='X';
bool draw =false;
void display_board()
{
	system("cls");
	cout<<"\t\t\t\t\t\t tik tak toe \n";
	cout<<"\t\t\t\t\t\t--------------\n";
	cout<<"\t\t\t PLAYER1[x]\n";
	cout<<"\t\t\t PLAYER2[0]\n\n";
	cout<<"\t\t\t\t\t\t     |     |     \n";
	cout<<"\t\t\t\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  | "<<board[0][2]<<"   \n";
	cout<<"\t\t\t\t\t\t_____|_____|_____\n";
	cout<<"\t\t\t\t\t\t     |     |     \n";
	cout<<"\t\t\t\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  | "<<board[1][2]<<"   \n";
	cout<<"\t\t\t\t\t\t_____|_____|_____\n";
	cout<<"\t\t\t\t\t\t     |     |     \n";
	cout<<"\t\t\t\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
	cout<<"\t\t\t\t\t\t     |     |     \n";
}
void gameplay()
{
	if(turn=='X')
	cout<<"PLAYER1[X] TURN\n";
	else
	cout<<"PLAYER2[0] TURN\n";
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:row=0;column=0;break;
		case 2:row=0;column=1;break;
		case 3:row=0;column=2;break;
		case 4:row=1;column=0;break;
		case 5:row=1;column=1;break;
		case 6:row=1;column=2;break;
		case 7:row=2;column=0;break;
		case 8:row=2;column=1;break;
		case 9:row=2;column=2;break;
		default:
			cout<<"INVALID ENTRY TRY AGAIN\n";
			return;
	}
	if(turn=='X'&&board[row][column]!='X'&&board[row][column]!='0')
	{
		board[row][column]='X';
		turn='0';
		return;
	}
	else if(turn=='0'&&board[row][column]!='X'&&board[row][column]!='0')
	{
		board[row][column]='0';
		turn='X';
		return ;
	}
	else
	{
		cout<<"BOX ALREADY FILLED!!\n TRY AGAIN\n";
		gameplay();
		return ;
	}
}
bool gameover()
{
	int i,j;
//	winning condition
	for(i=0;i<=2;i++)
	{
		if(board[i][0]==board[i][1]&&board[i][0]==board[i][2])
		return true;
		if(board[0][i]==board[1][i]&&board[2][i]==board[0][i])
		return true;
	}
	if(board[0][0]==board[1][1]&&board[0][0]==board[2][2])
	return true;
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])
	return true;
//	game continue
	for(i=0;i<=2;i++)
	for(j=0;j<=2;j++)
	if(board[i][j]!='X'&&board[i][j]!='0')
	return false;
//	game draw
	draw=true;
	return true;
}
int main()
{
	display_board();
	while(!gameover())
	{
	gameplay();
	display_board();
	}
	if(turn=='X'&&draw==false)
	cout<<"PLAYER2[0] WINS THE GAME\n";
	else if(turn=='0'&&draw==false)
	cout<<"PLAYER1[X] WINS THE GAME\n";
	else
	cout<<"GAME DRAW\n";
}
