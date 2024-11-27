#ifndef FILM_H
#define FILM_H

class Film
{
    std::string title;
    int year;
    std::string genre;
    int ageRestriction;
    int duration;

public:
    Film(std::string title, int year, std::string genre, int ageRestriction, int duration)
    {
        this->title = title;
        this->year = year;
        this->genre = genre;
        this->ageRestriction = ageRestriction;
        this->duration = duration;
    }

    Film() : title(""), year(0), genre(""), ageRestriction(0), duration(0) {}

    std::string getTitle() const {return title;}
    int getYear() const {return year;}
    std::string getGenre() const {return genre;}
    int getAgeRestriction() const {return ageRestriction;}
    int getDuration() const {return duration;}

    std::string getCatecory() const {
        if (ageRestriction <= 12)
        {return "дитячий фільм";}
        else
        {return "дорослий фільм";}
    }

};


#endif //FILM_H
