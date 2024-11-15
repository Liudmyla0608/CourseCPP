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
    cout << "sum of numbers between first and last elements of massife: " << endl;
    
    //define first and second positive numbers
    //with cicle define the sum of that numbers
    
    int fPN = -1;
    int lPN = -1;
    
    int sum = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if(massife[i] > 0 && fPN == -1)
        {
            fPN = i;
        }
        else if (massife[i] > 0 && lPN == -1)
        {
            lPN = i;
        }
 
    }
    
    if (fPN != -1 && lPN != -1 && fPN != lPN)
    {
        for(int i = fPN + 1; i < lPN; ++i)
        {
            sum += massife[i];
        }
    }
    
    cout << sum << endl;
}

void toLocateZero(int * massife, int n)
{
    
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
    toLocateZero(massife, n);
    
    
    delete [] massife;
    
    return 0;
}
