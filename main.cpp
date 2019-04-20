#include <iostream>
#include <string>
#include <vector>
#include "Record.h"
#include "Database.h"

using namespace std;

int main(){
    int databaseSize{3}, numOfRecord{0};        //initialize the size of database, no. of records in database
    Database database(databaseSize);            //initialize the database
    
    
    Record acc1{10000, "USD", "F", "C", "001123456789", "11042019", "2300"};    //create a record
        
    database.addRecord(acc1, databaseSize, numOfRecord);        //add 1st record to database
    cout << numOfRecord << endl;                                //display the no. of records in database
    database.showDatabase(numOfRecord);                         //list all the records in databse
        
    database.addRecord(acc1, databaseSize, numOfRecord);        //add 2nd record to database
    cout << numOfRecord << endl;                                //display the no. of records in database
    database.showDatabase(numOfRecord);                         //list all the records in databse
    
    return 0;
}