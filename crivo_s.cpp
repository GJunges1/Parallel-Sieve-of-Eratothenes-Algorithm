// Gabriel Junges Baratto
// Crivo de Eratóstenes (números primos)
// Versão SERIAL

#include <iostream>
#include <cmath>

#define MAXN 5000000000

const int lastNumberSqrt = (int)sqrt((double)MAXN);
long int memorySize = (MAXN - 1) / 2;

using namespace std;

char *eh_primo;

void crivo(long int i){
    
    eh_primo[i] = 1;

    for(long int k = i + i; k <= MAXN; k += i){
        eh_primo[k] = 0;
    }
}

int main(){

    eh_primo = new char [MAXN+1];


    long int j = 0;
    long int i = 0;

    cout << "inicializando o vetor de marcação de primos...\n";

    // Inicializando "eh_primo" com 1, considerando todos primos inicialmente.
    for (i = 1; i <= MAXN; i++){
        eh_primo[i] = 1;
    }

    // Pesquisar os nao primos ... 
    for (long int i = 3; i <= lastNumberSqrt; i += 2)
        if (eh_primo[i / 2])
            for (long int j = i * i; j <= MAXN; j += 2 * i)
                eh_primo[j / 2] = 0;
    long int found = MAXN >= 2 ? 1 : 0; 


    cout << "Contando o número de primos encontrados ...\n";

    for (long int i = 1; i <= MAXN; i++)
        found += eh_primo[i];

    cout << "Prime numbers (" << MAXN << ") .....: " << found << endl;    

 
    delete [] eh_primo;

    return 0;

}

	
	
