#include <stdio.h>
#include <pthread.h>

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
void writeA(); 
void writeB();
void writeC();

int main(int argc, char *argv[])
{

	pthread_t tid;  /* the thread identifier */
  	pthread_attr_t attr;  /* set of thread attributes */

	writeA();

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
	struct arguments  * arg = param;
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

void writeA()
{
	printf("   A \n");	     
	printf("  A A\n"); 
	printf("  AAA\n");
        printf(" A   A\n");
	        A       A	
	      \n");

}

void writeB()
{
	printf("BBBB
		B   B
		BBBB
		B   B
		BBBB		
	   \n");
}

void writeC()
{
	printf(" CCCC
		C
		C
		C
		 CCCC
	   \n");
}
	
