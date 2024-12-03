#ifndef FILM_H
#define FILM_H
#include <string>
#include <iostream>

class Film {
    std::string title;
    int year;
    std::string genre;
    int ageRestriction;
    int duration;

public:
    Film() : title(""), year(0), genre(""), ageRestriction(0), duration(0) {}
    Film(std::string title, int year, std::string genre, int ageRestriction, int duration)
        : title(title), year(year), genre(genre), ageRestriction(ageRestriction), duration(duration) {}

    Film(const Film &other)
        : title(other.title), year(other.year), genre(other.genre),
          ageRestriction(other.ageRestriction), duration(other.duration) {}

    Film &operator=(const Film &other) {
        if (this != &other) {
            title = other.title;
            year = other.year;
            genre = other.genre;
            ageRestriction = other.ageRestriction;
            duration = other.duration;
        }
        return *this;
    }

    ~Film() = default;

    std::string getTitle() const { return title; }
    int getYear() const { return year; }
    std::string getGenre() const { return genre; }
    int getAgeRestriction() const { return ageRestriction; }
    int getDuration() const { return duration; }

    friend std::ostream &operator<<(std::ostream &os, const Film &film) {
        os << film.title << " " << film.year << " " << film.genre << " "
           << film.ageRestriction << " " << film.duration;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Film &film) {
        is >> film.title >> film.year >> film.genre >> film.ageRestriction >> film.duration;
        return is;
    }

    bool operator==(const Film &other) const {
        return title == other.title && year == other.year;
    }

    bool operator>(const Film &other) const {
        return duration > other.duration;
    }

    operator double() const { return static_cast<double>(duration); }
};
#endif // FILM_H
