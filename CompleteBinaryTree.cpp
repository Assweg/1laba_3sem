#include "CompleteBinaryTree.h"

using namespace std;

// Конструктор
CompleteBinaryTree::CompleteBinaryTree(int capacity) : capacity(capacity), size(0) {
    tree = new int[capacity]; // Выделяем память для массива
}

// Деструктор
CompleteBinaryTree::~CompleteBinaryTree() {
    delete[] tree; // Освобождаем память
}

// Функция для добавления элемента в полное двоичное дерево
void CompleteBinaryTree::Tinsert(int value) {
    if (size >= capacity) {
        cout << "Дерево переполнено!\n";
        return;
    }
    tree[size] = value; // Добавляем элемент в конец массива
    size++;
}

// Функция для поиска элемента в дереве
bool CompleteBinaryTree::Tsearch(int value) const {
    for (int i = 0; i < size; i++) {
        if (tree[i] == value) {
            return true; // Элемент найден
        }
    }
    return false; // Элемент не найден
}

// Функция для проверки, является ли дерево полным
bool CompleteBinaryTree::TisComplete() const {
    for (int i = 0; i < size; i++) {
        // Проверяем, что значения для левого и правого детей
        // находятся в пределах размерности дерева
        if ((2 * i + 1 < size && tree[2 * i + 1] == -1) ||
            (2 * i + 2 < size && tree[2 * i + 2] == -1)) {
            return false; // Не полное двоичное дерево
        }
    }
    return true; // Полное двоичное дерево
}

// Функция для вывода дерева
void CompleteBinaryTree::Tprint() const {
    if (size == 0) {
        cout << "Дерево пустое.\n";
        return;
    }
    printTree(0, 0); // Начинаем с корня дерева
}

// Вспомогательная функция для печати дерева
void CompleteBinaryTree::printTree(int index, int indent) const {
    if (index < size) {
        if (tree[index] != -1) {
            printTree(2 * index + 2, indent + 4); // Правое поддерево
            if (indent) {
                cout << setw(indent) << ' '; // Выравнивание
            }
            cout << tree[index] << "\n"; // Печатаем узел
            printTree(2 * index + 1, indent + 4); // Левое поддерево
        }
    }
}
