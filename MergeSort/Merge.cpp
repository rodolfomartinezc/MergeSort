/*								 #Kawaii
          =,    (\_/)    ,=
           /`-'--(")--'-'\       #Murcielago
          /     (___)     \		 
         /.-.-./ " " \.-.-.\     #PorqueHalloween

*/

#include <iostream>														//Librerias a ocupar
#include <fstream>
#include <vector>

using namespace std;													//espacio de trabajo standar

void merge(int *,int, int , int );


void mergesort(int *a, int minimo, int maximo)							//Metodo de Ordenamiento
{
    int medio;
    if (minimo < maximo)
    {
        medio=(minimo+maximo)/2;
        mergesort(a,minimo,medio);
        mergesort(a,medio+1,maximo);
        merge(a,minimo,maximo,medio);
    }
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void merge(int *a, int minimo, int maximo, int medio)
{
    int i, j, k, c[50];											//variables de apoyo, C[_] auxiliar
    i = minimo;
    k = minimo;
    j = medio + 1;
    

	while (i <= medio && j <= maximo)							//Ordenamiento de los valores
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= medio)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= maximo)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = minimo; i < k; i++)
    {
        a[i] = c[i];
    }
}
int main()													//main,cuyos parametros hacen la base para la creacion del 
{															//ejecutable

	vector<int> valores;									//Se crea un vector que almacenara los datos de nuestro archivo

	ifstream in("valores.txt",ios::in);						//Abrimos nuestro archivo con los valores a ordenar


	int numero;  											//Declaramos una variable para los digitos de nuestro archivo 
	

    while (in >> numero) {									//Leemos el digito y lo acomodamos al final del vector
		valores.push_back(numero);							//hasta terminar el archivo
	}

	in.close();												//Cerramos el archivo

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Debido a que nuestro Ordenamiento recibe como argumento un arreglo y nosotros tenemos un vector, llenamos un arreglo 
con nuestros datos contenidos en el vector*/


	int M = valores.size();									//Tamaño del vector = Tamaño del arreglo
	int a[M];												//Arreglo


    cout<<"\n           -MergeSort y Archivos-              \n";          // Metodo a Evaluar
	cout<<"      Rodolfo Martinez    Brenda Ortega    \n\n";              // Integrantes del Equipo
	
	cout << "Los numeros a ordenar son:\n";

	for (int i=0; i<valores.size(); i++) {                  //Recorremos el vector para imprimirlo y asignar los valores
		cout << valores[i];									//a un arreglo
		cout<<"  ";
		a[i]=valores[i];
	}


    mergesort(a, 0, 28);									//Metemos nuestro arreglo a nuestra funcion de ordenamiento
															//nos regresa nuestro arreglo ya ordenado
    cout<<"Numeros Ordenados: \n";
    for (int i = 0; i < 29; i++)					
    {
        cout<<a[i];											//Recorremos nuestro arreglo ordenado y lo imprimimos
		cout<<"  ";
    }
    
   
}															//Fin
