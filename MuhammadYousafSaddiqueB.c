/* Muhammad Yousaf Saddique*/

   // The BlackJack Game Program

#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include<time.h>

char cards[13] = {'A','J', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'Q', 'K'};

int values[13] = {11 , 10 , 2, 3, 4, 5, 6, 7, 8, 9, 10, 10,10};

int p=0,d=0; // for player and dealer win count


char handp[20]; // slots for players counter
char handd[20]; // slots for dealers counter
char choice=' ';    // Input for hit or dealers play
char enter,w;     // Input for quit game

        int psum=0,dsum=0; // for sum of player's and dealer's card

        int x,y;
        int countp = 0; // counter for player turns
        int countd = 0; // counter for dealer turns

int pplay();  // function dealing with all players things
int dplay();  // function dealing with all dealers things

int winlose(); // Function with conditions to determine win or lose


int phand();   // Function for Storing the previous cards of player and displaying them along with new ones
int dhand();   // Function for Storing the previous cards of dealer and displaying them along with new ones


int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // For colored title of the Game
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("\t\t 'The BlackJack' \n\n"); // This text will be in green
    SetConsoleTextAttribute(hConsole, 7);

    printf("Enter 'p' to start game : ");
    scanf(" %c",&w);

    srand(time(NULL));

    if(w=='p')
    {

    printf("\nHERE THE GAME BEGINS\n\n");

    srand(time(NULL));

    while(enter!='q') // loop to play as many games as you like
    {
        psum=0,dsum=0; // for sum of player's and dealer's card

        x=0,y=0;
        countp = 0; // counter for player turns
        countd = 0; // counter for dealer turns

        pplay();

        if (psum>21)
        {
            printf("\nUnfortunately You burst. The Dealer wins.");
        }
        else
            dplay();
            {
            if(dsum>21)
            {
                printf("The dealer burst. Congrats You won the hand.");
            }


        winlose();
            }

        printf("\n\nPress g for another game : ");
        scanf(" %c",&enter);

    }
    }



    return 0;
}


int pplay() // Function to generate player cards and
{

    x=rand()%13;  // To generate first random card for player
    handp[countp]=cards[x]; // To store the player's first card
    countp++; // Moving to next slot in array
    psum=psum+values[x];

    x=rand()%13;  // To generate second random card for player
    handp[countp]=cards[x]; // To store the player's second card
    countp++;
    psum=psum+values[x];

    printf("\nPlayer's Hand : ");
    phand(); // Returning the already stored player cards
    countp++;

    printf("\nDealer's Hand : ");
    y = rand()%13;
        handd[countd] = cards[y]; // Storing the dealers first card to be displayed in next turn too
        dhand();
        countd++;
        dsum = dsum + values[y];

    printf(" X");

    printf("\n\nEnter   's' for Dealer's play\n\t'h' for HIT : ");
    scanf(" %c", &choice);

    while(choice != 's'&& choice != 'S'&& psum <= 21)
    {
        x=rand()%13;
        handp[countp]=cards[x]; //
        countp++; // Another slot created in handp
        printf("\nPlayer's Hand : ");
        phand();

        if (psum>10) // Value of Ace will be 1 if including it exceed the sum from 21
        {
            values[0]=1;
        }

        psum = psum + values[x];

        if (psum>21)
        {
          break;
        }

        printf("\n\nEnter   's' for Dealer's play\n\t'h' for HIT ");
        scanf(" %c", &choice);
    }

    printf("\nYour sum is %d.\n",psum);

    }

int dplay() // Function dealing with storing and displaying dealers previous card and generating dealers new cards.
{
    int c;
    while(dsum<=17 && dsum<=psum) // loop will run if the dealer's sum is less than both the number 17 and the player's sum.
    {
        printf("\nDealer's Hand : ");
        y=rand()%13; // Generating random card for dealer
        handd[countd]=cards[y]; // Having a count of dealers cards and mapping it with a card in cards array.
        countd++;  //
        dhand(); // Calling function to give previous cards of dealer too

        if (dsum>10) // Ensures that value of Ace is 1 if the sum increases 21 in any case
        {
             values[0]=1; // Giving value 1 to Ace

        }
        dsum = dsum + values[y];
    }
        printf("\nDealer's sum is %d.\n",dsum);

    }





int phand() // Storing the previous cards of player and displaying them along with new ones
{
    int l;
    for(l=0;l<=countp;l++)
    {
        if(handp[l]==cards[10])
            printf(" 10 ");
        else
            printf(" %c",handp[l]);
    }

}


int dhand() // Storing the previous cards of dealer and displaying them along with new ones
{
    int o;
    for(o=0;o<=countd;o++)
    {
        if(handd[o]==cards[10])
            printf(" 10 ");
        else
            printf(" %c",handd[o]);
    }

}

int winlose()
{
    if (dsum<=21 && dsum>=psum)
    {
        printf("\nThe dealer wins the bet. Better luck next time.");
        d++;
    }
    else if (psum<22 && psum>=dsum)
    {
        printf("\nYou have won the bet. Good game.");
    }
}


