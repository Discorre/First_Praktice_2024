#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#include "Database.h"

class QueryProcessor {
public:
    QueryProcessor(Database& db);
    void processQuery(const std::string& query);

private:
    Database& db;

    void processSelect(const std::string& query);
    void processInsert(const std::string& query);
    void processDelete(const std::string& query);
};

#endif // QUERYPROCESSOR_H