
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
  


TEST_CASE( "Testa velha", "[single-file]" ) {
	int teste1[3][3]= {   { 2, 0, 1 }, 
	                      { 2, 0, 1 },
						  { 0, 2, 1 }
					  };


    REQUIRE( VerificaVelha(teste1) != -2 );
	int teste2[3][3]= {   { 2, 0, 1 }, 
	                      { 2, 0, 1 },
						  { 2, 2, 1 }
					  };
	REQUIRE( VerificaVelha(teste2) == -2);
} 

TEST_CASE("Testa se X ganhou", "[velha]") {
    // Tabuleiro onde X ganha pela primeira linha
    int x_ganhou_linha[3][3] = {
        {1, 1, 1},  // X vence pela primeira linha
        {2, 0, 0},
        {0, 2, 0}
	};
	REQUIRE( VerificaVelha(x_ganhou_linha) == 1);

	int o_ganhou_linha[3][3] = {
		{2, 2, 2},
		{1, 1, 0},
		{1, 0, 0}
	};
	REQUIRE( VerificaVelha(o_ganhou_linha) == 1);

	// Tabuleiro onde X ganha pela segunda coluna
	int x_ganhou_coluna[3][3] = {
		{2, 1, 2},
		{0, 1, 2},
		{0, 1, 0}
	};
	REQUIRE( VerificaVelha(x_ganhou_coluna) == 1);

	// Tabuleiros onde X ganha por ambas as diagonais
	int x_ganhou_diagonal[3][3] = {
		{1, 2, 2},
		{0, 1, 0},
		{0, 0, 1}
	};
	REQUIRE( VerificaVelha(x_ganhou_diagonal) == 1);

	int x_ganhou_diagonal_inversa[3][3] = {
		{2, 2, 1},
		{0, 1, 0},
		{1, 0, 0}
	};
	REQUIRE( VerificaVelha(x_ganhou_diagonal_inversa) == 1);


	//outros testes aqui

}