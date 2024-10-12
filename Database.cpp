#include "Database.h"
#include <filesystem>

Database::Database(const json& config) {
    schemaName = config["name"];
    initializeTables(config["structure"]);
}

Database::~Database() {
    for (auto& [name, table] : tables) {
        delete table;
    }
}

Table* Database::getTable(const std::string& tableName) {
    return tables.at(tableName);
}

const std::unordered_map<std::string, Table*>& Database::getTables() const {
    return tables;
}

void Database::initializeTables(const json& config) {
    std::filesystem::create_directory(schemaName);

    for (auto& [tableName, columns] : config.items()) {
        std::vector<std::string> columnNames = columns;
        columnNames.insert(columnNames.begin(), tableName + "_pk");
        tables[tableName] = new Table(schemaName, tableName, columnNames);
    }
}