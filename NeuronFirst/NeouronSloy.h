#pragma once
#include <iostream>

#include "Activate.h"
class NeouronSloy :
    public Activate
{
public: 
    
    int function=2; // переменная задающая тип функции
    void directDirection(double* sloy1, double* sloy2,double* weight, double* NoActivateSloy2,int  sizeSloy1, int sizeSloy2) {
        int k = 0;
        for (int i = 0; i < sizeSloy1; i++) {

            for (int j = 0; j < sizeSloy2; j++) {

                sloy2[j] += sloy1[i] * weight[k];
                NoActivateSloy2[j] += sloy1[i] * weight[k];
                k += 1;
            }

        }
        //Функция активации релу
        if (function == 1) {
            for (int g = 0; g < sizeSloy2; g++) {
                sloy2[g] = Relu(sloy2[g]);
            }

        }
        // функция активации сигмоида
        if (function == 2) {
            for (int g = 0; g < sizeSloy2; g++) {
                sloy2[g] = sigmoida(sloy2[g]);
            }

        }
        // функция активации гипербалический тангенс
        if (function == 3) {
            for (int g = 0; g < sizeSloy2; g++) {
                sloy2[g] = tanG(sloy2[g]);
            }

        }
       
    }
    void EvalutionError(double* VectorPerf, double* VectorOrigion, double* VectorEr, int SizeVectors) {
      
        for (int i = 0; i < SizeVectors; i++) {
            VectorEr[i] = (VectorOrigion[i] - VectorPerf[i]);

        }
       
    }
    void EvalutionErrorLast(double* VectorErForw, double* Weight, double* NoActivateSloy, double* VectorEr, int SizeVectorErForw, int SizeLastSloy) {
        //Для релу
        if (function == 1) {
            int k = 0;
            for (int i = 0; i < SizeLastSloy; i++) {
                for (int j = 0; j < SizeVectorErForw; j++) {
                    VectorEr[i] += VectorErForw[j]*Weight[k];
                    k += 1;
                }
            }
        }
    // для сигмоиды
        if (function == 2) {
            int k = 0;
            for (int i = 0; i < SizeLastSloy; i++) {
                for (int j = 0; j < SizeVectorErForw; j++) {
                    VectorEr[i] += VectorErForw[j] * Weight[k]* DerSigmoida(NoActivateSloy[j]);
                    k += 1;
                }
            }
        }
        //Для 3 функции потом
    }
    void ErorrTeachSloy(double* VectorEr, double* VectorLastSloy, double* NoActivateSloy, double* Weight, int SizeLastSloy, int SizeVectorEr) {
       //релу 
        if (function == 1) {
            int k = 0;
            for (int i = 0; i < SizeVectorEr; i++) {
                for (int j = 0; j < SizeLastSloy; j++) {
                    Weight[k] = Weight[k] - (VectorLastSloy[j] * VectorEr[i]*SpeedTeach);
                    k += 1;

                }
            }
        }
        // сигмоида
        if (function == 2) {
            int k = 0;
            for (int i = 0; i < SizeVectorEr; i++) {
                for (int j = 0; j < SizeLastSloy; j++) {
                    Weight[k] = Weight[k] - (VectorLastSloy[j] * VectorEr[i] * SpeedTeach*DerSigmoida(NoActivateSloy[i]));
                    k += 1;
                }
            }
        }
        
    }
};

