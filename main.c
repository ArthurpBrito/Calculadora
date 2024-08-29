#include <stdio.h>

void binario(int n) {
    printf("Convertendo %d para binario:\n", n);
    int bin[32];
    int i = 0;

    while (n > 0) {
        bin[i] = n % 2;
        printf("%d (pois o resto de %d e = %d)\n", bin[i], n, bin[i]);
        n = n / 2;
        printf("Atualizando n: %d\n", n);
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
        printf("%d (pois %d dividido por 8 e = %d)\n", oct[i], n, oct[i]);
        n = n / 8;
        printf("Atualizando n: %d\n", n);
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
        printf("%c (pois %d dividido por 16 e = %d)\n", hex[i], n, resto);
        n = n / 16;
        printf("Atualizando n: %d\n", n);
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
        printf("%d (pois %d dividido por 10  e = %d)\n", digito, n, digito);
        printf("Representacao em BCD de %d: ", digito);
        for (int i = 3; i >= 0; i--) {
            printf("%d", (digito >> i) & 1);
        }
        printf("\n");
        n /= 10;
    }
    printf("\n");
}

int main() {
    int num;

    printf("digitoe um numero decimal: ");
    scanf("%d", &num);

    printf("\n");
    binario(num);
    octal(num);
    hexa(num);
    bcd(num);

    return 0;
}
