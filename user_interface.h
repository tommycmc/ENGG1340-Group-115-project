#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "Database.h"

//user interface//
int Database::topMenu(void);
Record Database::menuAddRecord(void);
void Database::menuDelRecord(void);
void Database::menuBatchDel(void);
void Database::menuEditRecord(void);
void Database::menuShowRecord(void);
void Database::menuExit(void);



//report interface//
void Database::summaryReportoutput(const int &numOfRecord, const int choice);
void Database::summaryTotalReportoutput(const int &numOfRecord);
void Database::summaryAnnualReportoutput(const int &numOfRecord, const int &year);
void Database::summaryMonthlyReportoutput(const int &numOfRecord, const int &year, const int &month);


#endif // USER_INTERFACE_H
