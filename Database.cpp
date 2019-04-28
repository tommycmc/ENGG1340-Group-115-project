#include "Database.h"


Database::Database(int &databaseSize) {
    this->database = new Record[databaseSize];                //create dynamic array according to defined database size 
}

Database::~Database() {
    delete [] this->database;                                 //release database (record pointer) properly.
}

//getter function//
Record Database::getRecordFromDatabase(int &pos){
    return this->database[pos];
}

Record *Database::getAddress(){
    return this->database;
}


//setter function//
void Database::setNull(){
    this->database = nullptr;
}

void Database::manDelDatabase(){
    delete [] database;
//    cout << "deleted database manually" << endl;
    this->database = nullptr;
}


//display function//
void Database::displayRecordWithPos(int &i){
    cout << i << "\t";
    this->database[i].display();
}

void Database::showDatabase(int &numOfRecord, int choice){
    this->sortDatabase(numOfRecord, choice);
    for(int i{0}; i<numOfRecord; i++)
        displayRecordWithPos(i);
}
void Database::showDatabase(int &numOfRecord){
    return showDatabase(numOfRecord, 1);
}

//insert function//
void Database::insertBackRecordWithoutEnlarge(Record &newRecord, int &numOfRecord, int &databaseSize){
    this->database[numOfRecord++] = newRecord;
}

void Database::insertBackRecordWithEnlarge(Record &newRecord, int &numOfRecord, int &databaseSize){
    Database tempLargeDatabase = Database(databaseSize);
    for(int i{0}; i<numOfRecord; i++)
        tempLargeDatabase.getAddress()[i] = this->database[i];
    tempLargeDatabase.getAddress()[numOfRecord++] = newRecord;
    this->database = tempLargeDatabase.getAddress();
    tempLargeDatabase.setNull();
}

void Database::addRecord(Record &newRecord, int &numOfRecord, int &databaseSize){
    if(numOfRecord+1 > databaseSize){
        databaseSize *= 2;
        this->insertBackRecordWithEnlarge(newRecord, numOfRecord, databaseSize);
    }
    else
        this->insertBackRecordWithoutEnlarge(newRecord, numOfRecord, databaseSize);
}



//edit function//
void Database::changeDataInRecord(int pos, double Amount_val, string Currency_val, string characterOfPayment_val, 
            string typeOfPayment_val, string accNoOfBank_val, string Date_val, string Time_val){
    this->database[pos].setAmount(Amount_val);
    this->database[pos].setCurrency(Currency_val);
    this->database[pos].setCharacterOfPayment(characterOfPayment_val);
    this->database[pos].setTypeOfPayment(typeOfPayment_val);
    this->database[pos].setAccNoOfBank(accNoOfBank_val);
    this->database[pos].setDate(Date_val);
    this->database[pos].setTime(Time_val);
}


//delete function//
void Database::skipRecord(int pos, int &numOfRecord, int &databaseSize){
    Database tempSmallDatabase = Database(databaseSize);
    for(int i{0}; i<pos; i++)
        tempSmallDatabase.getAddress()[i] = this->database[i];
    for(int i{pos+1}; i<numOfRecord; i++)
        tempSmallDatabase.getAddress()[i-1] = this->database[i];
    this->database = tempSmallDatabase.getAddress(); 
    tempSmallDatabase.setNull();
    numOfRecord--;
}

void Database::deleteRecord(int pos, int &numOfRecord, int &databaseSize){
    if(numOfRecord-1 <= databaseSize/2){
        databaseSize /= 2;
        this->skipRecord(pos, numOfRecord, databaseSize);
    }
    else
        this->skipRecord(pos, numOfRecord, databaseSize);
}



//filter function//
Database Database::filterDatabaseAmount(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, const int min, const int max){
    Database filterDatabase = Database(filterDatabaseSize);
    for(int i{0}; i<originalNumOfRecord; i++){
        if(this->database[i].getAmount() >= min && this->database[i].getAmount() <= max)
            filterDatabase.addRecord(this->database[i], filterNumOfRecord, filterDatabaseSize);
    }
    return filterDatabase;
}

