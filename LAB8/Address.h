#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>

class Address {
    std::string city;
    std::string street;
    int houseNumber;

public:
    Address() : city(""), street(""), houseNumber(0) {}
    Address(std::string city, std::string street, int houseNumber) 
        : city(city), street(street), houseNumber(houseNumber) {}

    Address(const Address &other) 
        : city(other.city), street(other.street), houseNumber(other.houseNumber) {}

    Address &operator=(const Address &other) {
        if (this != &other) {
            city = other.city;
            street = other.street;
            houseNumber = other.houseNumber;
        }
        return *this;
    }

    ~Address() = default;

    std::string get_full_address() const {
        return city + ", " + street + " " + std::to_string(houseNumber);
    }

    friend std::ostream &operator<<(std::ostream &os, const Address &addr) {
        os << addr.get_full_address();
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Address &addr) {
        is >> addr.city >> addr.street >> addr.houseNumber;
        return is;
    }
};
#endif // ADDRESS_H
