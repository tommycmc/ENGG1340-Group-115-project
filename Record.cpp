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
    : Record{inputAmount, allToUpper(inputCurrency), allToUpper(inputCharacterOfPayment), allToUpper(inputTypeOfPayment), "NA", inputAccNoOfBank, dateExtract(inputDate), inputTime} {
    if(allToUpper(accNoOfBank) == "NULL")
        bankName = "NULL";                          
    else{        
        ifstream bankCodeConvertFile{"../bankCodeConvert.txt"};            //Assume the file is existed
        string bankCode{accNoOfBank.substr(0, 3)};
        
        string searchBankCode{""};
        string line{""};
        
        while(getline(bankCodeConvertFile, line)){
            stringstream sLine{line};
            sLine >> searchBankCode;
            if(searchBankCode == bankCode){
                getline(sLine, bankName);
                bankName = bankName.substr(1);
                break;
            }
        }
        bankCodeConvertFile.close();
    }
    
    if(allToUpper(Currency) != "HKD"){
        ifstream currencyConvertFile{"../currencyConvert.txt"};            //Assume the file is existed
        string extCurrency{""};
        double exchangeRate{-1.0};
        while(currencyConvertFile >> extCurrency >> exchangeRate){
            if(extCurrency == allToUpper(Currency)){
                Amount *= exchangeRate;
                Currency = "HKD";
                break;
            }
        }
        if(exchangeRate == -1.0)
            Currency = "NA";
        
        currencyConvertFile.close();
    }
     
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

bool Record::isExpense() const{
    return (Amount <= 0);
}



//setter function//
void Record::setAmount(const double &inputAmount){
    if(Amount != inputAmount)                                                       //reject duplicate input value
        Amount = inputAmount;
    else 
        cout << "no change - not edit amount field" << endl;
}
void Record::setCurrency(const string &inputCurrency){
    if(Currency != inputCurrency){                                                //reject duplicate input value
        if(allToUpper(Currency) != "HKD"){
            ifstream currencyConvertFile{"../currencyConvert.txt"};            //Assume the file is existed
            string extCurrency{""};
            double exchangeRate{-1.0};
            while(currencyConvertFile >> extCurrency >> exchangeRate){
                if(extCurrency == allToUpper(Currency)){
                    Amount *= exchangeRate;
                    Currency = "HKD";
                    break;
                }
            }
            if(exchangeRate == -1.0)
                Currency = "NA";
            
            currencyConvertFile.close();
        }
    else
        cout << "no change - not edit currency field" << endl;
    }
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
        if(allToUpper(accNoOfBank) == "NULL")
            bankName = "NULL";                          
        else{        
            ifstream bankCodeConvertFile{"../bankCodeConvert.txt"};            //Assume the file is existed
            string bankCode{inputAccNoOfBank.substr(0, 3)};
            
            string searchBankCode{""};
            string line{""};
            
            
            while(getline(bankCodeConvertFile, line)){
                stringstream sLine{line};
                sLine >> searchBankCode;
                if(searchBankCode == bankCode){
                    getline(sLine, bankName);
                    bankName = bankName.substr(1);
                    cout << bankName << endl;
                    break;
                }
            }
            bankCodeConvertFile.close();
            accNoOfBank = inputAccNoOfBank;
        }
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
    cout << fixed << setprecision(2) << Amount << "\t" << Currency << "\t" << characterOfPayment << "\t" << typeOfPayment << "\t" 
         << bankName << "\t" << accNoOfBank << "\t" << Date << "\t" << Time << endl;
}

ostream &operator<<(ostream &os, const Record &record){
    os << fixed << setprecision(2) << record.getAmount() << "," << record.getCurrency() << "," << record.getCharacterOfPayment() << "," << record.getTypeOfPayment() << "," 
         << record.getBankName() << "," << record.getAccNoOfBank() << "," << record.getDate() << "," << record.getTime();
    return os;
}
