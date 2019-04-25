#include "Database.h"

Database::Database(int &databaseSize) {
    this->database = new Record[databaseSize];                //create dynamic array according to defined database size 
    cout << "created database" << endl;
}

Database::~Database() {
    delete [] this->database;                                 //release database (record pointer) properly.
    cout << "deleted database" << endl;
}

<<<<<<< HEAD

//getter function//
Record Database::getRecordFromDatabase(int &pos){
    return this->database[pos];
}

Record* Database::getAddress(){
    return this->database;
}


//setter function//
void Database::setNull(){
    this->database = nullptr;
}

void Database::manDelDatabase(){
    delete [] database;
    cout << "deleted database manually" << endl;
    this->database = nullptr;
}


//display function//
void Database::displayRecordWithPos(int &i){
    cout << i << " ";
    this->database[i].display();
}

void Database::showDatabase(int &numOfRecord){
    for(int i{0}; i<numOfRecord; i++)
        displayRecordWithPos(i);
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
void Database::filterShowDatabase(const int &numOfRecord, const int &choice){
    string keyword{""}, inputDay{"1"}, inputMonth{"1"}, inputYear{"1980"}, inputHour{"12"}, inputMinute{"59"};          //need to seperate request function to 
    int min{0}, max{0}, day{1}, month{1}, year{1980}, hour{12}, minute{59};                                             //another function
    if(choice == 2 || choice == 3 || choice == 4 || choice == 5){
        cout << "What's your filtered word?" << endl;
        cin >> keyword;
    }
    else if(choice == 1){
        cout << "Minimum: ";
        cin >> min;
        cout << "Maximum: ";
        cin >> max;
    }
    else if(choice == 6){
        cout << "Day: ";
        cin >> inputDay;
        day = stoi(inputDay);
        cout << "\nMonth: ";
        cin >> inputMonth;
        month = stoi(inputMonth);
        cout << "\nYear: ";
        cin >> inputYear;
        year = stoi(inputYear);
    }
    else if(choice == 7){
        cout << "Hour: ";
        cin >> inputHour;
        hour = stoi(inputHour);
        cout << "Minute: ";
        cin >> inputMinute;
        minute = stoi(inputMinute);
=======
void Database::addRecord(Record &newRecord, int &databaseSize, int &numOfRecord){
    if(numOfRecord < databaseSize)                      //if no. of records < database size, i.e. database has free space
        database[numOfRecord++] = newRecord;
    else{       
                    //not implement yet
                    //size of new array double
                    //expand array size + copy original content of array to new array
            
            databaseSize *= 2;                  // Double the previous size.
            Record* temp = new Record[databaseSize];  // Allocate new, bigger array.
            for (int i=0; i<numOfRecord; i++) {
                temp[i] = database[i];                 // Copy old array to new array.
            }
            delete [] database;                        // Free old array memory.
            database = temp;                           // Now a points to new array.  
>>>>>>> 695c773c38044f2630fc99bb6ec6ec5dc170664c
    }
    
    if(choice >= 0 && choice <= 7){
        for(int i{0}; i<numOfRecord; i++){
            switch(choice){
                case 1:     if(this->database[i].getAmount() >= min && this->database[i].getAmount() <= max)
                                displayRecordWithPos(i);
                            break;
                case 2:     if(this->database[i].getCharacterOfPayment() == keyword)
                                displayRecordWithPos(i);
                            break;
                case 3:     if(this->database[i].getTypeOfPayment() == keyword)
                                displayRecordWithPos(i);      
                            break;
                case 4:     if(this->database[i].getBankName().find(keyword) != string::npos)
                                displayRecordWithPos(i); 
                            break;
                case 5:     if(this->database[i].getAccNoOfBank() == keyword)
                                displayRecordWithPos(i);                
                            break;
                case 6:     if(this->database[i].getDay() == day && this->database[i].getMonth() == month && this->database[i].getYear() == year)   //+ range
                                displayRecordWithPos(i);  
                            break;
                case 7:     if(this->database[i].getHour() == hour && this->database[i].getMinute() == minute)          //+ range
                                displayRecordWithPos(i);  
                            break;
                default:    break;
            }
        }
    }
}


//sort function//
bool Database::sortSelector(int &i, int &j, int &choice){
    switch(choice){
        case 1: characterOfPaymentCond(i, j);
                break;
        case 2: typeOfPaymentCond(i, j);
                break;
        case 3: dateAndTimeCond(i, j);
                break;
        default:    break;
    }
    return false;
}

bool Database::characterOfPaymentCond(int &i, int &j){
    if(this->database[i].getCharacterOfPayment() <= this->database[j].getCharacterOfPayment())
        return true;
    else
        return false;
}

bool Database::typeOfPaymentCond(int &i, int &j){
    if(this->database[i].getTypeOfPayment() <= this->database[j].getTypeOfPayment())
        return true;
    else
        return false;
}

bool Database::dateAndTimeCond(int &i, int &j){
    if(this->database[i].getDay() < this->database[j].getDay())
        return true;
    else if(this->database[i].getDay() == this->database[j].getDay() && this->database[i].getMinute() <= this->database[j].getMinute())
        return true;
    else 
        return false;
}

void Database::singleMerge(int left, int mid, int right, int &choice){
    int z{right-left+1};
    Database tempDatabase = Database(z);                                            //temporary database
    int i = left, j = mid + 1;                                                      //i is for left-hand side, j is for right-hand side
    int k = 0;                                                                      //k is the index for the temporary database
    while(i <= mid && j <=right){
        if(sortSelector(i, j, choice))
            tempDatabase.getAddress()[k++] = this->database[i++];
        else
            tempDatabase.getAddress()[k++] = this->database[j++];
    }
    
    while(i <= mid)                                                                 //rest elements of left-half database
        tempDatabase.getAddress()[k++] = this->database[i++];
   
    while(j <= right)                                                               //rest elements of right-half database
        tempDatabase.getAddress()[k++] = this->database[j++];
   
    for(k = 0, i = left; i <= right; ++i, ++k)                                      //copy the mergered temporary database to the original database
        this->database[i] = tempDatabase.getAddress()[k];

}

void Database::recurseMerge(int left, int right, int &choice){
    if(left < right){
        int mid{left + (right - left)/2};
        this->recurseMerge(left, mid, choice);
        this->recurseMerge(mid+1, right, choice);
        this->singleMerge(left, mid, right, choice);
    }
}    

void Database::sortDatabase(int numOfRecord, int &choice){                   //use merge sort(recursive method)
    this->recurseMerge(0, numOfRecord-1, choice);
}