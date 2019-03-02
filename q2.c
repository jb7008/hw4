#include <stdio.h> /* Includes printf, scanf */

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
  print_digit(editable_num % 10, sum); /* Prints the right - most digit of
   editable_num and adds it to sum */
  editable_num = editable_num / 10; /* Removes the right - most digit of 
   editable_num */
 }

 if(*sum % 9 == 0) /* If the sum is divisible by 9 */
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
