#include <stdio.h>

double x[1000];
double y[1000];

void linear_spline(int n) {
    double a[1000];
    double b[1000];

    for (int i=0;i<=n-1;i++) {
        a[i]=y[i];
        b[i]=(y[i+1]-y[i])/(x[i+1]-x[i]);
    }

    for (int i=0;i<=n-1;i++) {
        printf("%.8lf %.8lf \n",a[i],b[i]);
    }

    return;
}

int main() {
    int n;
    printf("n \n");
    scanf("%d",&n);
    
    printf("x \n");
    for (int i=0;i<=n;i++) {
        scanf("%lf",&x[i]);
    }

    printf("y \n");
    for (int i=0;i<=n;i++) {
        scanf("%lf",&y[i]);
    }

    linear_spline(n);

    return 0;
}