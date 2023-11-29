#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"

typedef struct {
    int numero, total, ataque, defesa, ataqueEspecial, defesaEspecial, velocidade, geracao;
    char nome[50], tipo1[20], tipo2[20], cor[20];
    float altura, peso;
    int lendario, taxaCaptura, proximaEvolucao, preEvolucao;
}Pokemon;


int main() {
    Pokemon *pokedex = (Pokemon*) malloc(721 * sizeof(Pokemon));
    int numPokemons = 721;

    FILE *arquivoCSV = fopen("pokedex.csv", "r");
    if (arquivoCSV == NULL) {
        perror("Erro ao abrir o arquivo CSV");
        return 1;
    }

    // Pular a primeira linha do arquivo CSV
    char header[256];
    fgets(header, sizeof(header), arquivoCSV);

    cadastrarPokemon(pokedex, numPokemons, arquivoCSV);

  

    fclose(arquivoCSV);

    // Salvar dados em arquivo binário
    FILE *arquivoBinario = fopen("pokedex.bin", "wb");
    if (arquivoBinario == NULL) {
        perror("Erro ao criar o arquivo binário");
        return 1;
    }

    fwrite(pokedex, sizeof(struct Pokemon), numPokemons, arquivoBinario);

    fclose(arquivoBinario);

  
    return EXIT_SUCCESS;
    }


