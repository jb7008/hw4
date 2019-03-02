/*
 * Programmer : Josh Booth      Date : Mar 07 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Calculates and displays table of gas at different temperatures
 */

#include <stdio.h> /* Includes printf, scanf */
#include <math.h> /* Includes pow */

#define CARBON_DIOXIDE_CONST_1 3.592 /* Carbon dioxide constant in Van der Waals
  equation */
#define CARBON_DIOXIDE_CONST_2 0.0427 /* Carbon dioxide constant in Van der 
  Waals equation */
#define GAS_CONST 0.08206 /* Gas constant in Van der Waals equation */
#define ML_TO_L (1/1000.0) /* Conversion constant for converting milliliters
  to liters */

/* Prints out the temperature table */
void print_table(double carbon_dioxide_moles, int temperature, int volume_i,
  int volume_f, int delta_volume);

int
main(void)
{
  int volume_i, /* Initial volume (mL) */
    volume_f, /* Final volume (mL) */
    delta_volume; /* Volume increment (mL) */
  double carbon_dioxide_moles, /* Quantity of carbon dioxide (moles) */
    temperature; /* Temperature in kelvin */

  /* Gets program variables from user */
  printf("Quantity of carbon dioxide (moles)> ");
  scanf("%lf", &carbon_dioxide_moles);

  printf("Temperature (kelvin)> ");
  scanf("%lf", &temperature);

  printf("Initial volume (milliliters)> ");
  scanf("%d", &volume_i);

  printf("Final volume (milliliters)> ");
  scanf("%d", &volume_f);

  printf("Volume increment (milliliters)> ");
  scanf("%d", &delta_volume);

  printf("\n%.6f moles of carbon dioxide at %.1f K\n", carbon_dioxide_moles,
    temperature);

  /* Print temperature table */
  print_table(carbon_dioxide_moles, temperature, volume_i, volume_f,
    delta_volume);

  return 0;
}

/* Prints out the temperature table */

void print_table(double carbon_dioxide_moles, int temperature, int volume_i,
  int volume_f, int delta_volume)
{
  double pressure, /* Pressure of the gas */
    pressure_term_1, /* First term of the Van der Waals equation */
    pressure_term_2, /* Seconds term of the Van der Waals equation */
    current_vol; /* Current volume in the iteration */

  printf("Volume (l)\t\tPressure (atm)\n\n"); /* Print table heading */

  /* Prints pressure for each volume between volume_i and volume_f in increments
    of delta_volume */
  for(int i = 0; volume_i + (delta_volume * i) <= volume_f; i++)
  {
    /* Calculates current volume level */
    current_vol = (volume_i + (delta_volume * i)) * ML_TO_L;
    /* Calculates pressure with equation: (nRT)/(v-bn) - (an^2)/(v^2) */
    /* First term of Van der Waals equation */
    pressure_term_1 = (carbon_dioxide_moles * GAS_CONST * temperature) / 
      ((current_vol) - CARBON_DIOXIDE_CONST_2 * carbon_dioxide_moles);
    /* Second term of Van der Waals equation */
    pressure_term_2 = (CARBON_DIOXIDE_CONST_1 * (pow(carbon_dioxide_moles, 2)))
     / (pow(current_vol, 2));
    /* Combines terms */
    pressure = pressure_term_1 - pressure_term_2;

    /* Prints results */
    printf("%.6f\t\t\t\t%.4f\n", current_vol, pressure);
  }
}
