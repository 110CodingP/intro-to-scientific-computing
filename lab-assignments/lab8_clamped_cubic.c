#include <stdio.h>

double x[1000];
double y[1000];

void clamped_cubic(int n , double L, double R, double pt) {
    double a[1000];
    double b[1000];
    double c[1000];
    double d[1000];
    double l[1000];
    double u[1000];
    double z[1000];
    double v[1000];
    double h[1000];
    
    for (int i=0;i<=n;i++) {
        a[i]=y[i];
    }

    for (int i=0;i<=n-1;i++) {
        h[i]=x[i+1]-x[i];
    }

    v[0]= 3*(a[1]-a[0])/h[0]-3*L; //not there
    v[n]= 3*R-3*(a[n]-a[n-1])/h[n-1]; //not there

    for (int i=1;i<=n-1;i++) {
        v[i]=3*(a[i+1]-a[i])/h[i]-3*(a[i]-a[i-1])/h[i-1]; //fmla
    }

    l[0]=2*h[0]; //1
    u[0]=0.5;   //0
    z[0]=v[0]/l[0];     //0

    for (int i=1;i<=n;i++) {
        l[i]=2*(h[i-1]+h[i]) - h[i-1]*u[i-1];  //fmla
        u[i]=h[i]/l[i];  //fmla
        z[i]=(v[i]-h[i-1]*z[i-1])/l[i]; //fmla
    }

    l[n]= h[n-1]*(2-u[n-1]); //1;
    z[n]=(v[n]-h[n-1]*z[n-1])/l[n]; //0;
    c[n]=z[n]; //like before;

    for (int i=n-1;i>=0;i--) {
        c[i]=z[i]-u[i]*c[i+1]; //fmla
        b[i]=(a[i+1]-a[i])/h[i] - h[i]*(2*c[i]+c[i+1])/3; //fmla
        d[i]=(c[i+1]-c[i])/(3*h[i]); //fmla
    }
    for (int i=0;i<=n-1;i++) {
        printf("%lf %lf %lf %lf\n",a[i],b[i],c[i],d[i]);
    }
    double value = 0.0;
    for (int i=0;i<=n-1;i++) {
        if (pt<=x[i+1]&&pt>=x[i]) {
           value += a[i] + b[i]*(pt - x[i]) + c[i]*(pt - x[i])*(pt - x[i]) + d[i]*(pt - x[i])*(pt - x[i])*(pt - x[i]);
           break;
        }
    }
    printf("%lf <= value\n",value);
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
    double L,R;
    printf("derivatives: \n");
    scanf("%lf",&L);
    scanf("%lf",&R);
    printf("x: \n");
    double pt;
    scanf("%lf",&pt);
    clamped_cubic(n,L,R,pt);

    return 0;
}