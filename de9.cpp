#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <iomanip>  
  
using namespace std;  
  
class Phong {  
public:  
    static int nextMaKieuPhong;  
    int maKieuPhong;  
    string kieuPhong;  
    double mucTienThue;  
    int soPhong;  
  
    Phong(string kieu, double mucTien, int so) : kieuPhong(kieu), mucTienThue(mucTien), soPhong(so) {  
        maKieuPhong = nextMaKieuPhong++;  
    }  
};  
  
int Phong::nextMaKieuPhong = 1;  
  
class KhachHang {  
public:  
    static int nextMaKhachHang;  
    int maKhachHang;  
    string hoTen;  
    string diaChi;  
    string soDienThoai;  
    string loaiPhongCanThue;  
    int soPhongCanThue;  
  
    KhachHang(string ten, string diaChi, string sdt, string loaiPhong, int soPhong)  
        : hoTen(ten), diaChi(diaChi), soDienThoai(sdt), loaiPhongCanThue(loaiPhong), soPhongCanThue(soPhong) {  
        maKhachHang = nextMaKhachHang++;  
    }  
};  
  
int KhachHang::nextMaKhachHang = 1;  
  
class BangSapXep : public Phong, public KhachHang {  
public:  
    int soLuongPhong;  
    int soNgayThue;  
  
    BangSapXep(const KhachHang& khach, const Phong& p, int soLuong, int soNgay)  
        : KhachHang(khach), Phong(p), soLuongPhong(soLuong), soNgayThue(soNgay) {}  
};  
  
// H�m so s�nh cho vi?c s?p x?p theo h? t�n  
bool compareHoTen(const KhachHang& a, const KhachHang& b) {  
    return a.hoTen < b.hoTen;  
}  
  
// H�m so s�nh cho vi?c s?p x?p theo s? ti?n thu�  
bool compareSoTienThue(const BangSapXep& a, const BangSapXep& b) {  
    return (a.soLuongPhong * a.mucTienThue * a.soNgayThue) < (b.soLuongPhong * b.mucTienThue * b.soNgayThue);  
}  
  
// H�m nh?p th�ng tin ph�ng t? b�n ph�m  
Phong nhapPhong() {  
    string kieuPhong;  
    double mucTien;  
    int soPhong;  
    cin.ignore();  
    cout << "  Nhap kieu phong: ";  
    getline(cin, kieuPhong);  
  
    cout << "  Nhap muc tien thue: ";  
    cin >> mucTien;  
  
    cout << "  Nhap so phong: ";  
    cin >> soPhong;  
      
    cout << endl;  
      
    return Phong(kieuPhong, mucTien, soPhong);  
}  
  
// H�m nh?p th�ng tin kh�ch h�ng t? b�n ph�m  
KhachHang nhapKhachHang() {  
    string hoTen, diaChi, soDienThoai, loaiPhong;  
    int soPhong;  
      
    cout << "  Nhap ho ten khach hang: ";  
    cin.ignore(); // �? tr�nh l?i khi nh?p getline sau cin  
    getline(cin, hoTen);  
  
    cout << "  Nhap dia chi: ";  
    getline(cin, diaChi);  
  
    cout << "  Nhap so dien thoai: ";  
    cin >> soDienThoai;  
    cin.ignore();  
      
    cout << "  Nhap loai phong can thue: ";  
    getline(cin, loaiPhong);  
  
    cout << "  Nhap so phong can thue: ";  
    cin >> soPhong;  
      
    cout << endl;  
  
    return KhachHang(hoTen, diaChi, soDienThoai, loaiPhong, soPhong);  
}  
  
void inBangKhachHang(const std::vector<KhachHang>& danhSachKhachHang) {  
    // In ph?n d?u b?ng  
    cout << setw(5) << left << "STT" << "|"  
              << setw(20) << left << "Ho Ten" << "|"  
              << setw(30) << left << "Dia Chi" << "|"  
              << setw(15) << left << "So Dien Thoai" << "|"  
              << setw(15) << left << "Loai Phong" << "|"  
              << setw(10) << left << "So Phong" << "|"  
              << endl;  
  
    // In du?ng k? d?u b?ng  
    cout << setfill('-') << setw(105) << "" << setfill(' ') << endl;  
  
    // In th�ng tin t?ng kh�ch h�ng  
    for (size_t i = 0; i < danhSachKhachHang.size(); ++i) {  
        const KhachHang& khachHang = danhSachKhachHang[i];  
        cout << setw(5) << left << i + 1 << "|"  
                << setw(20) << left << khachHang.hoTen<< "|"  
                << setw(30) << left << khachHang.diaChi << "|"  
                << setw(15) << left << khachHang.soDienThoai << "|"  
                << setw(15) << left << khachHang.loaiPhongCanThue << "|"  
                << setw(10) << left << khachHang.soPhongCanThue << "|"  
                << endl;  
    }  
}  
  
