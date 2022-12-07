//
// Created by Gleb Nemirko on 04.12.2022.
//

#include "User.h"


//string User::transformLetter(char letter) {
//    w_char rus[66]={'А', 'а', 'Б', 'б',    'В', 'в', 'Г', 'г', 'Д', 'д', 'Е', 'е', 'Ж', 'ж', 'З', 'з', 'И', 'и', 'Й', 'й', 'К', 'к',
//                  'Л', 'л', 'М', 'м', 'Н', 'н', 'О', 'о', 'П', 'п',   'Р', 'р', 'С', 'с', 'Т', 'т', 'У', 'у', 'Ф', 'ф',   'Х', 'х', 'Ц', 'ц', 'Ч', 'ч',   'Ш', 'ш',
//                  'Щ', 'щ', 'Ь', 'ь', 'Ю', 'ю',   'Я', 'я', 'Ы', 'ы', 'Ъ', 'ъ', 'Ё', 'ё', 'Э', 'э'};
//
//    string eng[66]={"A", "a", "B", "b",    "V", "v", "G", "g", "D", "d", "E", "e", "Zh", "zh", "Z", "z", "I", "i", "J", "j", "K", "k",
//                         "L", "l", "M", "m", "N", "n", "O", "o", "P", "p",   "R", "r", "S", "s", "T", "t", "U", "u", "F", "f",   "H", "h", "Ts", "ts", "ch", "ch", "Sh", "sh",
//                         "Shh", "shh", "'", "'", "Yu", "yu","Ya", "ya", "Y", "y", "", "", "Yo", "yo", "E", "e"};
//    for (int i = 0; i < 74; ++i) {
//        if (rus[i] == letter) return eng[i];
//    }
//    string result;
//    result += letter;
//    return result;
//}

void User::generateLogin() {
    login = name[0];
    login += second_name[0];

    for (int i = 0; i < surname.size(); ++i) {
        login += surname[i];
    }
}

void User::generatePassword() {
    for (int i = 0; i < 20; ++i) {
        password += 41 + rand() % 81;
    }
}

int User::getAge() {
    return age;
}

bool User::getActivity() {
    return isActive;
}

string User::getLogin() {
    return login;
}

string User::getFullname() {
    string fullName = surname + ' ' + name + ' ' + second_name;
    return fullName;
}

string User::getPassword() {
    return password;
}

string User::getName() {
    return name;
}

string User::getSurname() {
    return surname;
}

string User::getSecondName() {
    return second_name;
}

void User::rewrite(string user_name, string user_surname, string user_second_name, int user_age) {
    const char alphabet[53] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                               's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                               'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                               'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
    for (int j = 0; j < user_name.size(); ++j) {
        bool isEnglish = true;
        for (int i = 0; i < 53; ++i) {
            if (user_name[j] == alphabet[i]) {
                isEnglish = true;
                break;
            } else isEnglish = false;
        }
        if (!isEnglish) {
            cout << "You are an Idiot, from now on it is your name." << endl;
            name = "Idiot";
            break;
        } else name = user_name;
    }
    for (int j = 0; j < user_surname.size(); ++j) {
        bool isEnglish = true;
        for (int i = 0; i < 53; ++i) {
            if (user_surname[j] == alphabet[i]) {
                isEnglish = true;
                break;
            } else isEnglish = false;
        }
        if (!isEnglish) {
            cout << "You are an Idiot, from now on it is your surname." << endl;
            surname = "Idiot";
            break;
        } else surname = user_surname;
    }
    for (int j = 0; j < user_second_name.size(); ++j) {
        bool isEnglish = true;
        for (int i = 0; i < 53; ++i) {
            if (user_second_name[j] == alphabet[i]) {
                isEnglish = true;
                break;
            } else isEnglish = false;
        }
        if (!isEnglish) {
            cout << "You are an Idiot, from now on it is your surname." << endl;
            second_name = "Idiot";
            break;
        } else second_name = user_second_name;

    }
}

User::User(int i) {
    string surnames[10] = {"Ivanov", "Joestar", "Kurosaki", "Giovini", "Zeppeli",
                           "Brando", "Valentine", "Kujo", "Pucci", "Abdul"};
    string names[10] = {"Ivan", "Joseph", "Ichigo", "Giorno", "Ceaser",
                        "DIO", "Funny", "Jotaro", "Enrico", "Muhammed"};
    string second_names[10] = {"Ivanovich", "Hermit Purple", "Monster", "Gold Experience", "Nero",
                               "WORLD", "D4C", "Star Platinum", "Made in Heaven", "Magician Red"};
    name = names[i];
    surname = surnames[i];
    second_name = second_names[i];
    age = 20 + i;
    generateLogin();
    generatePassword();
}


