//В одновимірному масиві який складається із N дійсних елементів, розрахувати:
//максимальний по модулю елемент масиву;
//суму елементів масиву, які знаходяться міжпершим і другим додатними елементами.
//Перетворити масив таким чином, щоб елементи рівні нулю розташовувалися після всіх інших.

#include <iostream>
#include <cmath>
using namespace std;


int * create(int n)
{
    int * massife = new int [n];
    return massife;
}

void filling(int * massife, int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << "input numbers of massife: ";
        cin >> *(massife + i);
        cout << endl;
    }
}

void print(int * massife, int n)
{
    cout << "this is your massife: ";
    for(int i = 0; i < n; ++i)
    {
        cout << *(massife + i) << " ";
    }
    cout << endl;
}

void maxInModule(int * massife, int n)
{
    cout << "this is maximym in module element of massife: ";
    
    int max;
    max = massife[0];
    
    for(int i = 0; i < n; ++i)
    {
       int number = fabs(massife[i]);

        if( number > max)
        {
            max = number;
        }
    }
    cout << max;
    cout << endl;
}

void sumOfElements(int * massife, int n)
{
    cout << "sum of numbers between first and last plus elements of massife: " << endl;
    int sum = 0;
    int firstEdge = -1;
    int secondEdge = -1;
    
    //determine the edges
    for (int i = 0; i < n; i++) {
        if (massife[i] > 0) {
            if (firstEdge == -1) {
                firstEdge = i;
            } else if (secondEdge == -1) {
                secondEdge = i;
                break;
            }
        }
    }

    if (firstEdge == -1 || secondEdge == -1) {
        cout << "Not enough positive numbers to perform sum calculation." << endl;
    } else {
        for (int i = firstEdge + 1; i < secondEdge; i++) {
            sum += massife[i];
        }
        cout << "Sum: " << sum << endl;
    }
    cout << endl;
}

void sorting(int * massife, int n)
{
    cout << "sorting: " << endl;
    for(int step = 0; step < n - 1; step++)
    {
        for(int i = 0; i < n - 1; i++)
        {
            if(massife[i] == 0 && massife[i + 1] != 0)
            {
                int next = massife[i + 1];
                int current = massife[i];
                
                massife[i] = next;
                massife[i + 1] = current;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Input count of number of massife: ";
    cin >> n;
    
    int * massife = create(n);
    filling(massife, n);
    print(massife, n);
    maxInModule(massife, n);
    sumOfElements(massife, n);
    sorting(massife, n);
    print(massife, n);
    
    delete [] massife;
    
    return 0;
}
