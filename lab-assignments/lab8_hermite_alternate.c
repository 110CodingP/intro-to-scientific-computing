#include <stdio.h>

double x[1000];
double y[1000];
double d[1000];


void hermite(int n) {
    double z[1000];
    double q[1000][1000];

    for (int i=0;i<=n;i++) {
        z[2*i]=x[i];
        z[2*i+1]=x[i];

        q[2*i][0]=y[i];
        q[2*i+1][0]=y[i];

        q[2*i+1][1]=d[i];
        if (i!=0) {
            q[2*i][1]=(q[2*i][0]-q[2*i-1][0])/(z[2*i]-z[2*i-1]);
        }
    }
    for (int j=2;j<=2*n+1;j++) {
        for (int i=j;i<=2*n+1;i++) {
            q[i][j]=(q[i][j-1]-q[i-1][j-1])/(z[i]-z[i-j]);
        }
    }

    for (int i=0;i<=2*n+1;i++) {
        printf("%lf \n",q[i][i]);
    }
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
    printf("derivatives: \n");
    for (int i=0;i<=n;i++) {
        scanf("%lf",&d[i]);
    }

    hermite(n);
    return 0;
}