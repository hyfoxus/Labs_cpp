#include <iostream>
#include <ctime>
#include <cstdlib>

#define SIZE 10000
#define START_ID 97
#define LAST_ID 122

using namespace std;
/*
 * Класс Letter (Буква)
 *
 * Имеет свойства
 * symbol - символ буквы
 * amount - количество букв в тексте
 * id - id буквы/символа в ascii
 *
 */
class Letter{
public:
    char symbol;
    int amount = 0;
    int id;
};

/*
 * Генерация массива букв - Текста
 *
 * @param size размер текста.
 * @param left id первого (левого) символа из массива символов для генерации (ascii).
 * @param right id поледнего (правого) символа из массива символов для генерации (ascii).
 * @return возвращает массив символов (Текст).
 */

int *Generate(int size, int left, int right){
    int resultArr[size];
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        resultArr[i] = left + rand() % (right - left + 1);
    }
    return resultArr;
}

/*
 * Подсчет букв - Текста
 *
 * @param array массив символов (Текст).
 * @param size размер текста.
 * @param left id первого (левого) символа из массива символов для генерации (ascii).
 * @param right id поледнего (правого) символа из массива символов для генерации (ascii).
 * @return возвращает массив объектов класса Letter (букв)
 */

Letter *CountLetters(int* array, int size, int left, int right){
    Letter amountLetters[right - left + 1];
    int letterPosition = 0;
    for(int i = START_ID; i <= LAST_ID; i++, letterPosition++){
        amountLetters[letterPosition].symbol = char(i);
        amountLetters[letterPosition].id = i;
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= right - left + 1; ++j) {
            if (amountLetters[j].id == array[i])
                amountLetters[j].amount++;
        }
    }
    return amountLetters;
}

int main() {
    int* array = Generate(SIZE, START_ID, LAST_ID);
    Letter* aux = CountLetters(array, SIZE, START_ID, LAST_ID);
    Letter result[26];
    for (int i = 0; i < 26; ++i) {
        result[i] = aux[i];
    }

    for (int i = 0; i < LAST_ID - START_ID + 1; ++i) {
        cout << "There are " << result[i].amount << " of " << result[i].symbol <<  endl;
    }
    return 0;
}





