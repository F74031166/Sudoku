#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include"Sudoku.h"
#define size 144

using namespace std;
//int gue[size];
/*int count,column,row,blocknine=0,countB,start;//函式
int test[9];//函式
bool result;//函式
int arr_test[9];//函式
int t;//函式*/
//bool check(int sudonum,int position);
//bool checkUnity(int oriarr[]);
//bool checkUnityall(int arr[]);



//

void Sudoku::ReadIn()
{
	int k;
	for(k=0;k<size;k++)//輸入答案
		cin>>gue[k];
	return;
}

void Sudoku::Solve()
{	
	int i,j,k,l=0;
	int spaceps[size];//這個陣列是要存入空格位置數i
	int spacenum=0;//這個變數是要計算空格0個數
	int ans[size];
	for(i=0;i<size;i++)
	{
		if(gue[i]==-1)
			l++;//計算-1數若不到36個則回傳0(無解)
		ans[i]=0;
		spaceps[i]=0;
	}
	if(l!=36)
	{
		cout<<0<<endl;
		return ;
	}
	/*for(i=0;i<size;i++)//輸入答案
		cin>>gue[i];*/
	//cout<<endl;test
	/*for(i=0;i<size;i++)//印出答案
	{	
		cout<<gue[i]<<' ';
		if((i+1)%12==0)
			cout<<endl;
	}*/
	//cout<<endl;//1
	//bool checkfirst=true;
	//int testf[9];
	//int t=0;
	//int blockhead=0;
	/*for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			if(gue[i*12+j]!=-1)
			{
				testf[t]=gue[i*12+j];
				t++;
			}
		}
		checkfirst=checkUnity(testf);
		if(checkfirst==false)
		{
			cout<<0<<endl;
			return ;
		}
		t=0;
		for(j=0;j<12;j++)
		{
			if(gue[i+j*12]!=-1)
			{
				testf[t]=gue[i+j*12];
				t++;			
			}	
		}
		checkfirst=checkUnity(testf);
		if(checkfirst==false)
		{
			cout<<0<<endl;
			return ;
		}
		t=0;
		if(gue[blockhead]==-1)
			blockhead+=3;
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				testf[t]=gue[blockhead+j*12+k];
				t++;
			}
		}
		checkfirst=checkUnity(testf);   //本來有用現在沒屁用
		if(checkfirst==false)
		{
			cout<<0<<endl;
				return ;
		}
		t=0;
		blockhead+=3;
		if((i+1)%3==0)
			blockhead=((i+1)/3)*36;
	}*/
	for(i=0;i<size;i++)//計算空格數
	{
		if(gue[i]==0)
		{	
			//cout<<i<<endl;//test
			spacenum++;//計算空格0數
			spaceps[spacenum-1]=i;//並將其位置一一放入spaceps[]
		}
	}
	int flag=0,num=0,a,tc;
	j=0;
	i=spaceps[j];//起始點
	bool checkit;
	int time=0;
	for(;;num++)
	{
		num=gue[i]+1;//從原本空格所填之數+1開始填
		checkit=check(num,i);//補   check function
		if(checkit==true)//此格有解
		{
			gue[i]=num;
			num=0;
			j++;
			if(j==spacenum)//填完了  放在checkit==true裡
			{ 
				if(flag==0)
				{
					for(a=0;a<size;a++)
						ans[a]=gue[a];
				}
				//cout<<"check!!!\n";
				j--;
				i=spaceps[j];//填完了往回檢查是否多重解
				flag++;
				if(flag==2)
					break;
				time++;
				continue;
			}
			time++;
			i=spaceps[j];
			continue;
		}
		else if(num>=9&&checkit==false)//此格無解  origin=(num>=9&&checkit==false)
		{
			gue[i]=0;//  9(X) -> 9(X)  ->  1~9(X) ->
			j--;
			if(j==-1&&flag==0)//無解  跳脫
			{
				flag=-1;
				break;
			}
			if(j==-1&&flag==1)
				break;
			i=spaceps[j];
			time++;
			continue;
		}
		/*else if(j==spacenum-1)//填完了  可能得放在checkit==true裡
		{
			if(flag==0)
			{
				for(a=0;a<size;a++)
					ans[a]=gue[a];
			}
			j--;
			i=spaceps[j];
			flag++;
			if(flag==2)
				break;
		}*/
		/*for(tc=0;tc<size;tc++)//印出答案
		{		
			cout<<gue[tc]<<' ';
			if((tc+1)%12==0)
				cout<<endl;
		}*/
		//cout<<endl<<i<<"   "<<num<<endl;
		time++;
	}
	switch(flag)
	{
		case -1: cout<<0<<endl;break;
		case  1: cout<<1<<endl; 
				for(i=0;i<size;i++)
				 {
				 	cout<<' '<<ans[i];
					if((i+1)%12==0)
					cout<<endl;
				 }
				break;
		case  2: cout<<2<<endl;
				/*for(i=0;i<size;i++)
				 {
				 	cout<<' '<<ans[i];
					if((i+1)%12==0)
					cout<<endl;
				 }*/
				 break;
	}
	cout<<"it takes "<<time<<"times!!"<<endl;
}





