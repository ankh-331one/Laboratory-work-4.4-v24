//Лабораторная работа №4.4v24
/**
4.4 Обработка трех массивов

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

    FILE* in_file = fopen("input.txt", "r");

    int a = input('A', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    int* A;
    mass_input(in_file, a, &A);

    int b = input('B', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    int* B;
    mass_input(in_file, b, &B);

    int c = input('C', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    int* C;
    mass_input(in_file, c, &C);

    int x;
    do{
        printf("\nВведите число X для проверки кратности: ");
        scanf("%d", &x);
        if (x == 0){
            printf("\n===============================================================\n");
            printf("Число K не может быть равно нулю");
            printf("\n===============================================================\n");
        }
    }while (x == 0);

    fclose(in_file);

    mass_print(out_file,'a', a, A);
    mass_print(out_file,'b', b, B);
    mass_print(out_file,'c', c, C);
    fprintf(out_file, "\nЧисло X для проверки кратности: %d", x);

    fprintf(out_file, "\n\n---------------------------------------------------------------\n");

    a = sum_mass_x(a, A, x);
    b = sum_mass_x(b, B, x);
    c = sum_mass_x(c, C, x);
    fprintf(out_file, "\nСуммы некратных %d элементов: A - %d, B - %d , C - %d\n", x, a, b, c);

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
            fprintf(out_file, "Во всех векторах нет элементов, некратных %d", x);
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
    free(A);
    free(B);
    free(C);

    return 0;
}
