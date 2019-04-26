#include <iostream>
#include <string>

using namespace std;

string allToUpper(string str)                //convert and return a str with all lowercase to UPPERcase
{
    for(int i{0}; i<str.length(); i++)
    {
        if(str[i]>=97 && str[i]<=122)       //by ACSII table
            str[i] -= 32;
    }

    return str;
}

string allToLower(string str)               //convert and return a str with all UPPERcase to lowercase
{
    for(int i{0}; i<str.length(); i++)
    {
        if(str[i]>=65 && str[i]<=90)        //by ACSII table
            str[i] += 32;
    }

    return str;
}

string dateExtract(string date)             //convert date format like DD-MM-YYYY or DD/MM/YYYY to DDMMYYYY
{
    string temp = "";
    if(date.length() == 10)
    {
        temp += date.substr(0, 2);
        temp += date.substr(3, 2);
        temp += date.substr(6, 4);

        return temp;
    }
    else
    {
        cout << "Incorrect date format" << endl;
        return "NA";
    }
}

bool checkDate(string date)                 //check if date input is valid or not (month > 12 or day > 31) Assume date format: DDMMYYYY
                                            //return true if valid otherwise return false
{
    int day   = stoi(date.substr(0,2));
    int month = stoi(date.substr(2,2));
    int year  = stoi(date.substr(4,4));
    if(month>12 || month==0)
    {
        cout << "Invalid month! (month > 12)" << endl;
        return false;
    }
    else if(day>31 || day==0)
    {
        cout << "Invalid day! (day > 31)" << endl;
        return false;
    }
    else if((month == 4 || month == 6 || month == 9 || month == 11) && day>30)
    {
        cout << "Invalid day! (day > 30 in small month)" << endl;
        return false;
    }
    else if(month==2 && year%4!=0 && day>28)
    {
        cout << "Invalid day! (day > 28 in normal Feb)" << endl;
        return false;
    }
    else if(month==2 && year%4==0 && day>29)
    {
        cout << "Invalid day! (day > 29 in Feb of leap year)" << endl;
        return false;
    }
    else
        return true;
}

bool checkTime (string timeStr)             //check if time input is valid or not (e.g. hour>24 or minute>60) Format: HHMM
                                            //return true if valid otherwise return false
{
    int hour   = stoi(timeStr.substr(0,2));
    int minute = stoi(timeStr.substr(2,2));
    if (hour>23)
    {
        cout << "Invalid hour! (hour > 23)" << endl;
        return false;
    }
    else if (minute>59)
    {
        cout << "Invalid minute! (minute > 59)" << endl;
        return false;
    }
    else
        return true;
}
