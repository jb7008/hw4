/*
 * Programmer : Josh Booth      Date : Mar 07 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Calculates half-life of Cobalt-60
 */

#include <stdio.h> /* Includes printf, scanf */
#include <math.h> /* Includes pow */

#define CO_HALF_LIFE 5.272 /* Constant of the half-life of cobalt-60 */
#define FIVE_YEARS 5

int
main(void)
{
  int co_amt; /* Amount of Cobalt-60 */
  double remaining_amt; /* Amount of Cobalt-60 remaining */

  /* Prints heading */
  printf("*******************\n");
  printf("Half-Life Co-60\n");
  printf("*******************\n");

  /* Gets amount of cobalkt-60 */
  printf("Enter amount of Co-60: ");
  scanf("%d", &co_amt);
  /* Prints table heading */
  printf("Year\t\tAmount\n");
  /* Prints cobalt-60 amount for 5 years in the future */
  for(int i = co_amt; i < co_amt + FIVE_YEARS; i++)
  {
    /* Calculates remaining amount with formula r = amt * (e^-0.693)^(year/H) */
    remaining_amt = co_amt * pow(pow(M_E, -0.693), (i / CO_HALF_LIFE));

    /* Prints results */
    printf("%d\t\t%f\n", i, remaining_amt);
  }

  return 0;
}
