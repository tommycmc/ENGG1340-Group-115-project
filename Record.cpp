#include "Record.h"
#include <iostream>

Record::Record(double inputAmount, string inputCurrency, string inputCharacterOfPayment, string inputTypeOfPayment, 
                        string inputBankName, string inputAccNoOfBank, string inputDate, string inputTime) 
    : Amount(inputAmount), Currency(inputCurrency), characterOfPayment(inputCharacterOfPayment), 
            typeOfPayment(inputTypeOfPayment), bankName(inputBankName), accNoOfBank(inputAccNoOfBank), Date(inputDate), Time(inputTime){
}


Record::Record() 
    : Record{0, "NA", "NA", "NA", "NA", "NA", "NA", "NA" }{
}

Record::Record(double inputAmount, string inputCurrency, string inputCharacterOfPayment, 
                        string inputTypeOfPayment, string inputAccNoOfBank, string inputDate, string inputTime)
    : Record{inputAmount, inputCurrency, inputCharacterOfPayment, inputTypeOfPayment, "NA", inputAccNoOfBank, inputDate, inputTime} {
    bankName = "HSBC";  
    cout << "added 1 record" << endl;
}

Record::Record(const Record &source)
    : Record{source.Amount, source.Currency, source.characterOfPayment, source.typeOfPayment, source.bankName, 
                        source.accNoOfBank, source.Date, source.Time}{
    cout << "used" << endl;
}

Record::~Record() {
    cout << "delete 1 record" << endl;
}

void Record::display() const{
    cout << Amount << "," << Currency << "," << characterOfPayment << "," << typeOfPayment << "," 
         << bankName << "," << accNoOfBank << "," << Date << "," << Time << endl;
}

//getter function//
double Record::getAmount() const{
    return Amount;
}

string Record::getCurrency() const{
    return Currency;
}

string Record::getCharacterOfPayment() const{
    return characterOfPayment;
}

string Record::getTypeOfPayment() const{
    return typeOfPayment;
}

string Record::getAccNoOfBank() const{
    return accNoOfBank;
}

string Record::getDate() const{
    return Date;
}

string Record::getTime() const{
    return Time;
}


//setter function//
void Record::setAmount(const double &inputAmount){
    Amount = inputAmount;
}
void Record::setCurrency(const string &inputCurrency){
    Currency = inputCurrency;
}
void Record::setCharacterOfPayment(const string &inputCharacterOfPayment){
    characterOfPayment = inputCharacterOfPayment;
}
void Record::setTypeOfPayment(const string &inputTypeOfPayment){
    typeOfPayment = inputTypeOfPayment;
}
void Record::setAccNoOfBank(const string &inputAccNoOfBank){
    accNoOfBank = inputAccNoOfBank;
}
void Record::setDate(const string &inputDate){
    Date = inputDate;
}
void Record::setTime(const string &inputTime){
    Time = inputTime;
}
