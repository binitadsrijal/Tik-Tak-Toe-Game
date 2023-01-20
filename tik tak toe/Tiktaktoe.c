#include <stdio.h>
#include <conio.h>

void printboard();
int checkwin();
void system();
char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};  //array
void main()
{
    int player = 1, input, status = -1;
    while (status = -1) //by default -1 which runs the code if the winner or loser is found we update the value and loop ends.
    {
        player = (player % 2 == 0) ? 2 : 1;  //it changes the number of player
        char mark = (player == 1) ? 'X' : 'O'; //if player is 1 then prints x if not then y

        //Tkaes the input of player turn wise
        printf("Enter number for player %d:\n", player);
        scanf("%d", &input);
        //For invalid numbers
        if (input < 1 || input > 9)
        {
            printf("Invalid number!!\n");
        }
        //iT CHANGES THE VALUE TO X AND Y
        board[input] = mark;
        printboard(); //function call
        
        //calling function checkwin which checks all theconditions
        int result = checkwin();
    if (result == 1)
    {
        printf("Yay! Player %d is winner.\n", player);
        return;
    }
    else if (result == 0)
    {
        printf("Draw");
        return;
    }
    player++;
    }
}
void printboard()
//table for Tiktaktoe
{
    system("cls");   //it dosnot prints the table again and again //one time printing
    printf("=== Tik TAC Toe ===\n\n");
    printf("      |      |     \n");
    printf("   %c  |   %c  |  %c  \n", board[1], board[2], board[3]);
    printf(" ____ | ____ | ____\n");
    printf("      |      |     \n");
    printf("   %c  |   %c  |  %c  \n", board[4], board[5], board[6]);
    printf(" ____ | ____ | ____\n");
    printf("      |      |     \n");
    printf("   %c  |   %c  |  %c  \n", board[7], board[8], board[9]);
    printf("      |      |     \n");
    printf("\n\n");
}
int checkwin()
//conditions checking
{
    if (board[1] == board[2] && board[2] == board[3])
    {
        return 1;
    }
    if (board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    if (board[7] == board[8] && board[8] == board[9])
    {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    if (board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    if (board[1] == board[5] && board[5] == board[9])
    {
        return 1;
    }
    if (board[3] == board[5] && board[5] == board[7])
    {
        return 1;
    }
    //for draw(If no one wins the game)
    int count = 0;
    for (int i = 1; i < 9; i++)
    
        if(board[i]=='X'|| board[i]=='Y'){
        count++;
        }
    if (count == 9)
    {
        return 0;
    }
    return -1;
}