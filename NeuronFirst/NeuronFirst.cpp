
#include <iostream>
#include "DataNeouron.h"
#include "loadDat.h"
using namespace std;


int main()
{
  /*setlocale(LC_ALL, ""); // Русская локализация
    double* indicat = new double[3]; 
    indicat[0] = 0.2;
    indicat[1] = 0.3;            ///////Для примера работы алгоритма, просто вводим рандомные данные с головы
    indicat[2] = 0.9;
    double* right = new double;
    *right = 1.0;              /// Вводим рандомное значение, которое хотим получить на выходе
    DataNeouron Data;
    Data.RandWeight(-0.8, 0.8); 
    Data.RandOffsets(-1, 1);///Выбираем рандомные значение весов от -0.8 до 0.8
    Data.loadOneSloy(indicat); // Загружаем нашие данные
    Data.StartDirect();
  cout << "Первое значение:";
  Data.StartDirect();   
  ///Выводим первое значение без обучения + веса
  cout << "Веса1:" << "\n";
  for (int y = 0; y < Data.SizeWeight1; y++) {
      cout << Data.Weight1[y] << "\n";
  }
  cout << "Веса2:" << "\n";
  cout << "......................." << "\n";       
  for (int k = 0; k < Data.SizeWeight2; k++) {
      cout << Data.Weight2[k] << "\n";
  }
  //Выводим значения после обучения + новые веса
    for (int i = 0; i < 550; i++) {
        Data.StartTraining(right);
       
        cout << "Значение "<< "поколения "<< i+1<<":";
        Data.StartDirect();
        cout << "Веса1:" << "\n";
        for (int y = 0; y < Data.SizeWeight1; y++) {
            cout << Data.Weight1[y] << "\n";
        }
        cout << "Веса2:" << "\n";
        for (int k = 0; k < Data.SizeWeight2; k++) {
            cout << Data.Weight2[k] << "\n";
        }
        cout << "......................." << "\n";

    }
   
  delete right;
  delete[] indicat;
   return 0; */ 

   setlocale(LC_ALL, "");
    loadDat Data(1000);
    DataNeouron Ner;
    double VectorsRight[10];
    Ner.RandWeight(-0.08, 0.08);
    Ner.RandOffsets(-0.1, 0.1);
   Data.loadFile("lib_MNIST_edit.txt");
   for (int i = 0; i < Data.NumberCol; i++) {
    //   cout << "ВЫБОРКА..." << i << "\n";


       Ner.loadOneSloy(Data.Vectors[i]);
       Ner.StartDirect();
     //  cout << "Нейроны выходов...";
     //  for (int j = 0; j < 10; j++)
    //  cout<< Ner.Neuron3[j]<<" ";
    //   cout << "\n";
       ///// Инцилизация вектора правильных ответов
     //  cout << "Вектор правильных ответов...";
       for (int j = 0; j < 10; j++) {
           VectorsRight[j]=0;
           if (j == Data.numbers[i]) {
               VectorsRight[Data.numbers[i]] = 1;
           }
    //       cout << VectorsRight[j] << " ";

       }  
       if (i == 1000) {
           cout <<"1" << "\n";
       }
    //   cout << "\n";
       /////
       bool F=true;
       int k = 0;
       while (F) {
           Ner.StartTraining(VectorsRight);
           Ner.StartDirect();
        

           if (k == 50) {
               F = false;
           }
           else
           {
               F = true;
           }
           if (!F) {
            /*  cout << "Загадоное число: " << Data.numbers[i] << " Целивые значения:" << "\n";
               for (int f = 0; f < 10; f++)
                   cout << "(" << f << ") " << Ner.Neuron3[f]*100<<"%";
               cout << "\n"; */
           }

           k += 1;
          
          
           
       }
       k = 0;
   }
  
   cout << "Обучение закончилось...." << "\n";
   cout << "Тестовые значения...." << "\n";

   loadDat Data1(1000);
   Data.loadFile("lib_10k.txt");
   for (int i = 0; i < Data1.NumberCol; i++) {
       Ner.loadOneSloy(Data.Vectors[i]);
       Ner.StartDirect();
       cout << "Загадоное число: " << Data.numbers[i] << " Целивые значения:" << "\n";
       for (int f = 0; f < 10; f++)
           cout << "(" << f << ") " << Ner.Neuron3[f] * 100 << "%";
       cout << "\n"; 
   }


   ////////////Более оптимальная функция сигмоида. Тангенс не тестировал
   
}




