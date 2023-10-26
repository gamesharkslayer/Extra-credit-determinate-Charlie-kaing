
#include "Matrix.h"
Matrix::Matrix()  : intermatrix { 
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},

		/*
		//test determinate
		{1,3,1,5,3},
		{-2,-7,0,-4,2},
		{0,0,1,0,0},
		{0,0,2,1,0},
		{0,0,0,1,1}, // final determinate is negative 2
		// factor test
		{2,4,8,12,2},
		{0,1,0,0,0},
		{0,0,1,0,0},
		{0,0,0,1,0},
		{0,0,0,0,1},
		*/
}
{ }
void Matrix::solve()
{
	
		while (pivot < maxsize)
		{
		if (checkpivotvalue() == 1)
		{
			addcolumn(pivot, pivot);
			//std::cout << "intermatrix " << intermatrix[pivot][pivot] << std::endl; //Debug
		}
		else if (checkpivotvalue() > 1)
		{
			simplify(pivot);
			addcolumn(pivot, pivot);
		}
		else if (checkpivotvalue() == -1)
		{
			changesign(pivot, pivot);
			addcolumn(pivot, pivot);
		}
		else if (checkpivotvalue() < 0)
		{
			changesign(pivot, pivot);
			simplify(pivot);
			addcolumn(pivot, pivot);
		}
		pivot++;
	//	std::cout << "pivot: " << pivot << std::endl; //Debug


		}

	

	
}
void Matrix::simplify(int column)
{
	
	int divider = intermatrix[column][column];
	//std::cout << divider;
	if (checkcommondenominator(column,divider) == true)
	{
		outside[outsideitems] = divider;
		outsideitems++;

		for (int traverse = column; traverse < maxsize; traverse++)
		{
			intermatrix[column][traverse] =  intermatrix[column][traverse] / divider;
			//std::cout << intermatrix[column][traverse] << " = " << intermatrix[column][traverse] << " / " << divider << "\n";
		}
	}
	else
	{

		for (int traverse = column; traverse < maxsize; traverse++)
		{
		intermatrix[column][traverse] = intermatrix[column][traverse] / divider;
		}
	}	
	
	/*
	int divider = intermatrix[column][column];
	for (int traverse = column; traverse < maxsize; traverse++)
	{
		intermatrix[column][traverse] = intermatrix[column][traverse] / divider;
		
	}
	*/
	
	
	
}
bool Matrix::checkcommondenominator(int current,int divider)
{
	int cursor = 0;

	while (cursor < maxsize)
	{
		
		int check = intermatrix[current][cursor] % divider;

		if (check != 0)
		{
			return false;
		}
		cursor++;
	}
	std::cout << "common denominator found\n";
	return true;
}
/*
	Goes through each element in the column and performs row operation to get all element to zero
*/
void Matrix::addcolumn(int row,int column)
{
	
	int multiple;
	int next = column;
	
		while (next < maxsize - 1 ) // check if this wont get the multiple out of bound
		{
			
			next++;
			multiple = intermatrix[next][row];

			/*
			std::cout << "next: " << next << "\n";
			std::cout << "row and column" << row << "and" << column << std::endl;
			std::cout << "multiple: " << multiple << std::endl;
			*/
		
		
			
			
			// goes through each element in the row and subtracts the next row
			for (int traverserow = row; traverserow < maxsize; traverserow++)
			{
				
				intermatrix[next][traverserow] = intermatrix[next][traverserow] - intermatrix[column][traverserow] * multiple;

				/*
				int calctest = intermatrix[next][traverserow] - intermatrix[column][traverserow] * multiple;
				std::cout << "calctest: " << calctest << " = " << intermatrix[next][traverserow] << " - " << intermatrix[column][traverserow] << " * " << multiple << "\n";
				std::cout << "next: " << next << "\n";
				std::cout << "traverserow:" << traverserow << "\n";
				std::cout << "row and column" << row << "and" << column << std::endl;
				print();
				std::cout << std::endl;
				*/
				
				

			}

		}

	
}
void Matrix::changesign(int row,int column) {
	int currentcolumn = column;
	outside[outsideitems] = -1;
	outsideitems++;
	for (int currentrow = row; currentrow < maxsize; currentrow++)
	{
		intermatrix[currentcolumn][currentrow] *= -1;
	}

}
int Matrix::checkpivotvalue() {
	return intermatrix[pivot][pivot];
}

void Matrix::print() {
	for (int column = 0; column < maxsize; column++)
	{
		for (int row = 0; row < maxsize; row++)
		{
			std::cout << intermatrix[column][row] << " ";
		}
		std::cout << std::endl;
	}
	calculatedeterminate();
}

void Matrix::showoutsideitems()
{
	std::cout << "The Outside items are: ";
	for (int i = 0; i < outsideitems; i++)
	{
		std::cout << outside[i] << " ";
	}
	std::cout << std::endl;
}
void Matrix::input()
{
	int userentry;
	for (int column = 0; column < maxsize;column++)
	{
		std::cout << "Input Row " << column << ": ";
		for (int row = 0; row < maxsize; row++)
		{
			std::cin >> userentry;
			intermatrix[column][row] = userentry;
		}
		
	}
}
void Matrix::calculatedeterminate()
{
	int determinate = 1;
	for(int i = 0;i < outsideitems;i++)
	{
		determinate *= outside[i];
	}
	std::cout << "The Determinate of the Matrix is: " << determinate;
}
