#include "Record.h"

//Contructor - expect all 8 attributes(args)//
Record::Record(double inputAmount, string inputCurrency, string inputCharacterOfPayment, string inputTypeOfPayment, 
                        string inputBankName, string inputAccNoOfBank, string inputDate, string inputTime) 
    : Amount(inputAmount), Currency(inputCurrency), characterOfPayment(inputCharacterOfPayment), 
            typeOfPayment(inputTypeOfPayment), bankName(inputBankName), accNoOfBank(inputAccNoOfBank), Date(inputDate), Time(inputTime){
}

//Contructor - expect 0 attributes(no args)
Record::Record() 
    : Record{0, "NA", "NA", "NA", "NA", "NA", "NA", "NA" }{
}

//Contructor - expect 7 attributes(args)//
Record::Record(double inputAmount, string inputCurrency, string inputCharacterOfPayment, 
                        string inputTypeOfPayment, string inputAccNoOfBank, string inputDate, string inputTime)
    : Record{inputAmount, inputCurrency, inputCharacterOfPayment, inputTypeOfPayment, "NA", inputAccNoOfBank, inputDate, inputTime} {
    if(allToUpper(accNoOfBank) == "NULL")
        bankName = "NULL";                          //need add code convertor
    else
        bankName = "HSBC";  
}

//Copy-constructor//
Record::Record(const Record &source)
    : Record{source.Amount, source.Currency, source.characterOfPayment, source.typeOfPayment, source.bankName, 
                        source.accNoOfBank, source.Date, source.Time}{
}

//Destructor//
Record::~Record() {
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

string Record::getBankName() const{
    return bankName;
}
int Record::getDay() const{                                //Date format: DDMMYYYY
    return stoi(Date.substr(0, 2));                                         //capture first 2 characters, remove leading zero, and turn it into int
}
int Record::getMonth() const{
    return stoi(Date.substr(2, 2));                                         //capture next 2 characters, remove leading zero, and turn it into int
}
int Record::getYear() const{
    return stoi(Date.substr(4, 4));                                         //capture last 4 characters, remove leading zero, and turn it into int
}
int Record::getHour() const{                                //Time format: HHMM
    return stoi(Time.substr(0, 2));                                         //capture first 2 characters, remove leading zero, and turn it into int
}
int Record::getMinute() const{
    return stoi(Time.substr(2, 2));                                         //capture last 2 characters,remove leading zero, and turn it into int
}




//setter function//
void Record::setAmount(const double &inputAmount){
    if(Amount != inputAmount)                                                       //reject duplicate input value
        Amount = inputAmount;
    else 
        cout << "no change - not edit amount field" << endl;
}
void Record::setCurrency(const string &inputCurrency){
    if(Currency != inputCurrency)                                                   //reject duplicate input value
        Currency = inputCurrency;
    else
        cout << "no change - not edit currency field" << endl;
}
void Record::setCharacterOfPayment(const string &inputCharacterOfPayment){
    if(characterOfPayment != inputCharacterOfPayment)                               //reject duplicate input value
        characterOfPayment = inputCharacterOfPayment;
    else
        cout << "no change - not edit characterOfPayment field" << endl;
}
void Record::setTypeOfPayment(const string &inputTypeOfPayment){
    if(typeOfPayment != inputTypeOfPayment)                                         //reject duplicate input value
        typeOfPayment = inputTypeOfPayment;
    else 
        cout <<  "no change - not edit typeOfPayment field" << endl;
}
void Record::setAccNoOfBank(const string &inputAccNoOfBank){
    if(accNoOfBank != inputAccNoOfBank){                                             //reject duplicate input value
        if(allToUpper(inputAccNoOfBank) == "NULL")
            bankName = "NULL";                          //need add code convertor
        else
            bankName = "HSBC";  
        accNoOfBank = inputAccNoOfBank;
    }
    else
        cout << "no change - not edit accNoOfBank field" << endl;
}
void Record::setDate(const string &inputDate){
    if(Date != inputDate)                                                           //reject duplicate input value
        Date = inputDate;
    else
        cout << "no change - not edit Date field" << endl;
}
void Record::setTime(const string &inputTime){
    if(Time != inputTime)                                                           //reject duplicate input value
        Time = inputTime;
    else
        cout << "no change - not edit Time field" << endl;
}




//display function//
void Record::display() const{
    cout << Amount << "," << Currency << "," << characterOfPayment << "," << typeOfPayment << "," 
         << bankName << "," << accNoOfBank << "," << Date << "," << Time << endl;
}
