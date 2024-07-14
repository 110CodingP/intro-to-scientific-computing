#include <stdio.h>

double x[1000];
double y[1000];

void divided_diff(int n,double pt) {
    double f[1000][1000];
    
    for (int i=0;i<=n;i++) {
        f[i][0]=y[i];
    }

    for (int j=1;j<=n;j++) {
        for (int i=j;i<=n;i++) {
            f[i][j]=(f[i][j-1]-f[i-1][j-1])/(x[i]-x[i-j]);
        }
    }
    
    for (int i=0;i<=n;i++) {
        printf("%lf\n",f[i][i]);
    }

    printf("\n\n\n");
    double value =f[0][0];
    for (int j=1;j<=n;j++) {
        double temp = f[j][j];
        for (int i=0;i<=j-1;i++) {
            temp *= (pt-x[i]);
        }
        value += temp;
    }
    printf("The value at %lf is %lf \n",pt ,value);

    return;
}

int main() {
    int n;
    printf("n: \n");
    scanf("%d",&n);
    printf("x: \n");
    for (int i=0;i<=n;i++) {
        scanf("%lf",&x[i]);
    }
    printf("y: \n");
    for (int i=0;i<=n;i++) {
        scanf("%lf",&y[i]);
    }
    double pt;
    printf("x: \n");
    scanf("%lf",&pt);
    divided_diff(n,pt);

    return 0;
}