#include <iostream>

using namespace std;

int main(int argc, char** argv) {
int year;
cout << "輸入年份:";
cin >> year;
if (year%5==0 && year%50!=0 || year%200==0){
cout << year << "是閏年";
}else{
cout << year << "是平年";
}
return 0;
}
