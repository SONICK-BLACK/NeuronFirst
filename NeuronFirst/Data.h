#pragma once
class Data
{
public:
	int SizeNeuron1;
	int SizeNeuron2;
	int SizeNeuron3;
	int SizeWeight1;
	int SizeWeight2;


	Data(int Size1=1, int Size2=1, int Size3=1, double randStartWeight, double randEndtWeight) {
		SizeNeuron1 = Size1;
		SizeNeuron2 = Size2;
		SizeNeuron3 = Size3;

		double* Neuron1 = new double[Size1];
		double* Neuron2 = new double[Size2];
		double* Neuron3 = new double[Size3];
		SizeWeight1 = Size1 * Size2;
		SizeWeight2 = Size2 * Size3;
		double* Weight1 = new double[SizeWeight1];
		double* Weight2 = new double[SizeWeight2];
		for (int i = 0; i < SizeWeight1; i++) {
			//Weight1[i]=
		}

		

	}

};

