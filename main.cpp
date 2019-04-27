#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include "Record.h"
#include "Database.h"
#include "user_interface.h"
#include "utilityFunction.h"

using namespace std;

int main(){
    int  numOfRecord{0}, databaseSize{3};                                                               //initialize the size of database, no. of records in database
    Database database(databaseSize);                                                                    //initialize the database
    
    topMenu(database, numOfRecord, databaseSize);

    
    return 0;
}
