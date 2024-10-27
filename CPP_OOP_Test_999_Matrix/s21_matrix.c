#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err = OK;
  result->rows = 0;
  result->columns = 0;
  result->matrix = NULL;
  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0;
      }
    }
  } else {
    result->columns = 0;
    result->rows = 0;
    result->matrix = NULL;
    err = ERR_INCOR_MATRIX;
  }
  return err;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  A->rows = 0;
  A->columns = 0;
  free(A->matrix);
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int err = SUCCESS;
  if (A != NULL && B != NULL && A->rows > 0 && B->rows > 0 && A->columns > 0 &&
      B->columns > 0) {
    if (A->rows == B->rows && A->columns == B->columns) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
            err = FAILURE;
            break;
          }
        }
      }
    } else {
      err = FAILURE;
    }
  } else {
    err = FAILURE;
  }
  return err;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;
  int correct = SUCCESS;
  int equal = SUCCESS;
  correct = correct_matrix(*A, *B);
  if (correct == SUCCESS) {
    int rows = A->rows;
    int columns = A->columns;
    equal = equal_size_matrix(A, B);
    if (equal == SUCCESS) {
      s21_create_matrix(rows, columns, result);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    } else {
      err = ERR_CALCULATION;
    }
  } else {
    err = ERR_INCOR_MATRIX;
  }
  return err;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;
  int correct = SUCCESS;
  int equal = SUCCESS;
  correct = correct_matrix(*A, *B);
  if (correct == 1) {
    int rows = A->rows;
    int columns = A->columns;
    equal = equal_size_matrix(A, B);
    if (equal == SUCCESS) {
      s21_create_matrix(rows, columns, result);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else {
      err = ERR_CALCULATION;
    }
  } else {
    err = ERR_INCOR_MATRIX;
  }
  return err;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int err = OK;
  int correct = 0;
  int rows = A->rows;
  int columns = A->columns;
  correct = correct_matrix_once(*A);
  if (correct == SUCCESS) {
    err = s21_create_matrix(rows, columns, result);
    if (err == 0) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          result->matrix[i][j] = number * A->matrix[i][j];
        }
      }
    }
  } else {
    err = ERR_INCOR_MATRIX;
  }
  return err;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;
  err = correct_matrix_once(*A);
  if (err == SUCCESS) {
    err = correct_matrix_once(*B);
    if (err == SUCCESS) {
      err = 0;
      int rows_A = A->rows;
      int columns_A = A->columns;
      int rows_B = B->rows;
      int columns_B = B->columns;
      if (columns_A == rows_B) {  // согласованные матрицы или нет
        err = s21_create_matrix(rows_A, columns_B, result);
        for (int i = 0; i < rows_A; i++) {
          for (int j = 0; j < columns_B; j++) {
            for (int count = 0; count < columns_A; count++) {
              result->matrix[i][j] +=
                  (A->matrix[i][count] * B->matrix[count][j]);
            }
          }
        }
      } else {
        err = ERR_CALCULATION;
      }
    } else {
      err = ERR_INCOR_MATRIX;
    }
  } else {
    err = ERR_INCOR_MATRIX;
  }
  return err;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int err = OK;
  int correct = 0;
  correct = correct_matrix_once(*A);
  if (correct == SUCCESS) {
    int rows = A->rows;
    int columns = A->columns;
    err = s21_create_matrix(columns, rows, result);
    for (int i = 0; i < rows && err == 0; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  } else {
    err = ERR_INCOR_MATRIX;
  }
  return err;
}

// минор матрицы
void minor_matrix(int elem_rows, int elem_columns, matrix_t *A,
                  matrix_t *result) {
  int m = 0;
  int n = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != elem_rows) {
      n = 0;
      for (int j = 0; j < A->columns; j++) {
        if (j != elem_columns) {
          result->matrix[m][n] = A->matrix[i][j];
          n++;
        }
      }
      m++;
    }
  }
}

