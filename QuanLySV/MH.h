
#pragma once
#include"Const.h"
#include"Input.h"
#include"Convert.h"
#include"Button.h"


class Subject {
private:
    char maMH[11];
    char tenMH[51];
    int tcTH;
    int tcLT;
    bool moLop;
public:
    Subject();
    void setMaMH(const char* maMH);
    char* getMaMH();
    void setTenMH(const char* tenMH);
    char* getTenMH();
    void setTCTH(int tcTH);
    int getTCTH();
    void setTCLT(int tcLT);
    int getTCLT();
    void setData(Subject data);
    void setMoLop(bool moLop);
    bool getMoLop();
};
class Node {
private:
    Subject data;
    Node* left;
    Node* right;
public:
    Node();
    Node(Subject data);
    void setData(const Subject& data);
    Subject& getData();
    // truyền tham chiếu để có thể thay đổi biến trong dễ dàng hơn 
    void setLeft(Node* left);
    Node*& getLeft();
    void setRight(Node* right);
    Node*& getRight();
};
class treeMH {
private:
    Node* root;
public:
    treeMH();
    void setRoot(Node* root);
    Node*& getRoot();
    void DeleteNode(Node* r);
    // them mon hoc vao cay 
    void themNode(Node*& r, Subject& key, int& check);
    // xoa mon hoc
    Node* xoaNode(Node*& r, char* key);
    bool checkTrung(Node*& tmp,string maMH);
    int soNode(Node* r);
    void vietDataMH(Node* r, ofstream& fileOut);
    void vietDataDSMH(int n);
    void xuatDataMH();
    //nhap cay vao mang de sau xep theo ten
    void nhapCayVaoMang(Subject arr[], Node* r, int& n);
    void Swap(Subject& a, Subject& b);
    void sortTheoTen(Subject arr[], int n);
    void locMH(string s, Subject loc[], Subject arr[], int& soLuong, int n);
    void nhapMH(string str1, string str2, string str3, string str4, int check);
    void nhapLocMH(char* s, int& t, thaoTac& hDMH);
    void xuat1Trang(Subject arrMH[], int batDau, int ketThuc, Table Bang);
    void xuatTrang(Subject*& arrMH, int tongSoDong, thaoTac& hD, char* s, int& t, int& on);
    void menuSetMH(int& on);

};

