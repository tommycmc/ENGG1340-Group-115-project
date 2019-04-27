#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Record.h"
#include "Database.h"
#include "utilityFunction.h"

using namespace std;

int main(){
    int databaseSize{3}, numOfRecord{0};                                                                //initialize the size of database, no. of records in database
    Database database(databaseSize);                                                                    //initialize the database
    
    
    Record acc1{10000, "USD", "F", "C", "001123456789", "11042018", "2300"};                            //initialize a record - for demonstration only//

    for(int i{0}; i<50; i++){
        Record acc{100000.0-i, "USD", "F", "C", "001123456789", "31032018", to_string(1259-i)};
        database.addRecord(acc, numOfRecord, databaseSize);                                             //add 50 records to database
    }                                                                                                   //initial size of database = 3
                                                                                                        //1st expansion of database = 6
                                                                                                        //2nd expansion of database = 12
                                                                                                        //3rd expansion of database = 24
                                                                                                        //4th expansion of database = 48
                                                                                                        //5th expansion of database = 96 > 50 (enough!!)


    //Database: record 1,   record 2,   record 3,   record 4, ...
    //position:     0           1           2           3
    
    for(int i{0}; i<20; i++){
        Record acc{100000.0-i, "USD", "F", "C", "001123456789", to_string(30-i)+"042019", "1230"};
        database.addRecord(acc, numOfRecord, databaseSize);                                             //add 20 records to database
    }         
    
    cout << "\n" << numOfRecord << " records"<< endl;                                                   //display the no. of records in database
    database.showDatabase(numOfRecord);                                                                 //display all the records in database
                                                                                                        //sort by amount in ascending order - default
    
    
    cout << endl;
    database.changeDataInRecord(3, 700.9, "JPY", "T", "A", "null", "21022019", "1228");                 //change 4th record(pos = 3)
    
    cout << endl;
    database.changeDataInRecord(6, 500.54, "USD", "A", "A", "NULL", "20022019", "1300");                //change 7th record(pos = 6)

    cout << "\n" << numOfRecord << " records"<< endl;                                                   //display the no. of records in database
    database.showDatabase(numOfRecord);                                                                 //display all the records in database
    

    cout << endl;
    int filterNumOfRecord{0}, filterDatabaseSize{3};
//    Database febFilter = database.filterDatabaseAmount(filterNumOfRecord, filterDatabaseSize, numOfRecord, 100, 1000);
//    Database febFilter = database.filterDatabaseBykeyword(filterNumOfRecord, filterDatabaseSize, numOfRecord, 4, "567");
//    Database febFilter = database.filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, 2019); 
//    Database febFilter = database.filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, 2018, 2); 
//    Database febFilter = database.filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, 2018, 2, 21); 
//    Database febFilter = database.filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, 2018, 3, 31, 12); 
    Database febFilter = database.filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, 2018, 3, 31, 12, 59);                     //filter the records in database with criteria(WHERE)
                                                                                                        
                                                                                                        //filterDatabaseAmount
                                                                                                        //min, max(both inclusively)
                                                                                                        
                                                                                                        //filterDatabaseBykeyword, choice:
                                                                                                        //1:   characterOfPayment
                                                                                                        //2:   typeOfPayment
                                                                                                        //3:   bankName
                                                                                                        //4:   accNoOfBank
                                                                                                        
                                                                                                        //filterDatabaseBothDateTime
                                                                                                        //year [, month [, day [, hour [, minute]]]]
                                                                                                
                                                                                                        //!!both sorting function create dynamic filtered database 
    
    cout << "\n" << filterNumOfRecord << " records"<< endl;                                             //display the no. of records in database
    febFilter.showDatabase(filterNumOfRecord);                                                          //display all the records in database

//    database.sortDatabase(numOfRecord, 1);                      //merge inside showDatabase           //sort the records with different priority(GROUP BY)
                                                                                                        //1:    amount (ascending) - default
                                                                                                        //2:    amount (descending)
                                                                                                        //3:    characterOfPayment (ascending)
                                                                                                        //4:    characterOfPayment (descending)
                                                                                                        //5:    typeOfPaymentCond (ascending)
                                                                                                        //6:    typeOfPaymentCond (descending)
                                                                                                        //7:    date + Time (ascending)
                                                                                                        //8:    date + Time (descending)
    
    cout << "\n" << numOfRecord << " records - !!"<< endl;                                             //display the no. of records in database
    database.showDatabase(numOfRecord, 7);                                                              //display all the records in database    


    cout << endl;
    database.deleteRecord(6, numOfRecord, databaseSize);                                                //delete 7th record(pos = 6)
    
    cout << "\n" << numOfRecord << " records"<< endl;                                                   //display the no. of records in database
    database.showDatabase(numOfRecord);                                                                 //display all the records in database
    

    cout << fixed << endl;;
    cout << "Total: " << setw(6) << setprecision(2) << database.SUM(numOfRecord) << endl;
    cout << "Mean: " << database.AVERAGE(numOfRecord) << endl;
    cout << "Median: " << database.MEDIAN(numOfRecord) << endl;
    cout << "Minimum: " << database.MIN(numOfRecord) << endl;
    cout << "Maximum: " << database.MAX(numOfRecord) << endl << endl;
    cout << "Total in April, 2019: " << database.SUM(numOfRecord, 2019, 4) << endl;
    cout << "Average in April, 2019: " << database.AVERAGE(numOfRecord, 2019, 4) << endl;
    cout << "Minimum in April, 2019: " << database.MIN(numOfRecord, 4) << endl;
    cout << "Maximum in April, 2019: " << database.MAX(numOfRecord, 4) << endl;
    
    return 0;
}
