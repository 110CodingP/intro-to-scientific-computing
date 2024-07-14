#include <stdio.h>


int main() {
  printf("Please enter the real value: ");
  long double x;
  scanf("%llf",&x);
  printf("\nPlease enter the approximation: ");
  long  double xa;
  scanf("%llf",&xa);
  if (x==0) {
    printf("x is 0!");
    return 0;
  }
  long double er= x-xa;
  er/=x;
  printf("The relative error is %llf",er);
  return 0;
}
