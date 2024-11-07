#ifndef STACK_H
#define STACK_H

#include <iostream>

// Класс реализует стек (LIFO - Last In, First Out)
class Stack {
public:
    // Конструктор, который создаёт стек заданного размера
    Stack(int size);
    // Деструктор
    ~Stack();

    // Метод для добавления элемента в стек
    void Spush(int value);
    
    // Метод для удаления элемента из стека
    void Spop();
    
    // Метод для получения значения верхнего элемента без его удаления
    int Speek() const;
    
    // Метод для проверки, пуст ли стек
    bool SisEmpty() const;
    
    // Метод для проверки, заполнен ли стек
    bool SisFull() const;

    // Метод для вывода элементов стека
    void Sdisplay() const;

    void SreadFromFile(const std::string& filename);
    void SwriteToFile(const std::string& filename) const;

private:
    int* arr;      // Динамический массив для хранения элементов стека
    int top;       // Индекс верхнего элемента стека
    int maxSize;   // Максимальный размер стека
};

#endif
