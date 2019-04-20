#include "Database.h"

Database::Database(int &databaseSize) {
    database = new Record[databaseSize];                //create dynamic array according to defined database size 
    cout << "created database" << endl;
}

Database::~Database() {
    delete [] database;                                 //release database (record pointer) properly.
    cout << "deleted database" << endl;
}

void Database::addRecord(Record &newRecord, int &databaseSize, int &numOfRecord){
    if(numOfRecord < databaseSize)                      //if no. of records < database size, i.e. database has free space
        database[numOfRecord++] = newRecord;
    else{       
                    //not implement yet
                    //size of new array double
                    //expand array size + copy original content of array to new array
    }
    
    
}

//list all records in database
void Database::showDatabase(int &numOfRecord){
    for(int i{0}; i<numOfRecord; i++){
        database[i].display();
    }
}
