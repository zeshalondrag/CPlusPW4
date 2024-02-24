#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

string reverse(const string& word) {
    string reversedWord = word;
    int length = reversedWord.length();
    for (int i = 0; i < length / 2; ++i) {
        char temp = reversedWord[i];
        reversedWord[i] = reversedWord[length - i - 1];
        reversedWord[length - i - 1] = temp;
    }
    return reversedWord;
}

string removeVowels(const string& word) {
    string result;
    string vowels = "аеёиоуыэюяАЕЁИОУЫЭЮЯ";
    for (char c : word) {
        bool isVowel = false;
        for (char v : vowels) {
            if (c == v) {
                isVowel = true;
                break;
            }
        }
        if (!isVowel) {
            result += c;
        }
    }
    return result;
}

string removeConsonants(const string& word) {
    string result;
    string consonants = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
    for (char c : word) {
        bool isConsonant = false;
        for (char con : consonants) {
            if (c == con) {
                isConsonant = true;
                break;
            }
        }
        if (!isConsonant) {
            result += c;
        }
    }
    return result;
}

string shuffle(const string& word) {
    string shuffledWord = word;
    srand(time(0));
    int length = shuffledWord.length();
    for (int i = 0; i < length; ++i) {
        int j = rand() % length;
        char temp = shuffledWord[i];
        shuffledWord[i] = shuffledWord[j];
        shuffledWord[j] = temp;
    }
    return shuffledWord;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "");
    
    int choice;
    string word;

    cout << "Введите слово: ";
    getline(cin, word);

    cout << "Опции: \n";
    cout << "-------------------\n";
    cout << "1 - Слово выводится задом наперед\n";
    cout << "2 - Вывести слово без гласных\n";
    cout << "3 - Вывести слово без согласных\n";
    cout << "4 - Рандомно раскидывать буквы заданного слова\n";
    cout << "Выберите опцию: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Результат: " << reverse(word) << endl;
        break;
    case 2:
        cout << "Результат: " << removeVowels(word) << endl;
        break;
    case 3:
        cout << "Результат: " << removeConsonants(word) << endl;
        break;
    case 4:
        cout << "Результат: " << shuffle(word) << endl;
        break;
    default:
        cout << "Неверный выбор!" << endl;
        break;
    }

    return 0;
}