bool Database::filterMethodSeletor(const int &pos, const int &method, const string &keyword){
    switch(method){
        case 1:     if(this->database[pos].getCharacterOfPayment() == keyword)
                        return true;
                    break;
        case 2:     if(this->database[pos].getTypeOfPayment() == keyword)
                        return true;
                    break;
        case 3:     if(this->database[pos].getBankName().find(keyword) != string::npos)
                        return true;
                    break;
        case 4:     if(this->database[pos].getAccNoOfBank().find(keyword) != string::npos)
                        return true;
                    break;
    }
    return false;
}

Database Database::filterDatabaseBykeyword(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int method, string keyword){
    Database filterDatabase = Database(filterDatabaseSize);
    
    for(int i{0}; i<originalNumOfRecord; i++){
        if(this->filterMethodSeletor(i, method, keyword))
            filterDatabase.addRecord(this->database[i], filterNumOfRecord, filterDatabaseSize);
    }
    return filterDatabase;
}

bool Database::filterDateTimeSelector(int &pos, int &year, int &month, int &day, int &hour, int &minute){
    if(month == -1 && day == -1 && hour == -1 && minute == -1){
        if(this->database[pos].getYear() == year)
            return true;
    }
    if(day == -1 && hour == -1 && minute == -1){
        if(this->database[pos].getYear() == year && this->database[pos].getMonth() == month)
            return true; 
    }
    if(hour == -1 && minute == -1){
        if(this->database[pos].getYear() == year && this->database[pos].getMonth() == month && this->database[pos].getDay() == day)
            return true; 
    }
    if(minute == -1){
        if(this->database[pos].getYear() == year && this->database[pos].getMonth() == month && this->database[pos].getDay() == day
                                                && this->database[pos].getHour() == hour)
            return true; 
    }
    if(this->database[pos].getYear() == year && this->database[pos].getMonth() == month && this->database[pos].getDay() == day
                                                && this->database[pos].getHour() == hour && this->database[pos].getMinute() == minute){
            return true;
    }
    return false;
}

Database Database::filterDatabaseBothDateTime(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int year, int month, int day, int hour, int minute){
    Database filterDatabase = Database(filterDatabaseSize);
    for(int i{0}; i<originalNumOfRecord; i++){
        if(this->filterDateTimeSelector(i, year, month, day, hour, minute))
            filterDatabase.addRecord(this->database[i], filterNumOfRecord, filterDatabaseSize);
    }
    return filterDatabase;
}
Database Database::filterDatabaseBothDateTime(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int year){
    return filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, originalNumOfRecord, year, -1, -1, -1, -1);
}
Database Database::filterDatabaseBothDateTime(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int year, int month){
    return filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, originalNumOfRecord, year, month, -1, -1, -1);
}
Database Database::filterDatabaseBothDateTime(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int year, int month, int day){
    return filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, originalNumOfRecord, year, month, day, -1, -1);
}
Database Database::filterDatabaseBothDateTime(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, int year, int month, int day, int hour){
    return filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, originalNumOfRecord, year, month, day, hour, -1);
}

Database Database::filterDatabaseExpense(int &filterNumOfRecord, int &filterDatabaseSize, const int &originalNumOfRecord, const bool &expense){
    Database filterDatabase = Database(filterDatabaseSize);
    for(int i{0}; i<originalNumOfRecord; i++){
        if(this->database[i].isExpense() == expense)
            filterDatabase.addRecord(this->database[i], filterNumOfRecord, filterDatabaseSize);
    }
    return filterDatabase;
}



//sort function//
bool Database::sortSelector(int &i, int &j, int &choice){
    if(choice == 1)
        return amountCondAsc(i, j);
    else if(choice == 2)
        return amountCondDesc(i, j);
    else if(choice == 3)
        return characterOfPaymentCondAsc(i, j);
    else if(choice == 4)
        return characterOfPaymentCondDesc(i, j);  
    else if(choice == 5)
        return typeOfPaymentCondAsc(i, j);
    else if(choice == 6)
        return typeOfPaymentCondDesc(i, j);
    else if(choice == 7)
        return dateAndTimeCondAsc(i, j);
    else if(choice == 8)
        return dateAndTimeCondDesc(i, j);
    else return false;
}

