#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

class Node2 {
public:
    int data;             // Данные узла
    Node2* next;          // Указатель на следующий узел
    Node2* prev;          // Указатель на предыдущий узел

    Node2(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node2* head;          // Указатель на голову списка
    Node2* tail;          // Указатель на хвост списка
    int size;             // Текущий размер списка

public:
    DoublyLinkedList();      // Конструктор
    ~DoublyLinkedList();     // Деструктор

    void LpushFront2(int element);         // Добавление элемента в голову
    void LpushBack2(int element);          // Добавление элемента в хвост
    void LdelFront2();                     // Удаление элемента с головы
    void LdelBack2();                      // Удаление элемента с хвоста
    void Ldel2(int value);                 // Удаление элемента по значению
    bool Lfind2(int value) const;          // Поиск элемента по значению
    void Lprint2() const;                  // Чтение списка   
};

#endif 