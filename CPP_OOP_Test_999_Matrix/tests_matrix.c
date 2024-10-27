#include "s21_matrix.h"

#test S21_CREATE_MATRIX_000
  matrix_t A;
  int rows = 2;
  int columns = 2;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  print_matrix(A);
  s21_remove_matrix(&A);

#test S21_CREATE_MATRIX_001
  matrix_t A;
  int rows = 3;
  int columns = 3;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);

#test S21_CREATE_MATRIX_002
  matrix_t A;
  int rows = 1;
  int columns = 6;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);

#test S21_CREATE_MATRIX_003
  matrix_t A;
  int rows = 6;
  int columns = 1;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);

#test S21_CREATE_MATRIX_004
  matrix_t A;
  int rows = 0;
  int columns = 4;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_ne(A.columns, columns);
  s21_remove_matrix(&A);

#test S21_CREATE_MATRIX_005
  matrix_t A;
  int rows = 6;
  int columns = -4;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 1);
  ck_assert_int_ne(A.rows, rows);
  ck_assert_int_ne(A.columns, columns);
  s21_remove_matrix(&A);

#test S21_CREATE_MATRIX_006
  matrix_t A;
  int rows = -6;
  int columns = -1;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 1);
  ck_assert_int_ne(A.rows, rows);
  ck_assert_int_ne(A.columns, columns);
  s21_remove_matrix(&A);

#test S21_CREATE_MATRIX_007
  matrix_t A;
  int rows = 5;
  int columns = 0;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 1);
  ck_assert_int_ne(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);





#test S21_REMOVE_MATRIX_001
  matrix_t A;
  int rows = 3;
  int columns = 3;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);

#test S21_REMOVE_MATRIX_002
  matrix_t A;
  int rows = 2;
  int columns = 4;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 0);
  res = fill_matrix_with_double(&A);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);





#test S21_EQUAL_MATRIX_001
  matrix_t A;  // {4, 0, 1, 5, 0, 0, 0, 0, 0}
  matrix_t B;  // {1, 0, 2, 2, 0, 0, 0, 0, 0}
  int rows = 3;
  int columns = 3;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows, columns, &B);
  ck_assert_int_eq(res, 0);
  res = fill_matrix_with_int(&A);
  ck_assert_int_eq(res, 0);
  res = fill_matrix_with_int(&B);
  ck_assert_int_eq(res, 0);
  s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_EQUAL_MATRIX_002
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t B;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  int rows = 3;
  int columns = 3;
  int res = 0;
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows, columns, &B);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
        ck_assert_int_eq(A.matrix[i][j], B.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_EQUAL_MATRIX_003
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}}
  matrix_t B;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  int rows_A = 3;
  int rows_B = 2;
  int columns_A = 3;
  int columns_B = 3;
  int res = 0;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_EQUAL_MATRIX_004
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t B;  // {{0, 0}, {0, 0}, {0, 0}}
  int rows_A = 3;
  int rows_B = 3;
  int columns_A = 3;
  int columns_B = 2;
  int res = 0;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);





#test S21_SUM_MATRIX_001
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t B;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t C;
  int rows_A = 3;
  int rows_B = 3;
  int columns_A = 3;
  int columns_B = 3;
  int res = 0;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
        ck_assert_int_eq(C.matrix[i][j], 0);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

#test S21_SUM_MATRIX_002
  matrix_t A;  // {{4, 6, 2}, {4, 6, 2}, {4, 6, 2}}
  matrix_t B;  // {{4, 6, 2}, {3, 7, 5}, {9, 8, 7}}
  matrix_t C;
  matrix_t D;  // {{8, 12, 4}, {7, 13, 7}, {13, 14, 9}}
  int res = 0;
  int rows = 3;
  int columns = 3;
  int rows_A = 3;
  int columns_A = 3;
  double arr_1[] = {4, 6, 2, 4, 6, 2, 4, 6, 2};
  double arr_2[] = {4, 6, 2, 3, 7, 5, 9, 8, 7};
  double arr_3[] = {8, 12, 4, 7, 13, 7, 13, 14, 9};
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows, columns, &B);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows, columns, &D);
  ck_assert_int_eq(res, 0);
  fill_matrix_with_array(&A, arr_1);
  fill_matrix_with_array(&B, arr_2);
  fill_matrix_with_array(&D, arr_3);
  res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
        ck_assert_int_eq(C.matrix[i][j], D.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);

