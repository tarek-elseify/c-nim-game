/******************************************************************************
# file: /tug35668/lab/lab_10/NimGame.c
# Tarek Elseify
# November 11, 2018
# Lab 10 - Nim Game
# CIS 2107 SEC 003
# tug35668@temple.edu
#
# This is a program that creates a nim game
******************************************************************************/

/* standard include statements */
/*                             */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* function prototypes are listed here */
/*                                     */
void printCounters();
void takesCounters(char PLAYER[]);
int getRemaining();

/* GLOBAL VARIABLES LISTED HERE */
/*                              */

/* we make three sets of counters based on random var 5 <= var <= 10 */
/*                                                                   */
static int A = 10;
static int B = 9;
static int C = 8;

/******************************************************************************
#   function: main
#
#   arguments: none
#
#   returns: none
#
#   this is the main function of the program
******************************************************************************/
void main()
{
  
  /* player names */
  /*              */
  char PLAYER1[100];
  char PLAYER2[100];  
  
  /* ask player 1 to enter their name */
  /*                                  */
  printf("%s", "Player 1, please enter your name: ");

  /* enter user input into player 1 var */
  /*                                    */
  scanf("%s", PLAYER1);

  /* ask player 1 to enter their name */
  /*                                  */
  printf("%s", "Player 2, please enter your name: ");

  /* enter user input into player 1 var */
  /*                                    */
  scanf("%s", PLAYER2);

  /* will be used as boolean to check if we have one counter left */
  /*                                                              */
  int remaining = getRemaining();

  /* will be used to alternate between players */
  /* 1 will represent player 1, -1 will be p2  */
  /*                                           */
  int current = 1;
  
  /* while there is more than one counter left */
  /*                                           */
  while(remaining != 1 && remaining != 0){

    /* print out the counters */
    /*                        */
    printCounters();
    
    /* checks to see which player is current playing */
    /* if the current is positive, this is player 1  */
    /*                                               */
    if(current == 1){

      /* take counters from player 1 */      
      /*                             */
      takesCounters(PLAYER1);

      /* gets the remaning amount */
      /*                          */
      remaining = getRemaining();

      /* if amount remaning is 1 P1 wins */
      /*                                 */
      if(remaining == 1){

	/* print the winner */
	/*                  */
	printf("%s, you must take the last remaining counter!\n", PLAYER2);
	printf("%s wins!\n", PLAYER1); 	      
      }else if(remaining == 0){

	/* if user took last remaining pieces */
	/* user is not very good at playing.. */
	/*                                    */
	printf("%s, has taken the last piece!\n", PLAYER1);
	printf("%s wins!\n", PLAYER2);
      }
    }else{

      /* take counter from player 2 */
      /*                            */
      takesCounters(PLAYER2);

      /* gets the remaning amount */
      /*                          */
      remaining = getRemaining();

      /* if amount remaning is 1 P2 wins */
      /*                                 */
      if(remaining == 1){

	/* print the winner */
	/*                  */
	printf("%s, you must take the last remaining counter!\n", PLAYER1);
	printf("%s wins!\n", PLAYER2); 	      
      }else if(remaining == 0){

        /* if user took last remaining pieces */
	/* user is not very good at playing.. */
	/*                                    */
	printf("%s, has taken the last piece!\n", PLAYER2);
	printf("%s wins!\n", PLAYER1);
      }
    }
    current *= -1;
  }
}
/*                 */
/* end of function */


/******************************************************************************
#   function: printCounters
#
#   arguments: none
#
#   returns: none
#
#   this function is used to print the counter sets
******************************************************************************/
void printCounters()
{

  /* print out first counter */
  /*                         */
  printf("\n%s ", "A");

  /* print each counter for A */
  /*                          */
  for(int i=0; i < A; i++){
    printf("%s", "*");
  }

  /* print out second counter */
  /*                          */
  printf("\n%s ", "B");

  /* print each counter for B */
  /*                          */
  for(int i=0; i < B; i++){
    printf("%s", "*");
  }
  
  /* print out first counter */
  /*                         */
  printf("\n%s ", "C");

  /* print each counter for A */
  /*                          */
  for(int i=0; i < C; i++){
    printf("%s", "*");
  }

  /* newline */
  /*         */
  puts("\n");
}
/*                 */
/* end of function */


