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
