//
//  main.c
//  Project03
//
//  Created by Maxim Krasnoperov on 2/14/19.
//  Copyright © 2019 Maxim Krasnoperov. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>


void print_greeting()
{
    printf("Welcome to the Ancient Game of Nim \n");
}

int user_wants_to_play_again()
{
    char input;
    //checks if the user wants to play again if y then yes, n then no
    //prints the directions
    printf("Do you want to play again? (y/n) \n");
    //scans the user input
    
    scanf("%c", &input);
    
    
    while ( (input != 'y') || (input == 'Y') || (input == 'n') || (input == 'N'))
    {
        printf("Bad input! Try again. \n");
        printf("Do you want to play again? (y/n) \n");
        scanf("%c", &input);
    }
    // if to see if player wants to play again returning 0 for no 1 for yes
    if( input == 'y' || input == 'Y' )
    {
        return 1;
    }
    
    else if( input == 'n' || input == 'N')
    {
        
        return 0;
        
    }
    
    else
    {
        return 2;
    }
    //if input is incorrect prints error message and runs the program again
    
}

void print_scoreboard(int playerwins, int compwins)
{
    // prints the scoreboard
    printf("* * * * * * * * * * * \n");
    printf("Current Score: \n");
    printf("Player 1 (Human): %d \n", playerwins );
    printf("Player 2 (Computer): %d \n", compwins);
}

int get_computer_move(int heap_a, int heap_b, int heap_c)
{
    int nimnumber;
    nimnumber = heap_a ^ heap_b ^ heap_c;
    
    // if nimnumber = 0 removes a stone from the first avaliable pile
    if ((nimnumber = 0))
    {
        if( heap_a > 0 )
        {
            heap_a = 1;
            printf( "COMPUTER moves a1 \n");
        }
        else if ( heap_b > 0)
        {
            heap_b -= 1;
            printf( "COMPUTER moves b1 \n");
        }
        else if ( heap_c > 0)
        {
            heap_c -= 1;
            printf( "COMPUTER moves c1 \n");
        }
        
    }
    
    // removes stones from the piles based on the xor value
    if ( (heap_a ^ nimnumber) < heap_a )
    {
        heap_a -= (heap_a ^ nimnumber);
        printf( "COMPUTER moves a%d \n", nimnumber );
    }
    if ( (heap_b ^ nimnumber) < heap_b)
    {
        heap_b -= (heap_b ^ nimnumber);
        printf( "COMPUTER moves b%d \n", nimnumber );
    }
    if ((heap_c ^ nimnumber) < heap_c)
    {
        heap_c -= (heap_c ^ nimnumber);
        printf( "COMPUTER moves c%d \n", nimnumber );
    }
    
    return 0;
}

int play_nim(int winner, int comp_wins, int user_wins)
{
    int heap_a = 5;
    int heap_b = 4;
    int heap_c =3;
    int player_turn;
    char moveheap = '\0';
    int stones_removed = 0;
    int player1;
    int player2;
    
    if( winner == 1)
    {
        player_turn = 2;
    
    }
    if (winner == 2)
    {
        player_turn = 1;
    }
    
    printf("Player 1 is you (the human) \n");
    printf("Player 2 is me (the computer) \n");
    
    if( player_turn == 1 )
    {
        printf( "Player 1 goes first this time! \n");
        printf("\nPlayer %d \nHeaps: \nA: %d \nB: %d \nC: %d \n", player_turn, heap_a, heap_b, heap_c);
    }
    
    if( player_turn == 2 )
    {
        printf( "Player 2 goes first this time! \n");
        printf("\nPlayer %d \nHeaps: \nA: %d \nB: %d \nC: %d \n", player_turn, heap_a, heap_b, heap_c);
    }
    
    
    while((heap_a != 0 || heap_b !=0 || heap_c !=0))
    {
        if(player_turn == 1)
        {
            
            printf("Enter the letter of the heap and number of stones to remove: \n");
            scanf(" %c, %d", &moveheap, &stones_removed);
            if ((moveheap == 'a' || moveheap == 'A') && heap_a - stones_removed >= 0)
            {
                heap_a -= stones_removed;
                printf("\nPlayer %d \nHeaps: \nA: %d \nB: %d \nC: %d \n", player_turn, heap_a, heap_b, heap_c);
                player_turn = 2;
                if( (heap_a == 0) && (heap_b == 0) && (heap_c == 0))
                {
                    user_wins += 1;
                    print_scoreboard(comp_wins, user_wins);
                    return 1;
                }
            }
            else if ((moveheap == 'b' || moveheap == 'B') && heap_b - stones_removed >= 0)
            {
                heap_b -= stones_removed;
                printf("\nPlayer %d \nHeaps: \nA: %d \nB: %d \nC: %d \n", player_turn, heap_a, heap_b, heap_c);
                player_turn = 2;
                if( (heap_a == 0) && (heap_b == 0) && (heap_c == 0))
                {
                    
                    user_wins += 1;
                    print_scoreboard(comp_wins, user_wins);
                    return 1;
                }
            }
            else if ((moveheap == 'c' || moveheap == 'C') && heap_c - stones_removed >= 0)
            {
                printf("\nPlayer %d \nHeaps: \nA: %d \nB: %d \nC: %d \n", player_turn, heap_a, heap_b, heap_c);
                heap_c -= stones_removed;
                if( (heap_a == 0) && (heap_b == 0) && (heap_c == 0))
                {
                    user_wins += 1;
                    print_scoreboard(comp_wins, user_wins);
                    return 1;                }
                player_turn = 2;
            }
            
            else
            {
                printf("Illegal move! Try again. \n");
                player_turn = 1;
            }
        }
        else
        {
            get_computer_move(heap_a, heap_b, heap_c);
            printf("\nPlayer %d \nHeaps: \nA: %d \nB: %d \nC: %d \n", player_turn, heap_a, heap_b, heap_c);
            if( (heap_a == 0) && (heap_b == 0) && (heap_c == 0))
            {
                
                comp_wins +=1;
                print_scoreboard(comp_wins, user_wins);
                return 2;
            }
            player_turn = 1;
        }
    }
    return -1;
}


int main()
{
    // main function that runs the program
    // initialize instance variables
    int winner;
    bool playagain = true;
    
    
    print_greeting();
    
    winner = play_nim(2, 0, 0);
    
    while( playagain)
    {
        playagain = user_wants_to_play_again();
    }
    
    
    
    return 0;
}
