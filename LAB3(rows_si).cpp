#include <iostream>
#include <cstring>

using namespace std;

int main() {
    
    const int MAX_SIZE = 1000;
    char text[MAX_SIZE];

    cout << "Enter text: ";
    cin.getline(text, MAX_SIZE); 

    int count = 0; 
    int totalWords = 0; 

    char* word = strtok(text, " "); 

    while (word != nullptr) {
        totalWords++; 
        if (word[0] == word[strlen(word) - 1]) {
            count++;
        }
        word = strtok(nullptr, " "); 
    }

    if (count > 0) {
        cout << "Text has words that start and end with the same letter." << endl;
    } else {
        cout << "Text has no words that start and end with the same letter." << endl;
    }

    cout << "Number of words = " << totalWords << endl;
    cout << "Number of words that start and end with the same letter: " << count << endl;

    return 0;
}
