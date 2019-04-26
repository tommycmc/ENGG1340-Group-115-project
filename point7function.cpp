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
        if(str[i]>=65 && str[i]<=90)       //by ACSII table
            str[i] += 32;
    }

    return str;
}

string dateConvert(string date)             //convert date format like DD-MM-YYYY or DD/MM/YYYY to DDMMYYYY
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
