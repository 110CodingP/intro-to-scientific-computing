#include <stdio.h>
#include <stdlib.h>

#define SEPARATOR "\n\n\n*********\n\n\n"

int num_iter=10;
double omega=1.25;
void print_vec(int sz,double* vec) {
 for (int i=0;i<sz;i++) {
 printf("%lf ",vec[i]);
 }
 printf("\n");
}
void gj(int sz,double** arr,double* b,double* solution,double* init) {
 double* tmp_init=init;
 double *tmp=(double*) calloc(sz,sizeof(double));
 printf("Initial Vector is: ");
 print_vec(sz,tmp_init);
 for (int ct=0;ct<num_iter;ct++) {
 for (int i=0;i<sz;i++) {
 double sum=0;
 for (int j=0;j<sz;j++) {
 if (j==i) continue;
 sum+=arr[i][j]*init[j];
 }
 tmp[i]=b[i]-sum;
 tmp[i]/=arr[i][i];
 }
 printf("Iteration No. %d\n",ct+1);
 print_vec(sz,tmp);
 tmp_init=tmp;
 }
 solution =tmp;
}

void gs(int sz,double** arr,double* b,double* solution,double* tmp_init) {
 double *tmp=tmp_init;
 printf("Initial Vector is: ");
 print_vec(sz,tmp);
 for (int ct=0;ct<num_iter;ct++) {
 for (int i=0;i<sz;i++) {
 double sum=0;
 for (int j=0;j<i;j++) {
 sum+=arr[i][j]*tmp[j];
 }
 for (int j=i+1;j<sz;j++) {
 sum+=arr[i][j]*tmp[j];
 }
 tmp[i]=b[i]-sum;
 tmp[i]/=arr[i][i];
 }
 printf("Iteration No. %d\n",ct+1);
 print_vec(sz,tmp);
 }
 solution =tmp;
}

void sor(int sz,double** arr,double* b,double* solution,double* init,int omega) {
 double *tmp_init=init;
 double *tmp=(double*) calloc(sz,sizeof(double));
 printf("Initial Vector is: ");
 print_vec(sz,tmp_init);
 for (int ct=0;ct<num_iter;ct++) {
 for (int i=0;i<sz;i++) {
 double sum=0;
 for (int j=0;j<i;j++) {
 sum+=arr[i][j]*tmp[j];
 }
 for (int j=i+1;j<sz;j++) {
 sum+=arr[i][j]*init[j];
 }
 tmp[i]=b[i]-sum;
 tmp[i]/=arr[i][i];
 tmp[i]*=omega;
 tmp[i]+=(1-omega)*init[i];
 }
 printf("Iteration No. %d\n",ct+1);
 print_vec(sz,tmp);
 tmp_init=tmp;
 }
 solution =tmp;
}

int main() {
 double **arr,*b,*solution,*init;
 int sz;
 printf("Please enter the number of rows in the matrix\n");
 scanf("%d",&sz);
 arr=(double**) malloc(sz*sizeof(double*));
 for (int i=0;i<sz;i++) {
 arr[i]=(double*)malloc(sz*sizeof(double));
 }
 b=(double*)malloc(sz*sizeof(double));
 solution=(double*)malloc(sz*sizeof(double));
 printf("Please enter the matrix\n");
 for (int i=0;i<sz;i++) {
 for (int j=0;j<sz;j++) {
 scanf("%lf",&arr[i][j]);
 while (arr[i][i]==0) {
 printf("Diagonal element cannot be zero.Please re-enter the value\n");
         scanf("%lf",&arr[i][i]);
 }
 }
 }
 printf("Please enter b\n");
 for (int i=0;i<sz;i++) {
 scanf("%lf",&b[i]);
 }
 printf("Please enter the number of iterations\n");
 scanf("%d",&num_iter);
    init = (double*)malloc(sz*sizeof(double));
 printf("Please enter the initial vector: ");
 for (int i=0;i<sz;i++) {
 scanf("%lf",&init[i]);
 }
 printf("\n");
 printf("Please enter value of omega for SOR: ");
 scanf("%lf",&omega);
 printf("\n");
 printf("The solution using Gauss-Jacobi method is:\n");
 gj(sz,arr,b,solution,init);
 printf(SEPARATOR);
 printf("The solution using Gauss-Seidal method is:\n");
 gs(sz,arr,b,solution,init);
    printf(SEPARATOR);
 printf("The solution using SOR method is :\n");
 sor(sz,arr,b,solution,init,omega);
 return 0;
}