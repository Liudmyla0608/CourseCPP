#include <iostream>
using namespace std;


int** createMatrix(int n, int m) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    return matrix;
}


int* createArray(int size) {
    int* array = new int[size];
    return array;
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


void printArray(int* array, int size, const string& description) {
    cout << description << ": ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter the dimensions of the matrix (n rows, m columns): ";
    cin >> n >> m;

    int** matrix = createMatrix(n, m);
    int* maxima = createArray(m);

    fillMatrix(matrix, n, m);
    findColumnMaxima(matrix, maxima, n, m);
    sortMaxElements(maxima, m);
    printArray(maxima, m, "Sorted maximum elements of columns");


    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] maxima;

    return 0;
}
