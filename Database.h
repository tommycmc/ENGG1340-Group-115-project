#ifndef DATABASE_H
#define DATABASE_H

#include "Record.h"
#include <iostream>
#include <iomanip>

class Database {
private:
    Record *database;                                                           //create pointer to 1st record of database(record array)

public:
    //constructor
    Database(int &databaseSize);                                                //initialize the database with the given size

    //destructor
    ~Database();                                                                //destruct the database

        

    //getter function//
    Record *getAddress();                                                       //get the address of database(pointer to record array)
    Record getRecordFromDatabase(int &pos);                                     //get record from the database

    //setter function//
    void setNull();                                                             //set the database to NULL(pointer to record array = NULL)
    void manDelDatabase();                                                      //manually delete database


    //display function//
    void displayRecordWithPos(int &i);                                          //display 
    void showDatabase(int &numOfRecord, int choice);                            //display all the records in the database, with specific sorting perference
    void showDatabase(int &numOfRecord);                                        //default - amount ASC
    

    //insert function//
    void insertBackRecordWithoutEnlarge(Record &newRecord, int &numOfRecord, int &databaseSize);        
    void insertBackRecordWithEnlarge(Record &newRecord, int &numOfRecord, int &databaseSize);
    void addRecord(Record &newRecord, int &numOfRecord, int &databaseSize);                         //add record to the database
                                                                                                    //supports auto-enlargement
                                                                                                    //double the size of current database


    //edit function//
    void changeDataInRecord(int pos, double Amount_val, string Currency_val, string characterOfPayment_val, 
            string typeOfPayment_val, string accNoOfBank_val, string Date_val, string Time_val);
                                                                                //change the content of a record in given position of database

    //delete function//
    void skipRecord(int pos, int &numOfRecord, int &databaseSize);
    void deleteRecord(int pos, int &numOfRecord, int &databaseSize);


    //filter function//
    Database filterDatabaseAmount(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, const int min, const int max);
    
    bool filterMethodSeletor(const int &pos, const int &method, const string &keyword);
    Database filterDatabaseBykeyword(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int method, string keyword);
    
    bool filterDateTimeSelector(int &pos, int &year, int &month, int &day, int &hour, int &minute);
    Database filterDatabaseBothDateTime(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int year, int month, int day, int hour, int minute);
    Database filterDatabaseBothDateTime(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int year);
    Database filterDatabaseBothDateTime(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int year, int month);
    Database filterDatabaseBothDateTime(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int year, int month, int day);
    Database filterDatabaseBothDateTime(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int year, int month, int day, int hour);

    Database filterDatabaseExpense(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, const bool &expense);


    //sort function//
    bool amountCondAsc(int &i, int &j);
    bool amountCondDesc(int &i, int &j);
    bool characterOfPaymentCondAsc(int &i, int &j);                                //condition for sort function
    bool characterOfPaymentCondDesc(int &i, int &j); 
    bool typeOfPaymentCondAsc(int &i, int &j);
    bool typeOfPaymentCondDesc(int &i, int &j);
    bool dateAndTimeCondAsc(int &i, int &j);     
    bool dateAndTimeCondDesc(int &i, int &j);

    bool sortSelector(int &i, int &j, int &choice);

    void singleMerge(int left, int mid, int right, int &choice);
    void recurseMerge(int left, int right, int &choice);
    void sortDatabase(int numOfRecord, int choice);                            //use merge sort to sort the records in database based on some criteria
    
    
    //aggregate fucniton//
    double SUM(const int &numOfRecord);
    double SUM(const int &numOfRecord, const int year, const int month);
    double SUM(const int &numOfRecord, const int year);
    double SUMExpense(const int &numOfRecord, const bool &expense);
    double SUMExpense(const int &numOfRecord, const bool &expense, const int year, const int month);
    double SUMExpense(const int &numOfRecord, const bool &expense, const int year);
    double SUMExpenseByCharacter(const int &numOfRecord, const int &method, const string &keyword);
    double SUMExpenseByCharacter(const int &numOfRecord, const int &method, const string &keyword, const int year, const int month);
    double SUMExpenseByCharacter(const int &numOfRecord, const int &method, const string &keyword, const int year);
    double AVERAGE(const int &numOfRecord);
    double AVERAGE(const int &numOfRecord, const int year, const int month);
    double AVERAGE(const int &numOfRecord, const int year);
    double AVERAGEExpense(const int &numOfRecord, const bool &expense);
    double AVERAGEExpense(const int &numOfRecord, const bool &expense, const int year, const int month);
    double AVERAGEExpense(const int &numOfRecord, const bool &expense, const int year);
    double MEDIAN(const int &numOfRecord);
    double MEDIAN(const int &numOfRecord, const int year, const int month);                     
    double MEDIAN(const int &numOfRecord, const int year); 
    double MEDIANExpense(const int &numOfRecord, const bool &expense);
    double MEDIANExpense(const int &numOfRecord, const bool &expense, const int year, const int month);
    double MEDIANExpense(const int &numOfRecord, const bool &expense, const int year);
    double MIN(const int &numOfRecord);
    double MIN(const int &numOfRecord, const int year, const int month);
    double MIN(const int &numOfRecord, const int year);
    double MAX(const int &numOfRecord);
    double MAX(const int &numOfRecord, const int year, const int month);
    double MAX(const int &numOfRecord, const int year);
    double MINExpense(const int &numOfRecord, const bool &expense);
    double MINExpense(const int &numOfRecord, const bool &expense, const int year, const int month);
    double MINExpense(const int &numOfRecord, const bool &expense, const int year);
    double MAXExpense(const int &numOfRecord, const bool &expense);
    double MAXExpense(const int &numOfRecord, const bool &expense, const int year, const int month);
    double MAXExpense(const int &numOfRecord, const bool &expense, const int year);
    
    double percentageExpenseByCharacter(const int &numOfRecord, const int &method, const string &keyword);





};

#endif // DATABASE_H
