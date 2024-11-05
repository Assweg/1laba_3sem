#ifndef HASHTABLE_H
#define HASHTABLE_H

using namespace std;

#include <iostream>
#include <string> 

// Константа для определения размера таблицы
const int TABLE_SIZE = 10;

// Структура для представления узла в хеш-таблице
struct NodeH {
    string key;     // Ключ узла
    string value;   // Значение узла
    NodeH* next;    // Указатель на следующий узел (для цепочечного разрешения коллизий)

    // Конструктор для инициализации узла с заданным ключом и значением
    NodeH(const string &k, const string &v) : key(k), value(v), next(nullptr) {}
};

// Класс для реализации хеш-таблицы
class HashTable {
public:
    // Конструктор хеш-таблицы
    HashTable();
    
    // Деструктор хеш-таблицы для очистки ресурсов
    ~HashTable();
    
    // Метод для добавления или обновления элемента в хеш-таблице
    void Hinsert(const string &key, const string &value);
    
    // Метод для получения значения по ключу
    bool Hget(const string &key, string &value);
    
    // Метод для удаления элемента по ключу
    bool Hdel(const string &key);
    
    // Метод для отображения всех элементов в хеш-таблице
    void Hprint() const;

private:
    // Хеш-функция для получения индекса по ключу
    size_t hash(const string &key) const;

    // Массив указателей на узлы для представления хеш-таблицы
    NodeH* table[TABLE_SIZE];
};

#endif