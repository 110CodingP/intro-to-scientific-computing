#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    fp = fopen("fn","w");
    for (int i=1;i<=18;i++) {
        printf("%d ", i);
        double h=pow((double) 10,(double)-i);
        fprintf(fp,"%.18lf ",h);
        printf("%.6e ",h);
        double approx_val=sin(1+h)-sin(1);
        approx_val=approx_val/h;
        printf("%.6e ",approx_val);
        double true_val=cos(1);
        printf("%.6e ",true_val);
        double error=approx_val-true_val;
        error=fabs(error);
        printf("%.6e\n",error);
        fprintf(fp,"%.18lf\n",error);
    }
    fclose(fp);
    return 0;
}