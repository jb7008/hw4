/*
 * Programmer : Josh Booth      Date : Mar 07 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Prints each digit of an n digit number and sums the digits together
 */

#include <stdio.h> /* Includes printf, scanf */

#define DIVISBLE_BY_9 9 /* Checks if a number is divisible by 9 */
#define GET_LAST_DIGIT 10 /* Gets the last digit of a number */

void print_digit(int num, int *sum); /* Prints num and adds it to sum */

int
main(void)
{
  int num, /* Number that is to be printed and divided by 9 */
    editable_num; /* Temporary num that is diminshed over the while statemet */
  int *sum; /* Running sum of numbers printed */

  /* Gets num */
  printf("Enter a number: ");
  scanf("%d", &num);

  *sum = 0; /* Initializes sum to 0 */
  editable_num = num; /* Sets editable_num equal to num */

  while(editable_num > 0)
  {
  print_digit(editable_num % GET_LAST_DIGIT, sum); /* Prints the right - most 
    digit of editable_num and adds it to sum */
  editable_num = editable_num / 10; /* Removes the right - most digit of 
   editable_num */
  }

  if(*sum % DIVISBLE_BY_9 == 0) /* If the sum is divisible by 9 */
  {
  printf("n = %d is divisible by 9\n", num);
  }
  else
  {
  printf("n = %d is not divisible by 9\n", num);
  }

  return 0;
}

/* Prints num and adds it to sum */
void
print_digit(int num, int *sum)
{
  *sum = *sum + num; /* Adds num to sum */
  printf("d = %d, sum = %d\n", num, *sum); /* Prints num and sum */
}
