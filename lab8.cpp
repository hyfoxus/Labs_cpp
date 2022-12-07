#include <iostream>
#include <iterator>
#include <cstddef>



using namespace std;

template <class T>
class Stack{
private:
    class Element{
    public:
        Element* prev;
        Element* next;
        T data;
        Element(){
            prev = nullptr;
            next = nullptr;
        }
    };
    Element* first;
    Element* last;
    int count;

public:
    struct Iterator{

        using iterator_category = std::forward_iterator_tag; // категория итератора - однонаправленный
        using difference_type = std::ptrdiff_t; // // число типа рузультата вычитания двух указателей
        using value_type = T; // тип данных итератора
        using pointer = Element*; // указатель
        using reference = T&; // ссылка


        /**
         * @brief - пустой конструктор итератора
         *
         */
        Iterator(){}


        /**
         * @brief - основной конструктор итератора
         *
         * @param ptr - указатель
         */
        Iterator(pointer ptr) : m_ptr(ptr) {}


        /**
         * @brief - перегрузка оператора разывменования
         *
         * @return reference - ссылка
         */
        reference operator*() const {
            return m_ptr->data;
        }


        /**
         * @brief - перегрузка оператора доступа к члену ->
         *
         * @return pointer - указатель
         */
        pointer operator->() {
            return m_ptr;
        }


        /**
         * @brief - префиксный инкремент
         *
         * @return Iterator& - ссылка на текущий элемент
         */
        Iterator& operator++(){
            m_ptr = m_ptr->next;
            //m_ptr++;
            return *this;
        }


        /**
         * @brief - постфиксный инкремент
         *
         * @return Iterator - текущий элемент
         */
        Iterator operator++(int) {
            Iterator tmp = *this;
            //++(*this);
            m_ptr = m_ptr->next;
            return tmp;
        }


        /**
         * @brief - оператор сравнения на равенство итерируемых элементов
         *
         * @param a - ссылка на первый элемент
         * @param b - ссылка на второй элемент
         * @return true - равны
         * @return false - неравны
         */
        friend bool operator== (const Iterator& a, const Iterator& b) {
            return a.m_ptr == b.m_ptr;
        };


        /**
         * @brief - оператор сравнения на неравенство итерируемых элементов
         *
         * @param a - ссылка на первый элемент
         * @param b - ссылка на второй элемент
         * @return true - неравны
         * @return false - равны
         */
        friend bool operator!= (const Iterator& a, const Iterator& b) {
            return a.m_ptr != b.m_ptr;
        };

    protected:
        pointer m_ptr;
    };


    /**
     * @brief - прямой итератор-указатель на начало списка
     *
     * @return Iterator - первый элемент в списке
     */
    Iterator begin(){
        return Iterator(first);
    }


    /**
     * @brief - прямой итератор на конец списка (следующий элемент после последнего)
     *
     * @return Iterator - следующий после последнего элемента элемент
     */
    Iterator end(){
        return Iterator(last->next);
    }

    /**
     * @brief - пустой конструктор списка
     *
     */

    Stack(){
        first = last = nullptr;
        count = 0;
    }

    /**
     * @brief - конструктор копирования
     *
     * @param obj - ссилка на список
     */

    Stack(const Stack& obj){
        Copy(obj);
    }

    Stack<T>& operator== (const Stack& obj){
        Copy(obj);
        return *this;
    }

    /**
    * @brief - деструктор списка
    *
    */

    ~Stack(){
        clear();
    }

    /**
  * @brief - возврат первого элемента в списке
  *
  * @return List<T>& - значение первого элемента в списке
  */
    T& firstElement(){
        return first->data;
    }

    /**
     * @brief - проверка пустой ли список
     *
     * @return true - список пуст
     * @return false - список содержит какое-то количество элементов
     */
    bool empty(){
        return count == 0;
    }

    /**
     * @brief - возврат количества элементов в списке
     *
     * @return int - количество элементов в списке
     */
    int size(){
        return count;
    }

    /**
 * @brief - добавление элемента в начало списка
 *
 * @param _data - значение, которое добавляем
 */
    void add(T _data){
        try{
            Element* t = new Element;
            t->data = _data;
            t->prev = nullptr;
            t->next = first;

            if (count > 0){
                first->prev = t;
                first = t;
            } else {
                first = last = t;
            }
            count++;
        }
        catch (bad_alloc e){
            cout << e.what() << endl;
        }
    }
    /**
     * @brief - удаление первого элемента в списке
     *
     */

    void deleteFirst(){
        first->next->prev = nullptr;
        Element* item = first->next;
        delete first;
        first = item;
        count--;
    }


    /**
   * @brief - очистка списка
   *
   */

    void clear(){
        for (int i = 0; i < count; ++i) {
            deleteFirst();
        }
    }

    /**
     * @brief - вывод списка на экран
     *
     * @param msg - сообщение
     */
    void print(std::string msg){
        cout << msg << " => ";
        Element* t = first;
        for (int i = 0; i < count; i++){
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
    template <typename TF>
    friend ostream& operator << (ostream& out, Stack<TF>& stack);

};
template <typename T>
ostream& operator << (ostream& out, Stack<T>& stack){
    stack.print("Stack ");
}

int main() {
    Stack<int> stack;
    stack.add(64);
    stack.add(256);
    stack.add(1000);
    stack.print("My list: ");
    if (!stack.empty()){
        cout << "My list is not empty, it has " << stack.size() << " elements" << endl;
    }
    cout << "Show my list with iterator:" << endl;
    for (auto el : stack){
        cout << el << " " << endl;
    }
    cout << "First element in my list: " << stack.firstElement() << endl;
    stack.deleteFirst();
    cout << "New First element in my list: " << stack.firstElement() << endl;


    Stack<char> scream;
    for (int i = 0; i <20; i++) {
        scream.add('A');
    }

    cout << "SCREAM!" << endl;

    for (auto el : scream){
        cout << el << " ";
    }
    cout << endl;

    for (int i = 0; i < 3; ++i) {
        scream.add('a');
    }
    scream.print("Changed Scream: ");
    for (int i = 0; i < 2; ++i) {
        scream.deleteFirst();
    }
    cout << scream << endl;


    return 0;
}