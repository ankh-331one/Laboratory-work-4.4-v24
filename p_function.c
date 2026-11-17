/*
 * Лабораторная 4.4 Обработка трех массивов
 * Copyright (c) 2026 ankh-331one
 *
 * Licensed under the MIT License; see LICENSE file for details.
 */
#include <stdio.h>
#include <malloc.h>
#include "p_function.h"
#include <math.h>

int input(char name, int min_d, int max_d){
    int n;
    do{
        printf("\nВведите размер %c: ", name);
        scanf("%d", &n);
        if (n < min_d || n > max_d){
            printf("\n===============================================================\n");
            printf("Неверно задан размер %c", name);
            printf("\n===============================================================\n");
        }
    }while (n < min_d || n > max_d);
    return n;
}

void mass_input(FILE* in_file, int n, double* *X){
    (*X) = (double*) malloc(n * sizeof(double));
    for (int i = 0; i < n; i++){
        fscanf(in_file, "%lf", &(*X)[i]);
    }
    return;
}

void mass_print(FILE* out_file, char name, int n, double* X){
    fprintf(out_file, "\nМассив %c(%d): [%.3f", name, n, X[0]);
    for (int i = 1; i < n; i++){
        fprintf(out_file, ", %.3f", X[i]);
    }
    fprintf(out_file, "]\n");
    return;
}

int id_max(int n, double* X){
    int id_max = 0;
    double max = X[0];
    for (int i = 1; i < n; i++){
        if (X[i] >= max){
            max = X[i];
            id_max = i;
        }
    }
    return id_max;
}

void cr_geomet_poloz(FILE* out_file, int n, double* X){
    int k = 0;
    double res = 1;
    for (int i = 0; i < n; i++){
        if (X[i] > 0){
            k += 1;
            res *= X[i];
        }
    }
    if (k == 0){
        fprintf(out_file, "\n\nВ выбранном векторе нет положительных элементов");
    }else{
        fprintf(out_file, "\n\nСреднее геометрическое положительных элементов: %.3f",pow(res,(1.0/k)));
    }
    return;
}

