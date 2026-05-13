#include <stdio.h>

int main(int argc, char *argv[]) { 
    // verifica se passou o arquivo
    if (argc < 2) {
        printf("Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    // pega nome do arquivo
    char *nome_arquivo = argv[1];

    // abre arquivo pra leitura
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 1;
    }

    int caracteres = 0;
    int linhas = 0;
    int c;

    // le char por char ate o fim
    while ((c = fgetc(arquivo)) != EOF) {
        caracteres++;

        // conta quebra de linha
        if (c == '\n') {
            linhas++;
        }
    }

    // fecha arquivo
    fclose(arquivo);

    // imprime linhas chars e nome
    printf("%d %d %s\n", linhas, caracteres, nome_arquivo);

    return 0;
}