#pragma once
#include"Const.h"
#include"Convert.h"
#include"Input.h"
#include"Button.h"


class SinhVien {
private:
	string maSV;
	string ho;
	string ten;
	string sex;
	string sdt;
	string maLop;
	string namNhap;
public:
	void setMaSV(string maSV);
	void setHo(string ho);
	void setTen(string ten);
	void setSex(string sex);
	void setSdt(string sdt);
	void setMaLop(string maLop);
	void setNamNhap(string namNhap);
	string getMaSV();
	string getHo();
	string getTen();
	string getSex();
	string getSdt();
	string getMaLop();
	string getNamNhap();
	void setData(SinhVien data);
};
class NodeSV {
private:
	SinhVien dataSV;
	NodeSV* nextSV;
public:
	NodeSV();
	NodeSV(SinhVien dataSV);
	void setDataSV(SinhVien dataSV);
	SinhVien& getDataSV();
	void setNextSV(NodeSV* nextSV);
	NodeSV* getNextSV();
	void setNodeSV(NodeSV* SV);
	NodeSV* getNodeSV();
	void vietSV(SinhVien SV, ofstream& fileOut);
};
class DSSV {
private:
	NodeSV* headSV;
public:
	DSSV();
	void setHeadSV(NodeSV* headSV);
	NodeSV*& getHeadSV();
	bool checkRong();
	void freeSV(NodeSV*& SV);
	void pushFrontSv(NodeSV* SV);
	int viTriThem(NodeSV* SV);
	void themSV(SinhVien& SV, int& check);
	NodeSV* timSV(string maSV);
	void xoaSV(string maSV);
	bool checkTrung(string maSV);
	int soLuongSV();
	void locSV(string key, DSSV& dssv, int& n);
	void xuat1TrangDSV(NodeSV* SV, int batDau, int ketThuc, Table Bang);
	void nhapLop();
	void menuTimKiemSV(char* s);
	void xuatTrangDSSV(DSSV dssv, int tongSoSV, thaoTac& hD, int& t, char* s, int& on);

	void nhapLocSV(char* s, thaoTac& hD, int& t);
	void nhapSV(string str1, string str2, string str3, string str4, string str5, string str6, int check);
	void menuSetSV(int& on);
};
//class SinhVien
void SinhVien::setMaSV(string maSV) {
	this->maSV = maSV;
}
void SinhVien::setHo(string ho) {
	this->ho = ho;
}
void SinhVien::setTen(string ten) {
	this->ten = ten;
}
void SinhVien::setSex(string sex) {
	this->sex = sex;
}
void SinhVien::setSdt(string sdt) {
	this->sdt = sdt;
}
void SinhVien::setMaLop(string maLop) {
	this->maLop = maLop;
}
void SinhVien::setNamNhap(string namNhap) {
	this->namNhap = namNhap;
}
string SinhVien::getMaSV() {
	return this->maSV;
}
string SinhVien::getHo() {
	return this->ho;
}
string SinhVien::getTen() {
	return this->ten;
}
string SinhVien::getSex() {
	return this->sex;
}
string SinhVien::getSdt() {
	return this->sdt;
}
string SinhVien::getMaLop() {
	return this->maLop;
}
string SinhVien::getNamNhap() {
	return this->namNhap;
}
void SinhVien::setData(SinhVien data) {
	this->maSV = data.maSV;
	this->ho = data.ho;
	this->ten = data.ten;
	this->sex = data.sex;
	this->sdt = data.sdt;
	this->maLop = data.maLop;
	this->namNhap = data.namNhap;
}
// class NodeSV
NodeSV::NodeSV() {
	this->nextSV = NULL;
}
NodeSV::NodeSV(SinhVien data) {
	this->dataSV = data;
	this->nextSV = NULL;
}
void NodeSV::setDataSV(SinhVien dataSV) {
	this->dataSV = dataSV;
}
SinhVien& NodeSV::getDataSV() {
	return this->dataSV;
}
void NodeSV::setNextSV(NodeSV* nextSV) {
	this->nextSV = nextSV;
}
NodeSV* NodeSV::getNextSV() {
	return this->nextSV;
}
void NodeSV::setNodeSV(NodeSV* SV) {
	this->dataSV = SV->dataSV;
	this->nextSV = SV->nextSV;
}
NodeSV* NodeSV::getNodeSV() {
	return this;
}
void NodeSV::vietSV(SinhVien SV, ofstream& fileOut) {
	char tmp = ',';
	fileOut << SV.getMaSV();
	fileOut << tmp;
	fileOut << SV.getHo();
	fileOut << tmp;
	fileOut << SV.getTen();
	fileOut << tmp;
	fileOut << SV.getSex();
	fileOut << tmp;
	fileOut << SV.getSdt();
	fileOut << tmp;
	fileOut << SV.getNamNhap();
	fileOut << tmp;
	fileOut << SV.getMaLop();
	fileOut << "\n";

}
// class danh sach sinh vien
DSSV::DSSV() {
	this->headSV = NULL;
}

