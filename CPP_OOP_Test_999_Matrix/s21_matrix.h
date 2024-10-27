//
// Created by genesiss on 15.10.22.
//

#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>  // для работы с malloc, calloc, free
#include <time.h>  // для работы со случайными числами

#define OK 0
#define ERR_INCOR_MATRIX 1
#define ERR_CALCULATION 2

/**
 *  Результаты функций сравнения
 */
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

/**
 * @brief Функция создания матрицы.
 * @param rows int - кол-во строк.
 * @param columns int - кол-во столбцов.
 * @param result matrix_t - кол-во столбцов.
 * @return 0 - OK. 1 - Ошибка, некорректная матрица. 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

/**
 * @brief Функция очистки матрицы.
 * @param A matrix_t - матрица.
 * @return void
 */
void s21_remove_matrix(matrix_t *A);

/**
 * @brief Функция сравнения матриц. Сравнение должно происходить вплоть до 7
 * знака после запятой включительно.
 * @param A matrix_t - матрица A.
 * @param B matrix_t - матрица B.
 * @return 0 == FALSE - матрицы не равны. 1 == TRUE - матрицы равны.
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief Функция сложения матриц.
 * @param A matrix_t - матрица A.
 * @param B matrix_t - матрица B.
 * @param result matrix_t - матрица result.
 * @return 0 - OK. 1 - Ошибка, некорректная матрица. 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Функция вычитания матриц.
 * @param A matrix_t - матрица A.
 * @param B matrix_t - матрица B.
 * @param result matrix_t - матрица result.
 * @return 0 - OK. 1 - Ошибка, некорректная матрица. 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Функция умножения матрицы на число.
 * @param A matrix_t - матрица A.
 * @param number double - число.
 * @param result matrix_t - матрица result.
 * @return 0 - OK. 1 - Ошибка, некорректная матрица. 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

/**
 * @brief Функция умножения матрицы на матрицу.
 * @param A matrix_t - матрица A.
 * @param B matrix_t - матрица B.
 * @param result matrix_t - матрица result.
 * @return 0 - OK. 1 - Ошибка, некорректная матрица. 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Функция транспонирования матрицы. Замена строк этой матрицы её
 * столбцами с сохранением их номеров.
 * @param A matrix_t - матрица A.
 * @param result matrix_t - матрица result.
 * @return 0 - OK. 1 - Ошибка, некорректная матрица. 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_transpose(matrix_t *A, matrix_t *result);

/**
 * @brief Функция высчитывает минор матрицы. Минором M(i,j) называется
 * определитель (n-1)-го порядка, полученный вычёркиванием из матрицы A i-й
 * строки и j-го столбца.
 * @param A matrix_t - матрица A.
 * @param result matrix_t - матрица result.
 * @return 0 - OK. 1 - Ошибка, некорректная матрица. 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);

/**
 * @brief Функция высчитывает определитель (детерминант) матрицы.
 * @param A matrix_t - матрица A.
 * @param result double - детерминант (определитель).
 * @return 0 - OK. 1 - Ошибка, некорректная матрица. 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_determinant(matrix_t *A, double *result);

/**
 * @brief Функция для получения обратной матрицы. Матрицу A в степени -1
 * называют обратной к квадратной матрице А, если произведение этих матриц
 * равняется единичной матрице. Обратной матрицы не существует, если
 * определитель равен 0.
 * @param A matrix_t - матрица A.
 * @param result matrix_t - матрица result.
 * @return 0 - OK. 1 - Ошибка, некорректная матрица. 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

//------------------------ V Вспомогательные функции V ------------------------

/**
 * @brief Функция выводит матрицу в консоль.
 * @param matrix matrix_t - матрица.
 * @return 0 - OK. 1 - Ошибка, некорректная матрица. 2 - Ошибка вычисления
 * (несовпадающие размеры матриц; матрица, для которой нельзя провести
 * вычисления и т.д.)
 */
int print_matrix(matrix_t matrix);

/**
 * @brief Функция генерации случайного числа. Возвращает случайное целое число
 * в диапазоне [-10; 10]
 */
int ran_num_gen();

/**
 * @brief Функция генерации случайного числа. Возвращает случайное целое число
 * в диапазоне [-10; 10]
 */
double random_double();

/**
 * @brief Функция заполняет матрицу [-10; 10]
 */
int fill_matrix_with_int(matrix_t *matrix);

/**
 * @brief Функция заполняет матрицу [-10.0; 10.0]
 */
int fill_matrix_with_double(matrix_t *matrix);

/**
 * @brief Функция сравнения размеров двух матриц. Если кол-во строк матрицы A
 * равно кол-ву строк матрицы B, и кол-во столбцов матрицы A равно кол-ву
 * столбцов матрицы B, то размер матриц считается равным.
 * @param A matrix_t - матрица A.
 * @param B matrix_t - матрица B.
 * @return 0 == FALSE - размер матриц не равен.
 * 1 == TRUE - размер матриц равен.
 */
int equal_size_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief Функция проверки матриц на корректность. Сравнивается кол-во строк
 * двух матриц и кол-во столбцов матриц.
 * @param A matrix_t - матрица A.
 * @param B matrix_t - матрица B.
 * @return 0 == FALSE - матрицы некорректные. 1 == TRUE - матрицы корректные.
 */
int correct_matrix(matrix_t A, matrix_t B);

/**
 * @brief Функция проверки матрицы на корректность. Проверяется кол-во строк
 * и столбцов матрицы.
 * @param A matrix_t - матрица A.
 * @return 0 == FALSE - матрица некорректные. 1 == TRUE - матрица корректные.
 */
int correct_matrix_once(matrix_t A);

/**
 * @brief Функция заполняет матрицу в структуре. На вход получает структуру, в
 * которой лежит целевая матрица, и массив чисел, которомы надо заполнить
 * матрицу.
 * @param A matrix_t - матрица A.
 * @param arr double - массив чисел.
 */
void fill_matrix_with_array(matrix_t *A, double *arr);

void clean_matrix(matrix_t *matrix);

int check_matrix(matrix_t *matrix);

void div_matrix(matrix_t *A, double *number);

#endif /* SRC_S21_MATRIX_H_ */
