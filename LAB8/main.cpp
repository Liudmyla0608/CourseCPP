//Розробити клас, що представляє кінотеатр.
//Кінотеатр характеризується
//назвою, адресою розташування, списком фільмів, які демонструються, роком
//заснування.
//Адреса характеризується назвою міста, вулиці, номером будинку.
//Фільм характеризується назвою, роком створення, назвою жанру, віковим
//обмеженням, тривалістю фільму у хвилинах.
//категорії
//Розробити методи, які дозволяють:
//1. дізнатися назву кінотеатру
//2. дізнатися адресу розташування
//3. дізнатися процентну кількість фільмів, які відносяться до дитячої
//4. добавити новий фільм
//5. видалити фільм
//6. знайти найдовший фільм за часом
//7. дізнатися середню тривалість фільму

#include <iostream>
#include "Cinema.h"
using namespace std;

int main() {
    // Створюємо перший кінотеатр
    Cinema* x1;
    x1 = new Cinema("Silver", "New York", "Yolt Street", 22, 1997, 10);

    // Додаємо фільми до першого кінотеатру
    x1->addFilm(Film("Pretty Girl", 2020, "Romance", 16, 120));
    x1->addFilm(Film("Human-Spider", 2002, "Action", 13, 121));

    // Виводимо інформацію про перший кінотеатр
    cout << "Name of cinema 1: " << x1->get_name() << endl;
    cout << "Address of cinema 1: " << x1->get_address() << endl;

    // Виводимо процент дитячих фільмів
    cout << "Percentage of kids films in cinema 1: " << x1->get_percentage_of_kids_films() << "%" << endl;

    // Знаходимо найдовший фільм
    if (x1->get_average_duration() > 0) {
        Film longestFilm = x1->get_longest_film();
        cout << "Longest film in cinema 1: " << longestFilm.getTitle() << ", " << longestFilm.getDuration() << " minutes." << endl;
    } else {
        cout << "No films available to find the longest one." << endl;
    }

    // Виводимо середню тривалість фільмів
    cout << "Average film duration in cinema 1: " << x1->get_average_duration() << " minutes." << endl;

    // Видаляємо один із фільмів
    x1->remove_film("Human-Spider");

    // Звільняємо пам'ять
    delete x1;

    // Створюємо другий кінотеатр
    Cinema x2("Gold", "Los Angeles", "Yolt Street", 25, 1998, 5);
    x2.addFilm(Film("Toy Story", 1995, "Animation", 6, 81));
    x2.addFilm(Film("Frozen", 2013, "Animation", 0, 102));

    // Виводимо інформацію про другий кінотеатр
    cout << "Name of cinema 2: " << x2.get_name() << endl;
    cout << "Address of cinema 2: " << x2.get_address() << endl;
    cout << "Percentage of kids films in cinema 2: " << x2.get_percentage_of_kids_films() << "%" << endl;

    // Середня тривалість фільмів другого кінотеатру
    cout << "Average film duration in cinema 2: " << x2.get_average_duration() << " minutes." << endl;

    return 0;
}
