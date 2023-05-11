#pragma once
char* convertIntToChar(int so) {
    stringstream ss;
    ss << so;
    string str;
    str = ss.str();
    char* tmp = new char[str.size() + 1];
    strcpy_s(tmp, str.size() + 1, str.c_str());
    return tmp;
}

char* convertStringToChar(string str) {
    char* tmp = new char[str.size() + 1];
    strcpy_s(tmp, str.size() + 1, str.c_str());
    return tmp;
}





// dung cho MessageBoxx
wchar_t* convertCharArrayToLPCWSTR(const char* charArray)
{
    wchar_t* wString = new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
    return wString;
}
