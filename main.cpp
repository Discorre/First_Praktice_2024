#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Database.h"
#include "QueryProcessor.h"

using json = nlohmann::json;

int main() {
    system("chcp 65001");
    // Чтение конфигурации из файла schema.json
    std::ifstream configFile("C:\\Users\\Dom\\CLionProjects\\First_Praktice_2024\\schema.json");
    json config;
    configFile >> config;

    // Инициализация базы данных
    Database db(config);

    // Пример запроса SELECT для проверки вставленных данных
    std::string selectQuery = "SELECT table1.col1,table1.col2 FROM table1";

    // Обработка запроса SELECT
    QueryProcessor processor(db);
    //processor.processQuery(selectQuery);

    // Пример запроса INSERT
    std::string insertQuery = "INSERT INTO table1 VALUES (value1,value2,value3)";

    // Обработка запроса INSERT
    processor.processQuery(insertQuery);

    /*std::string insertQuery2 = "INSERT INTO table2 VALUES (value12,value23)";

    QueryProcessor processor2(db);
    processor2.processQuery(insertQuery2);*/

    // Обработка запроса SELECT
    processor.processQuery(selectQuery);

    // Пример запроса DELETE
    std::string deleteQuery = "DELETE FROM table1 WHERE column1 = value1";

    // Обработка запроса DELETE
    //processor.processQuery(deleteQuery);

    std::cout << std::endl;
    // Пример запроса SELECT для проверки удаленных данных
    //processor.processQuery(selectQuery);

    return 0;
}