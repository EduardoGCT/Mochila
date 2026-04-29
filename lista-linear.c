#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item{
    char nome[30];
    char tipo[20];
    int quantidade;
};

//funções

void inserirItem(int *qtdAtual, struct Item mochila[]);
void listarItens(int *qtdAtual, struct Item mochila[]);
void buscarItem(int *qtdAtual, struct Item mochila []);
void removerItem(int *qtdAtual, struct Item mochila[]);

//graficos


int main(){
    struct Item mochila[10];
    int qtdAtual = 0;
    
    int opcao;

    do{
        printf("=================================\n");
        printf("   MOCHILA DE SOBREVIVENCIA");
        printf("\n=================================\n\n");

        printf("Itens na Mochila: %d/10\n\n", qtdAtual);

        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens na Mochila\n");
        printf("4. Buscar Item\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao){
            case 1:
                printf("\n\n--- Adicionar Novo Item ---\n\n");
                inserirItem(&qtdAtual, mochila);
                break;
            case 2: 
                    printf("\n\n--- REMOVER ITEM ---\n\n");
                    removerItem(&qtdAtual, mochila);
                break;
            case 3:
                listarItens(&qtdAtual, mochila);
                break;
            case 4:
                printf("\n\n--- BUSCAR ITEM ---\n\n");
                buscarItem(&qtdAtual, mochila);
                break;
            case 0:
                printf("\n\nSaindo do Sistema...\n\n");
                break;
            default:
                printf("\n\nerro\n\n");
                break;
        }        
    } while (opcao != 0);

    return 0;
}

void inserirItem(int *qtdAtual, struct Item mochila[]){

    if (*qtdAtual >= 10){
        printf("\nMochila cheia.");
        return;
    }
    
    int i = *qtdAtual;

    printf("Nome do item: ");
    scanf("%s", mochila[i].nome);

    printf("Tipo do item (arma, municao, cura, etc.): ");
    scanf("%s", mochila[i].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[i].quantidade);

    printf("\n\nItem '%s' adicionado com sucesso!\n\n", mochila[i].nome);

    (*qtdAtual)++;

    printf("Pressione Enter para continuar...");
    setbuf(stdin, NULL);
    getchar();
}

void listarItens(int *qtdAtual, struct Item mochila[]){

    if (*qtdAtual == 0){
        printf("\n\nMochila vazia... Adicione um item para listar.\n\n");
        return;
    }

    printf("\n--- ITENS NA MOCHILA (%d/10) ---\n\n", *qtdAtual);
    printf("\n----------------------------------------\n");
    printf("%-10s | %-10s | %s\n", "NOME", "TIPO", "QUANTIDADE");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < *qtdAtual; i++){
        printf("%-10s | %-10s | %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("\n\n");

    printf("Pressione ENTER para continuar...");
    setbuf(stdin, NULL);
    getchar();
}

void buscarItem(int *qtdAtual, struct Item mochila[]){
    
    if (*qtdAtual == 0){
        printf("\n\nMochila sem itens....\n\n");
        return;
    }

    char nomeBuscado[15];
    int encontrou = 0;

    printf("Digite o nome do item: ");
    scanf("%s", nomeBuscado);
    
    printf("\n\n--- Resultado da Busca ---\n");
    for(int i = 0; i < *qtdAtual; i++){
        if (strcmp(nomeBuscado, mochila[i].nome) == 0){
            printf("%-10s | %-10s | %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrou = 1;
        }
    }

    if(encontrou == 0){
        printf("\nNenhum item encontrado...\n\n");
    }    

    printf("Pressione ENTER para continuar...");
    setbuf(stdin, NULL);
    getchar();
}

void removerItem(int *qtdAtual, struct Item mochila[]){

    char nomeRemover[15];
    int indiceRemover = -1;
    printf("Digite o nome do item: ");
    scanf("%s", nomeRemover);
    
    for(int i = 0; i < *qtdAtual; i++){
        if (strcmp(nomeRemover, mochila[i].nome) == 0){
            indiceRemover = i;
            break;
        }
    }

    if(indiceRemover != -1){
        for(int j = indiceRemover; j < *qtdAtual -1; j++){
            mochila[j] = mochila[j + 1];
        }

        (*qtdAtual)--;
        printf("\n\nItem '%s' removido com sucesso!\n\n", nomeRemover);
    } else {
        printf("\n\nItem não encontrado!\n\n");
    }

    printf("Pressione ENTER para continuar...");
    setbuf(stdin, NULL);
    getchar();
}
