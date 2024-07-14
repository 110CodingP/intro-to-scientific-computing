#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define newline printf("\n")

double mat[1000][1000];
double solution[1000];
double init[1000];
int  max_iter=10;

void gj(int sz) {
    double tmp[1000];
    for (int i=0;i<sz;i++) {
        tmp[i]=init[i];
    }
    for (int l=0;l<max_iter;l++) {
        for (int i=0;i<sz;i++) {
            double sum=0;
            for (int j=0;j<sz;j++) {
                if (j==i) continue;
                sum+=mat[i][j]*tmp[j];
            }
            solution[i]=mat[i][sz]-sum;
            solution[i]/=mat[i][i];
        }
        for (int i=0;i<sz;i++) {
            tmp[i]=solution[i];
        }
        printf("Iteration Number: %d",l+1);
        newline;
        for (int i=0;i<sz;i++) {
            printf("%lf ",solution[i]);
        }
        newline;
    }
}

int main() {
    int sz;
    scanf("%d",&sz);
    for (int i=0;i<sz;i++) {
        for (int j=0;j<sz+1;j++) {
            scanf("%lf",&mat[i][j]);
        }
    }
    for (int i=0;i<sz;i++) {
        scanf("%lf",&init[i]);
    }
    scanf("%d",&max_iter);
    gj(sz);
    return 0;
}