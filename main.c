#include <stdbool.h>
#include <stdio.h>

#define PLAYER_1 1
#define PLAYER_2 2

// declaring global variable for col & row
int row, col, winner = 0;

void printing_board(char board[3][3]);
void taking_input(char board[3][3], int player_number);
void finding_winner(char board[3][3]);
bool is_draw(char board[3][3]);

int main(void)
{
    int choice;

    // opening msg
    printf("\t\t************* Welcome to TIC TOE TAC Games *************\n\n");

    // infinite loop for gaming as many as user wants
    while (true)
    {
        // creating main board
        char main_board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
        winner = 0; 

        // starting message for each game
        printf("\tPress 1 to start a New game... \n\tTo exit press 0\n\n");
        scanf("%d", &choice);
        printf("\n\n");

        // exit message
        if (choice == 0)
        {
            printf("\n\n\t\t******** THANK YOU FOR PLAYING! GOODBYE! ********\n");
            // waiting for a bit before closing the application terminal
            sleep(3);
            break;
        }
        // gaming part
        else if (choice == 1)
        {
            printing_board(main_board);
            while (true)
            {
                // taking input from player 1
                taking_input(main_board, PLAYER_1);
                main_board[col][row] = 'X';
                printing_board(main_board);
                finding_winner(main_board);
                if (winner == 1)
                {
                    printf("\n\n\t\t******** PLAYER 1 IS WINNER ******** \n");
                    break;
                }
                // Check for draw
                if (is_draw(main_board))
                {
                    printf("\n\n\t\t******** THE GAME IS A DRAW ******** \n");
                    break;
                }

                // taking input from player 2
                taking_input(main_board, PLAYER_2);
                main_board[col][row] = 'O';
                printing_board(main_board);
                finding_winner(main_board);
                if (winner == 2)
                {
                    printf("\n\n\t\t******** PLAYER 2 IS WINNER ******** \n");
                    break;
                }
                // Check for draw
                if (is_draw(main_board))
                {
                    printf("\n\n\t\t******** THE GAME IS A DRAW ******** \n");
                    break;
                }
            }
        }
        // error message for invalid input
        else
        {
            printf("Invalid choice! Please enter 1 to start or 0 to exit.\n");
        }
    }
}

void printing_board(char board[3][3])
{
    // declaring variables of for loop
    int i, j;

    // printing the board to start the game
    for (i = 0; i < 3; i++)
    {
        // loop for 1st row of each number block row
        printf("     |     |     ");
        
        // loop for the row with numbers of each number block row
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                printf("  %c  ", board[i][j]);
            }
            else
            {
                printf("  %c  |", board[i][j]);
            }
        }
        printf("\n");

        // loop for last row of each number block row
        if (i == 2)
        {
            printf("     |     |     ");
        }
        else
        {
            printf("_____|_____|_____");
        }
        printf("\n");
    }
}

void taking_input(char board[3][3], int player_number)
{
    int sign_position;
    printf("\n");
    // taking a valid input
    while (true)
    {
        printf("Enter the number to put sign for player %d : ", player_number);
        scanf("%d", &sign_position);
        if (sign_position >= 1 && sign_position <= 9)
        {
            // finding row & col
            if (sign_position > 6)
            {
                col = 2, row = sign_position - 7;
            }
            else if (sign_position > 3)
            {
                col = 1, row = sign_position - 4;
            }
            else
            {
                col = 0, row = sign_position - 1;
            }
            if (board[col][row] != 'X' && board[col][row] != 'O')
            {
                return;
            }
            // if cell is occupied
            else
            {
                printf("Cell already occupied. Try again.\n");
            }
        }
        // error msg for invalid input
        else
        {
            printf("Invalid input. Enter a number between 1 and 9.\n");
        }
    }
}

void finding_winner(char board[3][3])
{
    // checking the horizontal lines for PLAYER 1
    for (int m = 0; m < 3; m++)
    {
        if (board[m][0] == 'X' && board[m][1] == 'X' && board[m][2] == 'X')
        {
            winner = 1;
            return;
        }
    }
    // checking the horizontal lines for PLAYER 2
    for (int m = 0; m < 3; m++)
    {
        if (board[m][0] == 'O' && board[m][1] == 'O' && board[m][2] == 'O')
        {
            winner = 2;
            return;
        }
    }
    // checking vertical lines for PLAYER 1
    for (int m = 0; m < 3; m++)
    {
        if (board[0][m] == 'X' && board[1][m] == 'X' && board[2][m] == 'X')
        {
            winner = 1;
            return;
        }
    }
    // checking vertical lines for PLAYER 2
    for (int m = 0; m < 3; m++)
    {
        if (board[0][m] == 'O' && board[1][m] == 'O' && board[2][m] == 'O')
        {
            winner = 2;
            return;
        }
    }
    // checking diagonal lines for PLAYER 1 (1)
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
    {
        winner = 1;
        return;
    }
    // checking diagonal lines for PLAYER 1 (2)
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
    {
        winner = 1;
        return;
    }
    // checking diagonal lines for PLAYER 2 (1)
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
    {
        winner = 2;
        return;
    }
    // checking diagonal lines for PLAYER 2 (2)
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
    {
        winner = 2;
        return;
    }
}

bool is_draw(char board[3][3])
{
    // checking draw
    for (int c = 0; c < 3; c++)
    {
        for (int d = 0; d < 3; d++)
        {
            if (board[c][d] != 'X' && board[c][d] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}