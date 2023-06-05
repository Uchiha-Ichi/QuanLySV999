
#pragma once
#include"Const.h"
//-----------------------------Menu--------------------------------------------------------
void vien(int left, int right, int top, int bottom) {
    setfillstyle(SOLID_FILL, Den);
    bar(left - 1, top, left + 1, bottom);
    setfillstyle(SOLID_FILL, Den);
    bar(left, top - 1, right, top + 1);
    setfillstyle(SOLID_FILL, Den);
    bar(right - 1, top, right + 1, bottom);
    setfillstyle(SOLID_FILL, Den);
    bar(left, bottom - 1, right, bottom + 1);
}


void _buttonLopTinChi() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(679, 228, 1011, 296);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((679 + 1011) / 2 - textwidth(_lopTinChi) / 2, (228 + 296) / 2 - textheight(_lopTinChi) / 2, _lopTinChi);
    vien(679, 1011, 228, 296);
}

void _buttonSinhVien() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(679, 354, 1011, 421);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((679 + 1011) / 2 - textwidth(_sinhVien) / 2, (354 + 421) / 2 - textheight(_sinhVien) / 2, _sinhVien);
    vien(679, 1011, 354, 421);
}


void _buttonMonHoc() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(679, 470, 1011, 537);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((679 + 1011) / 2 - textwidth(_monHoc) / 2, (470 + 537) / 2 - textheight(_monHoc) / 2, _monHoc);
    vien(679, 1011, 470, 537);
}


void _buttonDiem() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(679, 583, 1011, 651);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((679 + 1011) / 2 - textwidth(_diem) / 2, (583 + 651) / 2 - textheight(_diem) / 2, _diem);
    vien(679, 1011, 583, 651);
}

//void tenDoAn() {
//	setfillstyle(SOLID_FILL, XanhLe);
//	bar(1, 94, 305, SCREEN_HEIGHT);
//}
void buttonThoat() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1400, 10, 1490, 60);
    settextstyle(10, 0, 5);
    setcolor(RED);
    outtextxy((1490 + 1400) / 2 - textwidth(_thoat) / 2, (10 + 60) / 2 - textheight(_thoat) / 2, _thoat);
    vien(1400, 1490, 10, 60);
}
void tieuDe() {
    setbkcolor(HongNhat);
    setfillstyle(SOLID_FILL, HongNhat);
    bar(0, 0, 1540, 94);
    settextstyle(10, 0, 8);
    setcolor(Den);
    outtextxy((1540) / 2 - textwidth(_tieuDe) / 2, (95) / 2 - textheight(_tieuDe) / 2, _tieuDe);
    vien(0, 1540, 0, 94);
}

void buttonTimKiem() {
    setbkcolor(graynhat);
    setfillstyle(SOLID_FILL, graynhat);
    bar(55, 169, 180, 205);
    settextstyle(10, 0, 1);
    setcolor(Den);
    outtextxy((55 + 180) / 2 - textwidth(_timkiem) / 2, (169 + 205) / 2 - textheight(_timkiem) / 2, _timkiem);
    vien(55, 180, 169, 205);

}
// ------------------------------MON HOC--------------------------------------
void menuFirstSet();

void menuSetMH();

void buttonBack();

void buttonHuyMH();

void menuThemMH();

void menuSetThemMH();

void buttonThem();

void buttonSaveMH();

void buttonLui();

void buttonTien();

void buttonLoc(int colorBK, int colortext, bool active);

void menuSuaMH();

void tieuDeMH();


void buttonSaveMH() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1057, 695, 1137, 734);
    settextstyle(10, 0, 1);
    setcolor(Blue);
    outtextxy((1057 + 1137) / 2 - textwidth(_save) / 2, (695 + 734) / 2 - textheight(_save) / 2, _save);
    vien(1057, 1137, 695, 734);
}

void buttonSaveSV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(755, 695, 835, 734);
    settextstyle(10, 0, 1);
    setcolor(Blue);
    outtextxy((755 + 835) / 2 - textwidth(_save) / 2, (695 + 734) / 2 - textheight(_save) / 2, _save);
    vien(755, 835, 695, 734);
}

void buttonHuyMH() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(425, 695, 520, 734);
    settextstyle(10, 0, 1);
    setcolor(Blue);
    outtextxy((425 + 520) / 2 - textwidth(_huy) / 2, (695 + 734) / 2 - textheight(_huy) / 2, _huy);
    vien(425, 520, 695, 734);
}
void buttonBack() {
    setbkcolor(HongNhat);
    setfillstyle(SOLID_FILL, HongNhat);
    bar(21, 21, 193, 71);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((21 + 193) / 2 - textwidth(_back) / 2, (21 + 71) / 2 - textheight(_back) / 2, _back);
    vien(21, 193, 21, 71);
}



void menuSuaMH() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(631, 125, 933, 180);
    settextstyle(10, 0, 4);
    setcolor(Blue);
    outtextxy((631 + 933) / 2 - textwidth(_suaMH) / 2, (125 + 170) / 2 - textheight(_suaMH) / 2, _suaMH);
    vien(631, 933, 125, 180);
    buttonHuyMH();
    buttonSaveMH();
}

