#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double findAmount(double p, double i, double c){
  p += p * i;
  p += c;

  return p;
}

void retirement(int startAge, double initial,retire_info working,  retire_info retired){
  int months = startAge;
  double savings =initial;
  for (int i =0; i< working.months; i++){
    int age = months/12;
    int mo = months%12;
    printf("Age %3d month %2d you have $%.2lf\n", age, mo, savings);
    savings = findAmount(savings, working.rate_of_return, working.contribution);
    months += 1;
  }
  for (int j = 0; j < retired.months; j++){
    int age = months/12;
    int mo = months%12;
    printf("Age %3d month %2d you have $%.2lf\n", age, mo, savings);
    savings = findAmount(savings, retired.rate_of_return, retired.contribution);
    months += 1;
  }
}
int main(){
  retire_info r1;
  retire_info r2;
  r1.months = 489;
  r1.contribution = 1000.0;
  r1.rate_of_return = 0.045/12;
  r2.months = 384;
  r2.contribution = -4000.0;
  r2.rate_of_return = 0.01/12;
  retirement(327, 21345, r1, r2);
  return EXIT_SUCCESS;
}
