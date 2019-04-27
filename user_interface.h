#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "Database.h"

//user interface//
void topMenu(Database &database, int &databaseSize, int &numOfRecord);
void menuAddRecord(Database &database, int &databaseSize, int &numOfRecord);
void menuDelRecord(Database &database, int &databaseSize, int &numOfRecord);
void menuBatchDel(Database &database, int &databaseSize, int &numOfRecord);
void menuEditRecord(Database &database, int &databaseSize, int &numOfRecord);
void menuSummaryReport(Database &database, int &databaseSize, int &numOfRecord);
void menuExit(Database &database, int &databaseSize, int &numOfRecord);



//report interface//
void summaryReportoutput(Database &database, const int &numOfRecord, const int &choice);
void summaryTotalReportoutput(Database &database, const int &numOfRecord);
void summaryAnnualReportoutput(Database &database, const int &numOfRecord, const int &year);
void summaryMonthlyReportoutput(Database &database, const int &numOfRecord, const int &year, const int &month);


#endif // USER_INTERFACE_H