// Определитель - (детерминант), можно определить у квадратных матриц
int s21_determinant(matrix_t *A, double *result) {
  int err = OK;
  *result = 0;
  int correct = 0;
  correct = correct_matrix_once(*A);
  if (correct == SUCCESS) {
    int rows = A->rows;
    int columns = A->columns;
    if (rows == columns) {
      if (rows == 1) {
        *result = A->matrix[0][0];
      } else if (rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      } else {
        double temp_deter = 0;
        int j = 0;
        for (int i = 0; i < rows; i++) {
          matrix_t M;  // матрица миноров
          s21_create_matrix(rows - 1, columns - 1, &M);
          minor_matrix(i, j, A, &M);
          s21_determinant(&M, &temp_deter);
          *result += A->matrix[i][j] * temp_deter * pow(-1, i + j);
          s21_remove_matrix(&M);
        }
      }
    } else {
      err = ERR_CALCULATION;
    }
  } else {
    err = ERR_INCOR_MATRIX;
  }
  return err;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err = OK;
  int correct = 0;
  correct = correct_matrix_once(*A);
  if (correct == SUCCESS) {
    int rows = A->rows;
    int columns = A->columns;
    if (rows == columns) {
      if (rows == 1) {
        s21_create_matrix(rows, columns, result);
        result->matrix[0][0] = A->matrix[0][0];
      } else {
        double determ = 0;
        matrix_t M;
        s21_create_matrix(rows - 1, columns - 1, &M);
        s21_create_matrix(rows, columns, result);
        for (int i = 0; i < result->rows; ++i) {
          for (int j = 0; j < result->columns; ++j) {
            minor_matrix(i, j, A, &M);
            s21_determinant(&M, &determ);
            result->matrix[i][j] = pow(-1, i + j) * determ;
          }
        }
        s21_remove_matrix(&M);
      }
    } else {
      err = ERR_CALCULATION;
    }
  } else {
    err = ERR_INCOR_MATRIX;
  }
  return err;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (check_matrix(A)) {
    err = ERR_INCOR_MATRIX;
  } else if (A->rows != A->columns) {
    err = ERR_CALCULATION;
  } else if (A->rows == 1) {
    if (fabsl(A->matrix[0][0] - 0.0) > 1e-07) {
      s21_create_matrix(A->rows, A->columns, result);
      result->matrix[0][0] = 1. / A->matrix[0][0];
    } else {
      err = ERR_CALCULATION;
    }
  } else {
    double determ = 0;
    s21_determinant(A, &determ);
    if (fabsl(determ - 0.0) < 1e-07) {
      err = ERR_CALCULATION;
    } else {
      matrix_t C;
      s21_calc_complements(A, &C);
      s21_transpose(&C, result);
      s21_remove_matrix(&C);
      div_matrix(result, &determ);
    }
  }
  return err;
}

int print_matrix(matrix_t matrix) {
  int res = OK;
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      printf("%7.2f ", matrix.matrix[i][j]);
    }
    printf("\n");
  }
  return res;
}

int ran_num_gen() {
  int num = 0;
  int min = -10;
  int max = 10;
  num = min + rand() % (max - min + 1);
  return num;
}

double random_double() {
  double output = 0;
  double min = -10.0;
  double max = 10.0;
  output = (((double)rand() * (max - min)) / (double)RAND_MAX) + min;
  output = (truncl(output * 10000000.)) / 10000000.;
  return output;
}

int fill_matrix_with_int(matrix_t *matrix) {
  int res = 0;
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = ran_num_gen();
    }
  }
  return res;
}

int fill_matrix_with_double(matrix_t *matrix) {
  int res = 0;
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = random_double();
    }
  }
  return res;
}

int equal_size_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  int rows_A = A->rows;
  int rows_B = B->rows;
  int columns_A = A->columns;
  int columns_B = B->columns;
  if ((rows_A != rows_B) || (columns_A != columns_B)) {
    res = FAILURE;
  }
  return res;
}

int correct_matrix(matrix_t A, matrix_t B) {
  int res = OK;
  int rows_A = A.rows;
  int columns_A = A.columns;
  int rows_B = B.rows;
  int columns_B = B.columns;
  if ((rows_A <= 0) || (columns_A <= 0) || (A.matrix = NULL) || (rows_B <= 0) ||
      (columns_B <= 0) || (B.matrix = NULL)) {
    res = 0;
  } else if ((rows_A == rows_B) && (columns_A == columns_B)) {
    res = 1;
  } else {
    res = 1;
  }
  return res;
}

int correct_matrix_once(matrix_t A) {
  int res = OK;
  int rows_A = A.rows;
  int columns_A = A.columns;
  if ((rows_A <= 0) || (columns_A <= 0) || (A.matrix = NULL)) {
    res = 0;
  } else {
    res = 1;
  }
  return res;
}

void fill_matrix_with_array(matrix_t *A, double *arr) {
  int rows = A->rows;
  int columns = A->columns;
  int count = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A->matrix[i][j] = arr[count];
      count++;
    }
  }
}

void clean_matrix(matrix_t *matrix) {
  matrix->columns = 0;
  matrix->rows = 0;
  matrix->matrix = NULL;
}

int check_matrix(matrix_t *matrix) {
  int check = OK;
  if (matrix->rows < 1 || matrix->columns < 1 || matrix->matrix == NULL)
    check = ERR_INCOR_MATRIX;
  return check;
}

void div_matrix(matrix_t *A, double *number) {
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      A->matrix[i][j] /= *number;
    }
  }
}
