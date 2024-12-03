#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//Базовий шаблонний абстрактний клас
template <typename T>
class DynamicArrayBase {
protected:
    std::vector<T> array; //Динамічний масив

public:
    //Конструктор за замовченням
    DynamicArrayBase() = default;

    //Конструктор з ініціалізацією
    DynamicArrayBase(const std::vector<T>& initialArray) : array(initialArray) {}

    //Віртуальний деструктор
    virtual ~DynamicArrayBase() = default;

    void addElement(const T& element) {
        array.push_back(element);
    }
    void removeElement(size_t index) {
        if (index < array.size()) {
            array.erase(array.begin() + index);
        }
    }

    //Оголошення чисто віртуальних методів
    virtual void inputElements() = 0; //Метод вводу
    virtual void outputElements() const = 0; //Метод виводу
};

class Address {
    std::string city;
    std::string street;
    int houseNumber;

public:
    Address() : city(""), street(""), houseNumber(0) {}
    Address(std::string city, std::string street, int houseNumber) 
        : city(city), street(street), houseNumber(houseNumber) {}

    std::string get_full_address() const {
        return city + ", " + street + " " + std::to_string(houseNumber);
    }
};

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

    std::string getTitle() const { return title; }
    int getDuration() const { return duration; }
};

class Cinema {
    std::string name;
    Address address;
    int year_of_establishment;

public:
    Cinema() : name(""), address(), year_of_establishment(0) {}
    Cinema(std::string name, std::string city, std::string street, int houseNumber, int year_of_establishment)
        : name(name), address(city, street, houseNumber), year_of_establishment(year_of_establishment) {}

    std::string get_name() const { return name; }
    std::string get_address() const { return address.get_full_address(); }
};

//Успадкований клас CinemaDynamicArray
class CinemaDynamicArray : public DynamicArrayBase<Cinema> {
public:
    //Конструктор за замовченням
    CinemaDynamicArray() = default;

    //Конструктор з ініціалізацією
    CinemaDynamicArray(const std::vector<Cinema>& cinemas) : DynamicArrayBase(cinemas) {}

    void inputElements() override {
        int count;
        std::cout << "Enter the number of cinemas: ";
        std::cin >> count;

        for (int i = 0; i < count; ++i) {
            std::string name, city, street;
            int houseNumber, year;
            std::cout << "Enter name, city, street, house number, and year of establishment for cinema " << i + 1 << ": ";
            std::cin >> name >> city >> street >> houseNumber >> year;

            addElement(Cinema(name, city, street, houseNumber, year));
        }
    }

    void outputElements() const override {
        std::cout << "Cinemas in the dynamic array:\n";
        for (const auto& cinema : array) {
            std::cout << cinema.get_name() << " at " << cinema.get_address() << "\n";
        }
    }
};


int main() {

    CinemaDynamicArray cinemas;
    cinemas.inputElements();
    cinemas.outputElements();

    cinemas.addElement(Cinema("Silver Screen", "New York", "Broadway", 123, 1995));

    std::cout << "\nAfter adding a new cinema:\n";
    cinemas.outputElements();

    cinemas.removeElement(0);

    std::cout << "\nAfter removing the first cinema:\n";
    cinemas.outputElements();

    return 0;
}
