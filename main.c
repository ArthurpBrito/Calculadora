#include <stdio.h>

void binario(int n) {
    printf("Convertendo %d para binario:\n", n);
    int bin[32];
    int i = 0;

    while (n > 0) {
        bin[i] = n % 2;
        printf("%d (pois %d %% por 2 tem resto = %d)\n", bin[i], n, bin[i]);
        n = n / 2;
        i++;
    }

    printf("Resultado final em binario: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }
    printf("\n\n");
}

void octal(int n) {
    printf("Convertendo %d para octa:\n", n);
    int oct[32];
    int i = 0;

    while (n > 0) {
        oct[i] = n % 8;
        printf("%d (pois %d %% por 8 = %d)\n", oct[i], n, oct[i]);
        n = n / 8;
        i++;
    }

    printf("Resultado final em octa: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", oct[j]);
    }
    printf("\n\n");
}

void hexa(int n) {
    printf("Convertendo %d para hexa:\n", n);
    char hex[32];
    int i = 0;

    while (n > 0) {
        int resto = n % 16;
        if (resto < 10) {
            hex[i] = 48 + resto;
        } else {
            hex[i] = 55 + resto;
        }
        printf("%c (pois %d %% por 16 = %d)\n", hex[i], n, resto);
        n = n / 16;
        i++;
    }

    printf("Resultado final em hexa: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n\n");
}

void bcd(int n) {
    printf("Convertendo %d para codigo BCD:\n", n);
    int digito;

    while (n > 0) {
        digito = n % 10;
        printf("%d (pois %d %% por 10 = %d)\n", digito, n, digito);
        printf("Representacao em BCD de %d: ", digito);
        for (int i = 3; i >= 0; i--) {
            printf("%d", (digito >> i) & 1);
        }
        printf("\n");
        n /= 10;
    }
    printf("\n");
}

void complementoDois(int n) {
    printf("Convertendo %d para complemento a 2 com 16 bits:\n", n);

    unsigned short binario[16];
    unsigned short num = (unsigned short)n;
    int i = 0;

    for (i = 0; i < 16; i++) {
        binario[i] = (num >> i) & 1;
        printf("%d (pois %d %% por 2^%d = %d)\n", binario[i], num, i, binario[i]);
    }

    printf("Binario (antes do complemento, se aplicavel): ");
    for (int j = 15; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");

    if (n < 0) {
        printf("Como o numero e negativo, calculamos o complemento a 2:\n");
        for (i = 0; i < 16; i++) {
            binario[i] = ~binario[i] & 1;
            printf("Inversao do bit %d: %d\n", i, binario[i]);
        }

        printf("Adicionando 1 ao binario invertido:\n");
        for (i = 0; i < 16; i++) {
            if (binario[i] == 0) {
                binario[i] = 1;
                break;
            } else {
                binario[i] = 0;
            }
        }

        printf("Resultado final em complemento a 2: ");
        for (int j = 15; j >= 0; j--) {
            printf("%d", binario[j]);
        }
        printf("\n");
    }

    printf("\n");
}

int main() {
    int num;
    int opcao;

    printf("Escolha uma opcao:\n");
    printf("1. Converter de base 10 para base 2, base 8, base 16 e BCD\n");
    printf("2. Converter de base 10 para base com sinal (complemento a 2) com 16 bits\n");
    printf("Digite a sua opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Digite um numero decimal: ");
        scanf("%d", &num);
        printf("\n");
        binario(num);
        octal(num);
        hexa(num);
        bcd(num);
    } else if (opcao == 2) {
        printf("Digite um numero decimal: ");
        scanf("%d", &num);
        printf("\n");
        complementoDois(num);
    } else {
        printf("Opcao invalida!\n");
    }

    return 0;
}
