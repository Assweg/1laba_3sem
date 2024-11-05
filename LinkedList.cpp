#include <iostream>
#include "LinkedList.h"

using namespace std;

// Конструктор класса LinkedList
LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {
    // Инициализация: голова и хвост списка пусты, размер равен 0
}

// Деструктор класса LinkedList
LinkedList::~LinkedList() {
    // Удаляем все элементы списка
    while (head) {
        LdelFront(); // Вызов метода удаления первого элемента
    }
}

// Метод для добавления элемента в начало списка
void LinkedList::LpushFront(int element) {
    Node* newNode = new Node(element); // Создаем новый узел с данными
    if (!head) { // Если список пустой
        head = tail = newNode; // Голова и хвост указывают на новый узел
    } else { // Если список не пустой
        newNode->next = head; // Новый узел указывает на текущую голову
        head = newNode; // Голова теперь указывает на новый узел
    }
    size++; // Увеличиваем размер списка
}

// Метод для добавления элемента в конец списка
void LinkedList::LpushBack(int element) {
    Node* newNode = new Node(element); // Создаем новый узел
    if (!tail) { // Если список пустой
        head = tail = newNode; // Голова и хвост указывают на новый узел
    } else { // Если список не пустой
        tail->next = newNode; // Предыдущий хвост указывает на новый узел
        tail = newNode; // Хвост теперь указывает на новый узел
    }
    size++; // Увеличиваем размер списка
}

// Метод для удаления первого элемента списка
void LinkedList::LdelFront() {
    if (!head) return; // Если список пуст, ничего не делаем
    Node* temp = head; // Сохраняем текущую голову
    head = head->next; // Перемещаем голову на следующий узел
    delete temp; // Удаляем старую голову
    size--; // Уменьшаем размер списка
    if (!head) { // Если список стал пустым
        tail = nullptr; // Хвост также должен указывать на nullptr
    }
}

// Метод для удаления последнего элемента списка
void LinkedList::LdelBack() {
    if (!tail) return; // Если список пуст, ничего не делаем
    if (head == tail) { // Если есть только один элемент
        delete tail; // Удаляем элемент
        head = tail = nullptr; // Список становится пустым
    } else { // Если больше одного элемента
        Node* curr = head; // Начинаем с головы
        // Ищем предпоследний элемент
        while (curr->next != tail) {
            curr = curr->next; // Перемещаемся вперед
        }
        delete tail; // Удаляем последний узел
        tail = curr; // Обновляем хвост на предпоследний
        tail->next = nullptr; // Устанавливаем указатель на nullptr
    }
    size--; // Уменьшаем размер списка
}

// Метод для удаления элемента по значению из списка
void LinkedList::Ldel(int value) {
    if (!head) return; // Если список пуст, ничего не делаем
    if (head->data == value) { // Если элемент для удаления - голова
        LdelFront(); // Удаляем голову
        return; // Завершаем выполнение метода
    }
    Node* curr = head; // Начинаем с головы
    // Ищем элемент для удаления
    while (curr->next && curr->next->data != value) {
        curr = curr->next; // Перемещаемся вперед
    }
    if (curr->next) { // Если нашли элемент
        Node* temp = curr->next; // Сохраняем элемент для удаления
        curr->next = temp->next; // Пропускаем элемент, который удаляем
        delete temp; // Удаляем его
        size--; // Уменьшаем размер списка
        
        // Если удаленный элемент был хвостом, обновляем хвост
        if (!curr->next) { 
            tail = curr; 
        }
    }
}

// Метод для поиска элемента по значению
bool LinkedList::Lfind(int value) const {
    Node* curr = head; // Начинаем с головы
    while (curr) {
        if (curr->data == value) return true; // Возвращаем true, если нашли элемент
        curr = curr->next; // Продолжаем поиск
    }
    return false; // Если не нашли, возвращаем false
}

// Метод для вывода всех элементов списка
void LinkedList::Lprint() const {
    Node* curr = head; // Начинаем с головы
        while (curr) {
        cout << curr->data << " "; // Печатаем текущий элемент
        curr = curr->next; // Перемещаемся к следующему элементу
    }
    cout << endl; // Печатаем перевод строки
}