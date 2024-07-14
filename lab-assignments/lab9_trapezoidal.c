#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x,(double) 4);
}

void trapezoidal(int n, double a,double b) {
    double h = (b-a)/n;
    double Th = (f(b) + f(a))/2;
    for (int i=1;i<=n-1;i++) {
        Th = Th + f(a + i*h);
    }
    Th = h*Th;
    printf("%lf is the area\n",Th);
    return;
}

int main() {
    int n;
    scanf("%d",&n);

    double a,b;
    printf("a: \n");
    scanf("%lf",&a);
    printf("b: \n");
    scanf("%lf",&b);

    trapezoidal(n,a,b);

    return 0;
}