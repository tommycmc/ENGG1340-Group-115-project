#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "Database.h"
#include <fstream>

//user interface//
void topMenu(Database &database, int &databaseSize, int &numOfRecord);
void menuAddRecord(Database &database, int &databaseSize, int &numOfRecord);
void menuDelRecord(Database &database, int &databaseSize, int &numOfRecord);
void menuBatchDel(Database &database, int &databaseSize, int &numOfRecord);
void menuEditRecord(Database &database, int &databaseSize, int &numOfRecord);
void menuDisplayRecord(Database &database, int &databaseSize, int &numOfRecord);
void menuSummaryReport(Database &database, int &databaseSize, int &numOfRecord);
void menuExit(Database &database, int &databaseSize, int &numOfRecord);

//validation//
void amountCheck(Database &database, const int &numOfRecord, double &amount);
void currencyCheck(Database &database, string &currency, double &amount);
void characterOfPaymentCheck(Database &database, string &characterOfPayment);
void typeOfPaymentCheck(Database &database, string &typeOfPayment);
void accNoOfBankCheck(Database &database, string &accNoOfBank);

//report interface//
void summaryReportoutput(Database &database, const int &numOfRecord, const int &choice);
void summaryTotalReportoutput(Database &database, const int &numOfRecord);
void summaryAnnualReportoutput(Database &database, const int &numOfRecord, const int &year);
void summaryMonthlyReportoutput(Database &database, const int &numOfRecord, const int &year, const int &month);


#endif // USER_INTERFACE_H
