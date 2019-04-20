# ENGG1340-Group-115-project

## Problem statement
Question 4: <br/>
To build an accounting system to help user keep track of his/her income and expense. <br/>
The system also allows the user to display their records with certain filtering and sorting methods.

## Problem setting
1.  Due to privacy concern, we only consider one user in this accounting system. We also assume that his/her basic information has already been stated in the system, e.g. name, age, residential address, etc. Only two initialized data, amount of current bank account in terms of Hong Kong Dollars and the date of the account created, will be used in this program.

2.  Here is our intended attributes used in this program.

|     Field name     | Data type |          Description          |  Example of data  |
|     :----------:   |:---------:|          -----------          | :---------------: |
|       Amount       |   Double  | Amount of this transaction <br/>                                                                                                       (sign ‘+’ represents deposit and ‘-’ represents withdrawal) rounding to 2 decimal numbers | +14500.67 |
|      Currency      |   String  | Amount based on different currencies will convert to HKD using currency conversion table, lowercase currencies are acceptable | USD |
| characterOfPayment |   String  | Characteristics of payment includes: <br/>                                                                                              F/f(food and drink), A/a(fashion: clothing, shoes), B/b(bill), T/t(transportation fee) and S/s(salary) | S |
|   typeOfPayment    |   String  | Types of payment includes: <br/>                                                                                                        C/c(credit/debit card), H/h(cheque) and A/a(cash) | C |
|     bankName       |   String  | The name of current bank <br/>                                                                                                          (if deposit/withdrawal occurs outside the bank, NULL will be used; <br/>                                                                 if the deposit/withdrawal operation is in the bank, the program will auto-fill the field since the                                       leftmost 3-digit account number could identify which name of the bank belongs to) | HSBC |
|     accNoOfBank    |   String  | The account number of the bank with the format of AAABBBBBBBBB, AAA represents the bank code, BBBBBBBBB represents the corresponding account number [9-digit number will be assumed] <br/>                                                      (if deposit/withdrawal occurs outside the bank, NULL will be used; AAA-BBBBBBBBB will be converted to the above format automatically) | 004123456789 |
|       Date         |   String  | The date of the record with the format of DDMMYYYY <br/>                                                                                (DD-MM-YYYY or DD/MM/YYYY will be converted to the above format automatically) | 25032019 |
|       Time         |   String  | The time of the record with the format of 24-clock time HHMM <br/>                                                                      (12-clock time AM/PM will be converted to the above format automatically) | 1506 |

3.  The currency conversion data regarding HKD will be extracted from XE.com on 1st April, 2019 at 16:00 GMT and save it as currencyConvert.txt. The format of it likes this.

|  Currency  |     Rate     |
| :--------: |      :--:    |
|     USD    | 0.1273971466 |
|     EUR    | 0.1132153321 |
|     GBP    | 0.0964720740 |
|     ...    |      ...     |



## Features
1.	Data initialization and reset <br/>
    User could initialize the basic information or reset the system to original state
2.	Ability to control records  <br/>
    The records could be added, deleted and edited at any time
3.	Ability to display records according to user's preference <br/>
    The records could be displayed, filtered and sorted by certain criteria <br/>                                                           e.g. date, date and time, type, account, etc.
4.	Statistical report of users’ financial state <br/>                                                                                       The system could display the summary report in certain period of time, e.g. 1 month, 3 months, half an year, a year, etc.
    e.g. monthly income and expenses, percentage of food expenses, etc.
5.	Budget setting <br/>                                                                                                                     When expenses reach the budget, there should be an alert from the system
6.	Data validation <br/>
    If wrong data is input to the program, the request will be rejected and prompt the user to enter the data again <br/>
    e.g. If the amount of account is negative, no further deposit will be allowed.
7.	User-friendly design <br/>
    Operation code can be entered no matter it is uppercase or lowercase alphabetic characters, in different formats, field could be auto-filled <br/>                                                                                                                           e.g. C/H/A or c/h/a, auto-correct the format of date, time clock, account number, currency of bank entered by the user, auto-fill       the name of the bank, etc
8.	Cached result <br/>
    Once the user requests sorting list of data, the content of sorted list will be place in elsewhere. <br/>                               If the records in the system doesn’t change, and the user requests the records by the same filtered and sorting method, the cached       result will be displayed without searching the entire records in the system.
