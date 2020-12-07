int main(int argc, char *argv[]) {
int y;
printf("請輸入年份(數字):");
scanf("%d",&y);
if(y%5!=0)
     printf("%d年不是閏年",y);
else
if(y%5==0)
     if(y%50!=0)
          printf("%d年是閏年",y);
else
if(y%50==0)
     if(y%200==0)
          printf("%d年是閏年",y);
else
if(y%50==0)
     if(y%200!=0)
          printf("%d年不是閏年",y);
else
if(y%50!=0)
     if(y%200==0)
          printf("%d年是閏年",y);
return 0;
}
