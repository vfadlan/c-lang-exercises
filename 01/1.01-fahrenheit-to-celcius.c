#include <stdio.h>

/* (E1-3) Print Fahrenheit-Celcius Table from 0F-300F */ 
int main() {
    float fahr, celcius;
    float lower, upper, step;

    lower = 0.0;
    upper = 300.0;
    step = 20.0;

    printf("  Fahrenheit to Celcius\n    Convertion Table\n");
    printf("========================\n");

    printf("%8s\t%8s\n", "F", "C");

    fahr = lower;
    while (fahr <= upper) {
        celcius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%8.1f\t%8.1f\n", fahr, celcius);
        fahr += step;
    }
    return 0;
  }
