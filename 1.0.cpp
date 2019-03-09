#include<iostream>//基本輸出入
#include<cstdlib>//常用函數庫(亂數取得)
#include<ctime>//時間函數
#include<fstream>//讀檔案
#include<windows.h>//延時 
void Ra_setting(void);//讀取基礎設定
int not_likely(void);//亂數取得
void List_one(void);//名單讀取1
void List_two(char LA[][100]);//名單讀取2
using namespace std;//使用命名空間std。 
int NofP=0,X=1,i=0;//NofP(Number of people)。X為抽X人。i迴圈用
int main()
{
	Ra_setting();//呼叫副程式Ra_setting，得以讀取Basic_setting.txt。
	List_one();//呼叫副程式List_one，得以取得NofP(要抽的筆數)。
	char LA[NofP][100]={'\0'};//宣告一個叫LA的二維字元陣列，元素量為NofP*100，整個陣列初始值為'\0'。
	List_two(LA);//呼叫副程式List_two並且將二維字元陣列LA傳入，得以將名單資料全部輸入至LA內。 
	//===============
	int N=0;//N為最後結果輸出
	for(;X>0;X--)//X為抽取之筆數，將X輸出一次減一，得以做到輸出至輸入之次數。 
	{
	N=not_likely();//取得亂數。 
	cout << LA[N] << endl;//輸出將亂數作為索引值的陣列內容。 
	}
	system("pause");//使用執行檔時，結尾所需。
}
//==================================================================
void Ra_setting()//讀取基礎設定檔案 
{
	char SI[150]={'\0'};//宣告一個叫SI的字元陣列，元素量為150，整個陣列初始值為'\0'。 
	fstream setting;//以fstream建立檔案輸出、物件setting
	if(setting.is_open()==true)//檔案如果開啟即關檔
		setting.close();//關閉Basic_setting.txt檔，物件setting 
	else
		setting.open("Basic_setting.txt",ios::in);//開啟Basic_setting.txt以讀取的方式(ios::in)打開
	if(!setting)//是否開檔失敗
		cout << "Basic_setting.txt => Error" << endl;//讓使用者知道Basic_setting.txt有問題，此時還不需離開程式因還需判定List.txt是否可以。 
	//第一行是否需要輸入。0為需要，大於0的為不需要
	setting.getline(SI,150);//從Basic_setting.txt讀取一行至SI這個字元陣列內，後面的150是元素量。 
	for(i=0;'0'<=SI[i]&&SI[i]<='9'&&i<150;i++)//如果該行開頭讀到字元'1'~'9'就進入迴圈，而後i重複加一判定到SI陣列的最後。 
	{
		if(i==0)X=0;//如果成功進入該迴圈，一開始i=0，所以此時將X=0。 
		X+=(int)SI[i]-48;//將SI陣列，索引i，強制轉型為整數型態再減48即可得到該數值，而後加進X內。 
		if('0'<=SI[i+1]&&SI[i+1]<='9')X*=10;//如果該迴圈目前判定的下一位還是為數字就 
	}
		while(X==0)cin >> X;//如果輸入需抽之人數(X)為0就再重新輸入 
	setting.close();//關閉.Basic_setting.txt檔，物件setting 
}
//===================================================================
int not_likely(void)//亂數取得
{	int n=0;//宣告一個叫n，資料型態為int，初始為0。 
	srand((int)time(NULL));n=rand()%NofP;//以時間為亂數種子，而後取得亂數再將其取NofP的餘數。 
	return n;//回傳n(亂數計算完之結果)。 
}
//====================================================================
void List_one(void)//名單檔案讀取1(確認抽獎筆數)
{
	fstream List;//以fstream建立檔案輸出、物件List
	if(List.is_open()==true)//檔案如果開啟即關檔
		List.close();//關閉List.txt檔 
	else
		List.open("List.txt",ios::in);//開啟List.txt以讀取的方式(ios::in)打開
	if(!List)//是否開檔失敗
	{
		cout << "List.txt => Error" << endl;//讓使用者知道List.txt有問題。 
		system("pause");//使用執行檔時，結尾所需 。 
		exit(0);//讓使用者看完哪裡錯誤後離開程式。 
	}
	char T[100]={'\0'};//宣告一個叫T的字元陣列，元素量為100，整個陣列初始值為'\0'。 
	while(!List.eof())//取得需抽的個數，eof()是否為檔案結尾 
	{
		List.getline(T,100);//從List.txt讀取一行至T這個字元陣列內，後面的100是元素量。 
		if(0<=T[0]&&T[0]<=31||T[0]==127)NofP-=1;//如果輸入的第一個字為不可顯示之字元，將NofP減一。 
		NofP++;//讀過一行後將NofP加一。 
	} 
	List.close();//關閉List.txt檔
}
void List_two(char LA[][100])//名單檔案讀取2(將資料讀取進陣列)
{
	fstream List;//以fstream建立檔案輸出、物件List
	if(List.is_open()==true)//檔案如果開啟即關檔
		List.close();//關閉List.txt檔
	else
		List.open("List.txt",ios::in);//開啟List.txt以讀取的方式(ios::in)打開
	if(!List)//是否開檔失敗 
	{
		cout << "List.txt => Error" << endl;//讓使用者知道List.txt有問題。 
		system("pause");//使用執行檔時，結尾所需 。 
		exit(0);//讓使用者看完哪裡錯誤後離開程式。
	}
	for(i=0;i<NofP;i++)//將名單資料讀入陣列 
	{
		List.getline(LA[i],100);//從List.txt讀取一行至LA[i]這個字元陣列內，後面的100是元素量。(LA是二維陣列)。
		if(0<=LA[i][0]&&LA[i][0]<=31||LA[i][0]==127)i-=1;//如果該行為多餘行數，將i減一，以便換一行讀入可用行數。
	} 
	List.close();//關閉List.txt檔
}
//==============================================
