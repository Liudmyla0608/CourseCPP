#include <iostream>
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

void printMatrix(int ** matrix, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        cout << endl;
        for(int j = 0; j < m; j++)
        {
            cout << *(*(matrix + i) + j) << "    ";
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
	printMatrix(mat, n, m);
	
	newElementsMatrix(mat, n, m, massife);
	
	cout << "\nMassife after filling:\n";
	for(int i = 0; i < x; i++)
	{
	    cout << massife[i] << " ";
	}
	cout << endl;

    buildNewMatrix(newMat, massife, n, m); 

    
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
