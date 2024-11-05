
#include "Queue.h"
#include <stdexcept>

using namespace std;

// Конструктор
Queue::Queue(int size) : front(0), rear(0), maxSize(size) {
    arr = new int[maxSize]; // Выделение памяти для массива
}

// Деструктор
Queue::~Queue() {
    delete[] arr; // Освобождение памяти
}

// Добавление элемента
void Queue::Qpush(int value) {
    if (QisFull()) {
        cout << "Очередь переполнена!" << endl;
        return;
    }
    arr[rear] = value;
    rear = (rear + 1) % maxSize; // Циклическое увеличение индекса
}

// Удаление элемента
void Queue::Qpop() {
    if (QisEmpty()) {
        cout << "Очередь пуста!" << endl;
        return;
    }
    front = (front + 1) % maxSize; // Циклическое увеличение индекса
}

// Чтение элемента
int Queue::Qpeek() const {
    if (QisEmpty()) {
        throw runtime_error("Очередь пуста!");
    }
    return arr[front]; // Возврат переднего элемента
}

// Проверка на пустоту
bool Queue::QisEmpty() const {
    return front == rear; // Если индексы равны, очередь пуста
}

// Проверка на заполненность
bool Queue::QisFull() const {
    return (rear + 1) % maxSize == front; // Если следующий индекс rear равен front
}

void Queue::Qprint() const {
    if (QisEmpty()) {
        cout << "Очередь пуста" << endl;
        return;
    }

    cout << "Элементы очереди: ";
    for (int i = front; i != rear; i = (i + 1) % maxSize) {
        cout << arr[i] << " ";
    }
    cout << endl;
}