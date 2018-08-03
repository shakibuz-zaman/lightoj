#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int t,i;
    double r,pi;
    pi=2*acos(0.0);
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lf",&r);
        printf("Case %d: %.2f\n",i,4*r*r-pi*r*r);
 
    }
    return 0;
 
}
 