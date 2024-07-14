#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int a=1;
  int e=0;
  double delta=0;
  for (int i=0;;i--) {
    if (a+pow((double)10,(double) i) ==1) {
       e=i;
       cout<<e<<endl;
       break;
    }
  }
  for (int i=1;i<=15;i++) {
    for (int j=9;j>0;j--) {
      if ((a+delta+j*pow((double) 10, (double) e-i+1))==1) {
        delta+=j*pow((double) 10, (double) e-i+1);
        cout<<j<<endl;
        break;
      }
    }
  }
  cout<<delta<<endl;
	return 0;
}