#test S21_SUM_MATRIX_003
  matrix_t A;  // {{4, 6, 2}, {4, 6, 2}, {4, 6, 2}}
  matrix_t B;  // {{4, 6, 2}, {3, 7, 5}, {9, 8, 7}}
  matrix_t C;
  matrix_t D;  // {{8, 12, 4}, {7, 13, 7}, {13, 14, 9}}
  int res = 0;
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 2;
  int columns_B = 3;
  int rows_D = 2;
  int columns_D = 3;
  double arr_1[] = {4, 6, 2, 4, 6, 2, 4, 6, 2};
  double arr_2[] = {4, 6, 2, 3, 7, 5};
  double arr_3[] = {8, 12, 4, 7, 13, 7};
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_D, columns_D, &D);
  ck_assert_int_eq(res, 0);
  fill_matrix_with_array(&A, arr_1);
  fill_matrix_with_array(&B, arr_2);
  fill_matrix_with_array(&D, arr_3);
  res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&C);
  s21_remove_matrix(&D);

#test S21_SUM_MATRIX_004
  matrix_t A;
  matrix_t B;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t C;
  int rows_A = 0;
  int rows_B = 3;
  int columns_A = 3;
  int columns_B = 3;
  int res = 0;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 1);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&B);

#test S21_SUM_MATRIX_005
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t B;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t C;
  int rows_A = 3;
  int rows_B = 3;
  int columns_A = 3;
  int columns_B = 0;
  int res = 0;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 1);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);





#test S21_SUB_MATRIX_001
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t B;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t C;
  int rows_A = 3;
  int rows_B = 3;
  int columns_A = 3;
  int columns_B = 3;
  int res = 0;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
        ck_assert_int_eq(C.matrix[i][j], 0);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

#test S21_SUB_MATRIX_002
  int res = 0;
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t B;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t C;
  int rows_A = -2;
  int rows_B = 3;
  int columns_A = 3;
  int columns_B = 3;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 1);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  res = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&B);

#test S21_SUB_MATRIX_003
  int res = 0;
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t B;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t C;
  int rows_A = 3;
  int rows_B = 0;
  int columns_A = 3;
  int columns_B = 3;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 1);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  res = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);

