#include "user_interface.h"

void topMenu(Database &database, int &databaseSize, int &numOfRecord)
{
    int option{-1};
    cout << "What do you want to do?"   << endl;
    cout << "1. Add a new record"       << endl;
    cout << "2. Delete a record"        << endl;
    cout << "3. Edit a record"          << endl;
    cout << "4. Display all records"   << endl;
    cout << "5. Display Summary report" << endl;
    cout << "6. Exit"                   << endl;
    cout << endl;
    cin >> option;

    while(option < 0 || option > 6){
        cout    << "Sorry, it is invalid\n" 
                << "Please edit your choice again!" << endl
                << "Your choice: ";
        cin     >>  option;
    }
    if(option == 1)
        menuAddRecord(database, databaseSize, numOfRecord);
    else if(option == 2)
        menuDelRecord(database, databaseSize, numOfRecord);
    else if(option == 3)
        menuEditRecord(database, databaseSize, numOfRecord);
    else if(option == 4)
        menuDisplayRecord(database, databaseSize, numOfRecord);
    else if(option == 5)
        menuSummaryReport(database, databaseSize, numOfRecord);
    else if(option == 6)
        menuExit(database, databaseSize, numOfRecord);
}


void menuAddRecord(Database &database, int &databaseSize, int &numOfRecord)
{
    bool flag = true;
    while (flag)
    {
        double amount = 0.0;
        string currency = "NA";
        string characterOfPayment = "NA";
        string typeOfPayment = "NA";
        string bankName = "NULL";
        string accNoOfBank = "NA";
        string date = "NA";
        string time = "NA";

        int count{1};

        cout << count++ << ". Amount (+/-):                      ";
        cin >> amount;
        amountCheck(database, numOfRecord, amount);
        
        cout << count++ << ". Currency:                          ";
        cin >> currency;
        currencyCheck(database, currency, amount);
        
        cout << count++ << ". Characteristic of payment (Usage): ";
        cin >> characterOfPayment;
        characterOfPaymentCheck(database, characterOfPayment);
        
        cout << count++ << ". Payment method:                    ";
        cin >> typeOfPayment;
        typeOfPaymentCheck(database, typeOfPayment);
        
        if(allToUpper(typeOfPayment) != "A"){
            cout << count++ << ". Account no.:                       ";
            cin >> accNoOfBank;
            accNoOfBankCheck(database, accNoOfBank);
        }
        
        cout << count++ << ". Date (DDMMYYYY)                    ";
        cin >> date;
        while(date.length() != 8 && date.length() != 10){
            cout << "\nWrong format - It should be 8 digit date format\n"
                 << "Please enter again" << endl;
            cin  >> date;
        }
        while(!checkDate(date)){
            cout << "Please enter again" << endl;
            cin  >> date;
        }
        
        
        cout << count++ << ". Time (HHMM)                        ";
        cin >> time;
        while(time.length() != 4){
            cout << "\nWrong format - It should be 4 digit time format\n"
                 << "Please enter again" << endl;
            cin  >> time;
        }

        cout << endl;
        cout << "A new record was added." << endl;
        cout << endl;
        
        Record newRecord = Record{amount, currency, characterOfPayment, typeOfPayment, accNoOfBank, date, time};
        
        database.addRecord(newRecord, numOfRecord, databaseSize);

        

        cout << "Add another record? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'n'){
            flag = false;
            cout << "----- The current database -----" << endl;
            database.showDatabase(numOfRecord, 7);
            cout << endl;
        }
        else
            cout << endl;
    }
    topMenu(database, databaseSize, numOfRecord);
}


void menuDelRecord(Database &database, int &databaseSize, int &numOfRecord)
{
    //code for edit record
    cout << "Which record you would like to delete?" << endl;
    database.showDatabase(numOfRecord, 7);
    
    int targetRecord{0};
    cout    << "Which record do you delete?" << endl
            << "Please enter your choice: ";
    cin >> targetRecord;
    cout << endl;
    
    //show detail of record here
    cout << "Are you sure to delete this record? (y/n)" << endl;
    char choice;
    cin >> choice;
    if(choice == 'y'){
        database.deleteRecord(targetRecord, numOfRecord, databaseSize);
        cout << "Record " << targetRecord << " is deleted" << endl;
    }
    else
        cout << "Safe!! No record will be deleted!" << endl;
    topMenu(database, databaseSize, numOfRecord);
}

