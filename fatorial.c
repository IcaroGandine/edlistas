#include <stdio.h>

int f_fatorial(int n) {
    int fat;
    for(fat = 1; n > 1; n = n - 1)
        fat = fat * n;
    
    return fat;
}

int main() {
    
    int fat, n;
    printf("Insira um valor para o qual deseja calcular seu fatorial: ");
    scanf("%i", &n);

    fat=f_fatorial(n);

    printf("Valor N: %i", n);
    printf("\nFatorial calculado: %i\n", fat);

    return 0;
}