bool Database::amountCondAsc(int &i, int &j){
    if(this->database[i].getAmount() <= this->database[j].getAmount())
        return true;
    else
        return false;
}

bool Database::amountCondDesc(int &i, int &j){
    if(this->database[i].getAmount() >= this->database[j].getAmount())
        return true;
    else
        return false;
}

bool Database::characterOfPaymentCondAsc(int &i, int &j){
    if(this->database[i].getCharacterOfPayment() <= this->database[j].getCharacterOfPayment())
        return true;
    else
        return false;
}

bool Database::characterOfPaymentCondDesc(int &i, int &j){
    if(this->database[i].getCharacterOfPayment() >= this->database[j].getCharacterOfPayment())
        return true;
    else
        return false;
}

bool Database::typeOfPaymentCondAsc(int &i, int &j){
    if(this->database[i].getTypeOfPayment() <= this->database[j].getTypeOfPayment())
        return true;
    else
        return false;
}

bool Database::typeOfPaymentCondDesc(int &i, int &j){
    if(this->database[i].getTypeOfPayment() >= this->database[j].getTypeOfPayment())
        return true;
    else
        return false;
}

bool Database::dateAndTimeCondAsc(int &i, int &j){
    if(this->database[i].getYear() < this->database[j].getYear())
        return true;
    else if(this->database[i].getYear() > this->database[j].getYear())
        return false;
        
    if(this->database[i].getMonth() < this->database[j].getMonth())
        return true;
    else if(this->database[i].getMonth() > this->database[j].getMonth())
        return false;
    
    if(this->database[i].getDay() < this->database[j].getDay())
        return true;
    else if(this->database[i].getDay() > this->database[j].getDay())
        return false;
        
    if(this->database[i].getHour() < this->database[j].getHour())
        return true;
    else if(this->database[i].getHour() > this->database[j].getHour())
        return false;
    
    if(this->database[i].getMinute() <= this->database[j].getMinute())   
        return true;
    else
        return false;
}

bool Database::dateAndTimeCondDesc(int &i, int &j){
    if(this->database[i].getYear() > this->database[j].getYear())
        return true;
    else if(this->database[i].getYear() < this->database[j].getYear())
        return false;
        
    if(this->database[i].getMonth() > this->database[j].getMonth())
        return true;
    else if(this->database[i].getMonth() < this->database[j].getMonth())
        return false;
    
    if(this->database[i].getDay() > this->database[j].getDay())
        return true;
    else if(this->database[i].getDay() < this->database[j].getDay())
        return false;
        
    if(this->database[i].getHour() > this->database[j].getHour())
        return true;
    else if(this->database[i].getHour() < this->database[j].getHour())
        return false;
    
    if(this->database[i].getMinute() >= this->database[j].getMinute())   
        return true;
    else
        return false;
}

void Database::singleMerge(int left, int mid, int right, int &choice){
    int z{right-left+1};
    Database tempDatabase = Database(z);                                            //temporary database
    int i = left, j = mid + 1;                                                      //i is for left-hand side, j is for right-hand side
    int k = 0;                                                                      //k is the index for the temporary database
    while(i <= mid && j <=right){                                                   //We adapt the algorithm from http://www.codebind.com/cpp-tutorial/cpp-example-merge-sort-algorithm/ and https://www.geeksforgeeks.org/merge-sort/
        if(sortSelector(i, j, choice))
            tempDatabase.getAddress()[k++] = this->database[i++];
        else
            tempDatabase.getAddress()[k++] = this->database[j++];
    }
    
    while(i <= mid)                                                                 //rest elements of left-half database
        tempDatabase.getAddress()[k++] = this->database[i++];
   
    while(j <= right)                                                               //rest elements of right-half database
        tempDatabase.getAddress()[k++] = this->database[j++];
   
    for(k = 0, i = left; i <= right; i++, k++)                                      //copy the mergered temporary database to the original database
        this->database[i] = tempDatabase.getAddress()[k];

    tempDatabase.setNull();
}