void Sudoku::GiveQuestion()
{
	int i;
	srand(time(NULL));
	int r=random()%5+1;
	if(r==1)
	{
		cout<<r<<endl;
		int e;
		int another1[size]={
			0,2,0,0,0,0,0,0,1,-1,-1,-1,
			0,0,3,9,5,0,0,0,0,-1,-1,-1,
			0,0,0,0,0,4,0,0,0,-1,-1,-1,
			-1,-1,-1,0,0,0,0,8,7,0,0,6,
			-1,-1,-1,0,8,0,0,0,0,0,2,0,
			-1,-1,-1,4,0,6,0,0,0,0,0,0,
			1,0,0,0,0,0,-1,-1,-1,0,9,0,
			0,0,4,0,6,0,-1,-1,-1,0,0,7,
			0,0,5,0,1,7,-1,-1,-1,0,8,0,
			0,1,0,-1,-1,-1,7,0,0,5,0,9,
			7,0,8,-1,-1,-1,0,6,0,3,0,2,
			0,6,0,-1,-1,-1,3,1,0,0,0,0};
		for(e=0;e<size;e++)
		{
			cout<<another1[e]<<' ';
			if((e+1)%12==0)
				cout<<endl;
		}
	}
	else if(r==2)
	{
		cout<<r<<endl;
		int two;
		int another2[size]={
	0,0,0,0,4,2,0,5,0,-1,-1,-1,
	0,0,3,9,0,5,7,0,0,-1,-1,-1,
	0,6,0,0,0,0,4,0,0,-1,-1,-1,
	0,1,5,-1,-1,-1,0,0,0,0,0,0,
	0,0,0,-1,-1,-1,2,0,0,0,0,0,
	0,0,6,-1,-1,-1,0,0,0,0,2,0,
	-1,-1,-1,5,0,0,0,0,6,0,1,0,
	-1,-1,-1,6,0,0,0,2,0,0,0,0,
	-1,-1,-1,0,9,1,0,0,0,0,0,8,
	0,0,0,0,0,0,-1,-1,-1,0,0,0,
	7,5,0,4,0,0,-1,-1,-1,0,0,0,
	0,4,0,0,0,0,-1,-1,-1,0,3,2};
		for(two=0;two<size;two++)
		{
			cout<<another2[two]<<' ';
			if((two+1)%12==0)
			cout<<endl;
		}
	}
	else
	{
	int question[size]=
	{5,2,1,-1,-1,-1,9,6,8,3,4,7,
     3,9,4,-1,-1,-1,5,2,7,6,8,1,
	 8,7,6,-1,-1,-1,1,4,3,2,5,9,
	 -1,-1,-1,1,7,4,8,9,6,5,2,3,
	 -1,-1,-1,6,3,8,2,5,1,9,7,4,
	 -1,-1,-1,5,9,2,3,7,4,1,6,8,
	 6,3,8,7,5,9,-1,-1,-1,4,1,2,
	 7,1,5,4,2,3,-1,-1,-1,8,9,6,
	 9,4,2,8,1,6,-1,-1,-1,7,3,5,
	 2,8,7,3,4,5,6,1,9,-1,-1,-1,
	 4,5,3,9,6,1,7,8,2,-1,-1,-1,
	 1,6,9,2,8,7,4,3,5,-1,-1,-1};
	int change[size];
	//char variable[9]={'a','b','c','d','e','f','g','h','i'};
	//int    c c c c { 1   2   3   4   5   6   7   8   9 };
	int i,j,k;
	int p1,p2,p3,ps;
	//char cp1,cp2;
	//cout<<endl;
	for(i=0;i<size;i++)
			change[i]=question[i];
	srand(time(NULL));
	do{
		p1=random()%9+1;
		p2=random()%9+1;
		p3=random()%9+1;
	}while(p1==p2||p2==p3||p3==p1);
	//cp1=variable[p1];
	//cp2=variable[p2];
	/*char temp;
	temp=variable[p1];
	variable[p1]=variable[p2];
	variable[p2]=temp;
	char flag='z';*/
	for(i=0;i<size;i++)
	{
		if(change[i]==p1)
			change[i]=p2;		
		else if(change[i]==p2)
			change[i]=p3;
		else if(change[i]==p3)
			change[i]=p1;
	}
	for(i=0;i<75;i++)
	{
		ps=random()%size;
		if(change[ps]!=-1&&change[ps]!=0)
			change[ps]=0;
		else
			i--;
	}
	int printhead,printrand,p;
	int print[4]={0,36,72,108};
	for(i=0;i<4;i++)
	{
		p=0;
		printrand=random()%4;
		if(print[printrand]!=-2)
			printhead=print[printrand];
		else
		{
			i--;
			continue;
		}
		for(k=0;k<36;k++)
		{
			cout<<change[k+printhead]<<' ';
			p++;
			if(p%12==0)
				cout<<endl;
		}
		print[printrand]=-2;
	}
	//cout<<endl;
	//cout<<endl;
	/*for(i=0;i<size;i++)
	{
		cout<<change[i]<<' ';
		if((i+1)%12==0)
			cout<<endl;
	}*/}
}


