#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define separator printf("\n\n\n***********************************\n\n\n")

double x[100];
double y[100];
double yD[100];
double z[100];
double q[100][100];
double a[100];
double b[100];
double c[100];
double d[100];

void hermite(int n) {
    for (int i=0;i<=n;i++) {
        z[2*i]=x[i];
        z[2*i+1]=x[i];

        q[2*i][0]=y[i];
        q[2*i+1][0]=y[i];
        
        q[2*i+1][1]=yD[i];
    }
    for (int i=2;i<=2*n+1;i++) {
        for (int j=2;j<=i;j++) {
            q[2*i][1]=(q[i][j-1] - q[i-1][j-1])/(z[i]-z[i-j]);
        }
    }
    for (int i=0;i<=2*n+1;i++) {
        printf("%lf\n",q[i][i]);
    }
}

// void linearSpline(int n) {
//     for (int i=0;i<n;i++) {
//         a[i]=y[i];
//         b[i]=y[i+1]-y[i];
//         b[i]/=(x[i+1]-x[i]);
//     }
//     for (int i=0;i<n;i++) {
//         printf("%lf %lf\n",a[i],b[i]);
//     }
// }

// void naturalCubicSpline(int n) {
//     double l[100];
//     double h[100];
//     double v[100];
//     double u[100];
//     double z[100];
//     for (int i=0;i<n;i++) {
//         a[i]=y[i];
//         h[i]=x[i+1]-x[i];
//     }
//     for (int i=1;i<n;i++) {
//         v[i]=3*(a[i+1]-a[i])/h[i];
//         v[i]-= 3*(a[i]-a[i-1])/h[i-1];
//     }
//     l[0]=1;
//     u[0]=0;
//     x[0]=0;

//     for (int i=1;i<n;i++) {
//         l[i]=2*(h[i-1]+h[i])-h[i-1]*u[i-1];
//         u[i]=h[i]/l[i];
//         z[i]=(v[i]-h[i-1]z[i-1])/l[i];
//     }
//     l[n]=1;
//     z[n]=0;
//     c[n]=0;
//     for (int j=n-1;j>=0;j--) {
//         c[j]=z[j]-u[j]c[j+1];
//         b[j]=(a[j+1]-a[j])/h[j];
//         b[j]-=h[j](c[j+1] + 2*c[j])/3;
//         d[j]=c[j+1]-c[j];
//         d[j]/=3*h[j];
//     }
//     for (int i=0;i<n;i++) {
//         printf("%lf %lf %lf %lf\n",a[i],b[i],c[i],d[i]);
//     }
// }

// void clampedCubicSpline(int n) {
//     double h[100];
//     double v[100];
//     double l[100];
//     double u[100];
//     double z[100];

//     for (int i=0;i<=n;i++) {
//         a[i]=y[i];
//     }
//     double L= yD[0];
//     double R = yD[n];
//     for (int i=0;i<n;i++) {
//         h[i]=x[i+1]-x[i];
//     }
//     v[0]=3*(a[1]-a[0])/h[0]-3*L;
//     v[n]=3*R - 3*(a[n]-a[n-1])/h[n-1];
//     for (int i=1;i<n;i++) {
//         v[i]=3*(a[i+1]-a[i])/h[i];
//         v[i]-= 3*(a[i]-a[i-1])/h[i-1];
//     }
//     l[0]=2*h[0];
//     u[0]=0.5;
//     z[0]=v[0]/l[0];
//     for (int i=1;i<n;i++) {
//         l[i]=2*(h[i-1]+h[i])-h[i-1]u[i-1];
//         u[i]=h[i]/l[i];
//         z[i]=(v[i]-h[i-1]*z[i-1])/l[i];
//     }
//     l[n]=h[n-1]*(2-u[n-1]);
//     z[n]=v[n]-h[n-1]*z[n-1]/l[n];
//     c[n]=z[n];
//     for (j=n-1;j>=0;j--) {
//         c[j]=z[j]-u[j]c[j+1];
//         b[j]=(a[j+1]-a[j])/h[j]-(h[j]*(c[j+1]+ 2*c[j]))/3;
//         d[j]=(c[j+1]-c[j])/(3*h[j]);
//     }
//     for (int i=0;i<n;i++) {
//         printf("%lf %lf %lf %lf \n",a[i],b[i],c[i],d[i]);
//     }
// }

int main() {
    //input n
    int n;
    scanf("%d",&n);
    //input pt values
    for (int i=0;i<n;i++) {
      scanf("%lf",&x[i]);
    }
    //input func values
    for (int i=0;i<n;i++) {
        scanf("%lf",&y[i]);
    }
    //input deriv  values
    for (int i=0;i<n;i++) {
        scanf("%lf",&yD[i]);
    }
    
    hermite(n);


    separator;


    // scanf("%d",&n);
    // //input pt values
    // for (int i=0;i<n;i++) {
    //   scanf("%lf",&x[i]);
    // }
    // //input func values
    // for (int i=0;i<n;i++) {
    //     scanf("%lf",&y[i]);
    // }
    // linearSpline(n);


    // separator;


    // scanf("%d",&n);
    // //input pt values
    // for (int i=0;i<n;i++) {
    //   scanf("%lf",&x[i]);
    // }
    // //input func values
    // for (int i=0;i<n;i++) {
    //     scanf("%lf",&y[i]);
    // }
    // naturalCubicSpline(n);
    // separator;


    // scanf("%d",&n);
    // //input pt values
    // for (int i=0;i<n;i++) {
    //   scanf("%lf",&x[i]);
    // }
    // //input func values
    // for (int i=0;i<n;i++) {
    //     scanf("%lf",&y[i]);
    // }
    // //input deriv  values
    // for (int i=0;i<n;i++) {
    //     scanf("%lf",&yD[i]);
    // }
    // clampedCubicSpline(n);

    return 0;
}