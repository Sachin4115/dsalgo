#include <stdio.h>
/*
Rules of the game.
Both the play and the computer will choose 1-4 matchsticks at a time out of a set of total 21 matchsticks.
The player that picks up 21st matchstick wins the game.
*/
int main()
{
    int player_response, s=0;
    for (int i = 1; i < 6; i++)
    {
        printf("\nEnter the number you want to choose between 1-4 : ");
        scanf("%d", &player_response);
        if (player_response < 5 && player_response > 0)
        {
            printf("                                                 %d",5-player_response);
            s=s+5;
            if(s==20){
                printf("\nSince you will now have to pick up the 21st matchstik you loose.");
                printf("\nBetter luck next time");
            }
        }
        else{
            printf("\nPlease enter the correct input.");
            break;
        }
    }
    return 0;
}