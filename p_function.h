/*
 * Лабораторная 4.4 Обработка трех массивов
 * Copyright (c) 2026 ankh-331one
 *
 * Licensed under the MIT License; see LICENSE file for details.
 */
#ifndef P_FUNCTION.H
#define P_FUNCTION.H
#include <stdio.h>

int input(char name, int l_diapaz, int r_diapaz);
void mass_input(FILE* f_in, int nx, int* *X);
void mass_print(FILE* f_out, char name, int nx, int* X);
int sum_mass_x(int nx, int* X, int ne_kr);

#endif // P_FUNCTION.H