void menuThemMH() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(631, 125, 933, 180);
    settextstyle(10, 0, 4);
    setcolor(Blue);
    outtextxy((631 + 933) / 2 - textwidth(_themMH) / 2, (125 + 170) / 2 - textheight(_themMH) / 2, _themMH);
    vien(631, 933, 125, 180);
    buttonHuyMH();
    buttonSaveMH();

}


void buttonThem() {
    setbkcolor(HongNhat);
    setfillstyle(SOLID_FILL, HongNhat);
    bar(1390, 169, 1490, 214);
    settextstyle(10, 0, 2);
    setcolor(Blue);
    outtextxy((1390 + 1490) / 2 - textwidth(_them) / 2, (169 + 214) / 2 - textheight(_them) / 2, _them);
    vien(1390, 1490, 169, 214);
}

void buttonLui() {
    setbkcolor(gray);
    setfillstyle(SOLID_FILL, gray);
    bar(613, 703, 685, 734);
    settextstyle(10, 0, 1);
    setcolor(Den);
    outtextxy((613 + 685) / 2 - textwidth(_sangPhai) / 2, (703 + 734) / 2 - textheight(_sangPhai) / 2, _sangPhai);
    vien(613, 685, 703, 734);
}

void buttonTien() {
    setbkcolor(gray);
    setfillstyle(SOLID_FILL, gray);
    bar(777, 703, 848, 734);
    settextstyle(10, 0, 1);
    setcolor(Den);
    outtextxy((777 + 848) / 2 - textwidth(_sangTrai) / 2, (703 + 734) / 2 - textheight(_sangTrai) / 2, _sangTrai);
    vien(777, 848, 703, 734);
}

void buttonLoc() {
    setbkcolor(graynhat);
    setfillstyle(SOLID_FILL, graynhat);
    bar(563, 169, 630, 205);
    settextstyle(10, 0, 1);
    setcolor(Den);
    outtextxy((563 + 630) / 2 - textwidth(_loc) / 2, (169 + 205) / 2 - textheight(_loc) / 2, _loc);
    vien(563, 630, 169, 205);
}

void tieuDeMH() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(397, 20, 1173, 100);
    settextstyle(10, 0, 8);
    setcolor(Blue);
    outtextxy((397 + 1173) / 2 - textwidth(_monHoc) / 2, (20 + 100) / 2 - textheight(_monHoc) / 2, _monHoc);
    vien(397, 1173, 20, 100);
}


// ------------------------------Lop--------------------------------------

void tieuDeLopSV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(397, 20, 1173, 100);
    settextstyle(10, 0, 8);
    setcolor(Blue);
    outtextxy((397 + 1173) / 2 - textwidth(_lopSV) / 2, (20 + 100) / 2 - textheight(_lopSV) / 2, _lopSV);
    vien(397, 1173, 20, 100);
}

void menuThemLop() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(631, 125, 933, 180);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((631 + 933) / 2 - textwidth(_themLop) / 2, (125 + 170) / 2 - textheight(_themLop) / 2, _themLop);
    vien(631, 933, 125, 180);
    buttonHuyMH();
    buttonSaveMH();
}
// ------------------------------SINH VIEN--------------------------------------

void buttonThoatSV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(1100, 125, 1140, 165);
    settextstyle(10, 0, 5);
    setcolor(RED);
    outtextxy((1100 + 1140) / 2 - textwidth(_thoat) / 2, (125 + 165) / 2 - textheight(_thoat) / 2, _thoat);
    vien(1100, 1140, 125, 165);
}

void tieuDeSV() {
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(397, 20, 1173, 100);
    settextstyle(10, 0, 8);
    setcolor(Blue);
    outtextxy((397 + 1173) / 2 - textwidth(_sinhVien) / 2, (20 + 100) / 2 - textheight(_sinhVien) / 2, _sinhVien);
    vien(397, 1173, 20, 100);
}

void menuThemSV() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(560, 125, 1011, 180);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((560 + 1011) / 2 - textwidth(_themSinhVien) / 2, (125 + 170) / 2 - textheight(_themSinhVien) / 2, _themSinhVien);
    vien(560, 1011, 125, 180);
    buttonSaveSV();
}

void menuSuaSV() {
    setfillstyle(SOLID_FILL, BlueNhat);
    bar(402, 121, 1151, 748);
    vien(402, 1151, 121, 748);
    setbkcolor(Be);
    setfillstyle(SOLID_FILL, Be);
    bar(560, 125, 1011, 180);
    settextstyle(10, 0, 5);
    setcolor(Blue);
    outtextxy((560 + 1011) / 2 - textwidth(_suaSinhVien) / 2, (125 + 170) / 2 - textheight(_suaSinhVien) / 2, _suaSinhVien);
    vien(560, 1011, 125, 180);
    buttonSaveSV();
    buttonThoatSV();
}
