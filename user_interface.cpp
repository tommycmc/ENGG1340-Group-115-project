#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include "Record.h"
#include "Database.h"
#include "utilityFunction.h"

using namespace std;

int topMenu(void)
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

    else if(option == 2)

    else if(option == 3)

    else if(option == 4)

    else if(option == 5)
}

void menuAddRecord(void)
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
        string Date = "NA";
        string Time = "NA";

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
        cin >> Date;
        cout << "8. Time (HHMM)                   ";
        cin >> Time;

        cout << endl;
        cout << "A new record was added." << endl;
        cout << endl;

        //addRecord{amount, currency, characterOfPayment, typeOfPayment,
        //            bankName, accNoOfBank, date, time};

        cout << "Add another record? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'n')
            flag = false;
        else
            cout << endl;
    }
}

void menuDelRecord(void)
{
    //code for edit record
    cout << "Which record you would like to delete?" << endl;
    //list recent 10 record maybe? with number
    //if want to edit older record, check showRecord function?
    int numOfRecord;
    cin >> numOfRecord;
    //show detail of record here
    cout << "Are you sure to delete this record? (y/n)" << endl;
    char choice;
    cin >> choice;
    if(choice == 'y')
        //delete record
    else
        //cancel delete action
}

//here is the batch delete function, use this replace upper one or having both?
void menuBatchDel(void) //delete multiple records one time
{
    cout << "List the record you want to delete (divide the numbers by space): " << endl;
    int numOfRecord;
    while (cin >> numOfRecord)
        //delete numOfRecord
}

void menuEditRecord(void)
{
    //code for edit record
    cout << "Which record you would like to edit?" << endl;
    //list recent 10 record maybe? with number
    //if want to edit older record, check showRecord function?
    int numOfRecord;
    cin >> numOfRecord;
    //show detail of record here
    cout << "1. Amount (+/-):                 " << amount << endl;
    cout << "2. Currency:                     " << currency << endl;
    cout << "3. Character of payment (Usage): " << characterOfPayment << endl;
    cout << "4. Payment method:               " << typeOfPayment << endl;
    cout << "5. Bank name:                    " << bankName << endl;
    cout << "6. Account no.:                  " << accNoOfBank << endl;
    cout << "7. Date (DDMMYYYY)               " << date << endl;
    cout << "8. Time (HHMM)                   " << time << endl;

    cout << "Which option you would like to edit? (1-8)" << endl;
    int editOption;
    cin >> editOption;
    if(editOption == 1)

    else if(editOption == 2)

    else if(editOption == 3)

    else if(editOption == 4)

    else if(editOption == 5)

    else if(editOption == 6)

    else if(editOption == 7)

    else if(editOption == 8)

    else
        //leave without change?
}

void menuShowRecord(void)
{
    //use report interface?
}

void menuExit(void)
{
    //Exit option, save database to txt file before leaving
}