/******************************************************************************
#   function: printCounters
#
#   arguments: char PLAYER[] - current player
#
#   returns: none
#
#   this function is used to take the counters by player
******************************************************************************/
void takesCounters(char PLAYER[])
{

  /* which set to take from */
  /*                        */
  char SET;

  /* how much to take from set */
  /*                           */
  int take;
  
  /* ask the user to choose a pile */
  /*                               */
  printf("%s, choose a pile: ", PLAYER);

  /* get user input */
  /*                */
  getchar();
  scanf("%c", &SET);

  /* convert to upper case */
  /*                       */
  SET = toupper(SET);
  
  /* if user sets invalid set */
  /*                          */
  if(SET != 'A' && SET != 'B' && SET != 'C'){

    /* inform user of invalid set */
    /*                            */
    printf("%s\n", "Invalid set, try again");

    /* call this function again */
    /*                          */
    takesCounters(PLAYER);
  }
  
  /* switch cases */
  /*              */
  switch(SET){

    /* if user chose set A */
    /*                     */
    case 'A':

      /* if set A is empty */
      /*                   */
      if(A == 0){

	/* inform user set is empty */
	/*                          */
	printf("Nice try, %s. That pile is empty.\n", PLAYER);

	/* call this function again */
	/*                          */
	takesCounters(PLAYER);

	/* break */
	/*       */
	break;
      }

      /* asks user how much to take from set A */
      /*                                       */
      printf("%s", "How much to remove from set A: ");

      /* input user choice into take */
      /*                             */
      scanf("%d", &take);

      /* while the input is less than 1 */
      /*                                */
      while(take < 1 || take > A){

	/* if user tries to take less than 1 */
	/*                                   */
	if(take < 1){

	  /* inform user that they cannot take less than 1 */
	  /*                                               */
	  printf("\n%s", "You must choose at least 1. How many? ");

	  /* get new input */
	  /*               */
	  scanf("%d", &take);

	  /* check again */
	  /*             */
	  continue;
	}else{

	  /* inform user that they can not take more than is available */
	  /*                                                           */
	  printf("\n%s", "Pile A doesn't have that many. Try again: ");

	  /* get new input */
	  /*               */
	  scanf("%d", &take);
	}	
      }

      /* remove from A */
      /*               */
      A -= take;

      /* break */
      /*       */
      break;
    

    /* if user chose set B */
    /*                     */
    case 'B':

      /* if set B is empty */
      /*                   */
      if(B == 0){

	/* inform user set is empty */
	/*                          */
	printf("Nice try, %s. That pile is empty.\n", PLAYER);

	/* call this function again */
	/*                          */
	takesCounters(PLAYER);

	/* breaks */
	/*        */
	break;
      }

      /* asks user how much to take from set B */
      /*                                       */
      printf("%s", "How much to remove from set B: ");

      /* input user choice into take */
      /*                             */
      scanf("%d", &take);

      /* while the input is less than 1 */
      /*                                */
      while(take < 1 || take > B){

	/* if user tries to take less than 1 */
	/*                                   */
	if(take < 1){

	  /* inform user that they cannot take less than 1 */
	  /*                                               */
	  printf("\n%s", "You must choose at least 1. How many? ");

	  /* get new input */
	  /*               */
	  scanf("%d", &take);

	  /* check again */
	  /*             */
	  continue;
	}else{

	  /* inform user that they can not take more than is available */
	  /*                                                           */
	  printf("\n%s", "Pile B doesn't have that many. Try again: ");

	  /* get new input */
	  /*               */
	  scanf("%d", &take);
	}	
      }

      /* remove from B */
      /*               */
      B -= take;

      /* break */
      /*       */
      break;
    
    /* if user chose set C */
    /*                     */
    case 'C':

      /* if set C is empty */
      /*                   */
      if(C == 0){

	/* inform user set is empty */
	/*                          */
	printf("Nice try, %s. That pile is empty.\n", PLAYER);

	/* call this function again */
	/*                          */
	takesCounters(PLAYER);

	/* breaks */
	/*        */
	break;
      }

      /* asks user how much to take from set C */
      /*                                       */
      printf("%s", "How much to remove from set C: ");

      /* input user choice into take */
      /*                             */
      scanf("%d", &take);

      /* while the input is less than 1 */
      /*                                */
      while(take < 1 || take > C){

	/* if user tries to take less than 1 */
	/*                                   */
	if(take < 1){

	  /* inform user that they cannot take less than 1 */
	  /*                                               */
	  printf("\n%s", "You must choose at least 1. How many? ");

	  /* get new input */
	  /*               */
	  scanf("%d", &take);

	  /* check again */
	  /*             */
	  continue;
	}else{

	  /* inform user that they can not take more than is available */
	  /*                                                           */
	  printf("\n%s", "Pile C doesn't have that many. Try again: ");

	  /* get new input */
	  /*               */
	  scanf("%d", &take);
	}	
      }

      /* remove from C */
      /*               */
      C -= take;

      /* break */
      /*       */
      break;      
  }
}
/*                 */
/* end of function */

/******************************************************************************
#   function: getRemaining
#
#   arguments: none
#
#   returns: A + B + C
#
#   this function gets the remaining number of counters
******************************************************************************/
int getRemaining()
{
  return A + B + C;
}
