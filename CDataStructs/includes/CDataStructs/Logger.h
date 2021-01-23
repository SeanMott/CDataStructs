//defines a logger for the Data Types

#ifndef CDataStructs_Logger_h
#define CDataStructs_Logger_h

#include <stdio.h>
#include <stdlib.h>

#define CDataStructs_LogMessage(message) printf("CDataStructs: %s\n", message);
#define CDataStructs_LogWarning(type, message) printf("CDataStructs Warning: %s || %s\n", type, message);
#define CDataStructs_LogError(type, message) printf("CDataStructs Error: %s || %s\n", type, message);

//will hold the console open using getchar()
#define CDataStructs_LogFatalError(type, message) printf("CDataStructs Fatal Error: %s || %s\n", type, message); getchar(); exit(1);

#define CDataStructs_LogData(formate, message) printf(formate, message);

//will hold the console open using getchar()
#define CDataStructs_LogFatalData(formate, message) printf(formate, message); getchar(); exit(1);

#endif