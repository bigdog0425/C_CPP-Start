#include <iostream>

using namespace std;

int star(int n){
for(int i=0;i<n;i++){
cout << "*";
}
cout << "\n";
}

int main(int argc, char** argv) {
int n,a,b;
cout << "輸入星星:";
cin >> n;
cout << "輸入被乘數:";
cin >> a;
cout << "輸入乘數:";
cin >> b;
star(n);
for(int i=1;i<=a;i++){
for (int j=1;j<=b;j++){
cout << i << "x" << j << "=" << i*j << " ";
if (i*j<10){
cout << "  ";
}
if (i*j<100 && i*j >= 10){
cout << " ";
}

}
cout << "\n";
}
star(n);
return 0;
}
