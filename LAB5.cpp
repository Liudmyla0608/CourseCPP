#include <iostream>
using namespace std;

int n = 3; 


int** createMatrix(int size) {
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    return matrix;
}


void fillMatrix(int** matrix, int size) {
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}


void displayMatrix(int** matrix, int size, const string& label) {
    cout << label << ":" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int** transposeMatrix(int** matrix, int size) {
    int** transposed = createMatrix(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}


int** multiplyMatrices(int** matrixA, int** matrixB, int size) {
    int** result = createMatrix(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

bool isOrthogonal(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j && matrix[i][j] != 1) return false;
            if (i != j && matrix[i][j] != 0) return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the dimension of the matrix (n x n): ";
    cin >> n;

    int** matrixA = createMatrix(n);
    fillMatrix(matrixA, n);
    displayMatrix(matrixA, n, "Matrix A");

    int** matrixB = transposeMatrix(matrixA, n);
    displayMatrix(matrixB, n, "Transposed Matrix B");

    int** matrixC = multiplyMatrices(matrixA, matrixB, n);
    displayMatrix(matrixC, n, "Matrix A * Transposed B");

    if (isOrthogonal(matrixC, n)) {
        cout << "The matrix is orthogonal." << endl;
    } else {
        cout << "The matrix is not orthogonal." << endl;
    }

  
    for (int i = 0; i < n; i++) {
        delete[] matrixA[i];
        delete[] matrixB[i];
        delete[] matrixC[i];
    }
    delete[] matrixA;
    delete[] matrixB;
    delete[] matrixC;

    return 0;
}
