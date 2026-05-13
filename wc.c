#include <stdio.h>
#include <ctype.h> // pra usar isspace

int main(int argc, char *argv[]) { 
    // verifica se passou o arquivo
    if (argc < 2) {
        printf("Uso: %s [opcoes] <arquivo>\n", argv[0]);
        return 1;
    }

    // pega nome do arquivo (por enquanto assumimos que eh o ultimo argumento)
    char *nome_arquivo = argv[argc - 1];

    // abre arquivo pra leitura
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 1;
    }

    int caracteres = 0;
    int linhas = 0;
    int palavras = 0;
    int dentro_palavra = 0; // flag pra saber se ta lendo uma palavra
    int c;

    // le char por char ate o fim
    while ((c = fgetc(arquivo)) != EOF) {
        caracteres++;

        // conta quebra de linha
        if (c == '\n') {
            linhas++;
        }

        // logica pra contar palavras
        if (isspace(c)) {
            dentro_palavra = 0; // achou espaco, saiu da palavra
        } else if (dentro_palavra == 0) {
            dentro_palavra = 1; // achou letra nova, entrou na palavra
            palavras++;
        }
    }

    // fecha arquivo
    fclose(arquivo);

    // imprime linhas, palavras, chars e nome
    printf("%d %d %d %s\n", linhas, palavras, caracteres, nome_arquivo);

    return 0;
}