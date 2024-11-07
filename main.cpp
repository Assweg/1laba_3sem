#include <iostream>
#include "Array.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "HashTable.h"
#include "CompleteBinaryTree.h"

void printMainSelection() {
    cout << "Выберите тип хранения данных:\n";
    cout << "1. Массив\n";
    cout << "2. Односвязный список\n";
    cout << "3. Двусвязный список\n";
    cout << "4. Очередь\n";
    cout << "5. Стек\n";
    cout << "6. Хеш таблица\n";
    cout << "7. Деревья\n";
    cout << "8. Выход\n";
    cout << "Ваш выбор: ";
}

void ArrayMenu() {
    cout << "Выберите операцию:\n";
    cout << "1. Добавить элемент в конец\n";
    cout << "2. Вставить элемент по индексу\n";
    cout << "3. Удалить элемент по индексу\n";
    cout << "4. Заменить элемент по индексу\n";
    cout << "5. Вывести массив на экран\n";
    cout << "6. Получить элемент по индексу\n";
    cout << "7. Записать массив в файл\n";
    cout << "8. Выгрузить массив из файла\n";
    cout << "9. Узнать длину массива\n";
    cout << "10. Назад\n";
    cout << "Ваш выбор: ";
}

void LinkedListMenu() {
    cout << "Выберите операцию:\n";
    cout << "1. Добавить элемент в начало\n";
    cout << "2. Добавить элемент в конец\n";
    cout << "3. Удалить первый элемент\n";
    cout << "4. Удалить последний элемент\n";
    cout << "5. Удалить элемент по значению\n";
    cout << "6. Найти элемент по значению\n";
    cout << "7. Вывести список на экран\n";
    cout << "8. Записать односвязный список в файл\n";
    cout << "9. Выгрузить односвязный список из файла\n";
    cout << "10. Назад\n";
    cout << "Ваш выбор: ";
}

void DoublyLinkedListMenu() {
    cout << "Выберите операцию:\n";
    cout << "1. Добавить элемент в начало\n";
    cout << "2. Добавить элемент в конец\n";
    cout << "3. Удалить первый элемент\n";
    cout << "4. Удалить последний элемент\n";
    cout << "5. Удалить элемент по значению\n";
    cout << "6. Найти элемент по значению\n";
    cout << "7. Вывести список на экран\n";
    cout << "8. Записать двусвязный список в файл\n";
    cout << "9. Выгрузить двусвязный список из файла\n";
    cout << "10. Назад\n";
    cout << "Ваш выбор: ";
}

void QueueMenu() {
    cout << "Выберите операцию:\n";
    cout << "1. Добавить элемент\n";
    cout << "2. Удалить элемент\n";
    cout << "3. Вывести первый элемент очереди\n";
    cout << "4. Вывести очередь на экран\n";
    cout << "5. Считать очередь из файла\n";
    cout << "6. Записать очередь в файл\n";
    cout << "7. Назад\n";
    cout << "Ваш выбор: ";
}

void StackMenu() {
    cout << "Выберите операцию:\n";
    cout << "1. Добавить элемент\n";
    cout << "2. Удалить элемент\n";
    cout << "3. Прочитать элемент\n";
    cout << "4. Показать элементы стека\n";
    cout << "5. Считать стек из файла\n";
    cout << "6. Записать стек в файл\n";
    cout << "7. Назад\n";
    cout << "Ваш выбор: ";
}

void HashTableMenu() {
    cout << "Выберите операцию:\n";
    cout << "1. Добавить элемент\n";
    cout << "2. Получить элемент\n";
    cout << "3. Удалить элемент\n";
    cout << "4. Показать все элементы\n";
    cout << "5. Считать хеш таблицу из файла" << endl;
    cout << "6. Записать хеш таблицу в файл" << endl;
    cout << "7. Назад\n";
    cout << "Ваш выбор: ";
}

void CompleteBinaryTreeMenu() {
    cout << "Выберите операцию:\n";
    cout << "1. Добавить элемент\n";
    cout << "2. Поиск элемента\n";
    cout << "3. Проверить, является ли дерево полным\n";
    cout << "4. Показать дерево\n";
    cout << "5. Считать из файла\n";
    cout << "6. Записать в файл\n";
    cout << "7. Назад\n";
    cout << "Ваш выбор: ";
}

