#include <stdio.h>
double d_abs(double x) {
    return (x>0)?x:-x;
}

void fixed_point1(double x_init, double TOL, int max_iter) {
    for (int i=1;i<=max_iter;i++) {
        double x = x_init-pow(x_init,(double) 3) - 4*power(x_init,(double) 2) +10;
        if (d_abs(x-x_init)<=TOL) {
            printf("The approximate root is %lf\n",x);
        }
        x_init=x;
    }
    printf("Maximum number of iteration reached. The method fail after %d
iterations.\n",max_iter);
}
void fixed_point1(double x_init, double TOL, int max_iter) {
    for (int i=1;i<=max_iter;i++) {
        if (x_init==0) {
            printf("x0 became 0 cannot proceed\n");
            return;
        }
        double x = 10/x_init - 4*x_init; //what if some x is zero
        x= pow(x,0.5);
        if (d_abs(x-x_init)<=TOL) {
            printf("The approximate root is %lf\n",x);
        }
        x_init=x;
    }
    printf("Maximum number of iteration reached. The method fail after %d
iterations.\n",max_iter);
}
void fixed_point1(double x_init, double TOL, int max_iter) {
    for (int i=1;i<=max_iter;i++) {
        double x = 10-pow(x_init,(double) 3);
        x= 0.5*pow(x,0.5);
        if (d_abs(x-x_init)<=TOL) {
            printf("The approximate root is %lf\n",x);
        }
        x_init=x;
    }
    printf("Maximum number of iteration reached. The method fail after %d
iterations.\n",max_iter);
}
void fixed_point1(double x_init, double TOL, int max_iter) {
    for (int i=1;i<=max_iter;i++) {
        double x = 10/(4+x_init);
        x=pow(x,0.5);
        if (d_abs(x-x_init)<=TOL) {
            printf("The approximate root is %lf\n",x);
        }
        x_init=x;
    }
    printf("Maximum number of iteration reached. The method fail after %d
iterations.\n",max_iter);
}
void fixed_point1(double x_init, double TOL, int max_iter) {
    for (int i=1;i<=max_iter;i++) {
        double x = pow(x_init,(double) 3)+ 4*pow(x_init,(double) 2)-10;
        x/=3*pow(x_init,(double) 2) + 8*x_init;
        x= x_init -x;
        if (d_abs(x-x_init)<=TOL) {
            printf("The approximate root is %lf\n",x);
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

    fixed_point(x_init,TOL,max_iter);

    return 0;
}