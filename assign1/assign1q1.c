#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  double mant_a=0.0,mant_b=0.0,mant_c=0.0;
  int exp_a=0,exp_b=0,exp_c=0;
  while (mant_a==0.0) {
    printf("Please enter the (non-zero) mantissa of a:\n");
    scanf("%lf",&mant_a);
  }
  printf("Please enter the exponent of a:\n");
  scanf("%d",&exp_a);
  printf("Please enter the mantissa of b:\n");
  scanf("%lf",&mant_b);
  printf("Please enter the exponent of c:\n");
  scanf("%d",&exp_b);
  printf("Please enter the mantissa of c:\n");
  scanf("%lf",&mant_c);
  printf("Please enter the exponent of c:\n");
  scanf("%d",&exp_c);

  
  int min_exp=(exp_a>exp_b)?exp_b:exp_a;
  min_exp=(min_exp>exp_c)?exp_c:min_exp;
  exp_a-=min_exp;
  exp_b-=min_exp;
  exp_c-=min_exp;

  double a=mant_a*pow((double)10,(double) exp_a);
  double b=mant_b*pow((double)10,(double) exp_b);
  double c=mant_c*pow((double)10,(double) exp_c);
  if (a*pow((double)10,(double)min_exp)==0.0) {
    printf("Underflow in value of a\n");
    printf("Cannot calculate the roots thus");
    return 0;
  }
  if (b*pow((double)10,(double)min_exp)==0.0&&(mant_b!=0.0)) {
    printf("Underflow in value of b\n");
  }
  if (c*pow((double)10,(double)min_exp)==0.0&&(mant_c!=0.0)) {
    printf("Underflow in value of c\n");
  }
  if (a*pow((double)10,(double)min_exp)==INFINITY||-a*pow((double)10,(double)min_exp)==INFINITY) {
    printf("Overflow in value of a\n");
    printf("Cannot calculate the roots thus\n");
    return 0;
  }
  if (b*pow((double)10,(double)min_exp)==INFINITY||-b*pow((double)10,(double)min_exp)==INFINITY) {
    printf("Overflow in value of b\n");
    printf("Cannot calculate the roots thus\n");
    return 0;
  }
  if (c*pow((double)10,(double)min_exp)==INFINITY||-c*pow((double)10,(double)min_exp)==INFINITY) {
    printf("Overflow in value of c\n");
    printf("Cannot calculate the roots thus\n");
    return 0;
  }
  double D=0.0;
  D+=b*b-4*a*c;
  if (D<0) {
    printf("The roots are not real!");
  }
  else {
    printf("Yes the roots are real\n");
    double root1=0.0,root2=0.0;
    root1=-b+sqrt(D);
    root1/=2*a;
    root2=-b-sqrt(D);
    root2/=2*a;
    printf("The roots are %lf and %lf\n",root1,root2);
  }
  return 0;
}