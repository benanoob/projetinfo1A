#include<stdio.h>

int main(){
  double a=0;
  double b=1;
  while(a<b){
    b=b*10;
    a=a*10;
  }
  printf("la val max en double est%lf",a);
}
