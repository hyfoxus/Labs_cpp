#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

struct Square{
    double side;
    double area;
};

struct Rectangle{
    double height;
    double width;
    double area;
};

struct Triangle{
    double foundation;
    double height;
    double area;
};

struct Circle{
    double radius;
    double area;
};

enum Types{
    SquareType = 0,
    RectangleType,
    TriangleType,
    CircleType
};


/*
 * Формула площади прямоугольика
 *
 * @param height Высота прямоугольника.
 * @param width Ширина прямоугльника.
 * @return число площади.
 */
double rectangleArea(double height, double width){
    return height * width;
}
/*
 * Формула площади треугольника
 *
 * @param height Высота треугольника.
 * @param foundation основание треугольника.
 * @return число площади.
 */
double triangleArea(double height, double foundation){
    return (height * foundation) / 2;
}

/*
 * Формула площади прямоугольика
 *
 * @param height Радиус круга.
 * @return число площади.
 */
double circleArea(double radius){
    return radius * radius * M_PI;
}

/*
 * Сумма площадей фигур
 *
 * @param *array_obj Массив универсальных указателей.
 * @param types Массив типов (Types).
 * @param n Размер массивов.
 * @return число суммы площадей.
 */
double getSumArea(void* *array_obj, Types* types, int n){
    double result = 0;
    for (int i = 0; i < n; ++i) {
        switch (types[i]) {
            case 0:{
                Square *square = static_cast<Square *>(array_obj[i]);
                Square sqr = *square;
                result += sqr.area;
                break;
            }
            case 1: {
                Rectangle *rectangle = static_cast<Rectangle *>(array_obj[i]);
                Rectangle rect = *rectangle;
                result += rect.area;
                break;
            }
            case 2: {
                Triangle *triangle = static_cast<Triangle *>(array_obj[i]);
                Triangle tri = *triangle;
                result += tri.area;
                break;
            }
            case 3: {
                Circle *circle = static_cast<Circle *>(array_obj[i]);
                Circle circ = *circle;
                result += circ.area;
                break;
            }
            default: {
                cout << "Fuck you" << endl;
                return 0;
            }
        }

    }
    return result;
}
/*
 * Количество фигур
 *
 * @param n Размер массивов.
 * @param types Массив типов (Types).
 * @return Массив с количествами.
 */
