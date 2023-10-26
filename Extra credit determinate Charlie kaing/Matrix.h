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

	// The numbers that are taken out of the matrix
	int outside[12];
	// variable used to keep track of the ammount of items
	int outsideitems = 0;
	// Adds number to the array of outside
	void additem();
	// final calculates the determinate
	void calculatedeterminate();
	//Pivot used to keep track of row and column;
	int pivot = 0;
	// returns what row and column the matrix is on
	int checkpivotvalue();


	//Operations
	//Simplify the row
	void simplify(int column);
	//Reduces the row
	void reducecolumn(int row, int column);
	// Check for common denominator
	bool checkcommondenominator(int current, int divider);
	// Changes the sign of the rest of the row
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