void menuBatchDel(Database &database, int &databaseSize, int &numOfRecord) //delete multiple records one time
{
    cout << "List the record you want to delete (divide the numbers by space): " << endl;
    int targetRecord{0};
    while (cin >> targetRecord){
        while(targetRecord < 0 || targetRecord > numOfRecord-1){
            cout    << "Sorry, it is out of range. Please input again" << endl
                    << "Possible range: " << 0 << "-" << numOfRecord-1 << endl
                    << "\nRecord: ";
                    cin >> targetRecord;
    }
        database.deleteRecord(targetRecord, numOfRecord, databaseSize);
        cout    << "Record " << targetRecord << " is deleted" << endl
                << "Next record to be deleted: ";
    }
}


void menuEditRecord(Database &database, int &databaseSize, int &numOfRecord)
{
    //code for edit record
    database.showDatabase(numOfRecord, 7);
    
    int targetRecord;
    cout << "Which record you would like to edit?" << endl;
    cout << "\nRecord: ";
    cin >> targetRecord;
    while(targetRecord < 0 || targetRecord > numOfRecord-1){
        cout    << "Sorry, it is out of range. Please input again" << endl
                << "Possible range: " << 0 << "-" << numOfRecord-1 << endl
                << "\nRecord: ";
                cin >> targetRecord;
    }
        //show detail of record here
        
    cout << "1. Amount (+/-):                 " << database.getAddress()[targetRecord].getAmount() << endl;
    cout << "   Currency:                     " << database.getAddress()[targetRecord].getCurrency() << endl;
    cout << "2. Characteristic of payment (Usage): " << database.getAddress()[targetRecord].getCharacterOfPayment() << endl;
    cout << "3. Payment method:               " << database.getAddress()[targetRecord].getTypeOfPayment() << endl;
    cout << "   Bank name:                    " << database.getAddress()[targetRecord].getBankName() << endl;
    cout << "4. Account no.:                  " << database.getAddress()[targetRecord].getAccNoOfBank() << endl;
    cout << "5. Date (DDMMYYYY)               " << database.getAddress()[targetRecord].getDate() << endl;
    cout << "6. Time (HHMM)                   " << database.getAddress()[targetRecord].getTime() << endl;

    cout << "\nWhich option you would like to edit? (1-8) " << endl;
    int editOption;
    cin >> editOption;
    while(editOption < 1 || editOption > 6){
        cout    << "Sorry, it is invalid. Please input again" << endl
                << "Possible range: " << 1 << "-" << 6 << endl
                << "\nRecord: ";
        cin     >> targetRecord;
    }
    if(editOption == 1){
        cout << "Amount: ";
        double inputAmount{0.0};
        cin >> inputAmount;
        
        cout << "Currency: ";
        string inputCurrency{""};
        cin >> inputCurrency;
        currencyCheck(database, inputCurrency, inputAmount);
        
        database.getAddress()[targetRecord].setAmount(inputAmount);
        database.getAddress()[targetRecord].setCurrency(inputCurrency);
    }
    else if(editOption == 2){
        string inputCharacterOfPayment{""};
        cout << "Characteristic Of Payment: ";
        cin >> inputCharacterOfPayment;
        characterOfPaymentCheck(database, inputCharacterOfPayment);
        
        database.getAddress()[targetRecord].setCharacterOfPayment(allToUpper(inputCharacterOfPayment));
    }
    else if(editOption == 3){
        string inputTypeOfPayment{""};
        cout << "Type of Payment: ";
        cin >> inputTypeOfPayment;
        typeOfPaymentCheck(database, inputTypeOfPayment);
        
        database.getAddress()[targetRecord].setTypeOfPayment(allToUpper(inputTypeOfPayment));
    }
    else if(editOption == 4){
        string inputAccNoOfBank{""};
        cout << "Account of Payment: ";
        cin >> inputAccNoOfBank;
        accNoOfBankCheck(database, inputAccNoOfBank);
        
        database.getAddress()[targetRecord].setAccNoOfBank(inputAccNoOfBank);
    }
    else if(editOption == 5){
        string inputDate{""};
        cout << "Date: ";
        cin >> inputDate;
        
        while(inputDate.length() != 8 && inputDate.length() != 10){
            cout << "\nWrong format - It should be 8 digit date format\n"
                 << "Please enter again" << endl;
            cin  >> inputDate;
        }
        while(!checkDate(inputDate)){
            cout << "Please enter again" << endl;
            cin  >> inputDate;
        }
        
        database.getAddress()[targetRecord].setDate(inputDate);
    }
    else if(editOption == 6){
        string inputTime{""};
        cout << "Time: ";
        cin >> inputTime;
        while(inputTime.length() != 4){
            cout << "\nWrong format - It should be 4 digit time format\n"
                 << "Please enter again" << endl;
            cin  >> inputTime;
        }
        
        database.getAddress()[targetRecord].setTime(inputTime);
    }
    topMenu(database, databaseSize, numOfRecord);    
}
    