void Database::recurseMerge(int left, int right, int &choice){
    if(left < right){
        int mid{left + (right - left)/2};
        this->recurseMerge(left, mid, choice);
        this->recurseMerge(mid+1, right, choice);
        this->singleMerge(left, mid, right, choice);
    }
}    

void Database::sortDatabase(int numOfRecord, int choice){                      //use merge sort(recursive method)
    this->recurseMerge(0, numOfRecord-1, choice);
}



//aggregate function//
double Database::SUM(const int &numOfRecord){
    double totalAmount{0.0};
    for(int i{0}; i<numOfRecord; i++)
        totalAmount += this->database[i].getAmount();                          //traverse all records in Database, add add amount to totalAmount
    return totalAmount;
}

double Database::SUM(const int &numOfRecord, const int year, const int month){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database monthDatabase = this->filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, year, month);
    return monthDatabase.SUM(filterNumOfRecord);
}

double Database::SUM(const int &numOfRecord, const int year){
    return this->SUM(numOfRecord, year, -1);
}

double Database::SUMExpense(const int &numOfRecord, const bool &expense){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database expenseDatabase = this->filterDatabaseExpense(filterNumOfRecord, filterDatabaseSize, numOfRecord, expense);
    return expenseDatabase.SUM(filterNumOfRecord);
}

double Database::SUMExpense(const int &numOfRecord, const bool &expense, const int year, const int month){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database monthExpenseDatabase = this->filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, year, month);
    return monthExpenseDatabase.SUMExpense(filterNumOfRecord, expense);
}

double Database::SUMExpense(const int &numOfRecord, const bool &expense, const int year){
    return this->SUMExpense(numOfRecord, expense, year, -1);
}

double Database::SUMExpenseByCharacter(const int &numOfRecord, const int &method, const string &keyword){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database expenseCharacterDatabase = this->filterDatabaseBykeyword(filterNumOfRecord, filterDatabaseSize, numOfRecord, method, keyword);
    return expenseCharacterDatabase.SUM(filterNumOfRecord);
}
double Database::SUMExpenseByCharacter(const int &numOfRecord, const int &method, const string &keyword, const int year, const int month){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database monthExpenseCharacterDatabase = this->filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, year, month);
    return monthExpenseCharacterDatabase.SUM(filterNumOfRecord);
}
double Database::SUMExpenseByCharacter(const int &numOfRecord, const int &method, const string &keyword, const int year){
    return this->SUMExpenseByCharacter(numOfRecord, method, keyword, year, -1);
}

double Database::AVERAGE(const int &numOfRecord){
    return this->SUM(numOfRecord)/numOfRecord;                                 //use SUM function to get total amount, then divide it 
}                                                                              //by the no. of record we have
double Database::AVERAGE(const int &numOfRecord, const int year, const int month){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database monthDatabase = this->filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, year, month);
    return monthDatabase.AVERAGE(filterNumOfRecord);
}
double Database::AVERAGE(const int &numOfRecord, const int year){
    return AVERAGE(numOfRecord, year, -1);
}

double Database::AVERAGEExpense(const int &numOfRecord, const bool &expense){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database averageDatabase = this->filterDatabaseExpense(filterNumOfRecord, filterDatabaseSize, numOfRecord, expense);
    return averageDatabase.AVERAGE(filterNumOfRecord);
}

double Database::AVERAGEExpense(const int &numOfRecord, const bool &expense, const int year, const int month){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database monthAverageDatabase = this->filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, year, month);
    return monthAverageDatabase.AVERAGEExpense(filterNumOfRecord, expense);
}

double Database::AVERAGEExpense(const int &numOfRecord, const bool &expense, const int year){
    return this->AVERAGEExpense(numOfRecord, expense, year, -1);
}

