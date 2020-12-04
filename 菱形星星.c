#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
int i,j,k,x,a;
printf("請輸入一行中最多幾顆*");
scanf("%d",&x);
a=(x-1)/2;
for(i=1;i<=a+1;i++){
for(k=1;k<=a-i+1;k++){
printf(" ");
}
for(j=1;j<=i*2-1;j++){
printf("*");
}
printf("\n");
}
for(i=a;i>=1;i--){
for(k=1;k<=a-i+1;k++){
printf(" ");
}
for(j=1;j<=i*2-1;j++){
printf("*");
}
printf("\n");
}
return 0;
}
