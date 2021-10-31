#pragma once
#include <iostream>
#include <string>
using namespace std; 
#define MAX 3

namespace Math {
	class Matrice
	{
	private:
		int col;
		int ligne;
		int** Matrixe;

	public:
		Matrice(unsigned int NbrLingne, unsigned int NbrColonne);

		void Remplissage(int);
		Matrice& operator+(const Matrice&) const;
		Matrice& operator*(const Matrice&) const;
		Matrice& operator=(const Matrice&);
		void Print() const;

		void clone(int MatriceTab[][MAX], int nbLigne, int nbColo);

		~Matrice();

	};
};

