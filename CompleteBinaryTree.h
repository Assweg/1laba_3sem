#ifndef COMPLETE_BINARY_TREE_H
#define COMPLETE_BINARY_TREE_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip> // Для форматирования вывода
#include <cmath>   // Для функции pow

// Класс для представления полного бинарного дерева
class CompleteBinaryTree {
public:
    // Конструктор, который создаёт полное бинарное дерево с заданной вместимостью
    CompleteBinaryTree(int capacity);
    // Деструктор для освобождения ресурсов
    ~CompleteBinaryTree();

    // Метод для вставки элемента в дерево
    void Tinsert(int value);

    // Метод для поиска элемента в дереве
    bool Tsearch(int value) const;

    // Метод для проверки, является ли дерево полным
    bool TisComplete() const;

    // Метод для печати дерева в виде структурированного вывода
    void Tprint() const;
    void TreadFromFile(const std::string &filename);
    void TwriteToFile(const std::string &filename) const;

private:
    int *tree;         // Массив для хранения элементов дерева
    int capacity;      // Вместимость дерева (максимальное количество элементов)
    int size;          // Текущий размер дерева (количество элементов)

    // Вспомогательная функция для рекурсивной печати дерева
    // index - индекс текущего элемента, indent - отступ для форматирования
    void printTree(int index, int indent) const;
};

#endif