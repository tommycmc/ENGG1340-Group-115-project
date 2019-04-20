#ifndef _RECORD_H_
#define _RECORD_H_

#include <iostream>
#include <string>

using namespace std;

class Record {
private:
    double Amount;
    string Currency;
    string characterOfPayment;
    string typeOfPayment;
    string bankName;
    string accNoOfBank;
    string Date;
    string Time;
public:
    //Contructor - expect all 8 attributes(args)
    Record(double Amount, string Currency, string characterOfPayment, 
            string typeOfPayment, string bankName, string accNoOfBank, string Date, string Time);
    //Contructor - expect 7 attributes(args)
    Record(double Amount, string Currency, string characterOfPayment, 
            string typeOfPayment, string accNoOfBank, string Date, string Time);  
    //Contructor - expect 0 attributes(no args)
    Record();

    //Copy-constructor
    Record(const Record &source);
    
    //Destructor
    ~Record();
    
    void display() const;
    
    //getter function
    double getAmount() const;
    string getCurrency() const;
    string getCharacterOfPayment() const;
    string getTypeOfPayment() const;
    string getAccNoOfBank() const;
    string getDate() const;
    string getTime() const;
    
    //setter function
    void setAmount(const double &inputAmount);
    void setCurrency(const string &inputCurrency);
    void setCharacterOfPayment(const string &inputCharacterOfPayment);
    void setTypeOfPayment(const string &inputTypeOfPayment);
    void setAccNoOfBank(const string &inputAccNoOfBank);
    void setDate(const string &inputDate);
    void setTime(const string &inputTime);
};

#endif // _RECORD_H_
