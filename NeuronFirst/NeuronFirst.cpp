
#include <iostream>
#include "DataNeouron.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, ""); // Русская локализация
    double* indicat = new double[3]; 
    indicat[0] = 0.2;
    indicat[1] = 0.3;            ///////Для примера работы алгоритма, просто вводим рандомные данные с головы
    indicat[2] = 0.9;
    double* right = new double;
    *right = 1.0;              /// Вводим рандомное значение, которое хотим получить на выходе
    DataNeouron Data;
    Data.RandWeight(-0.8, 0.8); ///Выбираем рандомные значение весов от -0.8 до 0.8
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
    for (int i = 0; i < 25; i++) {
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
   return 0;
   ////////////Более оптимальная функция сигмоида. Тангенс не тестировал
}