int* countFigures(Types* types, int n){
    int arr[4];
    for (int i = 0; i < 4; ++i) {
            arr[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        arr[types[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (arr[types[i]] == 0){
            arr[types[i]] = 0;
        }
    }
    return arr;
}
/*
 * Вывод площадей больше чем введенное число
 *
 * @param *array_obj Массив универсальных указателей.
 * @param types Массив типов (Types).
 * @param n Размер массивов.
 * @param inserted Введенное число пользователя.
 * @return число суммы площадей.
 */
void getBiggerArea(void* *array_obj, Types* types, int n, double inserted){
    for (int i = 0; i < n; ++i) {
        switch (types[i]) {
            case 0:{
                Square *square = static_cast<Square*>(array_obj[i]);
                if ((*square).area > inserted) cout << "\nThis is a square with side:" << (*square).side << "\nSquare area:" << (*square).area<< endl;
                break;
            }
            case 1: {
                Rectangle *rectangle = static_cast<Rectangle *>(array_obj[i]);
                if ((*rectangle).area > inserted)cout << "\nThis is a rectangle with height:" << (*rectangle).height << "\nRectangle width:" << (*rectangle).width << "\nRectangle area is " << (*rectangle).area<< endl;
                break;
            }
            case 2: {
                Triangle *triangle = static_cast<Triangle *>(array_obj[i]);
                if ((*triangle).area > inserted)cout << "\nThis is a Triangle with height:" << (*triangle).height << "\nTriangle width:" << (*triangle).foundation << "\nTriangle area is " << (*triangle).area<< endl;
                break;
            }
            case 3: {
                Circle *circle = static_cast<Circle *>(array_obj[i]);
                if ((*circle).area > inserted)cout << "\nThis is a circle with height:" << (*circle).radius <<  "\nCircle area is " << (*circle).area<< endl;
                break;
            }
            default: {
                cout << "Fuck you" << endl;
            }
        }

    }
}

/*
 * Получение радиуса описанной окружности
 *
 * @param *array_obj Массив универсальных указателей.
 * @param types Массив типов (Types).
 * @param n Размер массивов.
 * @return число радиуса описанной окружности.
 */
double getOutsideCircle(void* *array_obj, Types* types, int n){
    double max_area = 0;
    for (int i = 0; i < n; ++i) {
        switch (types[i]) {
            case 0:{
                Square *square = static_cast<Square*>(array_obj[i]);
                if (max_area < (*square).area) max_area = (*square).area;
                break;
            }
            case 1: {
                Rectangle *rectangle = static_cast<Rectangle*>(array_obj[i]);
                if (max_area < (*rectangle).area) max_area =  (*rectangle).area;
                break;
            }
            case 2: {
                Triangle *triangle = static_cast<Triangle*>(array_obj[i]);
                if (max_area < (*triangle).area) max_area =  (*triangle).area;
                break;
            }
            case 3: {
                Circle *circle = static_cast<Circle*>(array_obj[i]);
                if (max_area < (*circle).area) max_area = (*circle).area;
                break;
            }
            default: {
                cout << "Fuck you" << endl;
                return 0;
            }
        }
    }
    double result;
    result = sqrt(max_area/M_PI);
    return result;
}

int main() {
    int n;
    srand(time(NULL));
    cin >> n;
    void* array_obj[n];
    Types array_types[n];
    for (int i = 0; i < n; ++i) {
        array_types[i] = static_cast<Types>(rand() % 4);
        switch (array_types[i]) {
            case 0: {
                Square square;
                square.side = 1 +  rand() % 10;
                square.area = rectangleArea(square.side, square.side);
                array_obj[i] = &square;
                break;
            }
            case 1: {
                Rectangle rectangle;
                rectangle.height = 1 +  rand() % 10;
                rectangle.width = 1 +  rand() % 10;
                rectangle.area = rectangleArea(rectangle.height, rectangle.width);
                array_obj[i] = &rectangle;
                break;
            }
            case 2: {
                Triangle triangle;
                triangle.height = 1 +  rand() % 10;
                triangle.foundation = 1 +  rand() % 10;
                triangle.area = triangleArea(triangle.height, triangle.foundation);
                array_obj[i] = &triangle;
                break;
            }
            case 3: {
                Circle circle;
                circle.radius = 1 +  rand() % 10;
                circle.area = circleArea(circle.radius);
                array_obj[i] = &circle;
                break;
            }
            default:
                cout << "FUCK YOU" << endl;
                return 0;
        }
    }
    cout << "IT WORKS" << endl;
    cout << getSumArea(array_obj, array_types, n) << endl;

    int amount_figures[4];
    int* arr = countFigures(array_types, n);
    for (int i = 0; i < 4; ++i) {
        amount_figures[i] = arr[i];
    }
    for (int i = 0; i < 4; ++i) {
        switch (i) {
            case 0:{
                cout << "Square: " << amount_figures[i] << endl;
                break;
            }
            case 1: {
                cout << "Rectangles: " <<amount_figures[i] << endl;
                break;
            }
            case 2: {
                cout << "Triangles: " << amount_figures[i] << endl;
                break;
            }
            case 3: {
                cout << "Circles: " << amount_figures[i] << endl;
                break;
            }
            default: {
                cout << "Fuck you" << endl;
                return 0;
            }
        }

    }
    int inserted_number;
    cin >> inserted_number;
    getBiggerArea(array_obj, array_types, n, inserted_number);
    cout << getOutsideCircle(array_obj, array_types, n) << endl;

    return 0;
}
