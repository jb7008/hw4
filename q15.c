/*
 * Programmer : Josh Booth      Date : Mar 07 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Approximates PI
 */

#include <stdio.h> /* Includes printf, scanf */
#include <math.h> /* Includes pow */

#define ITERATION_MAX 99 /* Number of iterations for adding fraction values */
#define APPROXIMATION_CONST 4 /* Constant to multiply running total by */
#define TRUE 1 /* Sets TRUE as 1 */
#define FALSE 0 /* Sets FALSE as 0 */

/* Finds total to multiply by 4 to find pi approximation */
double find_running_total(void);

int
main(void)
{
  double running_total, /* Total to multiply by 4 to find pi approximation */
    pi_approx; /* Pi approximation */

/* Finds total to multiply by 4 to find pi approximation */
  running_total = find_running_total();

  /* Finishes pi appoximation */
  pi_approx = APPROXIMATION_CONST * running_total;

  /* Displays results */
  printf("Approx PI: %.6f\n", pi_approx);

  return 0;
}

/* Finds total to multiply by 4 to find pi approximation */
double
find_running_total(void)
{
  double running_total = 0; /* Running total */
  int even = TRUE; /* Variable to switch between adding or subtractin */

  /* Runs ITERATION_MAX / 2 times */
  for(int i = 1; i <= ITERATION_MAX; i += 2)
  {
    if(even) /* Runs ever other time */
    {
      running_total += (1.0/i); /* Adds to running total */
      even = FALSE; /* Switches to other track */
    }
    else /* Runs ever other time */
    {
      running_total -= (1.0/i); /* Subtracts from running total */
      even = TRUE; /* Switches to other track */
    }
  }

  return running_total; /* Returns running total */
}