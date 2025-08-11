/******************************************************************************
Código para generar el RFC de una persona
Autor:Karol Ochoa Beltran
Fecha: 05/08/2025
*******************************************************************************/

#include <iostream>
#include <vector> 
#include <string>
#include <cctype>
#include <algorithm>

//Palabras prohibidas
const std::vector <std::string> PalabrasProhibidas = { 
    "PENE", "PUTO", "PITO", "TETA", "JOTO", "POPO"
};

//Verificación y modificación de palabras prohibidas
std::string CorregirRFC(const std::string& RFC) {
   for (const std::string& palabra : PalabrasProhibidas) {
       if (RFC.substr (0,4) == palabra) {
           std::string CorregirRFC = RFC;
           CorregirRFC [3] = 'X'; //Remplaza la última letra por "X"
           return CorregirRFC;
       }
   }
   return RFC;
}

//Función para obtener la primera vocal interna
char PrimerVocalI(const std::string& str) {
    for(size_t i = 1; i < str.length(); ++i) {
        char c = str[i];
        if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        return c;
    }
    return 'X'; //Si no encuentran vocal interna, usar 'X'
}

//Función principal para calcular el RFC
std::string CalcularRFC(const std::string& Nombre, const std::string ApellidoPaterno,
const std::string ApellidoMaterno, const std::string FechaNacimiento ) {
    
    std::string RFC;
    
    char  LetraInicial = toupper( ApellidoPaterno[0]);
    char  PrimeraVocalInterna = toupper(PrimerVocalI(ApellidoPaterno));
    char  InicialApellidoMaterno = (!ApellidoMaterno.empty()) ? toupper (ApellidoMaterno[0]) : 'X';
    char  InicialNombre = toupper (Nombre[0]);
    
    std::string Año = FechaNacimiento.substr(2, 2);
    std::string Mes = FechaNacimiento.substr(5, 2);
    std::string Día = FechaNacimiento.substr(8, 2);
    
    RFC += LetraInicial;
    RFC += PrimeraVocalInterna;
    RFC += InicialApellidoMaterno;
    RFC += InicialNombre;
    RFC += Año;
    RFC += Mes;
    RFC += Día;
    
    RFC = CorregirRFC(RFC);
    return RFC;
}

//Convierte toda la cadena a mayúsculas
std::string toupper (const std::string& str) {
    std::string resultado = str;
    std::transform (resultado.begin(), resultado.end(), resultado.begin(), [](unsigned char c){return
        std::toupper(c);});
        return resultado;
}


int main (){
    
    //Solicita los datos y los envía a consola 
    std::string Nombre, ApellidoPaterno, ApellidoMaterno, FechaNacimiento;
    std::cout << "Ingresa tu nombre: ";
    std::getline(std::cin, Nombre);
    std::cout << "Ingresa tu apellido paterno: ";
    std::getline(std::cin, ApellidoPaterno);
    std::cout << "Ingresa tu apellido materno (si no cuenta con este dato presione enter): ";
    std::getline(std::cin, ApellidoMaterno);
    std::cout << "Ingresa tu fecha de nacimiento (Año-Mes-Día): ";
    std::getline(std::cin, FechaNacimiento);
   
   //Corregimos a mayúsculas para evitar errores
   Nombre = toupper(Nombre);
   ApellidoPaterno = toupper(ApellidoPaterno);
   ApellidoMaterno = toupper(ApellidoMaterno);
   
    std::string RFC = CalcularRFC (Nombre, ApellidoPaterno, ApellidoMaterno, FechaNacimiento);
    std::cout << "RFC: " << RFC << std::endl;
    
return 0;
}
