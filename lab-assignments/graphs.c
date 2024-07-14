#include <stdio.h>


int main() {
    FILE *fp = NULL;
    fp = fopen("data.dat","w");
    for (int i=0;i<100;i++) {
        fprintf(fp,"%d %d\n",i, i*i);
    }
    fclose(fp);
    return 0;
}