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
    fprintf(out_file, "Программа 4.4v24. Сборка: %s %s", __DATE__, __TIME__);
    fprintf(out_file, "\n---------------------------------------------------------------\n");

    FILE* in_A = fopen("in_A.txt", "r");
    int a = input('A', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    int* A;
    mass_input(in_A, a, &A);
    fclose(in_A);

    FILE* in_B = fopen("in_B.txt", "r");
    int b = input('B', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    int* B;
    mass_input(in_B, b, &B);
    fclose(in_B);

    FILE* in_C = fopen("in_C.txt", "r");
    int c = input('C', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    int* C;
    mass_input(in_C, c, &C);
    fclose(in_C);

    int ne_krat;
    do{
        printf("\nВведите число X для проверки кратности: ");
        scanf("%d", &ne_krat);
        if (ne_krat == 0){
            printf("\n===============================================================\n");
            printf("Число X не может быть равно нулю");
            printf("\n===============================================================\n");
        }
    }while (ne_krat == 0);

    mass_print(out_file,'A', a, A);
    mass_print(out_file,'B', b, B);
    mass_print(out_file,'C', c, C);
    fprintf(out_file, "\nЧисло X для проверки кратности: %d", ne_krat);

    fprintf(out_file, "\n\n---------------------------------------------------------------\n");

    a = sum_mass_x(a, A, ne_krat);
    b = sum_mass_x(b, B, ne_krat);
    c = sum_mass_x(c, C, ne_krat);
    fprintf(out_file, "\nСуммы некратных %d элементов: A - %d, B - %d , C - %d\n", ne_krat, a, b, c);

    fprintf(out_file, "\n===============================================================\n\n\t\t");

    fprintf(out_file, "Результат: \n\n");
    if (a > b && a > c){
        fprintf(out_file, "Наибольшая сумма некратных элементов в масссиве A");
    }else if (a == b && a > c){
        fprintf(out_file, "Одинаковая наибольшая сумма в массивах A и B");
    }else if (a > b && a == c){
        fprintf(out_file, "Одинаковая наибольшая сумма в массивах A и C");
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
