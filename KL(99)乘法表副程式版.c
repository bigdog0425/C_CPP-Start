#include <stdio.h>
#include <stdlib.h>

int star(int x){
int l;
for(l=1;l<=x;l++){
printf("*");
}
}
int main(int argc, char *argv[]) {
int i,k,a,b,c,x;
printf("依序輸入星星、被乘數、乘數");
scanf("%d%d%d",&x,&b,&c);
star(x);
printf("\n");
for(i=1;i<=b;i++){
printf("\n");
for(k=1;k<=c;k++){
a=i*k;
if(a>=10){
printf("%dX%d=%d ",i,k,a);
}
else{
printf("%dX%d= %d ",i,k,a);
}
}
}
printf("\n");
printf("\n");
star(x);
return 0;
}