void inBangPhong(const vector<Phong>& danhSachPhong) {  
    // In ph?n d?u b?ng  
    cout << setw(5) << left << "STT" << "|"  
            << setw(20) << left << "Kieu phong" << "|"  
            << setw(30) << left << "Muc tien thue" << "|"  
            << setw(10) << left << "So Phong" << "|"  
            << endl;  
  
    // In du?ng k? d?u b?ng  
    cout << setfill('-') << setw(105) << "" << setfill(' ') << endl;  
  
    // In th�ng tin t?ng kh�ch h�ng  
    for (size_t i = 0; i < danhSachPhong.size(); ++i) {  
        const Phong& phong = danhSachPhong[i];  
        cout << setw(5) << left << i + 1 << "|"  
                << setw(20) << left << phong.kieuPhong << "|"  
                << setw(30) << left << phong.mucTienThue<< "|"  
                << setw(10) << left << phong.soPhong << "|"  
                << endl;  
    }  
}  
  
void inBangSapXep(const vector<BangSapXep>& danhSachSapXep) {  
    // In ph?n d?u b?ng  
    cout << setw(5) << left << "STT" << "|"  
            << setw(20) << left << "Ho Ten" << "|"  
            << setw(15) << left << "Loai Phong" << "|"  
            << setw(10) << left << "So Phong" << "|"  
            << setw(10) << left << "So Ngay Thue" << "|"  
            << endl;  
  
    // In du?ng k? d?u b?ng  
    cout << setfill('-') << setw(80) << "" << setfill(' ') << endl;  
  
    // In th�ng tin t?ng kh�ch h�ng  
    for (size_t i = 0; i < danhSachSapXep.size(); ++i) {  
        const BangSapXep& sapXep = danhSachSapXep[i];  
        cout << setw(5) << left << i + 1 << "|"  
                << setw(20) << left << sapXep.hoTen << "|"  
                << setw(15) << left << sapXep.kieuPhong << "|"  
                << setw(10) << left << sapXep.soLuongPhong << "|"  
                << setw(10) << left << sapXep.mucTienThue << "|"  
                << endl;  
    }  
}  
  
int main() {  
    // Danh s�ch c�c lo?i ph�ng  
    vector<Phong> danhSachPhong;  
  
    // Danh s�ch kh�ch h�ng  
    vector<KhachHang> danhSachKhachHang;  
  
    int soLoaiPhong, soKhachHang;  
    cout << "Nhap so loai phong: ";  
    cin >> soLoaiPhong;  
  
    for (int i = 0; i < soLoaiPhong; ++i) {  
        cout << "Nhap thong tin phong thu " << i + 1 << endl;  
        danhSachPhong.push_back(nhapPhong());  
    }  
  
    cout << "Nhap so khach hang: ";  
    cin >> soKhachHang;  
  
    for (int i = 0; i < soKhachHang; ++i) {  
        cout << "Nhap thong tin khach hang thu " << i + 1 << endl;  
        danhSachKhachHang.push_back(nhapKhachHang());  
    }  
      
  
    // In danh s�ch ph�ng  
    inBangPhong(danhSachPhong);  
    cout << endl;  
    inBangKhachHang(danhSachKhachHang);  
  
    // Nh?p th�ng tin s?p x?p cho m?i kh�ch h�ng  
    vector<BangSapXep> danhSachSapXep;  
    for (const auto& khachHang : danhSachKhachHang) {  
        for (const auto& phong : danhSachPhong) {  
            if (phong.kieuPhong == khachHang.loaiPhongCanThue && phong.soPhong >= khachHang.soPhongCanThue) {  
                danhSachSapXep.push_back(BangSapXep(khachHang, phong, khachHang.soPhongCanThue, phong.mucTienThue)); // S? ng�y thu� m?c d?nh l� 7 ng�y  
                break;  
            }  
        }  
    }  
      
    cout << endl;  
    inBangSapXep(danhSachSapXep);  
    cout << endl;  
    // S?p x?p danh s�ch theo h? t�n kh�ch h�ng  
    sort(danhSachKhachHang.begin(), danhSachKhachHang.end(), compareHoTen);  
  
    // In danh s�ch kh�ch h�ng sau khi s?p x?p  
    inBangSapXep(danhSachSapXep);  
    cout << endl;  
  
    // S?p x?p danh s�ch s?p x?p theo s? ti?n thu�  
    sort(danhSachSapXep.begin(), danhSachSapXep.end(), compareSoTienThue);  
  
    // In danh s�ch s?p x?p sau khi s?p x?p theo s? ti?n thu�  
    inBangSapXep(danhSachSapXep);  
  
    return 0;  
}


