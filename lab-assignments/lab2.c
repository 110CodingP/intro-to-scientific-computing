#include <stdio.h>
#include <math.h>
double AC=cos((double) 1);
double approxDeriv(double h) {
	double ret=sin((double)1+h);
	ret-=sin((double)1);
	ret/=h;
	return ret;
}
double absError(long double app) {
	double ret=(AC-app);
	ret = (ret>=0)?ret:-ret;
	return ret;
}
int main() {
	
	for (int k=1;k<=18;k++) {
		double h=pow((double) 10,(double) -k);
        double app=approxDeriv(h);
        double err=absError(app);
        printf("%2d %.6e %.6e %.6e %.6e\n",k,h,app,AC,err);
	}
	return 0;
}