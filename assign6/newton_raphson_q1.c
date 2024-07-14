#include <stdio.h>
#include <math.h>

double d_abs(double x) {
    return (x>0)?x:-x;
}

void NR(double x_init,double TOL, int max_iter) {
    for (int i=1;i<=max_iter;i++) {
        double x=x_init -(x_init - cos(x_init))/(1+sin(x_init));
        double y = x - cos(x);
        if (y==0) {
            printf("The root is: %lf\n",x);
            return;
        }
        if ((d_abs(x-x_init)<=TOL)||(d_abs(y)<=TOL)) {
            printf("The approximate root is: %lf\n",x);
            return;
        }
        x_init=x;
    }
    printf("Maximum number of iteration reached. The method fail after %d
iterations.\n",max_iter);
}

int main() {
    //input
    double x_init=0.0;
    scanf("%lf",&x_init);
    double TOL=0.0;
    scanf("%lf",&TOL);
    int max_iter;
    scanf("%lf",&N);

    NR(x_init,TOL,max_iter);

    return 0;
}