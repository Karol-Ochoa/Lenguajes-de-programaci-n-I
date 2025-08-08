/******************************************************************************
//Código para calcular si una persona es mayor de edad
//Autor: Karol Ochoa Beltran
//Fecha: 25 de julio 2025
*******************************************************************************/
#include <stdio.h>
int main()
{
   int edad;
   printf ("Escribe tu edad: \n");
   scanf ("%d",&edad);
   if (edad >=18)
   printf ("Usted es mayor de edad");
   if (edad <18)
    printf ("Usted es menor de edad");
    return 0;
}
