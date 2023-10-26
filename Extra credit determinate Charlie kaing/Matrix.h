#pragma once
#ifndef Matrixguard
#define Matrixguard
#include <iostream>
const int maxsize = 5;
class Matrix
{
private:
	int intermatrix[maxsize][maxsize];
	bool rowechelon = false;

	int outside[maxsize];
	int outsideitems = 0;
	void additem();
	void calculatedeterminate();
	//Pivot

	int pivot = 0;
	int checkpivotvalue();
	void pivotmove();

	//Operations

	void simplify(int column);
	void addcolumn(int row, int column);
	bool checkcommondenominator(int current, int divider);
	void changesign(int row, int column);

	// Checks
	void checkrow();
	bool rowecheloncheck();
	
	
public:
	Matrix();
	void solve();
	void input();
	void showoutsideitems();
	void print();
};


#endif