#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int linhas;
    int palavras;
    int caracteres;
} Opcoes;

int main(int argc, char *argv[]) { 
    Opcoes opcoes = {0, 0, 0};
    char *nome_arquivo = NULL;

    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-l") == 0) {
            opcoes.linhas = 1;
        } else if(strcmp(argv[i], "-w") == 0) {
            opcoes.palavras = 1;
        } else if(strcmp(argv[i], "-c") == 0) {
            opcoes.caracteres = 1;
        } else {
            nome_arquivo = argv[i];
        }
    }

    if (opcoes.linhas == 0 && opcoes.palavras == 0 && opcoes.caracteres == 0) {
        opcoes.linhas = 1;
        opcoes.palavras = 1;
        opcoes.caracteres = 1;
    }

    FILE *arquivo;
    if (nome_arquivo == NULL) {
        arquivo = stdin;
    } else {
        arquivo = fopen(nome_arquivo, "r");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
            return 1;
        }
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

    if (arquivo != stdin) {
        fclose(arquivo);
    }

    if (opcoes.linhas) printf("%d ", linhas);
    if (opcoes.palavras) printf("%d ", palavras);
    if (opcoes.caracteres) printf("%d ", caracteres);
    
    if (nome_arquivo != NULL) {
        printf("%s\n", nome_arquivo);
    } else {
        printf("\n");
    }

    return 0;
}