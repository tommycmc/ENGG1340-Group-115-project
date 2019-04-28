#include "user_interface.h"

void topMenu(Database &database, int &databaseSize, int &numOfRecord)
{
    int option;
    cout << "What do you want to do?"   << endl;
    cout << "1. Add a new record"       << endl;
    cout << "2. Delete a record"        << endl;
    cout << "3. Edit a record"          << endl;
    cout << "4. Show record"            << endl;
    cout << "5. Exit"                   << endl;
    cin >> option;

    if(option == 1)
        menuAddRecord(database, databaseSize, numOfRecord);
    else if(option == 2)
        menuDelRecord(database, databaseSize, numOfRecord);
    else if(option == 3)
        menuEditRecord(database, databaseSize, numOfRecord);
    else if(option == 4)
        menuSummaryReport(database, databaseSize, numOfRecord);
    else if(option == 5)
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
        string bankName = "NA";
        string accNoOfBank = "NA";
        string date = "NA";
        string time = "NA";

        cout << "1. Amount (+/-):                 ";
        cin >> amount;
        cout << "2. Currency:                     ";
        cin >> currency;
        cout << "3. Character of payment (Usage): ";
        cin >> characterOfPayment;
        cout << "4. Payment method:               ";
        cin >> typeOfPayment;
        cout << "5. Bank name:                    ";
        cin >> bankName;
        cout << "6. Account no.:                  ";
        cin >> accNoOfBank;
        cout << "7. Date (DDMMYYYY)               ";
        cin >> date;
        cout << "8. Time (HHMM)                   ";
        cin >> time;

        cout << endl;
        cout << "A new record was added." << endl;
        cout << endl;

        Record newRecord{amount, currency, characterOfPayment, typeOfPayment, accNoOfBank, date, time};
        database.addRecord(newRecord, numOfRecord, databaseSize);

        cout << "Add another record? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'n')
            flag = false;
        else
            cout << endl;
    }
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
}

void menuBatchDel(Database &database, int &databaseSize, int &numOfRecord) //delete multiple records one time
{
    cout << "List the record you want to delete (divide the numbers by space): " << endl;
    int targetRecord{0};
    while (cin >> targetRecord){
        database.deleteRecord(targetRecord, numOfRecord, databaseSize);
        cout    << "Record " << targetRecord << " is deleted" << endl
                << "Next record to be deleted: ";
    }
}

void menuEditRecord(Database &database, int &databaseSize, int &numOfRecord)            //not complete below yet
{
    //code for edit record
    database.showDatabase(numOfRecord, 7);
    
    int targetRecord;
    cout << "Which record you would like to edit?" << endl;
    cout << "\nRecord: ";
    cin >> targetRecord;
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
    if(editOption == 1){
        cout << "Amount: ";
        double inputAmount{0.0};
        cin >> inputAmount;
        
        cout << "Currency: "
        string inputCurrency{""};
        cin >> inputCurrency;
        
        database.getAddress()[targetRecord].setAmount(inputAmount);
        database.getAddress()[targetRecord].setCurrency(inputCurrency);
        
    }
    else if(editOption == 2){
        double inputAmount{0.0};
        database.getAddress()[targetRecord].setAmount(inputAmount);
    }

    else if(editOption == 3)

    else if(editOption == 4)

    else if(editOption == 5)

    else if(editOption == 6)

    else if(editOption == 7)

    else if(editOption == 8)

    else
        //leave without change?
}

void menuSummaryReport(Database &database, int &databaseSize, int &numOfRecord)
{
    int choice{0};
    cout    << "Which type of summary report you would like to view?" << endl
            << "1 - Total" << endl
            << "2 - Annual" << endl
            << "3 - Year - Month" << endl
            << "Enter your choice: " << endl;
    this->summaryReportoutput(numOfRecord, choice);
}

void menuExit(Database &database, int &databaseSize, int &numOfRecord)
{
    //Exit option, save database to txt file before leaving
}


