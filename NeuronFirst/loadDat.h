#pragma once
#include "DataNeouron.h"
#include <iostream>
#include <fstream>
class loadDat 
	
{
public:
	
	
	
	int NumberCol;
	int pixels=784;

	int* numbers;
		double** Vectors; 
		loadDat(int NumberCol1) {
			NumberCol = NumberCol1;
			numbers = new int[NumberCol];
			Vectors = new double* [NumberCol];
			for (int i = 0; i < NumberCol; i++) {
				
				Vectors[i] = new double[pixels];
			}
			
		
		}
		~loadDat() {
			delete[] numbers;
			for (int i = 0; i < NumberCol; i++)
			delete[] Vectors[i];
			delete[] Vectors;
		}

	
	void loadFile( string path) {
		ifstream f;
		f.open(path);
		if (!f.is_open()) {
			cout << "File reading error\n";
			system("pause");
		}
		for (int i = 0; i < NumberCol; i++) {
			f >> numbers[i];
			for (int j = 0; j < pixels; j++) {
				f >> Vectors[i][j];
			}
		}
		f.close();
		cout << "End of file reading\n";
	}
};

