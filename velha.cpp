/**
 * \file  velha.cpp
 */

 
#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */ 

int VerificaVelha(int velha[3][3]) {
    // 1. Verificar se o número de X e O é válido
    if (!VerificaNumeroXEO(velha)) {
        return -2;  // Jogo impossível
    }
  	for (int i = 0; i < 3; i++) {
    	// Verifica as linhas
        if (velha[i][0] == 1 && velha[i][1] == 1 && velha[i][2] == 1) {
            return 1;  // X ganhou
        }
        if (velha[i][0] == 2 && velha[i][1] == 2 && velha[i][2] == 2) {
            return 2;  // O ganhou
        }

		
		// Verifica as colunas
        if (velha[0][i] == 1 && velha[1][i] == 1 && velha[2][i] == 1) {
            return 1;  // X ganhou
		}
		if (velha[0][i] == 2 && velha[1][i] == 2 && velha[2][i] == 2) {
            return 2;  // O ganhou
        }
	}


		// Verifica as diagonais
		
    	if (velha[0][0] == 1 && velha[1][1] == 1 && velha[2][2] == 1) {
        	return 1;  // X ganhou
    	}
    	if (velha[0][2] == 1 && velha[1][1] == 1 && velha[2][0] == 1) {
        	return 1;  // X ganhou
		}
		// Verifica as diagonais para O
    	if (velha[0][0] == 2 && velha[1][1] == 2 && velha[2][2] == 2) {
        	return 2;  // O ganhou
    	}
    	if (velha[0][2] == 2 && velha[1][1] == 2 && velha[2][0] == 2) {
        	return 2;  // O ganhou
    	}
				

    // Aqui você pode adicionar outras verificações mais tarde (como verificação de vencedor, indefinido, etc.)
    
    return 0;  // Nenhum vencedor, impate ou indefinido
}

// Função auxiliar para verificar se o número de X e O é válido
bool VerificaNumeroXEO(int velha[3][3]) {
    int countX = 0, countO = 0;

    // Contando X e O
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (velha[i][j] == 1) countX++;
            else if (velha[i][j] == 2) countO++;
        }
    }

    // Se o número de X e O for válido (X não pode ser mais de 1 a mais que O, e O não pode ter mais peças que X)
    return (countX == countO || countX == countO + 1);
	// Verificar se é empate (tabuleiro cheio e sem vencedor)
    bool cheio = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (velha[i][j] == 0) {
                cheio = false;
                break;
            }
        }
    }
    if (cheio) return 0;  // Tabuleiro cheio sem vencedor é empate

    // Caso contrário, ainda pode estar indefinido
    return -1;
}

