#ifndef DATABASE_H
#define DATABASE_H

#include "Record.h"

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
    void showDatabase(int &numOfRecord);                                        //display all the records in the database
    

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
    void filterShowDatabase(const int &numOfRecord, const int &choice);


    //sort function//
    bool characterOfPaymentCond(int &i, int &j);                                //condition for sort function
    bool typeOfPaymentCond(int &i, int &j);
    bool dateAndTimeCond(int &i, int &j);                           

    bool sortSelector(int &i, int &j, int &choice);

    void singleMerge(int left, int mid, int right, int &choice);
    void recurseMerge(int left, int right, int &choice);
    void sortDatabase(int numOfRecord, int &choice);                            //use merge sort to sort the records in database based on some criteria
    

    










    




};

#endif // DATABASE_H
