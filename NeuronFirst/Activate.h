#pragma once
using namespace std;
#include <algorithm>
#include <iostream>
class Activate
{
public:

	double SpeedTeach = 0.1; //скорость обучения ///При 10 идеально, но вконце наны.
	//функция релу
	double Relu(  double neouronInput) {
		  double  neouronOut;
		if (neouronInput > 1e+2) {
			neouronInput = 1e+2;
		}
		//if (neouronInput > 1)
		//{
		//	neouronOut = 1;
		//}
		//else 
		//{
		
		neouronOut = max(0.0, neouronInput*0.01);
		
		
	return neouronOut;


	}
	//функция  сигмоида
	double sigmoida(double neouronInput) {
	//	if (neouronInput < 1e-300) {
		//	neouronInput = 1e-300;
		//}
		//if (neouronInput > 1e+300) {
			//neouronInput = 1e+300;
	//	}

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
		if (neouronInput < 1e-7) {
		neouronInput = 0;
		}
		if (neouronInput  > 1e+6) {
			neouronInput = 1e+6;
	}
		double  neouronOut = exp(-neouronInput) /pow((1 + exp(-neouronInput)),2);
		
		return neouronOut;
	}
};

