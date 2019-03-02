/*
 * Programmer : Josh Booth      Date : Mar 07 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Prints each digit of an n digit number and sums the digits together using
 * chars instead of ints
 */

#include <stdio.h> /* Includes printf, scanf */

#define NEWLINE '\n' /* Newline constant */
#define CONVERT_TO_INT '0' /* Char 0 constant */

void is_divisible_by_9(int sum); /* Checks if the sum of the number is divisible
  by 9 */


int
main(void)
{
  char num; /* Number that is to be printed and divided by 9 */
  int sum; /* Running sum of numbers printed */

  /* Gets num */
  printf("Enter a number: ");

  /* Reads one char */
  num = getchar();

  /* While it isn't the end of the line */
  while(num != NEWLINE)
  {
    /* Add integer version of num to sum */
    sum += num - CONVERT_TO_INT;

    /* Displays current num and running sum */
    printf("d = %d, sum = %d\n", num - CONVERT_TO_INT, sum);
    
    /* Gets the next char */
    num = getchar();
  }

  /* Checks if the sum of the number is divisible by 9 */
  is_divisible_by_9(sum);
  
  return 0;
}

/* Checks if the sum of the number is divisible by 9 */
void
is_divisible_by_9(int sum)
{
  if(sum % 9 == 0)
  {
    printf("is divisible by 9\n");
  }
  else
  {
    printf("is not divisible by 9\n");
  }
}