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

    void Qpush(int value);  // Метод для добавления элемента в конец очереди
    void Qpop();    // Метод для удаления элемента из начала очереди    
    int Qpeek() const;  // Метод для получения значения переднего элемента без его удаления
    bool QisEmpty() const;  // Метод для проверки, пуста ли очередь
    bool QisFull() const;   // Метод для проверки, заполнена ли очередь
    void Qprint() const;    // Метод для вывода элементов очереди
    void QreadFromFile(const std::string& filename);
    void QwriteToFile(const std::string& filename) const;

private:
    int* arr;      // Динамический массив для хранения элементов очереди
    int front;     // Индекс переднего элемента очереди
    int rear;      // Индекс заднего элемента очереди
    int maxSize;   // Максимальный размер очереди
};

#endif
