#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

// Класс реализует очередь (FIFO - First In, First Out)
class Queue {
public:
    // Конструктор, который создаёт очередь заданного размера
    Queue(int size);
    // Деструктор
    ~Queue();

    // Метод для добавления элемента в конец очереди
    void Qpush(int value);

    // Метод для удаления элемента из начала очереди
    void Qpop();
    
    // Метод для получения значения переднего элемента без его удаления
    int Qpeek() const;

    // Метод для проверки, пуста ли очередь
    bool QisEmpty() const;

    // Метод для проверки, заполнена ли очередь
    bool QisFull() const;
    
    // Метод для вывода элементов очереди
    void Qprint() const;

private:
    int* arr;      // Динамический массив для хранения элементов очереди
    int front;     // Индекс переднего элемента очереди
    int rear;      // Индекс заднего элемента очереди
    int maxSize;   // Максимальный размер очереди
};

#endif
