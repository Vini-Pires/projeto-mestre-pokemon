/* #include "pokedex.h"

//************************************************************************************

void cadastrarPokemon(struct Pokemon *pokedex, int *numPokemons, FILE *file) {
    if (*numPokemons < MAXIMO_DE_POKEMONS) {
        
        fscanf(file, "%d,%49[^,],%19[^,],%19[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%19[^,],%f,%f,%d,%d,%d\n",
               &pokedex[*numPokemons].numero, pokedex[*numPokemons].nome, pokedex[*numPokemons].tipo1,
               pokedex[*numPokemons].tipo2, &pokedex[*numPokemons].total, &pokedex[*numPokemons].ataque,
               &pokedex[*numPokemons].defesa, &pokedex[*numPokemons].ataqueEspecial,
               &pokedex[*numPokemons].defesaEspecial, &pokedex[*numPokemons].velocidade,
               &pokedex[*numPokemons].geracao, &pokedex[*numPokemons].lendario, pokedex[*numPokemons].cor,
               &pokedex[*numPokemons].altura, &pokedex[*numPokemons].peso, &pokedex[*numPokemons].taxaCaptura,
               &pokedex[*numPokemons].proximaEvolucao, &pokedex[*numPokemons].preEvolucao);

        (*numPokemons)++;
        printf("Pokemon cadastrado com sucesso!\n");
    } else {
        printf("Pokedex cheia. Impossível cadastrar mais Pokémons.\n");
    }
}

// ******************************************************************************** //

void listarPokemons(const struct Pokemon *pokedex, int numPokemons) {
    if (numPokemons > 0) {
        // listar todos os Pokémons, ou uma certa quantidade na tela
        for (int i = 0; i < numPokemons; i++) {
            printf("Número: %d, Nome: %s, Tipo1: %s, Tipo2: %s\n", pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2);
        }
    } else {
        printf("Pokedex vazia. Nenhum Pokémon cadastrado.\n");
    }
}
*/
