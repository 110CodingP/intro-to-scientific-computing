#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x,(double) 4);
}

void simpson(int n,double a, double b) {
    double h = (b-a)/(2*n);
    double Sh = f(a) + f(b);
    for (int i=0;i<=n-1;i++) {
        Sh = Sh + 4*f(a + (2*i + 1)*h);
    }
    for (int i=1;i<=n-1;i++) {
        Sh = Sh + 2*f(a+ 2*i*h);
    }
    Sh = Sh*h/3;
    printf("%lf <= area\n",Sh);
    return;
}

int main() {
    int n;
    double a,b;
    scanf("%d",&n);
    printf("endpoints: \n");
    scanf("%lf%lf",&a,&b);
    simpson(n,a,b);

    return 0;
}