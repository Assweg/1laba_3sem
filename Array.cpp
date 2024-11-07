#include <iostream>
#include <stdexcept>
#include "Array.h"
 
using namespace std;

// Конструктор класса Array
Array::Array() : size(0), capacity(10) {
    // Инициализируем текущий размер массива size(0) и вместимость capacity(10).
    data = new int[capacity]; // Выделяем память для массива с начальной вместимостью 10.
}

// Деструктор класса Array
Array::~Array() {
    delete[] data; // Освобождаем память, выделенную для массива.
}

// Метод для изменения размера массива
void Array::resize() {
    capacity *= 2; // Удваиваем текущую вместимость
    int* newData = new int[capacity]; // Создаем новый массив с увеличенной вместимостью
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i]; // Копируем старые данные в новый массив
    }
    delete[] data; // Освобождаем старый массив
    data = newData; // Перенаправляем указатель на новый массив
}

// Метод добавления элемента в конец массива
void Array::mpush(int element) {
    if (size == capacity) { // Проверяем, нужно ли увеличивать размер массива.
        resize();
    }
    data[size++] = element; // Добавляем элемент и увеличиваем размер.
}

// Метод вставки элемента по указанному индексу
void Array::minsert(int index, int element) {
    if (index < 0 || index > size) {
        throw out_of_range("Index out of range"); // Проверяем, находится ли индекс в допустимых пределах
    }
    if (size == capacity) {
        resize();
    }
    for (int i = size; i > index; --i) {
        data[i] = data[i - 1]; // Сдвигаем элементы вправо, чтобы освободить место для нового элемента
    }
    data[index] = element; // Вставляем новый элемент по заданному индексу
    size++; // Увеличиваем размер массива
}

// Метод удаления элемента по указанному индексу
void Array::mdel(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range"); // Проверяем, находится ли индекс в допустимых пределах
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1]; // Сдвигаем элементы влево, чтобы удалить элемент
    }
    size--; // Уменьшаем размер массива
}

// Метод для получения элемента по индексу
int Array::mprint(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range"); // Проверяем, находится ли индекс в допустимых пределах
    }
    return data[index]; // Возвращаем элемент по индексу
}

// Метод замены элемента по указанному индексу
void Array::mreplace(int index, int element) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range"); // Проверяем, находится ли индекс в допустимых пределах
    }
    data[index] = element; // Заменяем элемент по индексу
}

// Метод получения текущего размера массива
int Array::mlength() {
    return size; // Возвращаем текущее количество элементов
}

// Метод для печати содержимого массива
void Array::mget() const {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " "; // Выводим каждый элемент массива
    }
    cout << endl;
}


// Метод для считывания массива из файла
void Array::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        throw runtime_error("Unable to open file for reading");
    }
    
    int value;
    while (inFile >> value) {
        mpush(value); // Добавляем элементы в массив
    }
    inFile.close(); // Закрываем файл
}

// Метод для записи массива в файл
void Array::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        throw runtime_error("Unable to open file for writing");
    }
    
    for (int i = 0; i < size; ++i) {
        outFile << data[i] << " "; // Записываем каждый элемент массива в файл
    }
    outFile.close(); // Закрываем файл
}
