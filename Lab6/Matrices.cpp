#include <iostream>
#include <fstream>
using namespace std;
void readMatrices(string filename, int &size, int matrix1[100][100], int matrix2[100][100]);
void printMatrix(string label, int size, int matrix[100][100]);
int add(string &label, int size, int matrix1[100][100], int matrix2[100][100], int i, int j);
int mult(string &label, int size, int matrix1[100][100], int matrix2[100][100], int i, int j);
int sub(string &label, int size, int matrix1[100][100], int matrix2[100][100], int i, int j);
void matrixMath(int size, int matrix1[100][100], int matrix2[100][100], int (*operate)(string&, int, int[100][100], int[100][100], int, int));

int main() {
    int matrix1[100][100];
    int matrix2[100][100];
    int size;
    
    cout << "Connor Schroeder" << endl << "Lab #6: Matrix manipulation" << endl << endl;
    readMatrices("matrix_input.txt", size, matrix1, matrix2);
    printMatrix("Matrix A:", size, matrix1);
    printMatrix("Matrix B:", size, matrix2);
    matrixMath(size, matrix1, matrix2, &add);
    matrixMath(size, matrix1, matrix2, &mult);
    matrixMath(size, matrix1, matrix2, &sub);
    return 0;
}

void readMatrices(string filename, int &size, int matrix1[100][100], int matrix2[100][100]) {
    ifstream MyFile(filename);
    MyFile >> size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            MyFile >> matrix1[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            MyFile >> matrix2[i][j];
        }
    }
}
void printMatrix(string label, int size, int matrix[100][100]) {
    cout << label << endl;
    int cap = 10;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (; matrix[i][j] >= cap || matrix[i][j] <= cap/-10; cap *= 10) {}
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j];
            for (int spacer = cap; (matrix[i][j] < spacer && matrix[i][j] > spacer/-10) && spacer > 1; spacer /= 10) {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
int add(string &label, int size, int matrix1[100][100], int matrix2[100][100], int i, int j) {
    label = "Matrix Sum (A + B):";
    return matrix1[i][j] + matrix2[i][j];
}
int mult(string &label, int size, int matrix1[100][100], int matrix2[100][100], int i, int j) {
    label = "Matrix Product (A * B):";
    int newMatrix = 0;
    for (int entry = 0; entry < size; entry++) {
        newMatrix += matrix1[i][entry] * matrix2[entry][j];
    }
    return newMatrix;
}
int sub(string &label, int size, int matrix1[100][100], int matrix2[100][100], int i, int j) {
    label = "Matrix Difference (A - B):";
    return matrix1[i][j] - matrix2[i][j];
}
void matrixMath(int size, int matrix1[100][100], int matrix2[100][100], int (*operate)(string&, int, int[100][100], int[100][100], int, int)) {
    string label;
    int newMatrix[100][100];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            newMatrix[i][j] = operate(label, size, matrix1, matrix2, i, j);
        }
    }
    printMatrix(label, size, newMatrix);
}