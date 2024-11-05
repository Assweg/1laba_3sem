#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
public:
    int data;         // Данные узла
    Node* next;       // Указатель на следующий узел

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;       // Указатель на голову списка
    Node* tail;       // Указатель на хвост списка
    int size;         // Текущий размер списка

public:
    LinkedList();      // Конструктор
    ~LinkedList();     // Деструктор

    void LpushFront(int element);         // Добавление элемента в голову
    void LpushBack(int element);          // Добавление элемента в хвост
    void LdelFront();                     // Удаление элемента с головы
    void LdelBack();                      // Удаление элемента с хвоста
    void Ldel(int value);                 // Удаление элемента по значению
    bool Lfind(int value) const;          // Поиск элемента по значению
    void Lprint() const;                  // Чтение списка
};

#endif