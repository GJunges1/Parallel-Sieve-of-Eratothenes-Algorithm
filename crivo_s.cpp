// Gabriel Junges Baratto
// Crivo de Eratóstenes (números primos)
// Versão SERIAL

#include <iostream>

#define MAXN 2000000000

using namespace std;

int main(){

    short *eh_primo = new short [MAXN+1]; // -1 => indefinido, 0 => composto e 1 => primo.
                                        // seus elementos são inicializados com -1

    long int j = 0;
    long int i = 0;

    cout << "inicializando o vetor de marcação de primos...\n";

    // Inicializando "eh_primo" com -1, pois não sabemos nada sobre nenhum número, inicialmente.
    for (i = 1; i <= MAXN; i++){
        eh_primo[i] = -1;
    }

    cout << "procurando primos de 2 a" << MAXN <<" ...\n";

    // Para cada número de 2 até n
    {
	    for (i = 2;  i <= MAXN; i++){
		    
            // checo se o número atual é indefinido.
            if(eh_primo[i] == -1){
                
                // Se ele for, indico que ele é primo e o exibo
                eh_primo[i] = 1;
            
                // e que os múltiplos dele são compostos.

                for(int k = i + i; k <= MAXN; k += i){
                    eh_primo[k] = 0;
                }
            }
	    }
    }

    cout << "fim!\n-----------------------\n";
    cout << "\n último número verificado: " << i << std::endl;

    delete [] eh_primo;

    return 0;

}

	
	
