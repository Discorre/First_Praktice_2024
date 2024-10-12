#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include "Table.h"

using json = nlohmann::json;

class Database {
public:
    Database(const json& config);
    ~Database();

    Table* getTable(const std::string& tableName);
    const std::unordered_map<std::string, Table*>& getTables() const;

private:
    std::string schemaName;
    std::unordered_map<std::string, Table*> tables;

    void initializeTables(const json& config);
};

#endif // DATABASE_H