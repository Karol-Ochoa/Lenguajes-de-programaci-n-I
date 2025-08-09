/******************************************************************************
//Código que realizará las cuatro operaciones básicas con dos números
//Autor: Karol Ochoa Beltran
//Fecha: 29/07/2025
*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    float Num1, Num2;
    
    cout << "Ingresa el primer número: ";
    cin >> Num1;
    cout << "Ingresa el segundo número: ";
  cin >> Num2;
  
  cout << "La suma es: " << Num1+Num2 << endl;
  cout << "La resta es: " << Num1-Num2 << endl;
  cout << "La multplicación es: " << Num1*Num2 << endl;
  cout << "La división es: " << Num1/Num2 << endl;

    return 0;
}