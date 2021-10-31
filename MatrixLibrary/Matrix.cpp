#include "pch.h"
#include "Matrix.h"
#include <stdlib.h>
#include <assert.h>
using namespace std; 
using namespace Math;


Matrice::Matrice(unsigned int NbrLingne, unsigned int NbrColonne)
{
	this->col = NbrColonne; 
	this->ligne = NbrLingne; 
	this->Matrixe = new int*[NbrLingne];

	for (int i = 0; i < NbrLingne; i++)
		this->Matrixe[i] = new int[NbrColonne]; 
	
	for (int i = 0; i < this->ligne; i++)
		for (int j = 0; j < this->col; j++)
			this->Matrixe[i][j] = 0;
}


void Matrice::Remplissage(int C)
{
	for (int i = 0; i < this->ligne; i++)
		for (int j = 0; j < this->col; j++)
			this->Matrixe[i][j] = C;
}

Matrice& Matrice::operator+(const Matrice&M) const
{
	//assert(this->col == M.col && this->ligne == M.ligne);
	
	Matrice* MatriceRes = new Matrice(M.ligne, M.col); 
	for (int i = 0; i < this->ligne; i++)
		for (int j = 0; j < this->col; j++)
			MatriceRes->Matrixe[i][j] = this->Matrixe[i][j] + M.Matrixe[i][j];

	return *MatriceRes; 
}

Matrice& Matrice::operator*(const Matrice & M) const
{

	assert(this->col == M.ligne); 
	Matrice* MatriceRes = new Matrice(this->ligne, M.col);
	
	int index1 = 0;
	int index2 = 0;
	int k = 0; 

	long int cordo = 0;

	for (index1 = 0; index1 < MatriceRes->ligne; index1++)
	{
		for (index2 = 0; index2 < MatriceRes->col; index2++)
		{
			for (k = 0; k < MatriceRes->ligne; k++)
				cordo += this->Matrixe[index1][k] * M.Matrixe[k][index2];

			MatriceRes->Matrixe[index1][index2] = cordo; 
			cordo = 0; 
			k = 0; 
		}
	}

	return *MatriceRes;
}

Matrice& Matrice::operator=(const Matrice& M)
{
	this->col = M.col;
	this->ligne = M.ligne; 
	this->Matrixe = M.Matrixe; 

	return *this; 
}

void Matrice::Print() const
{
	for (int i = 0; i < this->ligne; i++) {
		
		for (int j = 0; j < this->col; j++)
		{
			cout << this->Matrixe[i][j] << " "; 
		}
		cout << endl; 
	}

	cout << "------------" << endl; 
}

void Matrice::clone(int MatriceTab[][MAX], int nbLigne, int nbColo)
{
	for (int i = 0; i < nbLigne; i++)
	{
		for (int j = 0; j < nbColo; j++) {
			this->Matrixe[i][j] = MatriceTab[i][j]; 
		}
	}
}

Matrice::~Matrice()
{
	for (int i = 0; i < this->ligne; i++)
		delete this->Matrixe[i]; 
	delete this->Matrixe; 
}
