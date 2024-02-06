#pragma once
using namespace std;
#include <algorithm>
#include <iostream>
class Activate
{
public:

	double SpeedTeach = 0.01; //скорость обучения
	//функция релу
	double Relu(double neouronInput) {

	double  neouronOut = max(0.0, neouronInput);
	return neouronOut;


	}
	//функция  сигмоида
	double sigmoida(double neouronInput) {
		double  neouronOut=1/(1+exp(-neouronInput));
		return neouronOut;
	}
    //функция гиперболический тангенс
	double tanG(double neouronInput) {
		double  neouronOut = (exp(2*neouronInput)-1)/(exp(2*neouronInput)+1);
		return neouronOut;

	}
	//производная сигмоиды
	double DerSigmoida(double neouronInput) {
		double  neouronOut = exp(-neouronInput) /pow((1 + exp(-neouronInput)),2);
		return neouronOut;
	}
};

