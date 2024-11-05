#include "Stack.h"
#include <stdexcept>

using namespace std;

// Конструктор
Stack::Stack(int size) : top(-1), maxSize(size) {
    arr = new int[maxSize]; // Выделение памяти для массива
}

// Деструктор
Stack::~Stack() {
    delete[] arr; // Освобождение памяти
}

// Добавление элемента
void Stack::Spush(int value) {
    if (SisFull()) {
        cout << "Стек переполнен!" << endl;
        return;
    }
    arr[++top] = value; // Увеличение индекса и добавление элемента
}

// Удаление элемента
void Stack::Spop() {
    if (SisEmpty()) {
        cout << "Стек пуст!" << endl;
        return;
    }
    --top; // Уменьшение индекса верхнего элемента
}

// Чтение элемента
int Stack::Speek() const {
    if (SisEmpty()) {
        throw runtime_error("Стек пуст!");
    }
    return arr[top]; // Возврат верхнего элемента
}

// Проверка на пустоту
bool Stack::SisEmpty() const {
    return top == -1; // Если индекс верхнего элемента -1, стек пуст
}

// Проверка на заполненность
bool Stack::SisFull() const {
    return top == maxSize - 1; // Если индекс верхнего элемента равен maxSize - 1, стек полный
}

// Метод для вывода элементов стека
void Stack::Sdisplay() const {
    if (SisEmpty()) {
        cout << "Стек пуст." << endl;
        return;
    }
    
    cout << "Элементы стека: ";
    for (int i = top; i >= 0; --i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}