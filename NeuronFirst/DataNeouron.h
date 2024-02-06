#pragma once
#include "NeouronSloy.h"
class DataNeouron :
    public NeouronSloy
{
public:

	int SizeNeuron1=3;
	int SizeNeuron2=2;
	int SizeNeuron3=1;
	int SizeWeight1 = SizeNeuron1 * SizeNeuron2;;
	int SizeWeight2 = SizeNeuron2 * SizeNeuron3;;
	double* Neuron1 = new double[SizeNeuron1];
	double* Neuron2 = new double[SizeNeuron2];
	double* Neuron3 = new double[SizeNeuron3];
	double* Weight1 = new double[SizeWeight1];
	double* Weight2 = new double[SizeWeight2];
	
	//Создаем дополнительные массивы, для легкого вычисления производных
		double* NoActivateNeuron2 = new double[SizeNeuron2];
		double* NoActivateNeuron3 = new double[SizeNeuron3];

	
	
public: 
	// Инцилизация
DataNeouron() {
	
	for (int i = 0; i < SizeNeuron2; i++) {
		Neuron2[i] = 0;
	}
	for (int j = 0; j < SizeNeuron3; j++) {
		Neuron3[j] = 0;
	}
	for (int g = 0; g < SizeNeuron2; g++) {
		NoActivateNeuron2[g] = 0;
	}
	for (int f = 0; f < SizeNeuron3; f++) {
		NoActivateNeuron3[f] = 0;
	}


		
		cout << "Инциализация в Data" << "\n";
}


~DataNeouron() {
	
	cout << "удаление....";
	delete[] Neuron1;
	delete[] Neuron2;
	delete[] Neuron3;
	delete[] Weight1;
	delete[] Weight2;
	delete[] NoActivateNeuron2;
	delete[] NoActivateNeuron3;
	
}
//Рандомайзер
void RandWeight(double randStartWeight, double randEndtWeight, int max_rand=1000) {
	for (int i = 0; i < SizeWeight1; i++) {
		Weight1[i] = randStartWeight + (randEndtWeight - randStartWeight)* (rand() % max_rand) / max_rand;;

	}
	for (int j = 0; j < SizeWeight2; j++) {
		Weight2[j] = randStartWeight + (randEndtWeight - randStartWeight) * (rand() % max_rand) / max_rand;;

	}
	}
//Загрузка 1 слоя
void loadOneSloy(double* Data) {
	for (int y = 0; y < SizeNeuron1; y++) {
		Neuron1[y] = Data[y];
	}

}
//Прямое распростронения
void StartDirect() {
	
	directDirection(Neuron1, Neuron2, Weight1, NoActivateNeuron2, SizeNeuron1, SizeNeuron2);
	directDirection(Neuron2, Neuron3, Weight2, NoActivateNeuron3, SizeNeuron2, SizeNeuron3);
	//Выводим значения выходного слоя, в примере у нас 1 выходной слой
	cout << Neuron3[0]<<"\n";

}
//Обучение слоев
void StartTraining(double* VectorRight) {

	double* VectorError = new double[SizeNeuron3];
	double* VectorError2 = new double[SizeNeuron2];
	for (int i = 0; i < SizeNeuron3; i++) {
		VectorError[i] = 0;
	}
	for (int j = 0; j < SizeNeuron2; j++) {
		VectorError2[j] = 0;
	}

	//Вычисляем ошибку выходного слоя
	 EvalutionError(VectorRight, Neuron3, VectorError, SizeNeuron3);
	//Вычисляем ошибку внешнего слоя
	 EvalutionErrorLast(VectorError, Weight2, NoActivateNeuron3, VectorError2, SizeNeuron3, SizeNeuron2);
	//Обратное распространение ошибки
	 ErorrTeachSloy(VectorError, Neuron2, NoActivateNeuron3, Weight2, SizeNeuron2, SizeNeuron3);
	
	 ErorrTeachSloy(VectorError2, Neuron1, NoActivateNeuron2, Weight1, SizeNeuron1, SizeNeuron2);
	
	 delete[] VectorError;
	 
	 delete[] VectorError2;

}
};

