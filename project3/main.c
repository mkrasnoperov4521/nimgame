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
    printf("Welcome to the Ancient Game of Nim");
}

int user_wants_to_play_again()
{
    char input;
    //checks if the user wants to play again if y then yes, n then no
    //prints the directions
    printf("Do you want to play again? (y/n)");
    //scans the user input
    
    scanf("%c", &input);
    
    
    while ( (input != 'y') || (input == 'Y') || (input == 'n') || (input == 'N'))
    {
        printf("Bad input! Try again. ");
        printf("Do you want to play again? (y/n)");
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
    printf("* * * * * * * * * * * ");
    printf("Current Score: ");
    printf("Player 1 (Human): %d", playerwins );
    printf("Player 2 (Computer): %d", compwins);
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
            printf( "COMPUTER moves a1");
        }
        else if ( heap_b > 0)
        {
            heap_b -= 1;
            printf( "COMPUTER moves b1");
        }
        else if ( heap_c > 0)
        {
            heap_c -= 1;
            printf( "COMPUTER moves c1");
        }
        
    }
    
    // removes stones from the piles based on the xor value
    if ( (heap_a ^ nimnumber) < heap_a )
    {
        heap_a -= (heap_a ^ nimnumber);
        printf( "COMPUTER moves a%d", nimnumber );
    }
    if ( (heap_b ^ nimnumber) < heap_b)
    {
        heap_b -= (heap_b ^ nimnumber);
        printf( "COMPUTER moves b%d", nimnumber );
    }
    if ((heap_c ^ nimnumber) < heap_c)
    {
        heap_c -= (heap_c ^ nimnumber);
        printf( "COMPUTER moves c%d", nimnumber );
    }
    
    return 0;
}

int play_nim(int winner, int comp_wins, int user_wins)
{
    int heap_a = 5;
    int heap_b = 4;
    int heap_c =3;
    int player_turn;
    char moveheap;
    int stones_removed;
    int player1;
    int player2;
    
    if( winner == player2 )
    {
        printf( "Player 1 goes first this time! ");
    }
    
    if( winner == player1 )
    {
        printf( " Player 2 goes first this time! ");
    }
    
    if( winner == player1 )
    {
        player_turn = 2;
    }
    else
    {
        player_turn = 1;
    }
    
    while((heap_a != 0 || heap_b !=0 || heap_c !=0))
    {
        if(player_turn = 1)
        {
            scanf(" %c, %d", moveheap, stones_removed);
            printf("Enter the letter of the heap and number of stones to remove: ");
            if ((moveheap == 'a' || moveheap == 'A') && heap_a - stones_removed >= 0)
            {
                heap_a -= stones_removed;
                player_turn = 2;
                if( (heap_a = 0) && (heap_b =0) && (heap_c = 0))
                {
                    return 1;
                    user_wins += 1;
                    break;
                }
            }
            else if ((moveheap == 'b' || moveheap == 'B') && heap_b - stones_removed >= 0)
            {
                heap_b -= stones_removed;
                player_turn = 2;
                if( (heap_a = 0) && (heap_b =0) && (heap_c = 0))
                {
                    return 1;
                    user_wins += 1;
                    break;
                }
            }
            else if ((moveheap == 'c' || moveheap == 'C') && heap_c - stones_removed >= 0)
            {
                heap_c -= stones_removed;
                if( (heap_a = 0) && (heap_b =0) && (heap_c = 0))
                {
                    return 1;
                    user_wins += 1;
                    break;
                }
                player_turn = 2;
            }
            
            else
            {
                printf("\nIllegal move! Try again. ");
                player_turn = 1;
            }
        }
        else
        {
            get_computer_move(heap_a, heap_b, heap_c);
            if( (heap_a = 0) && (heap_b =0) && (heap_c = 0))
            {
                return 2;
                comp_wins += 1;;
                break;
            }
            player_turn = 1;
        }
        
        if(winner == player1)
        {
            return 2;
        }
        else
        {
            return 1;
        }
        
        
        print_scoreboard(comp_wins, user_wins);
        
    }
}


int main()
{
    // main function that runs the program
    // initialize instance variables
    int comp_wins = 0;
    int user_wins = 0;
    int againplay = 1;
    int winner;
    int playagain;
    
    
    print_greeting();
    
    winner = play_nim(1, 0, 0);
    
    while( againplay != 0)
    {
        playagain = user_wants_to_play_again();
        if (playagain = 1)
        {
            play_nim(winner, comp_wins, user_wins);
        }
        if (playagain = 0 )
        {
            againplay = 0;
        }
    }
    
    
    
    return 0;
}
