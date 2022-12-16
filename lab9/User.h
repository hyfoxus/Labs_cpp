//
// Created by Gleb Nemirko on 04.12.2022.
//

#ifndef LAB1C___USER_H
#define LAB1C___USER_H
#include <string>
using namespace std;

class User {
private:
    string name;
     string surname;
     string second_name;

     int age;
     string login;
     string password;
     bool isActive;
     void generateLogin();
     void generatePassword();


public:
     User(string user_name, string user_surname, string user_second_name, int user_age){
         const char alphabet[53] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
         for (int j = 0; j < user_name.size(); ++j) {
                 bool isEnglish = true;
                 for (int i = 0; i < 53; ++i) {
                     if (user_name[j] == alphabet[i]) {
                         isEnglish = true;
                         break;
                     }
                     else isEnglish = false;
                 }
                 if (!isEnglish){
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
                 }
                 else isEnglish = false;
             }
             if (!isEnglish){
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
                 }
                 else isEnglish = false;
             }
             if (!isEnglish){
                 cout << "You are an Idiot, from now on it is your surname." << endl;
                 second_name = "Idiot";
                 break;
             } else second_name = user_second_name;
         }

         age = user_age;
         generateLogin();
         generatePassword();
         isActive = true;
     }
     //string transformLetter(char letter);
     User(User &user){
         name = user.getName();
         surname = user.getSurname();
         second_name = user.getSecondName();
         age = user.getAge();
         login = user.getLogin();
         password = user.getPassword();
     }
     User(){
         name = "N/A";
         surname = "N/A";
         second_name = "N/A";
         age = 0;
         login = "N/A";
         password = "N/A";
     }

     User(int name_ind, int surname_ind, int second_name_ind, int users_age){
         string surnames[10] = {"Ivanov", "Joestar", "Kurosaki", "Giovini", "Zeppeli",
                                "Brando", "Valentine", "Kujo", "Pucci", "Abdul"};
         string names[10] = {"Ivan", "Joseph", "Ichigo", "Giorno", "Ceaser",
                             "DIO", "Funny", "Jotaro", "Enrico", "Muhammed"};
         string second_names[10] = {"Ivanovich", "Hermit Purple", "Monster", "Gold Experience", "Nero",
                                    "WORLD", "D4C", "Star Platinum", "Made in Heaven", "Magician Red"};
         name = names[name_ind];
         surname = surnames[surname_ind];
         second_name = second_names[second_name_ind];
         age = users_age;
         generateLogin();
         generatePassword();
         isActive = rand() % 2;
     }

     ~User(){

     }

     string getLogin();
     int getAge();
     bool getActivity();
     string getFullname();
     string getName();
     string getSurname();
     string getSecondName();
     string getPassword();
     void rewrite(string user_name, string user_surname, string user_second_name, int user_age);
     void print();

     friend ostream& operator << (ostream& out, vector<User> users);


};


#endif //LAB1C___USER_H
