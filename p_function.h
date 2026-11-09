/*
 * Лабораторная 4.4 Обработка трех массивов
 * Copyright (c) 2026 ankh-331one
 *
 * Licensed under the MIT License; see LICENSE file for details.
 */
#ifndef P_FUNCTION.H
#define P_FUNCTION.H
#include <stdio.h>

int input(char a, int min_d, int max_d);
void mass_input(FILE* in_file, int n, int* *X);
void mass_print(FILE* out_file, char a, int n, int* X);
int sum_mass_x(int n, int* X, int a);

#endif // P_FUNCTION.H
