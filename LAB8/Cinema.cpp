
#include "Cinema.h"

using namespace std;

Cinema::Cinema(string name, string city, string street, int houseNumber, int year_of_establishment, int capacity)
: address( city, street, houseNumber ) {
    this->name = name;
    this->year_of_establishment = year_of_establishment;
    this->numFilms = 0;

    this->films = new Film[capacity];
}
Cinema::~Cinema(){
    delete[] films;
}



