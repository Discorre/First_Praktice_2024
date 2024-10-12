#include "Table.h"
#include <filesystem>
#include <sstream>
#include <fstream>
#include <iostream>

Table::Table(const std::string& schemaName, const std::string& tableName, const std::vector<std::string>& columns)
    : schemaName(schemaName), tableName(tableName), columns(columns) {
    createDirectoryAndFiles(); // Создаем директорию и файлы
}

Table::~Table() {}

void Table::insert(const std::vector<std::string>& values) {
    std::lock_guard<std::mutex> guard(lock);
    std::vector<std::string> row = {getNextPrimaryKey()}; // Генерация следующего первичного ключа
    row.insert(row.end(), values.begin(), values.end());
    writeToFile(row); // Запись строки в файл
}

void Table::remove(const std::string& columnName, const std::string& value) {
    std::lock_guard<std::mutex> guard(lock);

    // Читаем все строки из файла
    std::vector<std::vector<std::string>> rows = readFromFile("");

    // Находим индекс колонки для удаления
    int columnIndex = -1;
    for (size_t i = 0; i < columns.size(); ++i) {
        if (columns[i] == columnName) {
            columnIndex = static_cast<int>(i);
            break;
        }
    }

    // Если колонка не найдена, просто выходим из метода
    if (columnIndex == -1) {
        std::cerr << "Колонка " << columnName << " не найдена." << std::endl;
        return;
    }

    // Сохраняем новые строки, которые не соответствуют условию удаления
    std::vector<std::vector<std::string>> newRows;
    for (const auto& row : rows) {
        // Проверяем, соответствует ли значение в указанной колонке значению для удаления
        if (row[columnIndex] != value) {
            newRows.push_back(row);
        }
    }

    // Записываем обновленные строки обратно в файл
    writeToFile(newRows);
}


std::vector<std::vector<std::string>> Table::select(const std::vector<std::string>& columnNames, const std::string& condition) {
    return readFromFile(condition);
}

std::string Table::getNextPrimaryKey() {
    std::string pkFile = schemaName + "/" + tableName + "/" + tableName + "_pk_sequence";
    std::ifstream in(pkFile);
    int pk = 1; // Начинаем с 1
    if (in.is_open()) {
        in >> pk; // Читаем текущее значение первичного ключа
    }
    in.close();

    std::ofstream out(pkFile);
    out << pk + 1; // Увеличиваем первичный ключ на 1
    out.close();

    return std::to_string(pk); // Возвращаем текущее значение первичного ключа
}

void Table::writeToFile(const std::vector<std::string>& values) {
    std::string filePath = schemaName + "/" + tableName + "/" + tableName[tableName.size()-1] + ".csv";
    std::ofstream file(filePath, std::ios::app); // Открываем файл в режиме добавления
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для записи: " << filePath << std::endl;
        return;
    }
    for (size_t i = 0; i < values.size(); ++i) {
        file << values[i];
        if (i < values.size() - 1) {
            file << ",";
        }
    }
    file << "\n"; // Переход на новую строку
    file.close(); // Закрываем файл
}

void Table::writeToFile(const std::vector<std::vector<std::string>>& rows) {
    std::string filePath = schemaName + "/" + tableName + "/" + tableName[tableName.size()-1] + ".csv";
    std::ofstream file(filePath, std::ios::app); // Открываем файл в режиме добавления
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для записи: " << filePath << std::endl;
        return;
    }
    for (const auto& row : rows) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) {
                file << ",";
            }
        }
        file << "\n"; // Переход на новую строку
    }
    file.close(); // Закрываем файл
}

std::vector<std::vector<std::string>> Table::readFromFile(const std::string& condition) {
    std::vector<std::vector<std::string>> result;
    std::string filePath = schemaName + "/" + tableName + "/" + tableName[tableName.size()-1] + ".csv";
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения: " << filePath << std::endl;
        return result; // Возвращаем пустой результат, если файл не открыт
    }
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string item;
        while (std::getline(ss, item, ',')) {
            row.push_back(item);
        }
        result.push_back(row); // Добавляем строку в результат
    }
    file.close(); // Закрываем файл
    return result; // Возвращаем прочитанные строки
}

void Table::createDirectoryAndFiles() {
    std::filesystem::create_directory(schemaName);
    std::filesystem::create_directory(schemaName + "/" + tableName);

    // Создаем файл для первичного ключа, если он не существует
    std::string pkFile = schemaName + "/" + tableName + "/" + tableName + "_pk_sequence";
    std::ifstream in(pkFile);
    if (!in.is_open()) {
        std::ofstream pkStream(pkFile);
        pkStream << "1"; // Начинаем с первичного ключа 1
        pkStream.close();
    }

    // Создаем файл CSV, если он не существует
    std::string csvFile = schemaName + "/" + tableName + "/" + tableName[tableName.size()-1] + ".csv";
    std::ofstream csvStream(csvFile, std::ios::app); // Открываем в режиме добавления
    if (!csvStream.is_open()) {
        std::cerr << "Не удалось создать файл: " << csvFile << std::endl;
    }
    csvStream.close(); // Закрываем файл
}
