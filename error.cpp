#include "error.h"

bool error;
int errorID;

void makeError(int ID, std::string param)
{
    error = 1;
    errorID = ID;

    std::string msg = getErrorMsg(ID);

    if (ID==3) msg = msg + param;

    MessageBox(NULL, msg.c_str(), NULL, MB_OK);
}

std::string getErrorMsg(int ID)
{
    switch (ID)
    {
        case 1:
            return ERRORMSG1;
        case 2:
            return ERRORMSG2;
        case 3:
            return ERRORMSG3;
        case 4:
            return ERRORMSG4;
        default:
            return "";
    }
}
