#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
    int* data;           // Указатель на массив
    int size;            // Текущий размер массива
    int capacity;        // Вместимость массива

    void resize();       // Метод для изменения размера массива

public:
    Array();             // Конструктор
    ~Array();            // Деструктор

    void mpush(int element);                // Добавление элемента в конец
    void minsert(int index, int element);   // Добавление элемента по индексу
    void mdel(int index);                   // Удаление элемента по индексу
    int mprint(int index) const;            // Получение элемента по индексу
    void mreplace(int index, int element);  // Замена элемента по индексу
    int mlength() const;                    // Узнать длину массива
    void mget() const;                      // Чтение массива
};

#endif