// class subject
Subject::Subject() {
    strcpy_s(this->maMH, strlen("") + 1, "");
    strcpy_s(this->tenMH, strlen("") + 1, "");
    this->tcLT = 0;
    this->tcTH = 0;
    this->moLop = false;
}
void Subject::setMaMH(const char* maMH) {
    strcpy_s(this->maMH, strlen(maMH) + 1, maMH);
}
char* Subject::getMaMH() {
    return this->maMH;
}
void Subject::setTenMH(const char* tenMH) {
    strcpy_s(this->tenMH, strlen(tenMH) + 1, tenMH);
}
char* Subject::getTenMH() {
    return this->tenMH;
}
void Subject::setTCTH(int tcTH) {
    this->tcTH = tcTH;
}
int Subject::getTCTH() {
    return this->tcTH;
}
void Subject::setTCLT(int tcLT) {
    this->tcLT = tcLT;
}
int Subject::getTCLT() {
    return this->tcLT;
}
void Subject::setData(Subject data) {
    strcpy_s(this->maMH, strlen(data.maMH) + 1, data.maMH);
    strcpy_s(this->tenMH, strlen(data.tenMH) + 1, data.tenMH);
    this->tcLT = data.tcLT;
    this->tcTH = data.tcTH;
    this->moLop = data.moLop;
}
void Subject::setMoLop(bool moLop) {
    this->moLop = moLop;
}
bool Subject::getMoLop() {
    return this->moLop;
}
// class NodeMH
Node::Node() {
    this->left = NULL;
    this->right = NULL;
}
Node::Node(Subject data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}
void Node::setData(const Subject& data) {
    this->data.setData(data);
}
Subject& Node::getData() {
    return this->data;
}
// truyền tham chiếu để có thể thay đổi biến trong dễ dàng hơn 
void Node::setLeft(Node* left) {
    this->left = left;
}
Node*& Node::getLeft() {
    return this->left;
}
void Node::setRight(Node* right) {
    this->right = right;
}
Node*& Node::getRight() {
    return this->right;
}
// class TreeMH
treeMH::treeMH() {
    root = NULL;
}
void treeMH::setRoot(Node* root) {
    this->root = root;
}
Node*& treeMH::getRoot() {
    return root;
}
void treeMH::DeleteNode(Node* r) {
    if (r == NULL)return;
    DeleteNode(r->getLeft());
    DeleteNode(r->getRight());
    delete r;
    r = NULL;
}
// check trung maMH
bool treeMH::checkTrung(Node*& tmp,string maMH) {
    if (tmp == NULL) return false;
    if (strcmp(maMH.c_str(), tmp->getData().getMaMH()) < 0) {
        return (checkTrung(tmp->getLeft(), maMH) == true) ? true : false;
    }
    else if (strcmp(maMH.c_str(), tmp->getData().getMaMH()) > 0) {
        return (checkTrung(tmp->getLeft(), maMH) == true) ? true : false;
    }
    else return true;
}
// them mon hoc vao cay 
void treeMH::themNode(Node*& r, Subject& key, int& check) {
    if (r == NULL) {
        r = new Node(key);
        check = 0;
    }
    else {
        if (strcmp(key.getMaMH(), r->getData().getMaMH()) == 0) {
            if (check == 2) {
                // sửa node 
                r->getData().setMaMH(key.getMaMH());
                r->getData().setTenMH(key.getTenMH());
                r->getData().setTCTH(key.getTCTH());
                r->getData().setTCLT(key.getTCLT());
                check = 0;
                return;
            }
            //node trùng 
            check = 1;
            return;
        }
        else if (strcmp(key.getMaMH(), r->getData().getMaMH()) < 0) {
            themNode(r->getLeft(), key, check);
        }
        else if (strcmp(key.getMaMH(), r->getData().getMaMH()) > 0) {
            themNode(r->getRight(), key, check);
        }
    }
}
// xoa mon hoc
Node* treeMH::xoaNode(Node*& r, char* maMH) {

    if (r == NULL) {
        return NULL;
    }
    else if (strcmp(maMH, r->getData().getMaMH()) < 0) {
        r->setLeft(xoaNode(r->getLeft(), maMH));
    }
    else if (strcmp(maMH, r->getData().getMaMH()) > 0) {
        r->setRight(xoaNode(r->getRight(), maMH));
    }
    else {
        if (r->getLeft() == NULL && r->getRight() == NULL) {
            delete r;
            r = NULL;
        }
        else if (r->getLeft() == NULL && r->getRight() != NULL) {
            Node* tmp = r->getRight();
            r->setRight(NULL);
            delete r;
            return tmp;

        }
        else if (r->getRight() == NULL && r->getLeft() != NULL) {
            Node* tmp = r->getLeft();
            r->setLeft(NULL);
            delete r;
            return tmp;
        }
        else {
            Node* tmp = r->getRight();
            while (tmp && tmp->getLeft() != NULL) {
                tmp = tmp->getLeft();
            }
            r->getData().setMaMH(tmp->getData().getMaMH());
            r->getData().setTenMH(tmp->getData().getTenMH());
            r->getData().setTCTH(tmp->getData().getTCTH());
            r->getData().setTCLT(tmp->getData().getTCLT());
            r->setRight(xoaNode(r->getRight(), tmp->getData().getMaMH()));
        }
    }
    return r;
}
int treeMH::soNode(Node* r) {
    if (r == NULL) {
        return 0;
    }
    return 1 + soNode(r->getLeft()) + soNode(r->getRight());
}
//nhap cay vao mang de sau xep theo ten
void treeMH::nhapCayVaoMang(Subject arr[], Node* r, int& n) {
    if (r != NULL) {
        nhapCayVaoMang(arr, r->getLeft(), n);
        if (r != NULL) {
            arr[n++] = r->getData();
        }
        nhapCayVaoMang(arr, r->getRight(), n);
    }
}
void treeMH::Swap(Subject& a, Subject& b) {
    Subject tmp = a;
    a = b;
    b = tmp;
}
void treeMH::sortTheoTen(Subject arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i].getTenMH(), arr[j].getTenMH()) > 0) {
                Swap(arr[i], arr[j]);
            }
        }
    }
}
void treeMH::locMH(string s, Subject loc[], Subject arr[], int& soLuong, int n) {
    soLuong = 0;
    if (!s.empty()) {
        for (int i = 0; i < n; i++) {
            if (string(arr[i].getTenMH()).find(s) != string::npos) {
                loc[soLuong++] = arr[i];
            }

        }
    }
    else {
        for (int i = 0; i < n; i++) {
            loc[soLuong++] = arr[i];
        }
    }
}
void treeMH::vietDataMH(Node* r, ofstream& fileOut) {
    char tmp = ',';
    if (r != NULL) {
        vietDataMH(r->getLeft(), fileOut);
        fileOut << r->getData().getMaMH();
        fileOut << tmp;
        fileOut << r->getData().getTenMH();
        fileOut << tmp;
        fileOut << r->getData().getTCLT();
        fileOut << tmp;
        fileOut << r->getData().getTCTH();
        fileOut << tmp;
        fileOut << r->getData().getMoLop();
        fileOut << '\n';
        vietDataMH(r->getRight(), fileOut);
    }
}
void treeMH::vietDataDSMH(int n) {
    
    ofstream fileOut;
    fileOut.open((dataMH.c_str()), ios::trunc);
    fileOut << n << endl;
    if (fileOut.is_open()) {
        if (this->root != NULL) {
            vietDataMH(root, fileOut);
        }
    }
    fileOut.close();
}
void treeMH::xuatDataMH() {
    int n = 0;
    ifstream fileIn;
    char tmp;
    string tmpStr;
    int tmpInt;
    int check = 0;
    fileIn.open(dataMH.c_str(), ios::in);
    fileIn >> n;
    if (fileIn.is_open()) {
        while (!fileIn.eof()) {
            Subject MH;
            fileIn.ignore();
            getline(fileIn, tmpStr, ',');
            if (tmpStr == "") break;
            MH.setMaMH(tmpStr.c_str());
            getline(fileIn, tmpStr, ',');
            MH.setTenMH(tmpStr.c_str());
            fileIn >> tmpInt;
            MH.setTCLT(tmpInt);
            fileIn >> tmp;
            fileIn >> tmpInt;
            MH.setTCTH(tmpInt);
            fileIn >> tmp;
            fileIn >> tmpInt;
            MH.setMoLop(bool(tmpInt));
            //fileIn.ignore();
            themNode(root, MH, check);
            if (fileIn.eof()) break;
        }
    }
    fileIn.close();
}
void treeMH::xuat1Trang(Subject arrMH[], int batDau, int ketThuc, Table Bang) {
    int soDong = ketThuc % maxDong;
    if (soDong == 0) soDong = maxDong;
    if (ketThuc == 0 && batDau == 0) soDong = maxDong;
    else {
        int soDongTrong = maxDong - ketThuc % maxDong;
        soDong = ketThuc % maxDong == 0 ? ketThuc : ketThuc + soDongTrong;
    }
    char* STT = convertIntToChar(0);


    int x = tableLeft;
    int y = tableTop + kcY / 2 - textheight(STT) / 2;
    setbkcolor(BlueNhat); setcolor(Den); settextstyle(10, 0, 1);
    for (int i = batDau; i < soDong; i++) {
        y += kcY;
        if (i >= ketThuc) {

            x = tableLeft;
            STT = convertIntToChar(i + 1);
            outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
            x += Bang.getCols(0)->getChieuRong();

            outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

            x += Bang.getCols(1)->getChieuRong();
            outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

            x += Bang.getCols(2)->getChieuRong();
            outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

            x += Bang.getCols(3)->getChieuRong();
            outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

            x += Bang.getCols(4)->getChieuRong();
            outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
            continue;
        }

        x = tableLeft;
        //STT
        STT = convertIntToChar(i + 1);
        //Xoa STT cu
        outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(0)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
        //Xuat STT moi
        outtextxy(x + (Bang.getCols(0)->getChieuRong() / 2 - textwidth(STT) / 2), y, STT);
        x += Bang.getCols(0)->getChieuRong();
        // MaMH
        // Xoa maMH cu
        outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
        // Xuat maMH moi
        outtextxy(x + (Bang.getCols(1)->getChieuRong() / 2 - textwidth(arrMH[i].getMaMH()) / 2), y, arrMH[i].getMaMH());
        x += Bang.getCols(1)->getChieuRong();
        // TenMH
        // Xoa TenMH cu
        outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
        // Xuat TenMH moi
        outtextxy(x + (Bang.getCols(2)->getChieuRong() / 2 - textwidth(arrMH[i].getTenMH()) / 2), y, arrMH[i].getTenMH());
        x += Bang.getCols(2)->getChieuRong();
        // TC
        // Xoa TCLT cu
        outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
        // Xuat TCLT moi
        outtextxy(x + (Bang.getCols(3)->getChieuRong() / 2 - textwidth(convertIntToChar(arrMH[i].getTCLT())) / 2), y, convertIntToChar(arrMH[i].getTCLT()));
        x += Bang.getCols(3)->getChieuRong();
        // Xoa TCTH cu 
        outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
        // Xuat TCTH moi
        outtextxy(x + (Bang.getCols(4)->getChieuRong() / 2 - textwidth(convertIntToChar(arrMH[i].getTCTH())) / 2), y, convertIntToChar(arrMH[i].getTCTH()));
        x += Bang.getCols(4)->getChieuRong();
        // Xoa mo lop cu 
        outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
        // Xuat mo lop moi 
        if (arrMH[i].getMoLop() == 1) {
            outtextxy(x + (Bang.getCols(5)->getChieuRong() / 2 - textwidth(convertStringToChar("X")) / 2), y, convertStringToChar("X"));
        }
        x = tableLeft;
    }
    //clearmouseclick(WM_LBUTTONDOWN);
}


