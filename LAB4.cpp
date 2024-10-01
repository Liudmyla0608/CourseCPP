

/*
    У списку міститься інформація про володарів автотранспорту:
    ПІБ, марка, номер, потужність автомобіля.
    Сформувати список володарів машин, відсортований за зростанням потужності автомобілів.
*/

#include <iostream>
#include <string>

using namespace std;

    struct FIO {
    string SurName;
    string FirstName;
    string SecondName;
    };

    struct Owner {
    FIO Name;
    string Brand;
    int Power;
    string Number;
    };
    
    int n = 10;

    Owner list[10] = {  {{"Surname1","FirstName1","SecondName1"},   "brand1",50,"number1" },
                        {{"Surname2","FirstName2","SecondName2"},   "brand2",100,"number2" },
                        {{"Surname3","FirstName3","SecondName3"},   "brand3",90,"number3" },
                        {{"Surname4","FirstName4","SecondName4"},   "brand4",170,"number4" },
                        {{"Surname5","FirstName5","SecondName5"},   "brand5",60,"number5" },
                        {{"Surname6","FirstName6","SecondName6"},   "brand6",85,"number6" },
                        {{"Surname7","FirstName7","SecondName7"},   "brand7",200,"number7" },
                        {{"Surname8","FirstName8","SecondName8"},   "brand8",300,"number8" },
                        {{"Surname9","FirstName9","SecondName9"},   "brand9",76,"number9" },
                        {{"Surname10","FirstName10","SecondName10"},"brand10",98,"number10" }
        
    };
    
    Owner* ptr = &list[0];

int main()
{
    int m;
    cin >> m;
    
    for (int i = 0; i < n; i++, cout << endl)
    {
        cout << list[i].Name.FirstName << "\t" << list[i].Name.SurName << "\t" << list[i].Name.SecondName << "\t" << list[i].Brand << "\t" << list[i].Power << "\t" << list[i].Number;
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((ptr + j)->Power > (ptr + j + 1)->Power)
            {
                Owner temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
    cout << endl << endl;
    
    
    for (int i = 0; i < n; i++, cout << endl)
    {
        cout << list[i].Name.FirstName << "\t" << list[i].Name.SurName << "\t" << list[i].Name.SecondName << "\t" << list[i].Brand << "\t" << list[i].Power << "\t" << list[i].Number;
    }

    return 0;
}