void DSSV::setHeadSV(NodeSV* headSV) {
	this->headSV = headSV;
}
NodeSV*& DSSV::getHeadSV() {
	return this->headSV;
}
void DSSV::freeSV(NodeSV*& SV) {
	NodeSV* tmp = NULL;
	if (SV == NULL) return;
	while (SV != NULL) {
		tmp = headSV;
		SV = SV->getNextSV();
		delete tmp;
	}
}
bool DSSV::checkRong() {
	return this->headSV == NULL ? true : false;
}
void DSSV::pushFrontSv(NodeSV* SV) {
	SV->setNextSV(this->headSV);
	this->headSV = SV->getNodeSV();

}
int DSSV::viTriThem(NodeSV* SV) {
	int viTri = 1;
	NodeSV* tmp = this->headSV;
	while (tmp != NULL && tmp->getDataSV().getTen() <= SV->getDataSV().getTen()) {
		if (tmp->getDataSV().getTen() == SV->getDataSV().getTen()) {
			while (tmp != NULL) {
				if (tmp->getDataSV().getHo() < SV->getDataSV().getHo()) {
					viTri++;
					tmp = tmp->getNextSV();
				}
				else if (tmp->getDataSV().getHo() == SV->getDataSV().getHo()) {
					return -1;
				}
				else break;
			}
			return viTri;
		}
		viTri++;
		tmp = tmp->getNextSV();

	}
	return viTri;
}
void  DSSV::themSV(SinhVien& sv, int& check) {

	if (checkTrung(sv.getMaSV())) {
		if (check == 0) {
			check = 1;
			return;
		}
		else if (check == 2) {
			NodeSV* tmp = timSV(sv.getMaSV());
			tmp->getDataSV().setHo(sv.getHo());
			tmp->getDataSV().setMaSV(sv.getMaSV());
			tmp->getDataSV().setTen(sv.getTen());
			tmp->getDataSV().setSdt(sv.getSdt());
			tmp->getDataSV().setSex(sv.getSex());
			tmp->getDataSV().setNamNhap(sv.getNamNhap());
			tmp->getDataSV().setMaLop(sv.getMaLop());
			return;
		}
	}
	NodeSV* SV = new NodeSV(sv);
	int viTriThem = this->viTriThem(SV);
	if (headSV == NULL || viTriThem == 1) {
		pushFrontSv(SV);
		return;
	}
	NodeSV* tmp = this->headSV;
	for (int i = 1; i < viTriThem - 1; i++) {
		tmp = tmp->getNextSV();
	}
	SV->setNextSV(tmp->getNextSV());
	tmp->setNextSV(SV);
	return;
}
NodeSV* DSSV::timSV(string maSV) {
	NodeSV* tmp = headSV;
	while (tmp->getNextSV() != NULL) {
		if (tmp->getDataSV().getMaSV() == maSV) {
			return tmp;
		}
		tmp = tmp->getNextSV();
	}
	return NULL;
}
void DSSV::xoaSV(string maSV) {
	if (this->headSV == NULL) return;
	NodeSV* tmp = headSV;

	if (tmp->getDataSV().getMaSV() == maSV) {

		headSV = tmp->getNextSV();
		tmp->setNextSV(NULL);
		delete tmp;
		return;

	}
	while (tmp->getNextSV() != NULL && tmp->getNextSV()->getDataSV().getMaSV() != maSV) {
		tmp = tmp->getNextSV();
	}
	if (tmp->getNextSV()->getDataSV().getMaSV() == maSV) {

		NodeSV* temp = tmp->getNextSV();
		tmp->setNextSV(temp->getNextSV());
		temp->setNextSV(NULL);
		delete temp;
		return;
	}
}
bool DSSV::checkTrung(string maSV) {
	if (getHeadSV() == NULL) return false;
	NodeSV* tmp = getHeadSV();
	while (tmp != NULL) {
		if (tmp->getDataSV().getMaSV() == maSV) {
			return true;
		}
		tmp = tmp->getNextSV();
	}
	return false;
}
int DSSV::soLuongSV() {
	int soLuong = 0;
	NodeSV* tmp = getHeadSV();
	while (tmp != NULL) {
		++soLuong;
		tmp = tmp->getNextSV();
	}
	return soLuong;
}
void DSSV::locSV(string key, DSSV& dssv, int& n) {
	dssv.freeSV(dssv.getHeadSV());
	dssv.setHeadSV(NULL);
	NodeSV* tmp = this->headSV;
	n = 0;
	int check = 0;
	if (!key.empty()) {
		while (tmp != NULL) {
			if (string(tmp->getDataSV().getMaSV()).find(key) != string::npos) {
				dssv.themSV(tmp->getDataSV(), check);
				n++;
			}

			tmp = tmp->getNextSV();
		}
	}
	else {
		while (tmp != NULL) {
			dssv.themSV(tmp->getDataSV(), check);
			tmp = tmp->getNextSV();
			n++;
		}
	}
}
void DSSV::xuat1TrangDSV(NodeSV* SV, int batDau, int ketThuc, Table Bang) {
	int soDong = ketThuc % maxDong;
	if (soDong == 0) soDong = maxDong;
	if (ketThuc == 0 && batDau == 0) soDong = maxDong;
	else {
		int soDongTrong = maxDong - ketThuc % maxDong;
		soDong = ketThuc % maxDong == 0 ? ketThuc : ketThuc + soDongTrong;
	}
	char* STT = convertIntToChar(0);

	for (int i = 0; i < batDau; i++) {
		SV = SV->getNextSV();
	}
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
			x += Bang.getCols(5)->getChieuRong();

			outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(6)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));

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
		// MaSV
		// Xoa maSV cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(1)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// Xuat maSV moi
		outtextxy(x + (Bang.getCols(1)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getMaSV())) / 2), y, convertStringToChar(SV->getDataSV().getMaSV()));
		x += Bang.getCols(1)->getChieuRong();
		// HO
		// Xoa Ho cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(2)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		// Xuat Ho moi
		outtextxy(x + (Bang.getCols(2)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getHo())) / 2), y, convertStringToChar(SV->getDataSV().getHo()));
		x += Bang.getCols(2)->getChieuRong();
		//Ten
		//Xoa Ten cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(3)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//Xuat Ten moi
		outtextxy(x + (Bang.getCols(3)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getTen())) / 2), y, convertStringToChar(SV->getDataSV().getTen()));
		x += Bang.getCols(3)->getChieuRong();
		// Gioi tinh
		//Xoa gioi tinh cu 
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(4)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//Xuat gioi tinh moi 
		outtextxy(x + (Bang.getCols(4)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getSex())) / 2), y, convertStringToChar(SV->getDataSV().getSex()));
		x += Bang.getCols(4)->getChieuRong();
		//Sdt
		//Xoa Sdt cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(5)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//xuat SDt moi
		outtextxy(x + (Bang.getCols(5)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getSdt())) / 2), y, convertStringToChar(SV->getDataSV().getSdt()));
		x += Bang.getCols(5)->getChieuRong();
		//Nam Nhap Hoc
		//Xoa nam cu
		outtextxy(x + textwidth(convertStringToChar(string("|"))), y, convertStringToChar(string((Bang.getCols(6)->getChieuRong() - textwidth(convertStringToChar(string("|")))) / textwidth(convertStringToChar(string(" "))), ' ')));
		//xuat Nam moi
		outtextxy(x + (Bang.getCols(6)->getChieuRong() / 2 - textwidth(convertStringToChar(SV->getDataSV().getNamNhap())) / 2), y, convertStringToChar(SV->getDataSV().getNamNhap()));
		x = tableLeft;

		//clearmouseclick(WM_LBUTTONDOWN);
		SV = SV->getNextSV();
	}
}
void DSSV::xuatTrangDSSV(DSSV dssv, int tongSoSV, thaoTac& hD, int& t, char* s, int& on) {
	int x = -1, y = -1;
	int batDau = 0;
	int ketThuc = (tongSoSV >= maxDong) ? maxDong : tongSoSV;
	Table newTable = table_SV();
	newTable.drawTable(maxDong);
	int trangHienTai = 1;
	int tongSoTrang = ((tongSoSV - 1) / maxDong) + 1;
	string str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
	settextstyle(10, 0, 1);
	setbkcolor(BlueNhat); setcolor(Den);
	outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
	bool ok = true;
	xuat1TrangDSV(dssv.getHeadSV(), batDau, ketThuc, newTable);
	NodeSV* temp = getHeadSV();
	int h = 0;
	while (ok) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (tableLeft <= x && x <= tableRightLop && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {

				int tmp = MessageBox(
					NULL,
					(LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON XOA MON LOP"),
					(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
					MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
				);
				if (tmp == IDYES) {
					temp = getHeadSV();
					for (int i = 0; i < ((y - 310) / kcY + (trangHienTai - 1) * maxDong); i++) {
						temp = temp->getNextSV();
					}
					this->xoaSV(string(temp->getDataSV().getMaSV()));

					cleardevice();
					break;
				}
			}
			else if ((613 <= x && x <= 685 && 703 <= y && y <= 734) && trangHienTai > 1) {

				batDau = batDau - maxDong;
				ketThuc = batDau + maxDong;
				trangHienTai--;
				xuat1TrangDSV(dssv.getHeadSV(), batDau, ketThuc, newTable);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				settextstyle(10, 0, 1);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if (((777 <= x && x <= 848 && 703 <= y && y <= 734) && trangHienTai < tongSoTrang)) {

				batDau = batDau + maxDong;
				ketThuc = (ketThuc + maxDong > tongSoSV) ? tongSoSV : ketThuc + maxDong;
				trangHienTai++;
				xuat1TrangDSV(dssv.getHeadSV(), batDau, ketThuc, newTable);
				str = to_string(trangHienTai) + " / " + to_string(tongSoTrang);
				settextstyle(10, 0, 1);
				setbkcolor(BlueNhat); setcolor(Den);
				outtextxy((685 + 777) / 2 - textwidth(convertStringToChar(str)) / 2, (703 + 734) / 2 - textheight(convertStringToChar(str)) / 2, convertStringToChar(str));
			}
			else if (21 <= x && x <= 193 && 21 <= y && y <= 71) {
				hD = BACK;
				t = 1;
				break;
			}
			else if (1390 <= x && x <= 1490 && 169 <= y && y <= 214) {
				hD = THEM;
				t = 1;
				break;
			}
			else if (563 <= x && x <= 630 && 169 <= y && y <= 205) {
				hD = LOC;
				t = 1;
				break;
			}
			else if (183 <= x && x <= 559 && 169 <= y && y <= 205) {
				nhapLocSV(s, hD, t);// nhập dự liệu lọc vào ô để lấy ra string để ném vào hàm locSV t
				break;
			}
			else if (1400 <= x && x <= 1490 && 10 <= y && y <= 60) {
				on = 0;
				hD = BACK;
				break;
			}
		}
		else if (ismouseclick(WM_RBUTTONDOWN)) {
			getmouseclick(WM_RBUTTONDOWN, x, y);
			clearmouseclick(WM_RBUTTONDOWN);
			if (tableLeft <= x && x <= tableRightLop && tableTop + kcY <= y && y <= (ketThuc - (trangHienTai - 1) * maxDong) * kcY + tableTop + kcY) {
				temp = dssv.getHeadSV();
				for (int i = 0; i < ((y - 310) / kcY + (trangHienTai - 1) * maxDong); i++) {
					temp = temp->getNextSV();
				}
				menuSuaSV();
				nhapSV(string(temp->getDataSV().getMaSV()), string(temp->getDataSV().getHo()), string(temp->getDataSV().getTen()), string(temp->getDataSV().getSex()), string(temp->getDataSV().getSdt()), string(temp->getDataSV().getNamNhap()), 2);
				cleardevice();
				break;
			}
		}
	}
	newTable.freeTable();
}
void DSSV::nhapSV(string str1, string str2, string str3, string str4, string str5, string str6, int check) {
	Input* input[6];
	input[0] = new Input(str1, 2, "Ma Sinh Vien", 50, 0, 650, 1050, 250, 290, DARKGRAY, 0, 3);
	input[1] = new Input(str2, 1, "Ho", 50, 0, 650, 1050, 320, 360, DARKGRAY, 0, 3);
	input[2] = new Input(str3, 1, "Ten", 50, 0, 650, 1050, 390, 430, DARKGRAY, 0, 3);
	input[3] = new Input(str4, 1, "Gioi Tinh", 50, 0, 650, 1050, 460, 500, DARKGRAY, 0, 3);
	input[4] = new Input(str5, 3, "So Dien Thoai", 50, 0, 650, 1050, 530, 570, DARKGRAY, 0, 3);
	input[5] = new Input(str6, 3, "Nam Nhap Hoc", 50, 0, 650, 1050, 600, 640, DARKGRAY, 0, 3);
	input[0]->draw();
	input[1]->draw();
	input[2]->draw();
	input[3]->draw();
	input[4]->draw();
	input[5]->draw();
	int x = -1;
	int y = -1;
	SinhVien SV;
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if (650 <= x && x <= 1050 && 250 <= y && y <= 290 && check != 2) {
				input[0]->setCheck(true);
				input[1]->setCheck(false);
				input[2]->setCheck(false);
				input[3]->setCheck(false);
				input[4]->setCheck(false);
				input[5]->setCheck(false);
				input[0]->addChar();
				input[1]->draw();
				input[2]->draw();
				input[3]->draw();
				input[4]->draw();
				input[5]->draw();
			}
			else if (650 <= x && x <= 1050 && 320 <= y && y <= 360) {
				input[0]->setCheck(false);
				input[1]->setCheck(true);
				input[2]->setCheck(false);
				input[3]->setCheck(false);
				input[4]->setCheck(false);
				input[2]->setCheck(false);
				input[0]->draw();
				input[1]->addChar();
				input[2]->draw();
				input[3]->draw();
				input[4]->draw();
				input[5]->draw();
			}
			else if (650 <= x && x <= 1050 && 390 <= y && y <= 430) {
				input[0]->setCheck(false);
				input[1]->setCheck(false);
				input[2]->setCheck(true);
				input[3]->setCheck(false);
				input[4]->setCheck(false);
				input[2]->setCheck(false);
				input[0]->draw();
				input[1]->draw();
				input[2]->addChar();
				input[3]->draw();
				input[4]->draw();
				input[5]->draw();
			}
			else if (650 <= x && x <= 1050 && 460 <= y && y <= 500) {
				input[0]->setCheck(false);
				input[1]->setCheck(false);
				input[2]->setCheck(false);
				input[3]->setCheck(true);
				input[4]->setCheck(false);
				input[2]->setCheck(false);
				input[0]->draw();
				input[1]->draw();
				input[2]->draw();
				input[3]->addChar();
				input[4]->draw();
				input[5]->draw();
			}
			else if (650 <= x && x <= 1050 && 530 <= y && y <= 570) {
				input[0]->setCheck(false);
				input[1]->setCheck(false);
				input[2]->setCheck(false);
				input[3]->setCheck(false);
				input[4]->setCheck(true);
				input[2]->setCheck(false);
				input[0]->draw();
				input[1]->draw();
				input[2]->draw();
				input[3]->draw();
				input[4]->addChar();
				input[5]->draw();
			}
			else if (650 <= x && x <= 1050 && 600 <= y && y <= 640) {
				input[0]->setCheck(false);
				input[1]->setCheck(false);
				input[2]->setCheck(false);
				input[3]->setCheck(false);
				input[4]->setCheck(false);
				input[2]->setCheck(true);
				input[0]->draw();
				input[1]->draw();
				input[2]->draw();
				input[3]->draw();
				input[4]->draw();
				input[5]->addChar();
			}

			else if (755 <= x && x <= 835 && 695 <= y && y <= 734) {
				if (check == 0) {
					if (input[0]->checkRong() == true && input[1]->checkRong() == true && input[2]->checkRong() == true && input[3]->checkRong() == true && input[4]->checkRong() == true && input[5]->checkRong() == true) {
						int tmp = MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN CO MUON LUU SINH VIEN"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
						);
						if (tmp == IDYES) {
							SV.setMaSV(string(input[0]->chuanHoa(input[0]->getContent())));
							SV.setHo(string(input[1]->chuanHoa(input[1]->getContent())));
							SV.setTen(string(input[2]->chuanHoa(input[2]->getContent())));
							SV.setSex(string(input[3]->chuanHoa(input[3]->getContent())));
							SV.setSdt(string(input[4]->chuanHoa(input[4]->getContent())));
							SV.setNamNhap(string(input[5]->chuanHoa(input[5]->getContent())));
							SV.setMaLop(string(getHeadSV()->getDataSV().getMaLop()));
							themSV(SV, check);
							if (check == -1) {
								MessageBox(
									NULL,
									(LPCWSTR)convertCharArrayToLPCWSTR("MA SINH VIEN DA BI TRUNG "),
									(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
									MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
								);
								continue;
							}
							nhapSV("", "", "", "", "", "", 0);
							break;
						}
					}
					else if (input[0]->checkRong() == false) {
						int tmp = MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("BAN CO MUON DUNG THEM SINH VIEN"),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
						);
						if (tmp == IDYES) {
							cleardevice();
							break;
						}
					}
					else {
						MessageBox(
							NULL,
							(LPCWSTR)convertCharArrayToLPCWSTR("VUI LONG NHAP DAY DAU THONG TIN "),
							(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
							MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY
						);
						continue;
					}
				}
				else if (check == 2) {
					if (input[0]->checkRong() == true && input[1]->checkRong() == true && input[2]->checkRong() == true && input[3]->checkRong() == true && input[4]->checkRong() == true && input[5]->checkRong() == true) {

							int tmp = MessageBox(
								NULL,
								(LPCWSTR)convertCharArrayToLPCWSTR("BAN CO MUON LUU CHINH SUA "),
								(LPCWSTR)convertCharArrayToLPCWSTR("THONG BAO"),
								MB_ICONQUESTION | MB_YESNO | MB_DEFAULT_DESKTOP_ONLY
							);
							if (tmp == IDYES) {
								SV.setMaSV(string(input[0]->chuanHoa(input[0]->getContent())));
								SV.setHo(string(input[1]->chuanHoa(input[1]->getContent())));
								SV.setTen(string(input[2]->chuanHoa(input[2]->getContent())));
								SV.setSex(string(input[3]->chuanHoa(input[3]->getContent())));
								SV.setSdt(string(input[4]->chuanHoa(input[4]->getContent())));
								SV.setNamNhap(string(input[5]->chuanHoa(input[5]->getContent())));
								SV.setMaLop(string(getHeadSV()->getDataSV().getMaLop()));
								themSV(SV, check);
								break;
							}
						
					}
				}
			}
			else if (1100 <= x && x <= 1140 && 125 <= y && y <= 165) {
				int tmp = MessageBox(
					NULL,
					(LPCWSTR)convertCharArrayToLPCWSTR("BAN MUON HUY SUA SINH VIEN"),
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

void DSSV::nhapLocSV(char* s, thaoTac& hD, int& t) {
	int x = -1, y = -1;
	setbkcolor(graynhat);
	settextstyle(10, 0, 1);
	setcolor(Den);
	int tmp = strlen(s);
	if (tmp > 0 && s[0] == ' ') {
		tmp = 0;
	}
	s[tmp + 1] = '\0';
	s[tmp] = '|';
	char c;
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
				hD = BACK;
				break;

			}
			else if (1390 <= x && x <= 1490 && 169 <= y && y <= 214) {
				s[tmp] = '\0';
				hD = THEM;
				t = 1;
				break;
			}
			else if (563 <= x && x <= 630 && 169 <= y && y <= 205) {
				s[tmp] = '\0';
				t = 1;
				hD = LOC;
				break;
			}
			else {
				s[tmp] = '\0';
				if (hD == LOC) break;
				hD = XUAT;
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

void menuSV() {
	setfillstyle(SOLID_FILL, mauNen);
	bar(0, 0, 1525, 777);
	tieuDeLopSV();
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

void DSSV::menuSetSV(int& on) {
	menuSV();
	int colorNen = BACKGROUND_COLOR;
	int colorText = 0;
	int x = -1; int y = -1;
	char s[100];
	s[0] = ' ';
	s[1] = '\0';
	int n = 0;
	int check = 0;

	Input* input[1];
	input[0] = new Input("", 1, "TIM KIEM", 50, 0, 183, 559, 169, 205, graynhat, 0, 3);
	input[0]->draw();
	DSSV dssv;
	for (NodeSV* p = this->headSV; p != NULL; p = p->getNextSV()) {
		dssv.themSV(p->getDataSV(), check);
	}
	int tongSoSV = soLuongSV();

	thaoTac hD = XUAT;
	bool ok = true;
	int thaoTacRoi = 0;
	//xuatTrangDSSV(dssv, tongSoSV, hD, thaoTacRoi, s, on);
	while (ok) {
		if (thaoTacRoi == 0) {
			if (ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				clearmouseclick(WM_LBUTTONDOWN);

				if (0 <= x && x <= 70 && 10 <= y && y <= 40) {
					hD = BACK;

				}
				else if (1420 <= x && x <= 1510 && 150 <= y && y <= 190) {
					hD = THEM;

				}
				else if (920 <= x && x <= 1260 && 155 <= y && y <= 185) {
					nhapLocSV(s, hD, thaoTacRoi);
				}
				else if (1290 <= x && x <= 1380 && 150 <= y && y <= 190) {
					hD = LOC;

				}
				else if (1400 <= x && x <= 1490 && 10 <= y && y <= 60) {
					on = 0;
					hD = BACK;
				}
			}
			/*else {
				hD = XUAT;

			}*/
		}
		switch (hD) {
		case XUAT: {
			cleardevice();
			menuSV();
			input[0]->draw();
			buttonTimKiem();
			dssv.freeSV(dssv.getHeadSV());
			for (NodeSV* p = this->headSV; p != NULL; p = p->getNextSV()) {
				dssv.themSV(p->getDataSV(), check);
			}
			tongSoSV = soLuongSV();
			outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
			xuatTrangDSSV(dssv, tongSoSV, hD, thaoTacRoi, s, on);
			thaoTacRoi = 0;
			break;
		}
		case LOC: {

			locSV(string(s), dssv, n);
			outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
			xuatTrangDSSV(dssv, n, hD, thaoTacRoi, s, on);
			break;

		}
		case THEM: {
			menuThemSV();
			nhapSV("", "", "", "", "", "", 0);
			menuSV();
			input[0]->draw();
			buttonTimKiem();
			dssv.freeSV(dssv.getHeadSV());
			for (NodeSV* p = this->headSV; p != NULL; p = p->getNextSV()) {
				dssv.themSV(p->getDataSV(), check);
			}
			tongSoSV = soLuongSV();
			outtextxy(183 + 5, (169 + 205 - textheight(s)) / 2, s);
			xuatTrangDSSV(dssv, tongSoSV, hD, thaoTacRoi, s, on);
			thaoTacRoi = 0;
			hD = XUAT;
			break;
		}
		case BACK: {
			/*for (NodeSV* p = this->headSV; p != NULL; p = p->getNextSV()) {
				dssv.themSV(p->getDataSV(), 0);
			}*/

			ok = false;
			dssv.freeSV(dssv.getHeadSV());
			return;
			break;
		}
		}
	}
}
