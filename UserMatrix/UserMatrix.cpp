#include <iostream>
#include "Matrix.h"
using namespace Math; 
using namespace std; 

int M1Tab[3][MAX] = {
	{2, 4, 3},
	{5, 6, 9},
	{1, 4, 0}
};

int M2Tab[3][MAX] = {
	{1, 3, 1},
	{2, 5, 6},
	{1, 4, 0}
};

int main()
{
	Matrice M1(3, 3);

	M1.clone(M1Tab, 3, 3);
	M1.Print();

	Matrice M2(3, 3);
	M2.clone(M2Tab, 3, 3);

	M2.Print();

	Matrice M3(3, 3); 
	M3 = (M1 + M2); 
	M3.Print();

	
	//M3.Print();
}
