
#ifndef ADDRESS_H
#define ADDRESS_H

class Address
{
    std::string city;
    std::string street;
    int houseNumber;
public:
    Address(std::string city, std::string street, int houseNumber) {
        this->city = city;
        this->street = street;
        this->houseNumber = houseNumber;
    }
    std::string get_full_address() const {
        return city + ", " + street + " " + std::to_string(houseNumber);
    }

    ~Address() = default;
};
#endif //ADDRESS_H
