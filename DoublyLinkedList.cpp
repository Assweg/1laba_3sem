#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

// Конструктор инициализирует список с нулевыми указателями на начало и конец, и нулевым размером.
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Деструктор последовательно удаляет все элементы из списка, освобождая память.
DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        LdelFront2(); // Удаление первого элемента до тех пор, пока список не станет пустым.
    }
}

// Добавляет новый элемент в начало списка.
void DoublyLinkedList::LpushFront2(int element) {
    Node2* newNode = new Node2(element); // Создаём новый узел с значением element.
    if (!head) { // Если список пустой, голова и хвост указывают на новый элемент.
        head = tail = newNode;
    } else { // Иначе, добавляем новый элемент перед текущей головой.
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++; // Увеличиваем размер списка.
}

// Добавляет новый элемент в конец списка.
void DoublyLinkedList::LpushBack2(int element) {
    Node2* newNode = new Node2(element);
    if (!tail) { // Если список пустой, голова и хвост указывают на новый элемент.
        head = tail = newNode;
    } else { // Иначе, добавляем новый элемент после текущего хвоста.
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++; // Увеличиваем размер списка.
}

// Удаляет первый элемент из списка.
void DoublyLinkedList::LdelFront2() {
    if (!head) return; // Если список пуст, ничего не делаем.
    Node2* temp = head;
    head = head->next; // Перемещаем голову на следующий элемент.
    if (head) {
        head->prev = nullptr; // Обнуляем предыдущий указатель новой головы.
    } else {
        tail = nullptr; // Если это был последний элемент, обнуляем хвост.
    }
    delete temp; // Освобождаем память.
    size--; // Уменьшаем размер списка.
}

// Удаляет последний элемент из списка.
void DoublyLinkedList::LdelBack2() {
    if (!tail) return; // Если список пуст, ничего не делаем.
    Node2* temp = tail;
    tail = tail->prev; // Перемещаем хвост на предыдущий элемент.
    if (tail) {
        tail->next = nullptr; // Обнуляем следующий указатель нового хвоста.
    } else {
        head = nullptr; // Если это был последний элемент, обнуляем голову.
    }
    delete temp; // Освобождаем память.
    size--; // Уменьшаем размер списка.
}

// Удаляет первый встреченный элемент со значением value.
void DoublyLinkedList::Ldel2(int value) {
    Node2* curr = head;
    while (curr) {
        if (curr->data == value) { // Если элементы совпали, удаляем элемент.
            if (curr == head) {
                LdelFront2(); // Если это голова, используем метод для удаления с начала.
            } else if (curr == tail) {
                LdelBack2(); // Если это хвост, используем метод для удаления с конца.
            } else { // Если элемент в середине.
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr; // Освобождаем память.
                size--; // Уменьшаем размер списка.
            }
            return; // Выходим после удаления элемента.
        }
        curr = curr->next; // Переходим к следующему элементу.
    }
}

// Определяет, содержится ли элемент со значением value в списке.
bool DoublyLinkedList::Lfind2(int value) const {
    Node2* curr = head;
    while (curr) {
        if (curr->data == value) return true; // Если элемент найден, возвращаем true.
        curr = curr->next; // Переходим к следующему элементу.
    }
    return false; // Если элемент не найден, возвращаем false.
}

// Печатает все элементы списка.
void DoublyLinkedList::Lprint2() const {
    Node2* curr = head;
    while (curr) {
        cout << curr->data << " "; // Печатаем значение текущего элемента.
        curr = curr->next; // Переходим к следующему элементу.
    }
        cout << endl;
}