#include <iostream>
using namespace std;

//Відсортувати за зменшенням масив максимальних елементів стовпців матриці


int ** createMatrix(int n , int m)
{
    int ** matrix = new int* [n];
    for(int i = 0; i < n; i++)
    {
        matrix[i] = new int [m];
    }
    return matrix;
}

int * createMassife(int e)
{
    int * massife = new int[e];
}

void fullingMatrix()
{
    cout << "Full matrix" << endl;
    
    for(int i = 0; i < n; i++)
    
}

void determineEachColomnMaxElement()
{
    
}

void sortingMaxElements()
{
    
}

void printMatrix()
{
    cout << "matrix in its nature: " << endl;
    
}

int main (){
    int n = 3;
    int m = 3;
    int e = 0;
    
    int ** matrix = createMatrix(n, m);
    int * massife = createMassife(e);
    
    fullingMatrix()
    void printMatrix()


 
    int Massife[e];
    int Matrix[n][m];
    int max, min;
    int imax, imin;
    imax = 0; imin = 0;
    cout << "Full matrix" << endl;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            {
                cout << "Matrix [" << i <<"] [" << j <<"] = ";
                cin >> Matrix[i][j];
                
               
                
            }
    cout << "matrix in its nature: ";
    
    
    for(int i = 0; i < n; i++)
        {
            cout << endl;
            for(int j = 0; j < m; j++)
            {
                cout << Matrix[i][j] << " ";
            }
        }
        
        
        
    
        
        
        
        for( int j = 0; j < n; j++)
        {
            
             max = Matrix[0][j];
            for( int i = 0; i <= m; i++)
            {
                if( Matrix[i][j] > max)
                {
                    max = Matrix[i][j]; imax = i;
                }
                else
                if( Matrix[i][j] < min)
                {
                    min = Matrix[i][j]; imin = i;
                }
                
            }
            
            Massife[e] = max; e++;
        }
        
        
        cout << endl;
        cout << "Massife e: ";
        for(int k = 0; k < e; k++)
        cout << Massife[k] << " ";
        
        
        
        
         cout << "sorting" << endl;
    
    int a;
    
    for (int z = 1; z < n; z++)
        for (int i = 0; i < n - z; i++)
        {
            if (Massife[i] < Massife[i + 1])
            {
                a = Massife[i];
                Massife[i] = Massife[i + 1];
               Massife[i + 1] = a;
            }
        }
        
    cout << "result: " << endl;
    
    for(int i = 0; i < n; i++)
    cout << Massife[i] << " ";

}
