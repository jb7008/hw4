/*
 * Programmer : Josh Booth      Date : Mar 07 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Finds the GCD of two numbers
 */

#include <stdio.h> /* Includes printf, scanf */
#include <stdlib.h> /* Includes abs */

void find_gcd(int num1, int num2, int *gcd); /* Finds GCD */

int
main(void)
{
  int num1, /* One of the numbers used to find the GCD */
    num2; /* Other number to be used to find the GCD */
  int *gcd; /* greatest common divisor */

  /* Gets two numbers */
  printf("Enter two numbers (m n): ");
  scanf("%d %d", &num1, &num2);

  num1 = abs(num1); /* Takes the absolute value of num1 */
  num2 = abs(num2); /* Takes the absolute value of num2 */

  find_gcd(num1, num2, gcd); /* Finds GCD */

  /* Prints gcd */
  printf("%d\n", *gcd);

  return 0;
}

/* Finds GCD */
void
find_gcd(int num1, int num2, int *gcd)
{
  int nums_divided, /* Integer of num1 divided by num2 */
    remainder; /* Remainder of the division operation */

  nums_divided = (int)(num1 / num2); /* Whole divided number */
  remainder = num1 - (num2 * nums_divided); /* Remainder */
  
  if(remainder == 0) /* If remainder is 0, GCD is the divisor */
  {
    *gcd = num2;
  }
  else
  {
    find_gcd(num2, remainder, gcd); /* If remainder is not 0, rerun the 
      operation */
  }
}
