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

    // Aqui você pode adicionar outras verificações mais tarde (como verificação de vencedor, indefinido, etc.)
    
    return 1;  // Se for válido, retornamos 1 (pode-se prosseguir com o jogo)
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
}

