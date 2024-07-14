#include <stdio.h>
#include <math.h>

double d_abs(double x) {
    return (x>0)?x:-x;
}

void secant(double x_first, double x_second,double TOL, int max_iter) {
    double y_first= x_first-cos(x_first);
    double y_second= x_second-cos(x_second);
    for (int i=2;i<=max_iter;i++) {
        double x=x_second -(y_second*(x_second - x_first))/(y_second-y_first);
        double y=x-cos(x);
        if (y==0) {
            printf("The root is: %lf\n",x);
            return;
        }
        if ((d_abs(x-x_init)<=TOL)||(d_abs(y)<=TOL)) {
            printf("The approximate root is: %lf\n",x);
            return;
        }
        x_first=x_second;
        x_second=x;
        y_first=y_second;
        y_second=y;
    }
    printf("Maximum number of iteration reached. The method fail after %d
iterations.\n",max_iter);
}

int main() {
    //input
    double x_first=0.0;
    double x_second=0.0;
    scanf("%lf",&x_first);
    scanf("%lf",&x_second);
    double TOL=0.0;
    scanf("%lf",&TOL);
    int max_iter;
    scanf("%lf",&N);

    secant(x_first,x_second,TOL,max_iter);

    return 0;
}