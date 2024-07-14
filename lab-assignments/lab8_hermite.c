#include <stdio.h>
double x[1000];
double y[1000];
double d[1000];

void hermite(int n, double pt) {   
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
    double value = q[0][0];
    for (int j=1;j<=2*n+1;j++) {
        double temp = q[j][j];
        for (int i=0;i<=j-1;i++) {
            temp *= (pt-z[i]);
        }
        value += temp;
    }
    printf("%lf is the value at %lf\n",value,pt);
    return;
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<=n;i++) {
      scanf("%lf",&x[i]);
    }
    for (int i=0;i<=n;i++) {
        scanf("%lf",&y[i]);
    }
    for (int i=0;i<=n;i++) {
        scanf("%lf",&d[i]);
    }
    printf("x: \n");
    double pt;
    scanf("%lf",&pt);
    hermite(n,pt);
    return 0;
}