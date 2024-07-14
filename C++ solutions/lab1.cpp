#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long double a,b,c;
    int exp1,exp2,exp3;
    cout<<"Please enter the first part of a: ";
    cin>>a;
    cout<<"Please enter the exponent of a: ";
    cin>>exp1;
    cout<<"Please enter the first part of b: ";
    cin>>b;
    cout<<"Please enter the exponent of b: ";
    cin>>exp2;
    cout<<"Please enter the first part of c: ";
    cin>>c;
    cout<<"Please enter the exponent of c: ";
    cin>>exp3;
    if ((1+a*pow(10,exp1))==1) {
      cout<<"This is not a quadratic equation or a is too small"<<endl;
      cout<<"The root is "<<(-1*c/b)*pow((double) 10, (double) exp3-exp2)<<endl;
    }
    else if ((c*pow(10,exp3))==0) {
      cout<<"The roots are: "<<0<<" "<<(-b/a)*pow((double) 10,(double)exp2-exp1)<<endl;
    }
    else {
      int exp=min(min(exp1,exp2),exp3);
      a=a*(pow((double)10,(double)exp1-exp));
      b=b*(pow((double)10,(double) exp2-exp));
      c=c*(pow((double) 10,(double) exp3-exp));
      long double d= b*b - 4*a*c;
      if (d<0) {
      	cout<<"This equation has no real roots"<<endl;
      	d = sqrt(-d);
        long double first_imaginary=d;
        first_imaginary/=2*a;
        b=-b;
        b/=2*a;
        long double second_imaginary= -d;
        second_imaginary/=2*a;
        cout<<"The roots are: "<<b<<" + "<<first_imaginary<<"i"<<" "<<b<<" + "<<second_imaginary<<"i"<<endl;
      }
      else {
        d = sqrt(d);
        long double first= -1*b + d;
        first/=2*a;
        long double second= -1*b-d;
        second/=2*a;
        cout<<"The roots are: "<<first<<" "<<second<<endl;
      }
    }
	return 0;
}