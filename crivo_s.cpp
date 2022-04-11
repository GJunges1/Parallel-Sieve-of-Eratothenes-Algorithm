// Gabriel Junges Baratto
// Crivo de Eratóstenes (números primos)
// Versão SERIAL

#include <iostream>

#define MAXN 600000000

using namespace std;

short *eh_primo;

void crivo(long int i){
    
    eh_primo[i] = 1;

    for(long int k = i + i; k <= MAXN; k += i){
        eh_primo[k] = 0;
    }
}

int main(){

    eh_primo = new short [MAXN+1]; // -1 => indefinido, 0 => composto e 1 => primo.
                                        // seus elementos são inicializados com -1

    long int j = 0;
    long int i = 0;

    cout << "inicializando o vetor de marcação de primos...\n";

    // Inicializando "eh_primo" com -1, pois não sabemos nada sobre nenhum número, inicialmente.
    for (i = 1; i <= MAXN; i++){
        eh_primo[i] = -1;
    }

    cout << "procurando primos de 2 a " << MAXN <<" ...\n";

    // Para cada número de 2 até n
    for (i = 2;  i <= MAXN; i++){
        
        // checo se o número atual é indefinido.
        if(eh_primo[i] == -1){
            crivo(i);
        }
    }

    cout << "fim!\n-----------------------\n";

    delete [] eh_primo;

    return 0;

}

	
	