#test S21_SUB_MATRIX_004
  int res = 0;
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t B;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t C;
  int rows_A = 3;
  int rows_B = 2;
  int columns_A = 3;
  int columns_B = 3;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_SUB_MATRIX_005
  int res = 0;
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t B;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t C;
  matrix_t D;
  int rows_A = 3;
  int rows_B = 3;
  int rows_D = 3;
  int columns_A = 3;
  int columns_B = 3;
  int columns_D = 3;
  double arr_1[] = {2, 4, 6, 4, 6, 8, 10, 6, 2};
  double arr_2[] = {1, 2, 3, 2, 3, 4, 5, 3, 1};
  double arr_3[] = {1, 2, 3, 2, 3, 4, 5, 3, 1};
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_D, columns_D, &D);
  ck_assert_int_eq(res, 0);
  fill_matrix_with_array(&A, arr_1);
  fill_matrix_with_array(&B, arr_2);
  fill_matrix_with_array(&D, arr_3);
  res = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_B; j++) {
        ck_assert_int_eq(C.matrix[i][j], D.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);





#test S21_MUL_NUMBER_MATRIX_001
  int res = 0;
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t B;
  double number = 2;
  int rows_A = 3;
  int columns_A = 3;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_mult_number(&A, number, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_MUL_NUMBER_MATRIX_002
  int res = 0;
  matrix_t A;  // {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
  matrix_t B;
  matrix_t C;
  double number = 2;
  int rows = 3;
  int columns = 3;
  double arr_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double arr_2[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};  
  res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows, columns, &C);
  ck_assert_int_eq(res, 0);
  fill_matrix_with_array(&A, arr_1);
  fill_matrix_with_array(&C, arr_2);
  res = s21_mult_number(&A, number, &B);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
        ck_assert_int_eq(B.matrix[i][j], C.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

#test S21_MUL_NUMBER_MATRIX_003
  int res = 0;
  matrix_t A;  // {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
  matrix_t B;
  double number = 2;
  int rows_A = -5;
  int columns_A = 3;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 1);
  res = s21_mult_number(&A, number, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);





#test S21_MULT_MATRIX_001
  int res = 0;
  matrix_t A;  // {{2, 2, 2}, {3, 3, 3}, {5, 5, 5}}
  matrix_t B;  // {{1, 2, 3}, {2, 3, 4}, {5, 3, 1}}
  matrix_t C;
  matrix_t D;  // {{16, 16, 16}, {24, 24, 24}, {40, 40, 40}}
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 3;
  int rows_D = 3;
  int columns_D = 3;
  double arr_1[] = {2, 2, 2, 3, 3, 3, 5, 5, 5};
  double arr_2[] = {1, 2, 3, 2, 3, 4, 5, 3, 1};
  double arr_3[] = {16, 16, 16, 24, 24, 24, 40, 40, 40};
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_D, columns_D, &D);
  ck_assert_int_eq(res, 0);
  fill_matrix_with_array(&A, arr_1);
  fill_matrix_with_array(&B, arr_2);
  fill_matrix_with_array(&D, arr_3);
  res = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        ck_assert_int_eq(C.matrix[i][j], D.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);

#test S21_MULT_MATRIX_002
  int res = 0;
  matrix_t A;  // {{2, 2, 2}, {3, 3, 3}, {5, 5, 5}}
  matrix_t B;  // {{1, 2, 3}, {2, 3, 4}, {5, 3, 1}}
  matrix_t C;
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 2;
  int columns_B = 3;
  int rows_C = 3;
  int columns_C = 3;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_C, columns_C, &C);
  ck_assert_int_eq(res, 0);
  res = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

#test S21_MULT_MATRIX_003
  int res = 0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 0;  //
  int rows_C = 3;
  int columns_C = 3;
  int rows_D = 3;
  int columns_D = 3;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 1);
  res = s21_create_matrix(rows_C, columns_C, &C);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_D, columns_D, &D);
  ck_assert_int_eq(res, 0);
  res = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);

#test S21_MULT_MATRIX_004
  int res = 0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  int rows_A = -2;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 3;
  int rows_C = 3;
  int columns_C = 3;
  int rows_D = 3;
  int columns_D = 3;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 1);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_C, columns_C, &C);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_D, columns_D, &D);
  ck_assert_int_eq(res, 0);
  res = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);





