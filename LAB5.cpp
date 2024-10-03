//Перевірити, чи є задана матриця ортогональною

#include <iostream>
using namespace std;

int e = 20;
int q = 20;
int n = 3;
int m = 3;

int MatrixA[3][3];
int MatrixB[3][3];
int MatrixC[3][3];

int Mas[20];
int Result[20];


void fullMatrixA() {
  cout << "Enter matrix A elements: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << "MatrixA[" << i << "][" << j << "]" << endl;
      cin >> MatrixA[i][j];
    }
  }
}


void displayMatrixA()
{
  cout << endl << "Your matrix A:" << endl;
  for (int i = 0; i < n; i++) {
    cout << endl;
    for (int j = 0; j < m; j++) {
      cout << MatrixA[i][j] << " ";
    }
  }
}

void matrixTransposition() {
  cout << "transposed matrix:" << endl;
  for (int i = 0; i < n; i++) {
    cout << endl;
    for (int j = 0; j < m; j++) {
      cout << MatrixA[j][i] << " ";
      MatrixB[i][j] = MatrixA[j][i];
    }
  }
}
void displayMatrixB() {
  cout << endl << endl << "transposed matrix is matrix B:" << endl;
  for (int k = 0; k < n; k++) {
    cout << endl;
    for (int l = 0; l < m; l++) {
      cout << MatrixB[k][l] << " ";}
  }
}

void multiplicationAB() {
  cout << "multiplication both matrix A and B:" << endl;


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      MatrixC[i][j] = 0;
      for (int k = 0; k < m; k++) {
        MatrixC[i][j] += MatrixA[i][k] * MatrixB[k][j];
      }
      cout << MatrixC[i][j] << " ";
    }
    cout << endl;
  }
}

void determineOrthogonal() {
  cout << "the matrix is orthogonal or not?" << endl;


  //if the matrix does not consist of zeros and ones - it is not orthogonal
  for (int i = 0; i < n; i++) {
    Mas[i] = MatrixC[i][i];
    for (int j = 0; j < m; j++) {
      if (MatrixC[i][j] != 0 && MatrixC[i][j] !=  1) {
        Result[i] = 8; //8 = matrix is not orthogonal
      }

    }
  }

  //if the lateral diagonal is not one, it is not orthogonal
  for (int i = 0; i < n; i++) {
    if (Mas[i] != 1) {
      Result[i] = 8; //8 = matrix is not orthogonal
    }
  }

  //if the array is filled - it is not orthogonal
  for (int i = 0; i < n; i++) {
    if (!Result[i]) {
      cout << "matrix is orthogonal" << endl;
    }
    else {
      cout << "matrix is non-orthogonal" << endl;
      break;
    }
  }
}


int main() {


  fullMatrixA();
  displayMatrixA();
  cout << endl << endl;

  matrixTransposition();
  cout << endl << endl;

  displayMatrixB();
  cout << endl << endl;

  multiplicationAB();

  determineOrthogonal();

  return 0;
}
