#pragma once
#include"UI.h"
class Input : public UI {
protected:
    // char id[2];
    char content[50];
    int type;
    char title[30];
    int maxChar;
    int textColor;
    bool check = false;
    int size;
public:
    Input(string content, int type, string title, int maxChar, int textColor, int left, int right, int top, int bottom, int backgroundColor, int borderColor, int size) :UI(left, right, top, bottom, backgroundColor, borderColor) {
        strcpy_s(this->content, content.size() + 1, content.c_str());
        this->type = type;
        strcpy_s(this->title, title.c_str());
        this->maxChar = maxChar;
        this->textColor = textColor;
        this->size = size;
    }
    void draw() {
        UI::draw();
        settextstyle(10, 0, size);
        setbkcolor(backgroundColor);
        setcolor(textColor);
        outtextxy(left - textwidth(title) - 2, (top + bottom - textheight(title)) / 2, title);
        outtextxy(left + 5, (top + bottom - textheight(content)) / 2, content);

    }
    void setCheck(bool check) {
        this->check = check;
    }
    bool getCheck() {
        return this->check;
    }
    wchar_t* convertCharArrayToLPCWSTR(const char* charArray)
    {
        wchar_t* wString = new wchar_t[4096];
        MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
        return wString;
    }
    char* getContent() {
        return this->content;
    }
    char* chuanHoa(char* a) {
        if (strlen(a) == 0) {
            return a;
        }
        else {
            bool check = 0;
            char s[50];
            int tmp = 0;
            for (int i = 0; i < strlen(a); i++) {
                if (check == 1 || a[i] != ' ') {
                    s[tmp++] = a[i];
                }
                if (a[i] != ' ') check = 1;
                else check = 0;
            }
            s[tmp] = '\0';
            char* temp = new char[strlen(s) + 1];
            strcpy_s(temp, strlen(s) + 1, s);
            return temp;
        }
    }
    void addChar() {
        int tmp = strlen(content);
        if (tmp > 0 && content[0] == ' ') {
            tmp = 0;
        }
        content[tmp + 1] = '\0';
        content[tmp] = '|';
        char c;
        while (kbhit()) c = getch();
        while (1) {
            delay(10);
            outtextxy(left + 5, (top + bottom - textheight(content)) / 2, content);
            if (check = true) {
                if (kbhit()) {
                    c = getch();
                    if (this->type == 2) {
                        if (97 <= c && c <= 122) {
                            c = c - 32;
                        }
                    }
                    else if (this->type == 3) {
                        while (1) {
                            if ((97 <= c && c <= 122) || (65 <= c && c <= 90)) {
                                MessageBox(
                                    NULL,
                                    (LPCWSTR)convertCharArrayToLPCWSTR("VUI LONG NHAP SO"),
                                    (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                                    MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
                                );
                                c = getch();
                            }
                            else {
                                break;
                            }
                        }
                    }
                    if (c == 8 && tmp > 0) {
                        if (strlen(content) > 0) {
                            content[tmp] = ' ';
                            content[tmp + 1] = '\0';
                            content[--tmp] = '|';
                        }
                    }
                    else if (c != 8 && tmp < this->maxChar && this->check == true) {
                        if (strlen(content) < 50) {
                            content[tmp++] = c;
                            content[tmp] = '\0';
                        }
                    }
                }

                else if (!kbhit()) {
                    content[tmp] = '|';
                    content[tmp + 1] = '\0';
                    delay(100);
                    outtextxy(left + 5, (top + bottom - textheight(content)) / 2, content);
                    content[tmp] = ' ';
                    content[tmp + 1] = '\0';
                    delay(100);
                    outtextxy(left + 5, (top + bottom - textheight(content)) / 2, content);
                }
            }


            if (ismouseclick(WM_LBUTTONDOWN)) {
                content[tmp] = '\0';
                break;
            }
        }
    }
    bool checkRong() {
        return (strlen(content) != 0);
    }
};
