#pragma once
#include "NeouronSloy.h"
class DataNeouron :
    public NeouronSloy
{
public:

	int SizeNeuron1= 784;
	int SizeNeuron2= 392;
	int SizeNeuron3=10;
	int SizeWeight1 = SizeNeuron1 * SizeNeuron2;
	int SizeWeight2 = SizeNeuron2 * SizeNeuron3;
	double* Neuron1 = new double[SizeNeuron1];
	double* Neuron2 = new double[SizeNeuron2];
	double* Neuron3 = new double[SizeNeuron3];
	double* Weight1 = new double[SizeWeight1];
	//double* Offsets1 = new double[SizeWeight1];
	//double* Offsets2 = new double[SizeWeight1];
	double* Offsets1 = new double[SizeNeuron2];
	double* Offsets2 = new double[SizeNeuron3];
	double* Weight2 = new double[SizeWeight2];
	
	//������� �������������� �������, ��� ������� ���������� �����������
		double* NoActivateNeuron2 = new double[SizeNeuron2];
		double* NoActivateNeuron3 = new double[SizeNeuron3];

	
	
public: 
	// �����������
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


		
		cout << "������������ � Data" << "\n";
}


~DataNeouron() {
	
	cout << "��������....";
	delete[] Neuron1;
	delete[] Neuron2;
	delete[] Neuron3;
	delete[] Weight1;
	delete[] Weight2;
	delete[] Offsets1;
	delete[] Offsets2;
	delete[] NoActivateNeuron2;
	delete[] NoActivateNeuron3;
	
}
//�����������
void RandWeight(double randStartWeight, double randEndtWeight, int max_rand=1000) {
	for (int i = 0; i < SizeWeight1; i++) {
		Weight1[i] = randStartWeight + (randEndtWeight - randStartWeight)* (rand() % max_rand) / max_rand;
		//Weight1[i] = 0.01;
	//	cout<< Weight1[i] << "\n";

	}
	for (int j = 0; j < SizeWeight2; j++) {
		Weight2[j] = randStartWeight + (randEndtWeight - randStartWeight) * (rand() % max_rand) / max_rand;
	//	Weight2[j] = 0.01;
		//cout<< Weight2[j] << "\n";
	}
	}
void RandOffsets(double randStartOffsets, double randEndtOffsets, int max_rand = 1000) {
	for (int i = 0; i < SizeNeuron2; i++) {
		Offsets1[i] = randStartOffsets + (randEndtOffsets - randStartOffsets) * (rand() % max_rand) / max_rand;;
	//	Offsets1[i] = 0.01;
		//cout << Offsets1[i] << "\n";

	}
	for (int j = 0; j < SizeNeuron3; j++) {
		Offsets2[j] = randStartOffsets + (randEndtOffsets - randStartOffsets) * (rand() % max_rand) / max_rand;;
		//Offsets2[j] = 0.01;
		//cout << Offsets2[j] << "\n";
	}
}
//�������� 1 ����
void loadOneSloy(double* Data) {
	for (int y = 0; y < SizeNeuron1; y++) {
		Neuron1[y] = Data[y];
	}

}
//������ ���������������
void StartDirect() {
	
	directDirection(Neuron1, Neuron2, Weight1, Offsets1, NoActivateNeuron2, SizeNeuron1, SizeNeuron2,1);
	///for (int i = 0; i < SizeNeuron2; i++) {
	//	cout << Neuron2[i]<<"\n";
	//}
	directDirection(Neuron2, Neuron3, Weight2, Offsets2, NoActivateNeuron3, SizeNeuron2, SizeNeuron3,2);
	//������� �������� ��������� ����, � ������� � ��� 1 �������� ����
	//cout << Neuron3[0]<<"\n";

}
//�������� �����
void StartTraining(double* VectorRight) {

	double* VectorError = new double[SizeNeuron3];
	double* VectorError2 = new double[SizeNeuron2];
	for (int i = 0; i < SizeNeuron3; i++) {
		VectorError[i] = 0;
	}
	for (int j = 0; j < SizeNeuron2; j++) {
		VectorError2[j] = 0;
	}

	//��������� ������ ��������� ����
	 EvalutionError(VectorRight, Neuron3, VectorError, SizeNeuron3);
	//��������� ������ �������� ����
	
	 
	 
	 EvalutionErrorLast(VectorError, Weight2, NoActivateNeuron3, VectorError2, SizeNeuron3, SizeNeuron2,2);
	//�������� ��������������� ������







	 ErorrTeachSloy(VectorError, Neuron2, NoActivateNeuron3, Weight2, Offsets2, SizeNeuron2,  SizeNeuron3,2);
	
	 ErorrTeachSloy(VectorError2, Neuron1, NoActivateNeuron2, Weight1, Offsets1, SizeNeuron1, SizeNeuron2,1);
	
	 delete[] VectorError;
	 
	 delete[] VectorError2;

}
};

