#include <iostream>
using namespace std;


int** createMatrix(int n, int m) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    return matrix;
}


void fillMatrix(int** matrix, int n, int m) {
    cout << "Fill the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}


void printMatrix(int** matrix, int n, int m) {
    cout << "Matrix in its nature:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void findColumnMaxima(int** matrix, int* maxima, int n, int m) {
    for (int j = 0; j < m; j++) {
        int max = matrix[0][j];
        for (int i = 1; i < n; i++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        maxima[j] = max;
    }
}


void printMaxima(int* maxima, int m) {
    cout << "Maximum elements of each column before sorting: ";
    for (int i = 0; i < m; i++) {
        cout << maxima[i] << " ";
    }
    cout << endl;
}


void sortMaxElements(int* maxima, int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (maxima[j] < maxima[j + 1]) {
                int temp = maxima[j];
                maxima[j] = maxima[j + 1];
                maxima[j + 1] = temp;
            }
        }
    }
}


void printSortedMaxima(int* maxima, int m) {
    cout << "Sorted maximum elements of columns: ";
    for (int i = 0; i < m; i++) {
        cout << maxima[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter the dimensions of the matrix (n rows, m columns): ";
    cin >> n >> m;

    int** matrix = createMatrix(n, m);
    int* maxima = new int[m];

    fillMatrix(matrix, n, m);
    printMatrix(matrix, n, m);
    findColumnMaxima(matrix, maxima, n, m);
    printMaxima(maxima, m);
    sortMaxElements(maxima, m);
    printSortedMaxima(maxima, m);


    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] maxima;

    return 0;
}