double Database::MEDIAN(const int &numOfRecord){
    int medPos{numOfRecord/2};                                                 //find the central pos regardless of odd/even
    this->sortDatabase(numOfRecord, 1);
    if(numOfRecord % 2 == 0 || numOfRecord <= 1)                                                            
        return this->database[medPos].getAmount();                              //no. of records = even
    else                                                                                
        return (this->database[medPos].getAmount() + this->database[medPos+1].getAmount())/2;               //no. of records = odd
}

double Database::MEDIAN(const int &numOfRecord, const int year, const int month){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database monthDatabase = this->filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, year, month);
    return monthDatabase.MEDIAN(filterNumOfRecord);
}

double Database::MEDIAN(const int &numOfRecord, const int year){
    return this->MEDIAN(numOfRecord, year, -1);
}

double Database::MEDIANExpense(const int &numOfRecord, const bool &expense){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database medianDatabase = this->filterDatabaseExpense(filterNumOfRecord, filterDatabaseSize, numOfRecord, expense);
    return medianDatabase.MEDIAN(filterNumOfRecord);
}

double Database::MEDIANExpense(const int &numOfRecord, const bool &expense, const int year, const int month){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database monthMedianDatabase = this->filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, year, month);
    return monthMedianDatabase.MEDIANExpense(filterNumOfRecord, expense);
}

double Database::MEDIANExpense(const int &numOfRecord, const bool &expense, const int year){
    return this->MEDIANExpense(numOfRecord, expense, year, -1);
}

double Database::MIN(const int &numOfRecord){
    this->sortDatabase(numOfRecord, 1);
    return this->database[0].getAmount(); 
}

double Database::MIN(const int &numOfRecord, const int year, const int month){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database monthDatabase = this->filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, year, month);
    return monthDatabase.MIN(filterNumOfRecord);
}

double Database::MIN(const int &numOfRecord, const int year){
    return this->MIN(numOfRecord, year, -1);
}

double Database::MINExpense(const int &numOfRecord, const bool &expense){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database minDatabase = this->filterDatabaseExpense(filterNumOfRecord, filterDatabaseSize, numOfRecord, expense);
    return minDatabase.MIN(filterNumOfRecord);
}

double Database::MINExpense(const int &numOfRecord, const bool &expense, const int year, const int month){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database monthMinDatabase = this->filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, year, month);
    return monthMinDatabase.MINExpense(filterNumOfRecord, expense);
}

double Database::MINExpense(const int &numOfRecord, const bool &expense, const int year){
    return this->MINExpense(numOfRecord, expense, year, -1);
}

double Database::MAX(const int &numOfRecord){
    this->sortDatabase(numOfRecord, 2);
    return this->database[0].getAmount(); 
}

double Database::MAX(const int &numOfRecord, const int year, const int month){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database monthDatabase = this->filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, year, month);
    return monthDatabase.MAX(filterNumOfRecord);
}

double Database::MAX(const int &numOfRecord, const int year){
    return this->MAX(numOfRecord, year, -1);
}

double Database::MAXExpense(const int &numOfRecord, const bool &expense){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database maxDatabase = this->filterDatabaseExpense(filterNumOfRecord, filterDatabaseSize, numOfRecord, expense);
    return maxDatabase.MAX(filterNumOfRecord);
}

double Database::MAXExpense(const int &numOfRecord, const bool &expense, const int year, const int month){
    int filterNumOfRecord{0}, filterDatabaseSize{3}; 
    Database monthMaxDatabase = this->filterDatabaseBothDateTime(filterNumOfRecord, filterDatabaseSize, numOfRecord, year, month);
    return monthMaxDatabase.MAXExpense(filterNumOfRecord, expense);
}

double Database::MAXExpense(const int &numOfRecord, const bool &expense, const int year){
    return this->MAXExpense(numOfRecord, expense, year, -1);
}

double Database::percentageExpenseByCharacter(const int &numOfRecord, const int &method, const string &keyword){
    return ((this->SUMExpenseByCharacter(numOfRecord, method, keyword))/(this->SUMExpense(numOfRecord, true))) * 100;
}





