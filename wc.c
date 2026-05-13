#include <stdio.h>
#include <string.h> // pra usar strcmp
#include <ctype.h> // pra usar isspace

// estrutura pra guardar as opcoes escolhidas
typedef struct {
    int linhas;
    int palavras;
    int caracteres;
} Opcoes;

int main(int argc, char *argv[]) { 
    if (argc < 2) {
        printf("Uso: %s [opcoes] <arquivo>\n", argv[0]);
        return 1;
    }

    Opcoes opcoes = {0, 0, 0}; // zera as flags
    char *nome_arquivo = NULL;

    // le os argumentos pra ver quais flags foram passadas
    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-l") == 0) {
            opcoes.linhas = 1;
        } else if(strcmp(argv[i], "-w") == 0) {
            opcoes.palavras = 1;
        } else if(strcmp(argv[i], "-c") == 0) {
            opcoes.caracteres = 1;
        } else {
            // se nao eh flag, assumimos que eh o nome do arquivo
            nome_arquivo = argv[i];
        }
    }

    if (nome_arquivo == NULL) {
        printf("Erro: arquivo nao informado\n");
        return 1;
    }

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 1;
    }

    int caracteres = 0;
    int linhas = 0;
    int palavras = 0;
    int dentro_palavra = 0;
    int c;

    while ((c = fgetc(arquivo)) != EOF) {
        caracteres++;
        if (c == '\n') linhas++;

        if (isspace(c)) {
            dentro_palavra = 0;
        } else if (dentro_palavra == 0) {
            dentro_palavra = 1;
            palavras++;
        }
    }

    fclose(arquivo);

    printf("%d %d %d %s\n", linhas, palavras, caracteres, nome_arquivo);

    return 0;
}