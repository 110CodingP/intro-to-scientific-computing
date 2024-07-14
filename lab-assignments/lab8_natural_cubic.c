#include <stdio.h>

double x[1000];
double y[1000];

void natural_cubic(int n) {
   double a[1000];
   double b[1000];
   double c[1000];
   double d[1000];

   double l[1000];
   double u[1000];
   double z[1000];

   double h[1000];
   double v[1000];

    for (int i=0;i<=n;i++) {
        a[i]=y[i];
    }
    for (int i=0;i<=n-1;i++) {
        h[i]=x[i+1]-x[i];
    }
    for (int i=1;i<=n-1;i++) {
        v[i]= 3*(a[i+1]-a[i])/h[i] -3*(a[i]-a[i-1])/h[i-1];
    }
    l[0]=1;
    u[0]=0;
    z[0]=0;

    for (int i=1;i<=n-1;i++) {
        l[i]= 2*(h[i-1] + h[i]) - h[i-1]*u[i-1];
        u[i]=h[i]/l[i];
        z[i]=(v[i]-h[i-1]*z[i-1])/l[i];
    }

    l[n]=1;
    z[n]=0;
    c[n]=0;

    for (int i=n-1;i>=0;i--) {
        c[i]= z[i]-u[i]*c[i+1];
        b[i]= (a[i+1]-a[i])/h[i] - h[i]*(2*c[i] + c[i+1])/3;
        d[i]=(c[i+1]-c[i])/3*h[i];
    }
    for (int i=0;i<=n-1;i++) {
        printf("%.8lf %.8lf %.8lf %.8lf\n",a[i],b[i],c[i],d[i]);
    }
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

    natural_cubic(n);

    return 0;
}