int main() {
    int mainChoice;

    while (true) {
        printMainSelection();
        cin >> mainChoice;

        if(mainChoice == 8) {
            cout << "Завершение программы...\n";
            break;
        }

        if (mainChoice == 1) {
            Array array;
            int choice;
            int element, index;
            string filename;

            while (true) {
                ArrayMenu();
                cin >> choice;

                if(choice == 10) {
                    break;
                }

                switch (choice) {
                    case 1:
                        cout << "Введите элемент для добавления: ";
                        cin >> element;
                        array.mpush(element);
                        break;

                    case 2:
                        cout << "Введите индекс и элемент для вставки: ";
                        cin >> index >> element;
                        try {
                            array.minsert(index, element);
                        } catch (const out_of_range& e) {
                            cerr << e.what() << endl;
                        }
                        break;

                    case 3:
                        cout << "Введите индекс для удаления: ";
                        cin >> index;
                        try {
                            array.mdel(index);
                        } catch (const out_of_range& e) {
                            cerr << e.what() << endl;
                        }
                        break;

                    case 4:
                        cout << "Введите индекс и новый элемент: ";
                        cin >> index >> element;
                        try {
                            array.mreplace(index, element);
                        } catch (const out_of_range& e) {
                            cerr << e.what() << endl;
                        }
                        break;

                    case 5:
                        cout << "Элементы массива: ";
                        array.mget();
                        break;

                    case 6: // Получить элемент по индексу
                        //int index;
                        cout << "Введите индекс элемента для получения: ";
                        cin >> index;
                        // Проверьте, что индекс находится в пределах допустимых значений
                        if (index < 0 || index >= array.mlength()) {
                            cout << "Ошибка: индекс выходит за пределы массива." << endl;
                        } else {
                            cout << "Элемент по индексу " << index << ": " << array.mprint(index) << endl; // Получение элемента
                        }
                        break;
                    
                    case 7: // Сохранить массив в файл
                        //string filename;
                        cout << "Введите имя файла для сохранения: ";
                        cin >> filename;
                        array.saveToFile(filename);
                        break;

                    case 8: // Загрузить массив из файла
                        //string filename;
                        cout << "Введите имя файла для загрузки: ";
                        cin >> filename;
                        array.loadFromFile(filename);
                        break;

                    case 9:
                        cout << "Длина массива: " << array.mlength() << endl;
                        break;

                    default:
                        cout << "Некорректный выбор, попробуйте снова.\n";
                        break;
                }
            }
        }
        if (mainChoice == 2) {
            LinkedList list; // Создаем экземпляр списка
            int choice;
            int value;
            string filename;

            while (true) {
                LinkedListMenu(); // Показываем меню
                cin >> choice; // Читаем выбор пользователя

                if(choice == 10) {
                    break;
                }

                switch (choice) {
                    case 1:
                        cout << "Введите значение для добавления в начало: ";
                        cin >> value;
                        list.LpushFront(value); // Добавление в начало
                        break;

                    case 2:
                        cout << "Введите значение для добавления в конец: ";
                        cin >> value;
                        list.LpushBack(value); // Добавление в конец
                        break;

                    case 3:
                        list.LdelFront(); // Удаление первого элемента
                        cout << "Первый элемент удален.\n";
                        break;

                    case 4:
                        list.LdelBack(); // Удаление последнего элемента
                        cout << "Последний элемент удален.\n";
                        break;

                    case 5:
                        cout << "Введите значение для удаления: ";
                        cin >> value;
                        list.Ldel(value); // Удаление элемента по значению
                        cout << "Элемент " << value << " удален.\n";
                        break;

                    case 6:
                        cout << "Введите значение для поиска: ";
                        cin >> value;
                        if (list.Lfind(value)) {
                            cout << "Элемент " << value << " найден в списке.\n";
                        } else {
                            cout << "Элемент " << value << " не найден в списке.\n";
                        }
                        break;

                    case 7:
                        cout << "Элементы списка: ";
                        list.Lprint(); // Печать списка
                        break;
                    case 8:
                        cout << "Введите имя файла для записи: ";
                        cin >> filename;
                        list.writeToFile(filename);
                        break;

                    case 9:
                        cout << "Введите имя файла для чтения: ";
                        cin >> filename;
                        list.readFromFile(filename);
                        break;
                    
                    default:
                        cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
                        break;
                }
            }
        }
        if (mainChoice == 3) {
            DoublyLinkedList list; // Создаем экземпляр списка
            int choice;
            int value;
            string filename;

            while (true) {
                DoublyLinkedListMenu(); // Показываем меню
                cin >> choice; // Читаем выбор пользователя

                if(choice == 10) {
                    break;
                }

                switch (choice) {
                    case 1:
                        cout << "Введите значение для добавления в начало: ";
                        cin >> value;
                        list.LpushFront2(value); // Добавление в начало
                        break;

                    case 2:
                        cout << "Введите значение для добавления в конец: ";
                        cin >> value;
                        list.LpushBack2(value); // Добавление в конец
                        break;

                    case 3:
                        list.LdelFront2(); // Удаление первого элемента
                        cout << "Первый элемент удален.\n";
                        break;

                    case 4:
                        list.LdelBack2(); // Удаление последнего элемента
                        cout << "Последний элемент удален.\n";
                        break;

                    case 5:
                        cout << "Введите значение для удаления: ";
                        cin >> value;
                        list.Ldel2(value); // Удаление элемента по значению
                        cout << "Элемент " << value << " удален.\n";
                        break;

                    case 6:
                        cout << "Введите значение для поиска: ";
                        cin >> value;
                        if (list.Lfind2(value)) {
                            cout << "Элемент " << value << " найден в списке.\n";
                        } else {
                            cout << "Элемент " << value << " не найден в списке.\n";
                        }
                        break;

                    case 7:
                        cout << "Элементы списка: ";
                        list.Lprint2(); // Печать списка
                        break;

                    case 8:
                        cout << "Введите имя файла для записи: ";
                        cin >> filename;
                        try {
                            list.LwriteToFile2(filename);
                            cout << "Список успешно записан в файл.\n";
                        } catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        break;

                    case 9:
                        cout << "Введите имя файла для считывания: ";
                        cin >> filename;
                        try {
                            list.LreadFromFile2(filename);
                            cout << "Список успешно считан из файла.\n";
                        } catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        break;

                    default:
                        cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
                        break;
                }
            }
        }
        if (mainChoice == 4) {
            int size;
            cout << "Введите размер очереди: ";
            cin >> size;

            Queue queue(size); // Создаём очередь определённого размера
            int choice;
            string filename;

            while (true) {
                QueueMenu(); // Показываем меню
                cin >> choice; // Читаем выбор пользователя

                if(choice == 7) {
                    break;
                }

                switch (choice) {
                    case 1: { // Добавление элемента
                    int value;
                    cout << "Введите значение для добавления: ";
                    cin >> value;
                    queue.Qpush(value);
                    break;
            }
                    case 2: // Удаление элемента
                        queue.Qpop();
                        break;
                    case 3: { // Чтение элемента
                        try {
                            int frontValue = queue.Qpeek();
                            cout << "Элемент на переднем плане: " << frontValue << endl;
                        } catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        break;
                    }
                    case 4:
                        queue.Qprint();
                        break;

                    case 5:
                        cout << "Введите имя файла для считывания: ";
                        cin >> filename;
                        try {
                            queue.QreadFromFile(filename);
                            cout << "Очередь успешно считана из файла.\n";
                        } catch (runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        break;

                    case 6:
                        cout << "Введите имя файла для записи: ";
                        cin >> filename;
                        try {
                            queue.QwriteToFile(filename);
                            cout << "Очередь успешно записана в файл.\n";
                        } catch (runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        break;

                    default: // Неверный выбор
                        cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
                }
            }
        }
        if (mainChoice == 5) {
            int size;
            cout << "Введите размер стека: ";
            cin >> size;

            Stack stack(size); // Создаём стек определённого размера
            int choice;
            string filename;

            while (true) {
                StackMenu();
                cin >> choice;

                if(choice == 7) {
                    break;
                }

                switch (choice) {
                    case 1: { // Добавление элемента
                        int value;
                        cout << "Введите значение для добавления: ";
                        cin >> value;
                        stack.Spush(value);
                        break;
                    }
                    case 2: // Удаление элемента
                        stack.Spop();
                        break;
                    case 3: { // Чтение элемента
                        try {
                            int topValue = stack.Speek();
                            cout << "Верхний элемент: " << topValue << endl;
                        } catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        break;
                    }
                    case 4: // Показать элементы стека
                        stack.Sdisplay();
                        break;

                    case 5:
                        cout << "Введите имя файла для считывания: ";
                        cin >> filename;
                        try {
                            stack.SreadFromFile(filename);
                            cout << "Стек успешно считан из файла.\n";
                        } catch (runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        break;

                    case 6:
                        cout << "Введите имя файла для записи: ";
                        cin >> filename;
                        try {
                            stack.SwriteToFile(filename);
                            cout << "Стек успешно записан в файл.\n";
                        } catch (runtime_error& e) {
                            cout << e.what() << endl;
                        }
                        break;

                    default: // Неверный выбор
                        cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
                }
            }
        }
        if (mainChoice == 6) {
            HashTable table;
            int choice;
            string key, value, filename;

            while (true) {
                HashTableMenu();
                cin >> choice;

                if(choice == 7) {
                    break;
                }

                switch (choice) {
                    case 1: // Добавить элемент
                        cout << "Введите ключ: ";
                        cin >> key;
                        cout << "Введите значение: ";
                        cin >> value;
                        table.Hinsert(key, value);
                        cout << "Элемент добавлен.\n";
                        break;

                    case 2: // Получить элемент
                        cout << "Введите ключ: ";
                        cin >> key;
                        if (table.Hget(key, value)) {
                            cout << "Значение: " << value << endl;
                        } else {
                            cout << "Ключ не найден.\n";
                        }
                        break;

                    case 3: // Удалить элемент
                        cout << "Введите ключ: ";
                        cin >> key;
                        if (table.Hdel(key)) {
                            cout << "Элемент удалён.\n";
                        } else {
                            cout << "Ключ не найден.\n";
                        }
                        break;

                    case 4: // Показать все элементы
                        table.Hprint();
                        break;

                    case 5:
                        cout << "Введите имя файла для считывания: ";
                        cin >> filename;
                        try {
                            table.HreadFromFile(filename);
                            cout << "Данные считаны из файла." << endl;
                        } catch (const runtime_error &e) {
                            cout << e.what() << endl;
                        }
                        break;
                    case 6:
                        cout << "Введите имя файла для записи: ";
                        cin >> filename;
                        try {
                            table.HwriteToFile(filename);
                            cout << "Данные записаны в файл." << endl;
                        } catch (const runtime_error &e) {
                            cout << e.what() << endl;
                        }
                        break;

                    default:
                        cout << "Неверный выбор. Попробуйте снова.\n";
                        break;
                }
            }
        }
        if (mainChoice == 7) {
            int capacity;
            cout << "Введите вместимость дерева: ";
            cin >> capacity;

            CompleteBinaryTree tree(capacity);

            int choice, value;
            string filename;

            while (true) {
                CompleteBinaryTreeMenu(); // Показываем меню
                cin >> choice; // Читаем выбор пользователя

                if(choice == 7) {
                    break;
                }

                switch (choice) {
                    case 1: // Добавление элемента
                        cout << "Введите значение: ";
                        cin >> value;
                        tree.Tinsert(value);
                        cout << "Элемент добавлен.\n";
                        break;

                    case 2: // Поиск элемента
                        cout << "Введите значение: ";
                        cin >> value;
                        if (tree.Tsearch(value)) {
                            cout << "Элемент найден.\n";
                        } else {
                            cout << "Элемент не найден.\n";
                        }
                        break;

                    case 3: // Проверка на полное двоичное дерево
                        if (tree.TisComplete()) {
                            cout << "Дерево является полным.\n";
                        } else {
                            cout << "Дерево не является полным.\n";
                        }
                        break;

                    case 4: // Показать дерево
                        cout << "Дерево:\n";
                        tree.Tprint();
                        break;

                    case 5:
                        cout << "Введите имя файла для чтения: ";
                        cin >> filename;
                        tree.TreadFromFile(filename);
                        break;
                    
                    case 6:
                        cout << "Введите имя файла для записи: ";
                        cin >> filename;
                        tree.TwriteToFile(filename);
                        break;    

                    default:
                        cout << "Неверный выбор. Попробуйте снова.\n";
                        break;
                }
            }
        }
    }
}