#test S21_TRANSPOSE_001
  int res = 0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  int rows_A = 4;
  int columns_A = 2;
  int rows_C = 2;
  int columns_C = 4;
  double arr_1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  double arr_2[] = {1, 3, 5, 7, 2, 4, 6, 8};
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_C, columns_C, &C);
  ck_assert_int_eq(res, 0);
  fill_matrix_with_array(&A, arr_1);
  fill_matrix_with_array(&C, arr_2);
  res = s21_transpose(&A, &B);
  ck_assert_int_eq(res, 0); 
  for (int i = 0; i < columns_A; i++) {
    for (int j = 0; j < rows_A; j++) {
        ck_assert_int_eq(B.matrix[i][j], C.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

#test S21_TRANSPOSE_002
  int res = 0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  int rows_A = 3;
  int columns_A = 3;
  int rows_C = 3;
  int columns_C = 3;
  double arr_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double arr_2[] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_C, columns_C, &C);
  ck_assert_int_eq(res, 0);
  fill_matrix_with_array(&A, arr_1);
  fill_matrix_with_array(&C, arr_2);
  res = s21_transpose(&A, &B);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < columns_A; i++) {
    for (int j = 0; j < rows_A; j++) {
        ck_assert_int_eq(B.matrix[i][j], C.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

#test S21_TRANSPOSE_003
  int res = 0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  int rows_A = 4;
  int columns_A = 2;
  int rows_B = 0;
  int columns_B = 3;
  int rows_C = 2;
  int columns_C = 4;
  double arr_1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  double arr_2[] = {1, 3, 5, 7, 2, 4, 6, 8};
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 1);
  res = s21_create_matrix(rows_C, columns_C, &C);
  ck_assert_int_eq(res, 0);
  fill_matrix_with_array(&A, arr_1);
  fill_matrix_with_array(&C, arr_2);
  res = s21_transpose(&A, &B);
  ck_assert_int_eq(res, 0); 
  for (int i = 0; i < columns_A; i++) {
    for (int j = 0; j < rows_A; j++) {
        ck_assert_int_eq(B.matrix[i][j], C.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  
#test S21_TRANSPOSE_004
  int res = 0;
  matrix_t A;
  matrix_t B;
  int rows_A = 4;
  int columns_A = 0;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 1);
  res = s21_transpose(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);





#test S21_DETERMINANT_001
  int res = 0;
  matrix_t A;
  matrix_t B;
  int rows_A = 3;
  int columns_A = 3;
  int rows_B = 3;
  int columns_B = 3;
  double det = 0;
  double det_res = 204;
  double arr_1[] = {1, -2, 3, 4, 0, 6, -7, 8, 9};
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  fill_matrix_with_array(&A, arr_1);
  res = s21_determinant(&A, &det);
  ck_assert_int_eq(det_res, det);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_DETERMINANT_002
  int res = 0;
  matrix_t A;
  matrix_t B;
  int rows_A = 1;
  int columns_A = 1;
  int rows_B = 1;
  int columns_B = 1;
  double det = 0;
  double det_res = 19;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  A.matrix[0][0] = 19;  // 1
  res = s21_determinant(&A, &det);
  ck_assert_int_eq(det_res, det);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_DETERMINANT_003
  int res = 0;
  matrix_t A;
  matrix_t B;
  int rows_A = 3;
  int columns_A = 2;
  int rows_B = 1;
  int columns_B = 1;
  double det = 0;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 0);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 0);
  A.matrix[0][0] = 19;  // 1
  res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, ERR_CALCULATION);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_DETERMINANT_004
  int res = 0;
  matrix_t A;
  matrix_t B;
  int rows_A = 0;
  int columns_A = 2;
  int rows_B = 0;
  int columns_B = 2;
  double det = 0;
  res = s21_create_matrix(rows_A, columns_A, &A);
  ck_assert_int_eq(res, 1);
  res = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(res, 1);
  res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, ERR_INCOR_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);





#test S21_CALC_COMPLEMENTS_001
  matrix_t A, result, D;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &D);
  double arr_1[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double arr_2[] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  fill_matrix_with_array(&A, arr_1);
  fill_matrix_with_array(&D, arr_2);
  s21_calc_complements(&A, &result);
  for (int i = 0; i < D.rows; i++) {
    for (int j = 0; j < D.columns; j++) {
      ck_assert_uint_eq(D.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&D);

#test S21_CALC_COMPLEMENTS_002
  int res = 0;
  matrix_t A, result, D;
  int row = 3;
  int col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &D);
  double arr_1[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double arr_2[] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  fill_matrix_with_array(&A, arr_1);
  fill_matrix_with_array(&D, arr_2);
  res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &D), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&D);

#test S21_CALC_COMPLEMENTS_003
  int res = 0;
  matrix_t A, B, C;
  int rows = 1;
  int columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &C);
  double arr_1[] = {19};
  double arr_2[] = {19};
  fill_matrix_with_array(&A, arr_1);
  fill_matrix_with_array(&C, arr_2);
  res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(B.matrix[i][j], C.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);

#test S21_CALC_COMPLEMENTS_004
  int res = 0;
  matrix_t A, B;
  int rows = -2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_CALC_COMPLEMENTS_005
  int res = 0;
  matrix_t A, B;
  int rows = 2;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);





