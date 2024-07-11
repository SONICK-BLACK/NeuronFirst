#pragma once
using namespace std;
#include <algorithm>
#include <iostream>
class Activate
{
public:

	double SpeedTeach = 0.1; 
	//function ReLu
	double Relu(  double neouronInput) {
		  double  neouronOut;
		if (neouronInput > 1e+2) {
			neouronInput = 1e+2; //Quite optimal constraints for this activation function
		}
	
		
		neouronOut = max(0.0, neouronInput*0.01);
		
		
	return neouronOut;


	}
	//function  sigmoida
	double sigmoida(double neouronInput) {
	

		double  neouronOut=1/(1+exp(-neouronInput));
	
		return neouronOut;
	}
    //function tanG
	double tanG(double neouronInput) {
		double  neouronOut = (exp(2*neouronInput)-1)/(exp(2*neouronInput)+1);
		return neouronOut;

	}
	
	//derivative  Sigmoida
	double DerSigmoida(double neouronInput) {
		if (neouronInput < 1e-7) {
		neouronInput = 0; //Quite optimal constraints for this activation function
		}
		if (neouronInput  > 1e+6) {
			neouronInput = 1e+6;
	}
		double  neouronOut = exp(-neouronInput) /pow((1 + exp(-neouronInput)),2);
		
		return neouronOut;
	}
};

