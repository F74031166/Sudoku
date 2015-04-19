#include<iostream>
#include<iomanip>
#include"Sudoku.h"
#include"Clock.h"

using namespace std;

int main()
{
	Sudoku guess1;
	Clock count;
	guess1.ReadIn();
	count.start();
	guess1.Solve();
	cout<<endl<<"it takes "<<fixed<<setprecision(5)<<count.getElapsedTime()<<" seconds"<<endl;
	return 0;	
}
