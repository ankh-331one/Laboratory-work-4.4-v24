#include <stdio.h>
#include <malloc.h>
#include "p_function.h"

int input(char a, int min_d, int max_d){
    int n;
    do{
        printf("\nВведите размер %c: ", a);
        scanf("%d", &n);
        if (n < min_d || n > max_d){
            printf("\n===============================================================\n");
            printf("Неверно задан размер %c", a);
            printf("\n===============================================================\n");
        }
    }while (n < min_d || n > max_d);
    return n;
}

void mass_input(FILE* in_file, int n, int* *X){
    (*X) = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        fscanf(in_file, "%d", &(*X)[i]);
    }
    return;
}

void mass_print(FILE* out_file, char a, int n, int* X){
    fprintf(out_file, "\nМассив %c(%d): [%d", a, n, X[0]);
    for (int i = 1; i < n; i++){
        fprintf(out_file, ", %d", X[i]);
    }
    fprintf(out_file, "]\n");
    return;
}

int sum_mass_x(int n, int* X, int a){
    int sum = 0;
    for (int i = 0; i < n; i++){
        if (X[i] % a != 0){
            sum += X[i];
        }
    }
    return sum;
}
