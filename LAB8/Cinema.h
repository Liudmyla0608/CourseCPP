#ifndef CINEMA_H
#define CINEMA_H
#include <string>
#include <vector>
#include <algorithm>
#include "Address.h"
#include "Film.h"
#include <iostream>

class Cinema {
    std::string name;
    Address address;
    int year_of_establishment;
    std::vector<Film> films;

public:
    Cinema() : name(""), address(), year_of_establishment(0) {}

    Cinema(std::string name, std::string city, std::string street, int houseNumber, int year_of_establishment)
        : name(name), address(city, street, houseNumber), year_of_establishment(year_of_establishment) {}

    Cinema(const Cinema &other)
        : name(other.name), address(other.address), year_of_establishment(other.year_of_establishment), films(other.films) {}

    Cinema &operator=(const Cinema &other) {
        if (this != &other) {
            name = other.name;
            address = other.address;
            year_of_establishment = other.year_of_establishment;
            films = other.films;
        }
        return *this;
    }

    ~Cinema() = default;

    void addFilm(const Film &newFilm) {
        films.push_back(newFilm);
    }

    void removeFilm(const std::string &title) {
        films.erase(std::remove_if(films.begin(), films.end(), [&title](const Film &f) { return f.getTitle() == title; }), films.end());
    }

    double getAverageDuration() const {
        if (films.empty()) return 0.0;
        return std::accumulate(films.begin(), films.end(), 0.0, [](double sum, const Film &f) {
                   return sum + f.getDuration();
               }) /
               films.size();
    }

    friend std::ostream &operator<<(std::ostream &os, const Cinema &cinema) {
        os << cinema.name << " " << cinema.address << " " << cinema.year_of_establishment;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Cinema &cinema) {
        is >> cinema.name >> cinema.address >> cinema.year_of_establishment;
        return is;
    }
};
#endif // CINEMA_H


#endif // CINEMA_H


