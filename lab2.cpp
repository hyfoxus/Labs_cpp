#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

/*
 * Заполнение массива
 *
 * @param arr ссылка на двумерный массив
 * @param size размер стороны массива.
 */

void fillArray(int** arr, int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            arr[i][j] = NULL;
            arr[i][j] = (j + 1) + size * i;
        }
    }
}
/*
 * Разварачивает массива
 *
 * @param arr ссылка на двумерный массив
 * @param size размер стороны массива.
 */

void reverseArray(int** arr, int size){
    int number = 1;
    for (int i = size - 1; i >= 0; i--) {
        for (int j = size - 1; j >= 0; --j) {
            arr[i][j] = NULL;
            arr[i][j] = number;
            number++;
        }
    }
}

/*
 * Корежит массив по главной линии
 *
 * @param arr ссылка на двумерный массив
 * @param size размер стороны массива.
 */

void mainLineArray(int** arr, int size){
    int start = 1;
    for (int i = size - 1; i >= 0; i--) {
        int aux_y = i;
        int aux_x = 0;
        for (int j = i; j < size; ++j) {
            arr[aux_y][aux_x] = NULL;
            arr[aux_y][aux_x] = start;
            aux_y++;
            aux_x++;
            start++;
        }
    }
    for (int i = 1; i < size; i++) {
        int aux_y = 0;
        int aux_x = i;
        for (int j = i; j < size; j++) {
            arr[aux_y][aux_x] = NULL;
            arr[aux_y][aux_x] = start;
            aux_y++;
            aux_x++;
            start++;
        }
    }
}

/*
 * Извращает массив по побочной линии
 *
 * @param arr ссылка на двумерный массив
 * @param size размер стороны массива.
 */

void sideLineArray(int** arr, int size){
    int number = 1;
    for (int i = 0; i < size; i++) {
        int aux_y = i;
        int aux_x = 0;
        for (int j = i; j >= 0; --j) {
            arr[aux_y][aux_x] = NULL;
            arr[aux_y][aux_x] = number;
            aux_y--;
            aux_x++;
            number++;
        }
    }
    for (int i = 1; i < size; i++) {
        int aux_y = size - 1;
        int aux_x = i;
        for (int j = i; j < size; j++) {
            arr[aux_y][aux_x] = NULL;
            arr[aux_y][aux_x] = number;
            aux_y--;
            aux_x++;
            number++;
        }
    }
}

/*
 * Вертит массив по часовой стрелке
 *
 * @param arr ссылка на двумерный массив
 * @param size размер стороны массива.
 */

void wibblyWobblyArray(int** arr, int size) {
    int border_Top = 0;
    int border_Right = size - 1;
    int border_Bottom = size - 1;
    int border_Left = 0;
    int number = 1;

    do {
        for (int i = border_Left; i <= border_Right; ++i) {
            arr[border_Top][i] = number;
            number++;
        }
        border_Top++;
        for (int i = border_Top; i <= border_Bottom; ++i) {
            arr[i][border_Right] = number;
            number++;
        }
        border_Right--;
        for (int i = border_Right; i >= border_Left; --i) {
            arr[border_Bottom][i] = number;
            number++;
        }
        border_Bottom--;
        for (int i = border_Bottom; i >= border_Top; --i) {
            arr[i][border_Left] = number;
            number++;
        }
        border_Left++;
    } while (number <= size*size);
}



int main() {
    int n;
    cout << "Insert a number:" << endl;
    cin >> n;
    int **arr;
    arr = new int * [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int [n];
    }
    int mode_id;
    bool success = false;
    while (!success) {
        cout << "What do you need (Insert number): 1) Normal matrix 2) Reversed matrix 3) Main Line matrix 4) Side Line matrix 5) Wibly-Wobbly Timey-whimey Matrix" << endl;
        cin >> mode_id;
        switch (mode_id) {
            case 1:
                fillArray(arr, n);
                success = true;
                break;
            case 2:
                fillArray(arr, n);
                reverseArray(arr, n);
                success = true;
                break;
            case 3:
                fillArray(arr, n);
                mainLineArray(arr, n);
                success = true;
                break;
            case 4:
                fillArray(arr, n);
                sideLineArray(arr, n);
                success = true;
                break;
            case 5:
                fillArray(arr, n);
                wibblyWobblyArray(arr, n);
                success = true;
                break;
            default:
                cout << "Ну ты и еблан конечно" << endl;
                mode_id = NULL;
                success = false;
                break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}


