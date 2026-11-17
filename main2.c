/*
 * Защита 4.4
 * Copyright (c) 2026 ankh-331one
 *
 * Licensed under the MIT License; see LICENSE file for details.
 */
/**
 найти макс макс отриц
*/

///p_function.с
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

void mass_input(FILE* f_in, int nx, double* *X){
    (*X) = (double*) malloc(nx * sizeof(double));
    for (int i = 0; i < nx; i++){
        fscanf(f_in, "%lf", &(*X)[i]);
    }
    return;
}

void mass_print(FILE* f_out, char name, int nx, double* X){
    fprintf(f_out, "\nМассив %c(%d): [%.3f", name, nx, X[0]);
    for (int i = 1; i < nx; i++){
        fprintf(f_out, ", %.3f", X[i]);
    }
    fprintf(f_out, "]\n");
    return;
}

int find_id_max(int nx, double* X, int *flag_find, double *max){
    int id_max;
    int j = 0;
    while (j < mx && !(*flag_find)){
        if (X[i] < 0){
            *max = X[i];
            id_max = j;
            (*flag_find) = 1;
        }else j++;
    }
    return id_max;
}

double find_max(int nx, double* X){
    int flag_find = 0;
    double max;
    int j = find_id_max(nx, X, &flag_find, &max);
    if (flag_find){
        for (j += 1; j < mx; j++){
            if (X[i] > max && X[i] < 0){
                max = X[i];
            }
        }
    }
    return max;
}


///p_function.h

#ifndef P_FUNCTION.H
#define P_FUNCTION.H
#include <stdio.h>

int input(char name, int l_diapaz, int r_diapaz);
void mass_input(FILE* f_in, int nx, double* *X);
void mass_print(FILE* f_out, char name, int nx, double* X);
int find_id_max(int nx, double* X, int *flag_find, double *max);
double find_max(int nx, double* X);

#endif // P_FUNCTION.H


///main.c

#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "p_function.h"

#define L_DIAPAZON_MASSIV 1
#define R_DIAPAZON_MASSIV 99

int main()
{
    setlocale(0,"");
    setlocale(LC_NUMERIC, "C");

    FILE* out_file = fopen("output.txt", "a");
    fprintf(out_file, "Программа 4.4v24. Сборка: %s %s", __DATE__, __TIME__);
    fprintf(out_file, "\n---------------------------------------------------------------\n");

    FILE* in_A = fopen("in_A.txt", "r");
    int na = input('A', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double* A;
    mass_input(in_A, na, &A);
    fclose(in_A);

    FILE* in_B = fopen("in_B.txt", "r");
    int nb = input('B', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double* B;
    mass_input(in_B, nb, &B);
    fclose(in_B);

    FILE* in_C = fopen("in_C.txt", "r");
    int nc = input('C', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double* C;
    mass_input(in_C, nc, &C);
    fclose(in_C);

    mass_print(out_file,'A', na, A);
    mass_print(out_file,'B', nb, B);
    mass_print(out_file,'C', nc, C);

    fprintf(out_file, "\n\n---------------------------------------------------------------\n");

    double a = find_max(na, A);
    double b = find_max(nb, B);
    double c = find_max(nc, C);
    fprintf(out_file, "\nМакс: A - %f, B - %f , C - %f\n", a, b, c);

    fprintf(out_file, "\n===============================================================\n\n\t\t");

    fprintf(out_file, "Результат: \n\n");
    if (a > b && a > c){
        fprintf(out_file, "Наибольшаяв масссиве A, %f");
    }else if (a == b && a > c){
        fprintf(out_file, "Одинаковая наибольшая в массивах A и B");
    }else if (a > b && a == c){
        fprintf(out_file, "Одинаковая наибольшая в массивах A и C");
    }else if (a == b && a == c){
        if (a == 0){
            fprintf(out_file, "Во всех векторах нет элементов, некратных %d", ne_krat);
        }else{
            fprintf(out_file, "Одинаковая наибольшая сумма во всех трёх массивах A, B, C");
        }
    }else if (b > c){
        fprintf(out_file, "Наибольшая сумма некратных элементов в масссиве B");
    }else if (b == c){
        fprintf(out_file, "Одинаковая наибольшая сумма в массивах B и C");
    }else{
        fprintf(out_file, "Наибольшая сумма некратных элементов в масссиве C");
    }
    fprintf(out_file, "\n\n===============================================================\n\n\n\n\n");

    fclose(out_file);
    free(A), A = NULL;
    free(B), B = NULL;
    free(C), C = NULL;

    return 0;
}
