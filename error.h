#ifndef ERROR_H
#define ERROR_H

#define ERRORMSG1 "Error initializing SDL!"
#define ERRORMSG2 "Error initializing video mode!"
#define ERRORMSG3 "Error loading file "
#define ERRORMSG4 "Error, invalid arguments! Usage: mapeditor filename"

#include <windows.h>
#include <string>

extern bool error;
extern int errorID;

void makeError(int ID, std::string param = "");
std::string getErrorMsg(int ID);

#endif
