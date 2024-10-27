#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

class S21Matrix {
public:
  S21Matrix() : S21Matrix(3, 3){};
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();
  
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  double DetCalc(double& result);
  void Minor(int rows, int cols, const S21Matrix& other);
  S21Matrix InverseMatrix();

  void FillMatrix(double* arr);
  void Print();
  void AllocateMemoryForMatrix(int rows, int cols);
  bool CheckEqSizeMatrix(const S21Matrix& other);

private:
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+(const S21Matrix& other);
  S21Matrix& operator-(const S21Matrix& other);
  S21Matrix& operator*(const double num);
  S21Matrix operator*(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double operator()(int rows, int cols);

  int GetRows();
  void SetRows(int valueRows);
  int GetCols();
  void SetCols(int valueCols);
};

#endif  // S21_MATRIX_OOP_H_
