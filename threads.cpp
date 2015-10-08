#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <string>
using namespace std;

//Estructura para meter dos argumentos para el ejercicio 3
struct arguments
{
	int n;
	int k;
};

double result;

//Ejercicio 3 de combinacion
void * combination(void * param);
void * writeName(void * param);

int factorial(int);
string replaceAll(string, const string&, const string&);
void printLetter(string letter);


int main(int argc, char *argv[])
{

	pthread_t tid;  /* the thread identifier */
  	pthread_attr_t attr;  /* set of thread attributes */


	if(atoi(argv[1]) >= atoi(argv[2]))
	{
		struct arguments arg;
		arg.n = atoi(argv[1]);
		arg.k = atoi(argv[2]);

		/* get the default attributes */
  		pthread_attr_init( &attr );

		pthread_create( &tid, &attr, combination,(void *) & arg);

		pthread_join( tid, NULL );

		printf("El resultado de la combinacion es: %f\n", result);
	}
	else
		printf("El primero argumento tiene que ser mayor o igual que el segundo\n");

	return 0;
}

void * combination(void * param)
{
	struct arguments  * arg = (arguments *)param;
	result = factorial(arg->n)/(factorial(arg->k)*factorial(arg->n - arg->k));
    	pthread_exit(NULL);
}

void * writeName(void * param)
{

}

int factorial(int n)
{

	int resultF = 1;

	if(n > 1)
	{
		int i;

		for( i = n; i > 1; i--)
		{
			resultF *= i;
		}

		return resultF;
	}
	else if(n >= 0)
	{
		return resultF;
	}
	else
	{
		printf("Error, no se puede obtener el factorial de un numero negativo, se devolvera -1\n");
		return -1;
	}

}


//Función para reemplazar todos los caracteres de una cadena

string replaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

//Imprime una letra en formato de 5x5

void printLetter(string letter)
{
    string L1 = "     8            8        888      8     8   8 8    8                                             8                                             ";
    string L2 = ".888 888. .888 .888 .8888  8'  .888 8888. 8   8 8.88 8 8888.888. 8888. .888. 888. .888  8888 8888 8888 8   8 88  88 88  88  88 88 88 88  88 8888 ";
    string L3 = "8  8 8  8 8    8  8 8.88' 8888 8  8 88 88 8   8 888  8 88 888 88 88 88 8' .8 8  8 8  8  88   `88.  8   88 88  8888   88888888   `8.   8888   88  ";
    string L4 = "`888 888' `888 `888 `8888  8   `888 8   8 8   8 8 88 8 8   8   8 8   8 `888' 888' `888  8    8888  888 `8888   88     88  88   88 88   88   8888 ";
    string L5 = "                               8888         888                              8       88                                               88         ";
    int sep[] = {0,5,10,15,20,26,31,36,42,44,48,53,55,65,71,77,82,88,93,98,103,109,116,127,133,140,145};
    int index = letter.at(0)-'a';
    cout << replaceAll( L1.substr(sep[index],sep[index+1]-sep[index]), "8", letter) << endl;
    cout << replaceAll( L2.substr(sep[index],sep[index+1]-sep[index]), "8", letter) << endl;
    cout << replaceAll( L3.substr(sep[index],sep[index+1]-sep[index]), "8", letter) << endl;
    cout << replaceAll( L4.substr(sep[index],sep[index+1]-sep[index]), "8", letter) << endl;
    cout << replaceAll( L5.substr(sep[index],sep[index+1]-sep[index]), "8", letter) << endl;

}


