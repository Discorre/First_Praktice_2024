#include "QueryProcessor.h"
#include <sstream>
#include <iostream>
#include <algorithm>

QueryProcessor::QueryProcessor(Database& db) : db(db) {}

void QueryProcessor::processQuery(const std::string& query) {
    if (query.substr(0, 6) == "SELECT") {
        processSelect(query);
    } else if (query.substr(0, 6) == "INSERT") {
        processInsert(query);
    } else if (query.substr(0, 6) == "DELETE") {
        processDelete(query);
    } else {
        std::cerr << "Неподдерживаемый тип запроса." << std::endl;
    }
}

void QueryProcessor::processSelect(const std::string& query) {
    // Разбор запроса SELECT
    std::stringstream ss(query);
    std::string token;
    std::vector<std::string> tokens;

    while (ss >> token) {
        tokens.push_back(token);
    }

    if (tokens.size() < 4 || tokens[0] != "SELECT" || tokens[2] != "FROM") {
        std::cerr << "Неверный формат запроса SELECT." << std::endl;
        return;
    }

    // Извлечение имен колонок
    std::vector<std::string> columnNames;
    std::string columns = tokens[1];
    size_t start = 0, end;
    while ((end = columns.find(',', start)) != std::string::npos) {
        columnNames.push_back(columns.substr(start, end - start));
        start = end + 1;
    }
    columnNames.push_back(columns.substr(start));

    // Извлечение имен таблиц
    std::vector<std::string> tableNames;
    std::string tables = tokens[3];
    start = 0;
    while ((end = tables.find(',', start)) != std::string::npos) {
        tableNames.push_back(tables.substr(start, end - start));
        start = end + 1;
    }
    tableNames.push_back(tables.substr(start));

    // Извлечение условия (если есть)
    std::string condition;
    if (tokens.size() > 5 && tokens[4] == "WHERE") {
        condition = tokens[5];
    }

    // Выполнение запроса
    for (const auto& tableName : tableNames) {
        Table* table = db.getTable(tableName);
        if (table) {
            std::vector<std::vector<std::string>> result = table->select(columnNames, condition);
            for (const auto& row : result) {
                for (const auto& value : row) {
                    std::cout << value << " ";
                }
                std::cout << std::endl;
            }
        } else {
            std::cerr << "Таблица " << tableName << " не найдена." << std::endl;
        }
    }
}

void QueryProcessor::processInsert(const std::string& query) {
    std::stringstream ss(query);
    std::string token;
    std::vector<std::string> tokens;

    while (ss >> token) {
        tokens.push_back(token);
    }

    if (tokens.size() < 4 || tokens[0] != "INSERT" || tokens[1] != "INTO" || tokens[3] != "VALUES") {
        std::cerr << "Неверный формат запроса INSERT." << std::endl;
        return;
    }

    std::string tableName = tokens[2];

    // Извлечение значений и удаление скобок
    std::string valuesStr = tokens[4];
    if (valuesStr.front() == '(' && valuesStr.back() == ')') {
        valuesStr = valuesStr.substr(1, valuesStr.size() - 2); // Убираем скобки
    }

    std::vector<std::string> values;
    size_t start = 0, end;
    while ((end = valuesStr.find(',', start)) != std::string::npos) {
        values.push_back(valuesStr.substr(start, end - start));
        start = end + 1;
    }
    values.push_back(valuesStr.substr(start));

    // Удаление лишних пробелов
    for (auto& value : values) {
        value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
    }

    // Выполнение запроса
    Table* table = db.getTable(tableName);
    if (table) {
        table->insert(values);
    } else {
        std::cerr << "Таблица " << tableName << " не найдена." << std::endl;
    }
}


void QueryProcessor::processDelete(const std::string& query) {
    // Разбор запроса DELETE
    std::stringstream ss(query);
    std::string token;
    std::vector<std::string> tokens;

    while (ss >> token) {
        tokens.push_back(token);
    }

    if (tokens.size() < 6 || tokens[0] != "DELETE" || tokens[1] != "FROM" || tokens[3] != "WHERE") {
        std::cerr << "Неверный формат запроса DELETE." << std::endl;
        return;
    }

    // Извлечение имени таблицы
    std::string tableName = tokens[2];

    // Извлечение колонки и значения условия
    std::string columnName = tokens[4]; // Предполагаем, что колонка указана сразу после WHERE
    std::string conditionValue = tokens[5]; // Значение для условия

    // Выполнение запроса
    Table* table = db.getTable(tableName);
    if (table) {
        table->remove(columnName, conditionValue);
    } else {
        std::cerr << "Таблица " << tableName << " не найдена." << std::endl;
    }
}
