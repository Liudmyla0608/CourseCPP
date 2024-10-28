
//Task 6 - Files.

// Сусідами елемента - в матриці назвемо елементи  k A з i-1 ≤ до ≤ i+1, j-1 ≤  ≤ j+1,
//к,  ) ≠ (i, j).. Операція згладжування матриці дає нову матрицю того ж розміру, кожен
//елемент якої виходить як середнє арифметичне наявних сусідів відповідного елемента
//вихідної матриці. Побудувати результат згладжування заданої матриці розміром 10 на 10.

#include <iostream>
#include <fstream>
using namespace std;



int ** create(int n, int m)
{
	int ** matrix = new int * [n];
	for(int i = 0; i < n; i++)
	{
		matrix[i] = new int [m];
	}

	return matrix;
}



void filling(int ** matrix, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << "mas[" << i << "][" << j << "] = ";
            cin >> *(*(matrix + i) + j);
        }
    }
}

void writeData(int ** matrix, int n, int m)
{
    ofstream write("data.txt");
    write << "elements of matrix that input the user: " << endl;
    for(int i = 0; i < n; i++) {
        cout << endl;
        for(int j = 0; j < m; j++) {
            write << *(*(matrix + i) + j) << " ";
        }
    }
    write.close();

}

void printMatrix(int ** matrix, int n, int m)
{
    cout << " matrix that input the user :" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << endl;
        for(int j = 0; j < m; j++)
        {
            cout << *(*(matrix + i) + j) << " ";
        }
    }
}



void newElementsMatrix (int ** matrix, int n, int m, int * massife)
{
    int index = 0;

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool hasTop = (i - 1 >= 0);
            bool hasBottom = (i + 1 < n);
            bool hasLeft = (j - 1 >= 0);
            bool hasRight = (j + 1 < m);

            if(hasBottom && hasRight && !hasTop && !hasLeft)
            {
                massife[index] = matrix[i + 1][j] + matrix[i][j + 1];
                index++;
            }

            if(hasLeft && hasRight && hasBottom && !hasTop)
            {
                massife[index] = matrix[i][j - 1] + matrix[i][j + 1] + matrix[i + 1][j];
                index++;
            }

            if(hasLeft && hasBottom && !hasTop && !hasRight)
            {
                massife[index] = matrix[i][j - 1] + matrix[i + 1][j];
                index++;
            }

            if(!hasLeft && hasBottom && hasTop && hasRight)
            {
                massife[index] = matrix[i + 1][j] + matrix[i - 1][j] + matrix[i][j + 1];
                index++;
            }

            if(hasBottom && hasRight && hasTop && hasLeft)
            {
                massife[index] = matrix[i + 1][j] + matrix[i - 1][j] + matrix[i][j - 1] + matrix[i][j + 1];
                index++;
            }

            if(hasBottom && hasTop && hasLeft && !hasRight)
            {
                massife[index] = matrix[i][j - 1] + matrix[i + 1][j] + matrix[i - 1][j];
                index++;
            }

            if(hasTop && hasRight && !hasLeft && !hasBottom)
            {
                massife[index] = matrix[i - 1][j] + matrix[i][j + 1];
                index++;
            }

            if(hasTop && hasRight && hasLeft && !hasBottom)
            {
                massife[index] = matrix[i - 1][j] + matrix[i][j - 1] + matrix[i][j + 1];
                index++;
            }

            if(hasTop && !hasRight && hasLeft && !hasBottom)
            {
                massife[index] = matrix[i - 1][j] + matrix[i][j - 1];
                index++;
            }
        }
    }
}

void buildNewMatrix(int ** newMat, int * massife, int n, int m)
{
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (index < n * m) {
                newMat[i][j] = massife[index++];
            }
        }
    }

    cout << "\nNew Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for(int j = 0; j < m; j++)
        {
            cout << newMat[i][j] << " ";
        }
        cout << endl;
    }
}

void writeResult(int ** newMat, int * massife, int n, int m) {
    ofstream writen("data2.txt", ios::out);
    writen << "new elements of matrix: " << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            writen << *(*(newMat + i) + j);
        }
    }
    writen.close();
}

int main()
{
	int n = 3;
	int m = 4;
	int x = n * m;
	int * massife = new int[x];


	for(int i = 0; i < x; i++)
	{
	    massife[i] = 0;
	}

	int ** mat = create(n, m);
	int ** newMat = create(n, m);

	filling(mat, n, m);
    writeData(mat, n, m);
	printMatrix(mat, n, m);

	newElementsMatrix(mat, n, m, massife);

	cout << "\nMassife after filling:\n";
	for(int i = 0; i < x; i++)
	{
	    cout << massife[i] << " ";
	}
	cout << endl;

    buildNewMatrix(newMat, massife, n, m);
    writeResult(newMat, massife, n, m);


    for (int i = 0; i < n; i++)
    {
        delete [] mat[i];
        delete [] newMat[i];
    }
    delete [] mat;
    delete [] newMat;
    delete [] massife;

	return 0;
}