//check需另作特殊function

bool Sudoku::check(int sudonum,int position)
{
	int count=0,/*column,row,block*/nine=0,countB=0,start;
	bool result;
	int test[9];
	gue[position]=sudonum;
	if(sudonum>9)
		return false;
	//cout<<sudonum<<endl;//test
	start=(position/12)*12;//25/3=8
	for(count=0;count<12;count++)
	{
		if(gue[start+count]!=-1)
		{
			test[nine]=gue[start+count];
			//cout<<test[nine]<<endl;
			nine++;
		}
	}
	//cout<<endl;//test
	result=checkUnity(test);
	if(result==false)
	{//gue[position]=0;
	return false;}
	nine=0;
	start=position%12;
	for(count=0;count<12;count++)
	{
		if(gue[start+12*count]!=-1)
		{
			test[nine]=gue[start+12*count];
			//cout<<test[nine]<<endl;//test
			nine++;
		}
	}
	//cout<<endl;//test
	result=checkUnity(test);
	if(result==false)
	{
	//gue[position]=0;
	return false;
	}
	nine=0;
	start=(position/12)/3*36+(position%12)/3*3;
	for(count=0;count<36;count+=12)
	{
		for(countB=0;countB<3;countB++)
		{
			if(gue[start+count+countB]!=-1)
			{
				test[nine]=gue[start+count+countB];
				//cout<<test[nine]<<endl;//test
				nine++;
			}
		}
	}
	//cout<<endl;//test
	result=checkUnity(test);
	if(result==false)
	{//gue[position]=0;
	return false;}
	return true;
}

bool Sudoku::checkUnity(int oriarr[])
{
	int arr_test[9];
	int t;
	for(t=0;t<9;t++)
		arr_test[t]=0;
	for(t=0;t<9;t++)
	{
		if(oriarr[t]==-1)
			return false;
		if(oriarr[t]!=0)
			++arr_test[oriarr[t]-1];
	}
	for(t=0;t<9;t++)
	{	
		if(arr_test[t]>1)
			return false;
	}
	return true;
}

//prepare
/*Sudokuguess::bool checkUnityall(int arr[])
{
	int arr_unity[9]; // counters   
    for(int i=0; i<9; ++i)
	arr_unity[i] = 0; // initialize
	for(int i=0; i<9; ++i)
	++arr_unity[arr[i]-1]; // count
	for(int i=0; i<9; ++i)
	if(arr_unity[i] != 1) // all element
	return false; // must be 1
	return true;
}*/


