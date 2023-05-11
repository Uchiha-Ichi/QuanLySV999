#pragma once
#include "Const.h"

class bang {
private:
	char ten[100];
	int chieuRong;
public:
	bang() {
		chieuRong = 0;
		strcpy_s(ten, sizeof(ten), "");
	}
	int getChieuRong() {
		return this->chieuRong;
	}

	void setChieuRong(int width) {
		this->chieuRong = width;
	}

	char* getTen() {
		return this->ten;
	}

	void setTen(char* ten) {
		strcpy_s(this->ten, sizeof(this->ten), ten);
	}

	void veHCN(int x, int y) {
		rectangle(x, y, x + chieuRong, y + kcY);
	}
};
class Table {
private:
	int soCot;
	bang* cot[15] = { NULL };
public:
	Table() {
		soCot = 0;
		for (int i = 0; i < 15; i++) this->cot[i] = new bang;
	}

	void freeTable() {
		for (int i = 0; i < 15; i++) delete this->cot[i];
	}

	int getNumOfCols() {
		return this->soCot;
	}

	void setCols(int cols) {
		this->soCot = cols;
	}

	bang*& getCols(int i) {
		return this->cot[i];
	}

	void drawLine(int x, int y) {

		for (int i = 0; i < soCot; i++) {

			this->cot[i]->veHCN(x, y);
			x += this->cot[i]->getChieuRong();
		}
	}

	void drawTable(int soHang) {
		setcolor(Blue); setbkcolor(BlueNhat); settextstyle(10, 0, 2);
		int y = tableTop; int x = tableLeft;
		// hang so 0 la hang tieu de, du lieu bat dau tu hang 1 -> numOfRows
		for (int i = 0; i <= soHang; i++) {

			drawLine(x, y);

			x = tableLeft;
			y += kcY;
		}

		printTitle();
	}

	void printTitle() {
		setcolor(Blue); setbkcolor(BlueNhat); settextstyle(10, 0, 2);
		int y = tableTop + kcY / 2 - textheight(this->cot[0]->getTen()) / 2;    //rowTableHeight/4 ; 
		int x = tableLeft;
		int temp = x;

		for (int i = 0; i < soCot; i++) {
			x = temp + this->cot[i]->getChieuRong() / 2 - textwidth(this->cot[i]->getTen()) / 2;

			outtextxy(x, y, this->cot[i]->getTen());

			temp += this->cot[i]->getChieuRong();
		}
	}

};
Table table_MH() {

	int soCot = 6;
	Table newTable;
	newTable.setCols(soCot);

	int arrWidth[6] = { 60, 160, 600, 200, 200, 110 };
	const char* arrName[6] = { "STT", "Ma mon hoc", "Ten mon hoc", "So TC ly thuyet", "So TC thuc hanh", "Mo Lop" };

	for (int i = 0; i < soCot; i++) {
		newTable.getCols(i)->setChieuRong(arrWidth[i]);
		char arr[100];
		strcpy_s(arr, arrName[i]);
		newTable.getCols(i)->setTen(arr);
	}

	return newTable;
}
Table table_SV() {
	int soCot = 7;
	Table newTable;
	newTable.setCols(soCot);
	int arrWidth[7] = { 60, 250, 300,120, 160, 200, 180 };
	const char* arrName[7] = { "STT","Ma SV","Ho","Ten","Gioi tinh","Sdt","Nam Nhap Hoc" };
	for (int i = 0; i < soCot; i++) {
		newTable.getCols(i)->setChieuRong(arrWidth[i]);
		char arr[100];
		strcpy_s(arr, arrName[i]);
		newTable.getCols(i)->setTen(arr);
	}

	return newTable;
}
Table table_Lop() {
	int soCot = 3;
	Table newTable;
	newTable.setCols(soCot);
	int arrWidth[3] = { 60,650,600 };
	const char* arrName[4] = { "STT","MA LOP","SO SINH VIEN","DSSV" };
	for (int i = 0; i < soCot; i++) {
		newTable.getCols(i)->setChieuRong(arrWidth[i]);
		char arr[100];
		strcpy_s(arr, arrName[i]);
		newTable.getCols(i)->setTen(arr);
	}

	return newTable;
}
class UI {
protected:
	int left;
	int top;
	int bottom;
	int right;
	int backgroundColor = BACKGROUND_TABLE;
	int borderColor = BORDER_TABLE;
public:
	UI() {
		this->left = -1;
		this->right = -1;
		this->top = -1;
		this->bottom = -1;

	}
	UI(int left, int right, int top, int bottom, int backgroundColor, int borderColor) {
		this->left = left;
		this->right = right;
		this->top = top;
		this->bottom = bottom;
		this->backgroundColor = backgroundColor;
		this->borderColor = borderColor;
	}
	virtual void draw() {
		setfillstyle(SOLID_FILL, backgroundColor);
		bar(left, top, right, bottom);
		setcolor(borderColor);
		rectangle(left, top, right, bottom);
	}
};
/*
int main() {
	initwindow(1500, 600, "My Table");
	setbkcolor(15);
	Table myTable = table_MH();
	myTable.drawTable(10); // Vẽ bảng với 10 hàng (trừ hàng tiêu đề)

	getch();
	closegraph();
	return 0;
}
*/