void menuDisplayRecord(Database &database, int &databaseSize, int &numOfRecord){
    cout << "-----current database-------\n";
    database.showDatabase(numOfRecord, 7);
    cout << "----------------------------" << endl;
    topMenu(database, databaseSize, numOfRecord); 
}



void menuSummaryReport(Database &database, int &databaseSize, int &numOfRecord)
{
    int choice{0};
    cout    << "Which type of summary report you would like to view?" << endl
            << "1 - Total" << endl
            << "2 - Annual" << endl
            << "3 - Year - Month" << endl
            << "Enter your choice: " << endl;
    while(choice < 1 || choice > 3){
        cout    << "Sorry, it is invalid. Please input again" << endl
                << "Possible range: " << 1 << "-" << 3 << endl
                << "\nRecord: ";
        cin     >> choice;
    }
    summaryReportoutput(database, numOfRecord, choice);
    topMenu(database, databaseSize, numOfRecord);
}

void menuExit(Database &database, int &databaseSize, int &numOfRecord)
{
    ofstream exportFile("../ExportDatabase.txt");
    for(int i{0}; i<numOfRecord; i++)
        exportFile << database.getRecordFromDatabase(i) << "\n";
    exportFile.close();
}


//validation//
void amountCheck(Database &database, const int &numOfRecord, double &amount){
    if(database.SUM(numOfRecord) < 0 && amount < 0){
        while(amount <= 0){
            cout    << "Negative balance" << endl
                    << "Please enter value of deposit: \n"
                    << "Amount (+: deposit/-: withdrawnal): ";
            cin     >> amount;
        }
    }
}

void currencyCheck(Database &database, string &Currency, double &amount){
    while(allToUpper(Currency) != "HKD"){
            ifstream currencyConvertFile{"../currencyConvert.txt"};            //Assume the file is existed
            string extCurrency{""};
            double exchangeRate{-1.0};
            while(currencyConvertFile >> extCurrency >> exchangeRate){
                if(extCurrency == allToUpper(Currency)){
                    amount *= exchangeRate;
                    Currency = "HKD";
                    currencyConvertFile.close();
                    break;
                }
                if(extCurrency == "ENDD"){
                    currencyConvertFile.close();
                    break;
                }
            }
            
            
            while(exchangeRate == 0 && Currency != "HKD"){
                cout    << "No this currency!\n"
                        << "Please enter correct currency: ";
                cin     >> Currency;
                currencyConvertFile = ifstream("../currencyConvert.txt");            //Assume the file is existed
                string extCurrency{""};
                double exchangeRate{-1.0};
                while(currencyConvertFile >> extCurrency >> exchangeRate){
                    if(extCurrency == allToUpper(Currency)){
                        amount *= exchangeRate;
                        Currency = "HKD";
                        currencyConvertFile.close();
                        break;
                    }
                }
            }
    }
}

void characterOfPaymentCheck(Database &database, string &characterOfPayment){
    while(string("FABTS").find(allToUpper(characterOfPayment)) == string::npos || characterOfPayment.length() != 1){
            cout    << "Invalid type" << endl
                    << "Please enter one of these types(F/A/B/T/S): ";
            cin     >> characterOfPayment;
    }
}

void typeOfPaymentCheck(Database &database, string &typeOfPayment){
    while(string("CHA").find(allToUpper(typeOfPayment)) == string::npos || typeOfPayment.length() != 1){
            cout    << "Invalid type" << endl
                    << "Please enter one of these types(C/H/A): ";
            cin     >> typeOfPayment;
    }
}

void accNoOfBankCheck(Database &database, string &accNoOfBank){
    bool flag{true};
    while(accNoOfBank.length() != 12 || flag){
            string bankCode{accNoOfBank.substr(0, 3)};
            flag = true;
            ifstream bankCodeConvertFile{"../bankCodeConvert.txt"};            //Assume the file is existed
                
            string searchBankCode{""};
            string line{""};
                
            while(getline(bankCodeConvertFile, line)){
                stringstream sLine{line};
                sLine >> searchBankCode;
                getline(sLine, line);
                
                if(searchBankCode == bankCode){
                    flag = false;
                    bankCodeConvertFile.close();
                    
                    break;
                }
            }
            
            while(flag){
                bankCodeConvertFile.close();
                cout << "\nWrong format - there is no bank that is existed\n"
                    << "Please enter again" << endl;
                cin >> accNoOfBank;
                bankCode = accNoOfBank.substr(0, 3);
                bankCodeConvertFile = ifstream("../bankCodeConvert.txt");
                while(getline(bankCodeConvertFile, line)){
                    stringstream sLine{line};
                    sLine >> searchBankCode;
                    if(searchBankCode == bankCode){
                        flag = false;
                        bankCodeConvertFile.close();
                        break;
                    }
                }   
            }
            if(flag){
                cout << "\nWrong format - It should be 12 digit bank account number\n"
                     << "Please enter again" << endl;
                cin >> accNoOfBank;
            }
    }
}


