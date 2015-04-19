#include<iostream>
#include<string>
#define size 144

using namespace std;

class  Sudoku{
	public:
	void GiveQuestion();
	void ReadIn();
	void Solve();
	//void GiveQuestion();
	private:
	int gue[size];
	bool check(int sudonum,int position);
	bool checkUnity(int oriarr[]);
};
