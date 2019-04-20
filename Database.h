#ifndef DATABASE_H
#define DATABASE_H

#include "Record.h"

class Database {
private:
    Record *database;               //create pointer to 1st record of record array

public:
    //constructor
    Database(int &databaseSize);            //initialize the database with the size
    
    //destructor
    ~Database();                        //destruct the database

    //add record to database
    void addRecord(Record &newRecord, int &databaseSize, int &numOfRecord);
    
    //display the records in database
    void showDatabase(int &numOfRecord);


};

#endif // DATABASE_H
