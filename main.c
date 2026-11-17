/*
 * Лабораторная 4.4 Обработка трех массивов
 * Copyright (c) 2026 ankh-331one
 *
 * Licensed under the MIT License; see LICENSE file for details.
 */
/**
    Во всех задачах дано 3 одномерных массива A, B и C разного размера.
 Для каждого из них найти требуемое значение, и затем из трёх полученных
 выбрать экстремум (наибольшее/наименьшее). Если значения экстремумов
 совпадают, вывести соответствующее сообщение (с указанием имён массивов
 с совпадающими значениями). Для обработки массивов, ввода и вывода
 использовать подпрограммы. Имейте в виду, что искомых элементов в
 массиве(ах) может не быть. Будьте внимательны при определении типа
 данных элементов массивов.

    24. Какой из массивов имеет наибольшую сумму элементов, некратных
 заданному числу?
*/

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
    fprintf(out_file, "Программа 4.5v24. Сборка: %s %s", __DATE__, __TIME__);
    fprintf(out_file, "\n---------------------------------------------------------------\n");

    FILE* in_A = fopen("input_A.txt", "r");
    int n_a = input('A', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double* A;
    mass_input(in_A, n_a, &A);
    fclose(in_A);

    FILE* in_B = fopen("input_B.txt", "r");
    int n_b = input('B', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double* B;
    mass_input(in_B, n_b, &B);
    fclose(in_B);

    FILE* in_C = fopen("input_C.txt", "r");
    int n_c = input('C', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double* C;
    mass_input(in_C, n_c, &C);
    fclose(in_C);


    mass_print(out_file,'a', n_a, A);
    mass_print(out_file,'b', n_b, B);
    mass_print(out_file,'c', n_c, C);

    fprintf(out_file, "\n\n---------------------------------------------------------------\n");

    int a = id_max(n_a, A);
    int b = id_max(n_b, B);
    int c = id_max(n_c, C);

    fprintf(out_file, "\nИндексы максимумов: A - %d, B - %d, C - %d\n", a, b, c);


    fprintf(out_file, "\n===============================================================\n\n\t\t");

    fprintf(out_file, "Результат: \n\n");
    if (a > b && a > c){
        fprintf(out_file, "Наибольший индекс максимума в масссиве A");
        cr_geomet_poloz(out_file, n_a, A);
    }else if (a == b && a > c){
        fprintf(out_file, "Одинаковый наибольший индекс максимума в массивах A и B");
        cr_geomet_poloz(out_file, n_a, A);
        cr_geomet_poloz(out_file, n_b, B);
    }else if (a > b && a == c){
        fprintf(out_file, "Одинаковый наибольший индекс максимума в массивах A и C");
        cr_geomet_poloz(out_file, n_a, A);
        cr_geomet_poloz(out_file, n_c, C);
    }else if (a == b && a == c){
        fprintf(out_file, "Одинаковый наибольший индекс максимума во всех трёх массивах A, B, C");
        cr_geomet_poloz(out_file, n_a, A);
        cr_geomet_poloz(out_file, n_b, B);
        cr_geomet_poloz(out_file, n_c, C);
    }else if (b > c){
        fprintf(out_file, "Наибольший индекс максимума в масссиве B");
        cr_geomet_poloz(out_file, n_b, B);
    }else if (b == c){
        fprintf(out_file, "Одинаковый наибольший индекс максимума в массивах B и C");
        cr_geomet_poloz(out_file, n_b, B);
        cr_geomet_poloz(out_file, n_c, C);
    }else{
        fprintf(out_file, "Наибольший индекс максимума в масссиве C");
        cr_geomet_poloz(out_file, n_c, C);
    }

    fprintf(out_file, "\n\n===============================================================\n\n\n\n\n");

    fclose(out_file);
    free(A);
    free(B);
    free(C);

    return 0;
}