#test S21_INVERSE_MATRIX_001
  matrix_t A, R;
    clean_matrix(&A);
    int row = 4;
    int col = 4;
    s21_create_matrix(row, col, &A);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[0][3] = 4;
    A.matrix[1][0] = 0;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 2;
    A.matrix[1][3] = 6;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = 2;
    A.matrix[2][2] = 1;
    A.matrix[2][3] = -1;
    A.matrix[3][0] = 4;
    A.matrix[3][1] = 4;
    A.matrix[3][2] = 0;
    A.matrix[3][3] = 1;
    int check = s21_inverse_matrix(&A, &R);
    ck_assert_int_eq(check, ERR_CALCULATION);
    s21_remove_matrix(&A);

    matrix_t O;
    clean_matrix(&O);
    row = 1;
    col = 1;
    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &O);
    A.matrix[0][0] = 5;
    check = s21_inverse_matrix(&A, &R);
    O.matrix[0][0] = 0.2;
    ck_assert_int_eq(check, 0);
    ck_assert_int_eq(s21_eq_matrix(&R, &O), SUCCESS);
    s21_remove_matrix(&R);
    s21_remove_matrix(&O);

    A.matrix[0][0] = 0.0;
    check = s21_inverse_matrix(&A, &R);
    ck_assert_int_eq(check, ERR_CALCULATION);
    s21_remove_matrix(&A);

    row = 3;
    col = 3;
    s21_create_matrix(row, col, &A);
    s21_create_matrix(row, col, &O);
    A.matrix[0][0] = 12;
    A.matrix[0][1] = 0.12;
    A.matrix[0][2] = 12.3;
    A.matrix[1][0] = 4;
    A.matrix[1][1] = 3;
    A.matrix[1][2] = -12;
    A.matrix[2][0] = 9;
    A.matrix[2][1] = -1;
    A.matrix[2][2] = 10;
    check = s21_inverse_matrix(&A, &R);
    O.matrix[0][0] = -0.0983284169;
    O.matrix[0][1] = 0.073746312;
    O.matrix[0][2] = 0.209439528;
    O.matrix[1][0] = 0.808478094;
    O.matrix[1][1] = -0.050803015;
    O.matrix[1][2] = -1.055391674;
    O.matrix[2][0] = 0.169343384;
    O.matrix[2][1] = -0.071451982;
    O.matrix[2][2] = -0.194034742;
    ck_assert_int_eq(s21_eq_matrix(&R, &O), SUCCESS);
    s21_remove_matrix(&R);

    A.matrix[0][0] = 2;
    A.matrix[0][1] = 5;
    A.matrix[0][2] = 7;
    A.matrix[1][0] = 6;
    A.matrix[1][1] = 3;
    A.matrix[1][2] = 4;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = -2;
    A.matrix[2][2] = -3;
    check = s21_inverse_matrix(&A, &R);
    O.matrix[0][0] = 1;
    O.matrix[0][1] = -1;
    O.matrix[0][2] = 1;
    O.matrix[1][0] = -38;
    O.matrix[1][1] = 41;
    O.matrix[1][2] = -34;
    O.matrix[2][0] = 27;
    O.matrix[2][1] = -29;
    O.matrix[2][2] = 24;
    ck_assert_int_eq(s21_eq_matrix(&R, &O), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
    s21_remove_matrix(&O);

#test S21_INVERSE_MATRIX_002
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_INVERSE_MATRIX_003
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  double arr_1[] = {2, 5, 7, 2, 5, 7, 5, -2, -3};
  fill_matrix_with_array(&A, arr_1);
  s21_create_matrix(3, 3, &B);
  res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_INVERSE_MATRIX_004
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  double arr_1[] = {19};
  fill_matrix_with_array(&A, arr_1);
  res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_INVERSE_MATRIX_005
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  double arr_1[] = {19.000000000001};
  fill_matrix_with_array(&A, arr_1);
  res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#test S21_INVERSE_MATRIX_006
  int res = 0;
  matrix_t A, B;
  s21_create_matrix(-2, 1, &A);
  s21_create_matrix(1, 1, &B);
  res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

#main-pre
  srunner_set_fork_status(sr, CK_NOFORK);