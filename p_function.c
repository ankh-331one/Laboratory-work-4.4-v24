/*
 * Лабораторная 4.4 Обработка трех массивов
 * Copyright (c) 2026 ankh-331one
 *
 * Licensed under the MIT License; see LICENSE file for details.
 */
#include <stdio.h>
#include <malloc.h>
#include "p_function.h"

int input(char name, int l_diapaz, int r_diapaz){
    int n;
    do{
        printf("\nВведите размер %c: ", name);
        scanf("%d", &n);
        if (n < l_diapaz || n > r_diapaz){
            printf("\n===============================================================\n");
            printf("Неверно задан размер %c", name);
            printf("\n===============================================================\n");
        }
    }while (n < l_diapaz || n > r_diapaz);
    return n;
}

void mass_input(FILE* f_in, int nx, int* *X){
    (*X) = (int*) malloc(nx * sizeof(int));
    for (int i = 0; i < nx; i++){
        fscanf(f_in, "%d", &(*X)[i]);
    }
    return;
}

void mass_print(FILE* f_out, char name, int nx, int* X){
    fprintf(f_out, "\nМассив %c(%d): [%d", name, nx, X[0]);
    for (int i = 1; i < nx; i++){
        fprintf(f_out, ", %d", X[i]);
    }
    fprintf(f_out, "]\n");
    return;
}

int sum_mass_x(int nx, int* X, int ne_kr){
    int sum = 0;
    for (int i = 0; i < nx; i++){
        if (X[i] % ne_kr != 0){
            sum += X[i];
        }
    }
    return sum;
}