void treeMH::xuatTrang(Subject*& arrMH, int tongSoDong, thaoTac& hDMH, char* s, int& t, int& on) {
    int x = -1, y = -1;
    int batDau = 0;
    int ketThuc = (tongSoDong >= maxDong) ? maxDong : tongSoDong;
    Table newTable = table_MH();
    newTable.drawTable(maxDong);
    int trangHienTai = 1;
    int tongSoTrang = ((tongSoDong - 1) / maxDong) + 1;
    string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
    settextstyle(10, 0, 1);
    setbkcolor(BlueNhat); setcolor(Den);
    outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
    bool ok = true;
    xuat1Trang(arrMH, batDau, ketThuc, newTable);
    while (ok) {
        //delay(200);
            // xuat1Trang(arrMH, batDau, ketThuc, newTable);
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if (tableLeft <= x && x <= tableRightMH && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {

                int tmp = MessageBox(
                    NULL,
                    (LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON XOA MON HOC"),
                    (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                    MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
                );
                if (tmp == IDYES) {
                    if (this->getRoot(), arrMH[(y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong].getMoLop() == 1) {
                        MessageBox(
                            NULL,
                            (LPCWSTR)convertCharArrayToLPCWSTR("MON HOC DA MO LOP KHONG THE XOA "),
                            (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                            MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
                        );
                        continue;
                    }
                    else {
                        this->xoaNode(this->getRoot(), arrMH[(y - 310) / kcY + (trangHienTai - 1) * maxDong].getMaMH());
                        int n = soNode(getRoot());
                        vietDataDSMH(n);
                        cleardevice();

                        break;
                    }
                }

            }
            else if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {

                batDau = batDau - maxDong;
                ketThuc = batDau + maxDong;
                trangHienTai--;
                xuat1Trang(arrMH, batDau, ketThuc, newTable);
                str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
                settextstyle(10, 0, 1);
                setbkcolor(BlueNhat); setcolor(Den);
                outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
            }
            else if ((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang) {


                batDau = batDau + maxDong;
                ketThuc = (ketThuc + maxDong > tongSoDong) ? tongSoDong : ketThuc + maxDong;
                trangHienTai++;
                xuat1Trang(arrMH, batDau, ketThuc, newTable);
                str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
                settextstyle(10, 0, 1);
                setbkcolor(BlueNhat); setcolor(Den);
                outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
            }
            else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
                t = 1;
                hDMH = BACK;
                break;

            }
            else if (1390 <= x && x <= 1490 && 169 <= y && y <= 214) {
                hDMH = THEM;
                t = 1;
                break;
            }
            /*else if (1290 <= x && x <= 1380 && 150 <= y && y <= 190) {
                buttonLoc(colorNen, colorText, true);
            }*/
            else if (183 <= x && x <= 559 && 169 <= y && y <= 205) {
                t = 1;
                nhapLocMH(s, t, hDMH);
                break;
            }
            else if (563 <= x && x <= 630 && 169 <= y && y <= 205) {
                t = 1;
                hDMH = LOC;
                break;
            }
            else if (1400 <= x && x <= 1490 && 10 <= y && y <= 60) {
                on = 0;
                hDMH = BACK;
                break;
            }
        }
        else if (ismouseclick(WM_RBUTTONDOWN)) {
            getmouseclick(WM_RBUTTONDOWN, x, y);
            clearmouseclick(WM_RBUTTONDOWN);
            if (this->getRoot(), arrMH[(y - tableTop - kcY) / kcY + (trangHienTai - 1) * maxDong].getMoLop() == 1) {
                MessageBox(
                    NULL,
                    (LPCWSTR)convertCharArrayToLPCWSTR("MON HOC DA MO LOP KHONG THE SUA "),
                    (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                    MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
                );
                continue;
            }
            if (tableLeft <= x && x <= tableRightMH && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
                int tp = (y - 310) / kcY + (trangHienTai - 1) * maxDong;
                menuSuaMH();
                nhapMH(string(arrMH[tp].getMaMH()),
                    string(arrMH[tp].getTenMH()),
                    to_string(arrMH[tp].getTCLT()),
                    to_string(arrMH[tp].getTCTH()), 2);
                break;
            }


        }


    }

    newTable.freeTable();
}

void treeMH::nhapMH(string str1, string str2, string str3, string str4, int check) {
    Input* input[4];
    input[0] = new Input(str1, 2, "Ma Mon Hoc", 50, 0, 667, 1101, 240, 295, graynhat, 0, 3);
    input[1] = new Input(str2, 1, "Ten Mon Hoc", 50, 0, 667, 1101, 330, 385, graynhat, 0, 3);
    input[2] = new Input(str3, 3, "So TCTH", 2, 0, 667, 1101, 410, 465, graynhat, 0, 3);
    input[3] = new Input(str4, 3, "So TCLT", 2, 0, 667, 1101, 500, 555, graynhat, 0, 3);
    int x = -1; int y = -1;
    input[0]->draw();
    input[1]->draw();
    input[2]->draw();
    input[3]->draw();
    Subject MH;
    while (1) {
        // delay(10);
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);
            if (667 <= x && x <= 1101 && 240 <= y && y <= 295 && check != 2) {
                input[0]->setCheck(true);
                input[1]->setCheck(false);
                input[2]->setCheck(false);
                input[3]->setCheck(false);
                input[0]->addChar();
                input[1]->draw();
                input[2]->draw();
                input[3]->draw();
            }
            else if (667 <= x && x <= 1101 && 330 <= y && y <= 385) {
                input[0]->setCheck(false);
                input[1]->setCheck(true);
                input[2]->setCheck(false);
                input[3]->setCheck(false);
                input[0]->draw();
                input[1]->addChar();
                input[2]->draw();
                input[3]->draw();
            }
            else if (667 <= x && x <= 1101 && 410 <= y && y <= 465) {
                input[0]->setCheck(false);
                input[1]->setCheck(false);
                input[2]->setCheck(true);
                input[3]->setCheck(false);
                input[0]->draw();
                input[1]->draw();
                input[2]->addChar();
                input[3]->draw();
            }
            else if (667 <= x && x <= 1101 && 500 <= y && y <= 555) {
                input[0]->setCheck(false);
                input[1]->setCheck(false);
                input[2]->setCheck(false);
                input[3]->setCheck(true);
                input[0]->draw();
                input[1]->draw();
                input[2]->draw();
                input[3]->addChar();

            }
            if (check == 0) {
                if (417 <= x && x <= 512 && 709 <= y && y <= 748) {
                    int tmp = MessageBox(
                        NULL,
                        (LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON HUY THEM MON HOC"),
                        (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                        MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
                    );
                    if (tmp == IDYES) {
                        break;
                    }
                }
                else if (1057 <= x && x <= 1151 && 709 <= y && y <= 748) {
                    if (input[0]->checkRong() == true && input[1]->checkRong() == true && input[2]->checkRong() == true && input[3]->checkRong() == true) {

                        int tmp = MessageBox(
                            NULL,
                            (LPCWSTR)convertCharArrayToLPCWSTR("BAN CO MUON LUU MON HOC"),
                            (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                            MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
                        );
                        if (tmp == IDYES) {
                            //check = 0;
                            MH.setMaMH((const char*)input[0]->chuanHoa(input[0]->getContent()));
                            MH.setTenMH((const char*)input[1]->chuanHoa(input[1]->getContent()));
                            MH.setTCLT(atoi(input[3]->getContent()));
                            MH.setTCTH(atoi(input[2]->getContent()));
                            //xuatDataMH();
                            themNode(getRoot(), MH, check);
                            if (check == 1) {
                                MessageBox(
                                    NULL,
                                    (LPCWSTR)convertCharArrayToLPCWSTR("MA MON HOC DA BI TRUNG "),
                                    (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                                    MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
                                );
                                check = 0;
                            }
                            else {
                                int n = soNode(getRoot());
                                vietDataDSMH(n);
                                break;
                            }
                        }
                    }
                    else {
                        MessageBox(
                            NULL,
                            (LPCWSTR)convertCharArrayToLPCWSTR("VUI LONG NHAP DAY DU THONG TIN "),
                            (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                            MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
                        );
                        continue;
                    }
                }

            }
            else if (check == 2) {
                if (667 <= x && x <= 1101 && 240 <= y && y <= 295) {
                    MessageBox(
                        NULL,
                        (LPCWSTR)convertCharArrayToLPCWSTR("BAN KHONG DUOC SUA MA MON HOC"),
                        (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                        MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
                    );
                }
                else if (1057 <= x && x <= 1151 && 709 <= y && y <= 748) {

                    int tmp = MessageBox(
                        NULL,
                        (LPCWSTR)convertCharArrayToLPCWSTR("BAN CO MUON LUU SUA MON HOC"),
                        (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                        MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
                    );
                    if (tmp == IDYES) {
                        //check = 0;
                        MH.setMaMH((const char*)input[0]->chuanHoa(input[0]->getContent()));
                        MH.setTenMH((const char*)input[1]->chuanHoa(input[1]->getContent()));
                        MH.setTCLT(atoi(input[3]->getContent()));
                        MH.setTCTH(atoi(input[2]->getContent()));
                        //xuatDataMH();
                        themNode(getRoot(), MH, check);
                        int n = soNode(getRoot());
                        vietDataDSMH(n);

                        break;
                    }
                }
                else if (417 <= x && x <= 512 && 709 <= y && y <= 748) {
                    int tmp = MessageBox(
                        NULL,
                        (LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON HUY SUA MON HOC"),
                        (LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
                        MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
                    );
                    if (tmp == IDYES) {

                        break;
                    }
                }

            }
        }


    }
}
// button trong trang MH
void treeMH::nhapLocMH(char* s, int& t, thaoTac& hDMH) {
    int tmp = strlen(s);
    if (tmp > 0 && s[0] == ' ') {
        tmp = 0;
    }
    s[tmp + 1] = '\0';
    s[tmp] = '|';
    char c;
    int x = -1, y = -1;
    setbkcolor(graynhat);
    settextstyle(10, 0, 1);
    setcolor(Den);
    while (kbhit()) c = getch();
    while (1) {
        delay(10);
        outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);

            if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
                s[tmp] = '\0';
                t = 1;
                hDMH = BACK;
                break;

            }
            else if (1390 <= x && x <= 1490 && 169 <= y && y <= 214) {
                s[tmp] = '\0';
                hDMH = THEM;
                t = 1;
                break;
            }
            else if (563 <= x && x <= 630 && 169 <= y && y <= 205) {
                s[tmp] = '\0';
                t = 1;
                hDMH = LOC;
                break;
            }
            else {
                s[tmp] = '\0';
                if (hDMH == LOC) break;
                hDMH = XUAT;
                break;
            }
        }

        else if (kbhit()) {
            c = getch();
            if (c == 8 && tmp > 0) {
                if (strlen(s) > 0) {
                    s[tmp] = ' ';
                    s[tmp + 1] = '\0';
                    s[--tmp] = '|';
                }


            }
            else if (c != 8 && tmp < 50) {
                if (strlen(s) < 50) {
                    s[tmp++] = c;
                    s[tmp] = '\0';

                }

            }
        }

        else if (!kbhit()) {
            s[tmp] = '|';
            s[tmp + 1] = '\0';
            delay(100);
            outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
            s[tmp] = ' ';
            s[tmp + 1] = '\0';
            delay(100);
            outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
        }
    }
}
void menuMH() {
    setfillstyle(SOLID_FILL, mauNen);
    bar(0, 0, 1525, 777);
    tieuDeMH();
    buttonBack();
    buttonThem();


    setfillstyle(SOLID_FILL, BlueNhat);
    bar(40, 243, 1490, 744);
    vien(40, 1490, 243, 744);
    buttonTien();
    buttonLui();
    buttonLoc();
    buttonThoat();
}

void treeMH::menuSetMH(int& on) {
    menuMH();
   // DeleteNode(getRoot());

    char s[100];
    s[0] = ' ';
    s[1] = '\0';
    Input* input[1];
    input[0] = new Input("", 1, "TIM KIEM", 50, 0, 183, 559, 169, 205, graynhat, 0, 3);
    input[0]->draw();
    vien(183, 559, 169, 205);

    Subject MH;
    xuatDataMH();

    Subject* mangMH = new Subject[100];
    Subject* arrMH = new Subject[100];
    int n = 0;
    int soLuong = 0;
    nhapCayVaoMang(mangMH, getRoot(), n);
    locMH("", arrMH, mangMH, soLuong, n);
    sortTheoTen(arrMH, n);
    int x = -1, y = -1;
    bool active = false;


    thaoTac hDMH = XUAT;
    int thaoTacRoi = 0;

    bool ok = 1;
    while (ok) {
        //delay(200);
        if (thaoTacRoi == 0) {
            if (ismouseclick(WM_LBUTTONDOWN)) {
                getmouseclick(WM_LBUTTONDOWN, x, y);
                clearmouseclick(WM_LBUTTONDOWN);
                if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
                    hDMH = BACK;

                }
                else if (1390 <= x && x <= 1490 && 169 <= y && y <= 214) {
                    hDMH = THEM;


                }
                /*else if (1290 <= x && x <= 1380 && 150 <= y && y <= 190) {
                    buttonLoc(colorNen, colorText, true);
                }*/
                else if (183 <= x && x <= 559 && 169 <= y && y <= 205) {

                    nhapLocMH(s, thaoTacRoi, hDMH);
                }
                else if (563 <= x && x <= 630 && 169 <= y && y <= 205) {

                    hDMH = LOC;
                }
                else if (1400 <= x && x <= 1490 && 10 <= y && y <= 60) {
                    on = 0;
                    hDMH = BACK;
                }
            }
        }
        switch (hDMH) {
        case XUAT: {
            cleardevice();
            menuMH();   
            input[0]->draw();
            buttonTimKiem();
            vien(183, 559, 169, 205);
            n = 0;
            soLuong = 0;
            nhapCayVaoMang(mangMH, getRoot(), n);
            locMH("", arrMH, mangMH, soLuong, n);
            sortTheoTen(arrMH, soLuong);
            outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
            xuatTrang(arrMH, soLuong, hDMH, s, thaoTacRoi, on);
            break;
        }
        case LOC: {
            cleardevice();
            menuMH();
            input[0]->draw();
            buttonTimKiem();
            vien(183, 559, 169, 205);
            n = 0;
            soLuong = 0;
            nhapCayVaoMang(mangMH, getRoot(), n);
            locMH(string(s), arrMH, mangMH, soLuong, n);
            sortTheoTen(arrMH, soLuong);
            outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
            xuatTrang(arrMH, soLuong, hDMH, s, thaoTacRoi, on);
            break;
        }
        case THEM: {
            menuThemMH();
            nhapMH("", "", "", "", 0);
            cleardevice();
            menuMH();
            input[0]->draw();
            buttonTimKiem();
            vien(183, 559, 169, 205);
            n = 0;
            soLuong = 0;
            nhapCayVaoMang(mangMH, getRoot(), n);
            locMH("", arrMH, mangMH, soLuong, n);
            sortTheoTen(arrMH, n);
            outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
            xuatTrang(arrMH, soLuong, hDMH, s, thaoTacRoi, on);
            hDMH = XUAT;
            break;
        }
        case BACK: {
            delete[] arrMH;
            delete[] mangMH;
            cleardevice();
            ok = 0;
            break;
        }
        }
    }
}
