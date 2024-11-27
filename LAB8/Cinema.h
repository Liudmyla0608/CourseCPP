#ifndef CINEMA_H
#define CINEMA_H
using namespace std;
#include <string>
#include "Address.h"
#include <iostream>
#include "Film.h"


class Cinema {
    string name;
    Address address;
    int year_of_establishment;

    int numFilms;
    int capacity;
    Film* films;
public:
    Cinema(string name, string city, string street, int houseNumber, int year_of_establishment, int capacity);
    ~Cinema();


    inline string get_name() const { return name; }
    inline string get_address() const { return address.get_full_address(); }


    void addFilm(Film newFilm) {
        if(numFilms < capacity) {
            films[numFilms++] = newFilm;
        }
    }

    void remove_film(string title) {
        for (int i = 0; i < numFilms; ++i) {
            if (films[i].getTitle() == title) {
                for (int j = i; j < numFilms - 1; ++j) {
                    films[j] = films[j + 1];
                }
                --numFilms;
                cout << "Film \"" << title << "\" removed." << endl;
                return;
            }
        }
        cout << "Film \"" << title << "\" not found." << endl;
    }


    double get_percentage_of_kids_films() const {
        if (numFilms == 0) return 0.0;

        int kidsCount = 0;
        for (int i = 0; i < numFilms; ++i) {
            if (films[i].getAgeRestriction() <= 12) {
                kidsCount++;
            }
        }
        return (100.0 * kidsCount) / numFilms;
    }

    Film get_longest_film() const {
        if (numFilms == 0) {
            cout << "No films available to find the longest one." << endl;
            return Film(); // Повертаємо "порожній" фільм.
        }

        Film longest = films[0];
        for (int i = 1; i < numFilms; ++i) {
            if (films[i].getDuration() > longest.getDuration()) {
                longest = films[i];
            }
        }
        return longest;
    }

    double get_average_duration() const {
        if (numFilms == 0) return 0.0;

        int totalDuration = 0;
        for (int i = 0; i < numFilms; ++i) {
            totalDuration += films[i].getDuration();
        }
        return totalDuration / (numFilms * 1.0);
    }

};


#endif // CINEMA_H


