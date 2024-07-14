#include <stdio.h>

double mat[1000][1000];
double L[1000][1000];
double U[1000][1000];
int solve(int n) {
 for (int i=0;i<n;i++) {
    double sum=0.0;
    for (int k=0;k<i;k++) {
        sum+=L[i][k]*U[k][i];
    }
    
    if ((mat[i][i]-sum)==0) {
        return 0;
    }
    U[i][i]=(mat[i][i]-sum);
    for (int j=i+1;j<n;j++) {
    sum=0.0;
    for (int k=0;k<i;k++) {
     sum+=L[i][k]*U[k][j];
    }
    double another_sum=0.0;
    for (int k=0;k<i;k++) {
     another_sum+=L[j][k]*U[k][i];
    }
        U[i][j]=(mat[i][j]-sum);
        L[j][i]=(mat[j][i]-another_sum)/U[i][i];
    }
 }
 return 1;
}
int main() {
 int n;
 scanf("%d",&n);
 
 
 //taking the matrix as input
 for (int i=0;i<n;i++) {
  for (int j=0;j<n;j++) {
   scanf("%lf",&mat[i][j]);
   U[i][j]=0.0;
   L[i][j]=((i==j)?1.0:0.0);
  }
 }

 int solved=solve(n);
    if (solved) {
     for (int i=1;i<=n;i++) {
      for (int j=1;j<=n;j++) {
       printf("%.1lf ",L[i-1][j-1]);
      }
      printf("\n");
     }
     printf("\n");
     printf("Here is U...\n");
     for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
       printf("%.1lf ",U[i][j]);
     }
     printf("\n");
    }
    }
    else {
     printf("Factorization impossible");
    }
    return 0;
}
