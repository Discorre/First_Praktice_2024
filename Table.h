#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include <fstream>
#include <mutex>

class Table {
public:
    // Конструктор: создает таблицу с заданными именем схемы, именем таблицы и вектором имен столбцов
    Table(const std::string& schemaName, const std::string& tableName, const std::vector<std::string>& columns);
    ~Table(); // Деструктор

    // Метод для вставки строки данных в таблицу
    void insert(const std::vector<std::string>& values);

    // Метод для удаления строк из таблицы на основе значения в указанном столбце
    void remove(const std::string& columnName, const std::string& value);

    // Метод для выборки данных из таблицы на основе условия
    std::vector<std::vector<std::string>> select(const std::vector<std::string>& columnNames, const std::string& condition);

private:
    std::string schemaName; // Имя схемы
    std::string tableName;  // Имя таблицы
    std::vector<std::string> columns; // Вектор имен столбцов
    std::mutex lock; // Мьютекс для защиты данных в многопоточной среде

    // Вспомогательные методы
    std::string getNextPrimaryKey(); // Генерирует следующий первичный ключ
    void writeToFile(const std::vector<std::string>& values); // Записывает одну строку в файл
    void writeToFile(const std::vector<std::vector<std::string>>& rows); // Записывает несколько строк в файл
    std::vector<std::vector<std::string>> readFromFile(const std::string& condition); // Читает строки из файла
    void createDirectoryAndFiles(); // Создает директории и файлы для таблицы
};

#endif // TABLE_H