//report output//
void summaryReportoutput(Database &database, const int &numOfRecord, const int &choice){
    if(choice == 1)
        summaryTotalReportoutput(database, numOfRecord);
    else if(choice == 2){
        int year{1980};
        cout << "Please input the year: ";
        cin >> year;
        cout << endl;
        summaryAnnualReportoutput(database, numOfRecord, year);
    }
    else if(choice == 3){
        int year{1}, month{1};
        cout << "Please input the year: ";
        cin >> year;
        cout << "\nPlease input the month: ";
        cin >> month;
        cout << endl;
        summaryMonthlyReportoutput(database, numOfRecord, year, month);
    }
}

void summaryTotalReportoutput(Database &database, const int &numOfRecord){
    cout    << fixed << setprecision(2)
            << "--Summary Report--" << std::endl
            << "Account balance = " << database.SUM(numOfRecord) << std::endl
            << std::endl
            << "Total expense = " << database.SUMExpense(numOfRecord, true) << std::endl
            << "Total deposit = " << database.SUMExpense(numOfRecord, false) << std::endl
            << std::endl
            << "Average = " <<database.AVERAGE(numOfRecord) << std::endl
            << "Median = " << database.MEDIAN(numOfRecord)  << std::endl
            << std::endl
            << "Minimum expense = " << database.MINExpense(numOfRecord, true) << std::endl
            << "Maximum expense = " << database.MAXExpense(numOfRecord, true) << std::endl
            << std::endl
            << "Minimum deposit = " << database.MINExpense(numOfRecord, false) << std::endl
            << "Maximum deposit = " << database.MAXExpense(numOfRecord, false) << std::endl
            << std::endl
            << "Percentage of food expenses: " << database.percentageExpenseByCharacter(numOfRecord, 1, "F") * (-1) << "%" << std::endl
            << "Percentage of fashion expenses: " << database.percentageExpenseByCharacter(numOfRecord, 1, "A") * (-1) << "%" << std::endl
            << "Percentage of transportation expenses: " << database.percentageExpenseByCharacter(numOfRecord, 1, "T") * (-1) << "%" << std::endl
            << std::endl;
}

void summaryAnnualReportoutput(Database &database, const int &numOfRecord, const int &year){
    cout    << fixed << setprecision(2) 
            << "--Summary Report " << year << "--" << endl
            << "Account balance = " << database.SUM(numOfRecord, year) << endl
            << endl
            << "Total expense = " << database.SUMExpense(numOfRecord, true, year) << endl
            << "Total deposit = " << database.SUMExpense(numOfRecord, false, year) << endl
            << endl
            << "Average = " << database.AVERAGE(numOfRecord, year) << endl
            << "Median = " << database.MEDIAN(numOfRecord, year)  << endl
            << endl
            << "Minimum expense = " << database.MINExpense(numOfRecord, true, year) << endl
            << "Maximum expense = " << database.MAXExpense(numOfRecord, true, year) << endl
            << endl
            << "Minimum deposit = " << database.MINExpense(numOfRecord, false, year) << endl
            << "Maximum deposit = " << database.MAXExpense(numOfRecord, false, year) << endl
            << endl;
}

void summaryMonthlyReportoutput(Database &database, const int &numOfRecord, const int &year, const int &month){
    cout    << fixed << setprecision(2) 
            << "--Summary Report " << year << "-" << month << "--" << endl
            << "Account balance = " << database.SUM(numOfRecord, year, month) << endl
            << endl
            << "Total expense = " << database.SUMExpense(numOfRecord, true, year, month) << endl
            << "Total deposit = " << database.SUMExpense(numOfRecord, false, year, month) << endl
            << endl
            << "Average = " << database.AVERAGE(numOfRecord, year, month) << endl
            << "Median = " << database.MEDIAN(numOfRecord, year, month)  << endl
            << endl
            << "Minimum expense = " << database.MINExpense(numOfRecord, true, year, month) << endl
            << "Maximum expense = " << database.MAXExpense(numOfRecord, true, year, month) << endl
            << endl
            << "Minimum deposit = " << database.MINExpense(numOfRecord, false, year, month) << endl
            << "Maximum deposit = " << database.MAXExpense(numOfRecord, false, year, month) << endl
            << endl;
}