void summaryReportoutput(const int &numOfRecord, const int &choice){
    if(choice == 1)
        this->summaryTotalReportoutput(numOfRecord);
    else if(choice == 2){
        int year{1980};
        cout << "Please input the year: ";
        cin >> year;
        cout << endl;
        this->summaryAnnualReportoutput(numOfRecord, year);
    }
    else if(choice == 3){
        int year{1}, month{1};
        cout << "Please input the year: ";
        cin >> year;
        cout << "\nPlease input the month: ";
        cin >> month;
        cout << endl;
        this->summaryMonthlyReportoutput(numOfRecord, year, month);
    }
}

void summaryTotalReportoutput(const int &numOfRecord){
    cout    << fixed << setprecision(2)
            << "--Summary Report--" << std::endl
            << "Account balance = " << this->SUM(numOfRecord) << std::endl
            << std::endl
            << "Total expense = " << this->SUMExpense(numOfRecord, true) << std::endl
            << "Total deposit = " << this->SUMExpense(numOfRecord, false) << std::endl
            << std::endl
            << "Average = " << this->AVERAGE(numOfRecord) << std::endl
            << "Median = " << this->MEDIAN(numOfRecord)  << std::endl
            << std::endl
            << "Minimum expense = " << this->MINExpense(numOfRecord, true) << std::endl
            << "Maximum expense = " << this->MAXExpense(numOfRecord, true) << std::endl
            << std::endl
            << "Minimum deposit = " << this->MINExpense(numOfRecord, false) << std::endl
            << "Maximum deposit = " << this->MAXExpense(numOfRecord, false) << std::endl
            << std::endl
            << "Percentage of food expenses: " << this->percentageExpenseByCharacter(numOfRecord, 1, "F") << "%" << std::endl
            << "Percentage of fashion expenses: " << this->percentageExpenseByCharacter(numOfRecord, 1, "A") << "%" << std::endl
            << "Percentage of transportation expenses: " << this->percentageExpenseByCharacter(numOfRecord, 1, "T") << "%" << std::endl
            << std::endl;
}

void summaryAnnualReportoutput(const int &numOfRecord, const int &year){
    cout    << fixed << std::setprecision(2) 
            << "--Summary Report " << year << "--" << std::endl
            << "Account balance = " << this->SUM(numOfRecord, year) << std::endl
            << std::endl
            << "Total expense = " << this->SUMExpense(numOfRecord, true, year) << std::endl
            << "Total deposit = " << this->SUMExpense(numOfRecord, false, year) << std::endl
            << std::endl
            << "Average = " << this->AVERAGE(numOfRecord, year) << std::endl
            << "Median = " << this->MEDIAN(numOfRecord, year)  << std::endl
            << std::endl
            << "Minimum expense = " << this->MINExpense(numOfRecord, true, year) << std::endl
            << "Maximum expense = " << this->MAXExpense(numOfRecord, true, year) << std::endl
            << std::endl
            << "Minimum deposit = " << this->MINExpense(numOfRecord, false, year) << std::endl
            << "Maximum deposit = " << this->MAXExpense(numOfRecord, false, year) << std::endl
            << std::endl;
}

void summaryMonthlyReportoutput(const int &numOfRecord, const int &year, const int &month){
    cout    << fixed << std::setprecision(2) 
            << "--Summary Report " << year << "-" << month << "--" << std::endl
            << "Account balance = " << this->SUM(numOfRecord, year, month) << std::endl
            << std::endl
            << "Total expense = " << this->SUMExpense(numOfRecord, true, year, month) << std::endl
            << "Total deposit = " << this->SUMExpense(numOfRecord, false, year, month) << std::endl
            << std::endl
            << "Average = " << this->AVERAGE(numOfRecord, year, month) << std::endl
            << "Median = " << this->MEDIAN(numOfRecord, year, month)  << std::endl
            << std::endl
            << "Minimum expense = " << this->MINExpense(numOfRecord, true, year, month) << std::endl
            << "Maximum expense = " << this->MAXExpense(numOfRecord, true, year, month) << std::endl
            << std::endl
            << "Minimum deposit = " << this->MINExpense(numOfRecord, false, year, month) << std::endl
            << "Maximum deposit = " << this->MAXExpense(numOfRecord, false, year, month) << std::endl
            << std::endl;
}
