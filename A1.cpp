#include<iostream>//基本輸出入
#include<cstdlib>//亂數取得
#include<ctime>//時間函數
#include<fstream>//讀檔案
int not_likely(void);//亂數取得
void List_one(void);//名單讀取1
void List_two(char LA[][100]);//名單讀取2
using namespace std;
int NofP=0;//NofP(Number of people)。
int main()
{
	int i=0;
	char CX[100]={'\0'},SI='\0';
	fstream setting;//以fstream建立檔案輸出、物件setting
	if(setting.is_open()==true)//檔案如果開啟即關檔
		setting.close();
	else
		setting.open("Basic_setting.txt",ios::in);
	if(!setting)
		cout << "Basic_setting.txt => Error" << endl;
	List_one();
	char LA[NofP][100]={'\0'};
	List_two(LA);
	//cin >> CX;
	int N=0,X=0;//N為最後結果輸出，X為抽X人
	N=not_likely();//取得亂數 
	cout << LA[N] << endl;//輸出將亂數作為索引值的陣列內容 
	setting.close();
}
//===================================================================
int not_likely(void)//亂數取得
{	int n=0;
	srand((int)time(NULL));n=rand()%NofP;
	//srand(n);n=rand()%NofP;
	return n;
}
//====================================================================
void List_one(void)//名單檔案讀取1(確認抽獎筆數)
{
	int i=0;//i迴圈用
	fstream List;//以fstream建立檔案輸出、物件List
	if(List.is_open()==true)//檔案如果開啟即關檔
		List.close();
	else
		List.open("List.txt",ios::in);
	if(!List)
	{
		cout << "List.txt => Error" << endl;
		system("pause");
		exit(0);
	}
	char T[100]={'\0'};
	while(!List.eof())//取得需抽的個數
	{
		List.getline(T,100);
		if(0<=T[0]&&T[0]<=31||T[0]==127)NofP-=1;//如果輸入的第一個字非可顯示字元
		NofP++;
	}
	List.close();
}
void List_two(char LA[][100])//名單檔案讀取2(將資料讀取進陣列)
{
	fstream List;//以fstream建立檔案輸出、物件List
	if(List.is_open()==true)//檔案如果開啟即關檔
		List.close();
	else
		List.open("List.txt",ios::in);
	if(!List)
	{
		cout << "List.txt => Error" << endl;
		system("pause");
		exit(0);
	}
	int i=0;
	for(i=0;i<NofP;i++)
		List.getline(LA[i],100);
	List.close();
}
//==============================================
