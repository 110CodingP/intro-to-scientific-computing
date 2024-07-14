#include <stdio.h>

double mat[1000][1000];
double solution[1000];
int solve(int n) {
 for (int i=0;i<n;i++) {
 for (int p=i;p<n;p++) {
 if (mat[p][i]!=0) {
   if (p!=i) {
    for (int j=0;j<n+1;j++) {
      double temp=mat[i][j];
      mat[i][j]=mat[p][j];
      mat[p][j]=temp;
    }
   }
   break;
  }
    if (p==n) {
      return 0;
    }
 }
  for (int k=i+1;k<n;k++) {
   double factor=mat[k][i]/mat[i][i];
   for (int j=i;j<n+1;j++) {
    mat[k][j]-=factor*mat[i][j];
   }
  }
  for (int r=0;r<n;r++) {
    for (int c=0;c<n+1;c++) {
        printf("%3.1lf ",mat[r][c]);
    }
    printf("\n");
 }
 printf("\n");
 }
 if (mat[n-1][n-1]==0) {
 return 0;
 }
  for (int c=n;c>=0;c--) {
 double sum=0;
 for (int j=n-1;j>c;j--) {
 sum+=mat[c][j]*solution[j];
 }
 solution[c]=mat[c][n]-sum;
 solution[c]/=mat[c][c];
 }
 return 1;
}
int main() {
 int n;
 scanf("%d",&n);
 
 //taking matrix as input
 for (int i=0;i<n;i++) {
 for (int j=0;j<n+1;j++) {
 scanf("%lf",&mat[i][j]);
 }
 }
 int solved=solve(n);
    if (solved) {
    for (int i=0;i<n;i++) {
    printf("%lf\n",solution[i]);
 }
 }
 else {
 printf("no unique solution exists");
 }
 return 0;
}