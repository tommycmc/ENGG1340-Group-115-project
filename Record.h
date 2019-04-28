#ifndef _RECORD_H_
#define _RECORD_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "utilityFunction.h"

using namespace std;

class Record {
    friend ostream &operator<<(ostream &os, const Record &record);
private:                                    //for filter function ref from Database.h
    double Amount;                          //1
    string Currency;                                        //need currency conversion table txt - from https://www.xe.com/zh-HK/currencytables/?from=USD&date=2019-04-01
                                                            //convert USD/JPY/EUR/... -> HKD (for standardization)
    string characterOfPayment;              //2
    string typeOfPayment;                   //3
    string bankName;                        //4             //need bank code(first 3 digits of accNoOfBank) <-> bank name conversion table txt
    string accNoOfBank;                     //5
    string Date;                            //6
    string Time;                            //7

public:
    //Constructor//
    //Contructor - expect all 8 attributes(args)
    Record(double Amount, string Currency, string characterOfPayment, 
            string typeOfPayment, string bankName, string accNoOfBank, string Date, string Time);
    //Contructor - expect 7 attributes(args)
    Record(double Amount, string Currency, string characterOfPayment, 
            string typeOfPayment, string accNoOfBank, string Date, string Time);  
    //Contructor - expect 0 attributes(no args)
    Record();

    //Copy-constructor//
    Record(const Record &source);
    
    //Destructor//
    ~Record();
    
    //getter function//
    double getAmount() const;
    string getCurrency() const;
    string getCharacterOfPayment() const;
    string getTypeOfPayment() const;
    string getAccNoOfBank() const;
    string getDate() const;
    string getTime() const;
    
    string getBankName() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getHour() const;
    int getMinute() const;
    
    bool isExpense() const;
    
    //setter function//
    void setAmount(const double &inputAmount);
    void setCurrency(const string &inputCurrency);
    void setCharacterOfPayment(const string &inputCharacterOfPayment);
    void setTypeOfPayment(const string &inputTypeOfPayment);
    void setAccNoOfBank(const string &inputAccNoOfBank);
    void setDate(const string &inputDate);
    void setTime(const string &inputTime);
    
    //display function//
    void display() const;
};

#endif // _RECORD_H_
