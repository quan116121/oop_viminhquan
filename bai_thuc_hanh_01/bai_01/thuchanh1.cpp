#include<iostream>
#include<iomanip>
using namespace std;
class phuong_tien{
	private:
		int maxe;
		string loaixe;
		int giovao;
		int tgdo;
		double phiDoXe;
	public:
		phuong_tien(){
			maxe = 0;
			loaixe = "";
			giovao = 0;
			tgdo = 0;
			phiDoXe = 0.0;
		}
		phuong_tien(int ma, string loai, int gio, int tg){
			maxe = ma;
			loaixe = loai;
			giovao = gio;
			tgdo = tg;
			phiDoXe = 0.0;
		}
		int layMaXe() const{
			return maxe;
		}
		string layLoaiXe() const{
			return loaixe;
		}
		double tinh_phi() {
			double gia;
			if(loaixe == "Car")
			   gia = 6000;
			else if(loaixe == "Motorcycle")
			   gia = 4000;
			else if(loaixe == "Bicycle")
			   gia = 2000;
			if((giovao >= 6 && giovao <= 9) || (giovao >= 15 && giovao <= 18)){
				gia *= 1.3;
			}
			else{
				gia *= 0.95;
			}
			if(tgdo > 2){
				phiDoXe = gia * 2 + gia * (tgdo - 2) * 0.9;
			}
			else{
				phiDoXe = gia * tgdo;
			}
			return phiDoXe;
		}
		void hienthi() const{
			cout<<"Ma xe: "<<maxe<<endl;
			cout<<"Loai xe: "<<loaixe<<endl;
			cout<<"Gio vao: "<<giovao<<endl;
			cout<<"Thoi gian do: "<<tgdo<<endl;
			cout<<"Phi: "<<phiDoXe<<" VND";
		}
};
class bai_xe{
	private:
		int mabai;
		char kichthuoc;
		phuong_tien pt1, pt2, pt3;
		bool co1, co2, co3;
	public:
		bai_xe(){
			mabai = 0;
			kichthuoc = '\0';
		    co1 = co2 = co3 = false;
		}
		bai_xe(int ma, char kt){
			mabai = ma;
			kichthuoc = kt;
			co1 = co2 = co3 = false;
		}
		int layMaBai() const{
			return mabai;
		}
		bool them(phuong_tien v){
			int cap = (kichthuoc == 'S')?1:(kichthuoc == 'M')?2:3;
			if(cap >= 1 && !co1){
				pt1 = v;
				co1 = true;
				return true;
			}
			if(cap >= 2 && !co2){
				pt2 = v;
				co2 = true;
				return true;
			}
			if(cap >= 3 && !co3){
				pt3 = v;
				co3 = true;
				return true;
			}
			return false;
		}
		bool xoa(int ma_xe){
			if(co1 && pt1.layMaXe() == ma_xe){
				if(co2){
					pt1 = pt2;
					if(co3){
						pt2 = pt3;
						co3 = false;
					}
					else co2 = false;
				}
				else co1 = false;
				return true;
			}
			if(co2 && pt2.layMaXe() == ma_xe){
				if(co3){
					pt2 = pt3;
					co3 = false;
				}
				else co2 = false;
				return true;
			}
			if(co3 && pt3.layMaXe() == ma_xe){
				co3 = false;
				return true;
			}
			return false;
		}
		bool chua(int ma_xe) const{
			if(co1 && pt1.layMaXe() == ma_xe) return true;
			if(co2 && pt2.layMaXe() == ma_xe) return true;
			if(co3 && pt3.layMaXe() == ma_xe) return true;
			return false;
		}
		void hien_thi() const{
		    int cap = (kichthuoc == 'S')?1:(kichthuoc == 'M')?2:3;
		    int so_xe = co1 + co2 + co3;
		    cout<<"Bai"<<mabai<<"["<<kichthuoc<<"]"<<so_xe<<"/"<<cap<<"xe\n";
		    if(co1) pt1.hienthi();
		    if(co2) pt2.hienthi();
		    if(co3) pt3.hienthi();
		}
		bool co_loai(string loai, int& dem, double& tong) {
		    dem =0; tong = 0;
		    if(co1 && pt1.layLoaiXe() == loai){
		    	++dem;
		    	tong += pt1.tinh_phi();
			}
			if(co2 && pt2.layLoaiXe() == loai){
				++dem;
				tong += pt2.tinh_phi();
			}
			if(co3 && pt3.layLoaiXe() == loai){
				++dem;
				tong += pt3.tinh_phi();
			}
			return dem > 0;
		}
};
class giao_dien{
	private:
		bai_xe bai1, bai2, bai3;
		bool co1, co2, co3;
	public:
		giao_dien(){
			co1 = co2 = co3 = false;
		};
		void runMenu(){
			int chon;
			while(true){
				cout<<"\n=====QUAN LY BAI DO XE=====\n";
				cout<<"1. Tao bai do\n";
				cout<<"2. Them xe\n";
				cout<<"3. Xoa bai do\n";
				cout<<"4. Lay xe ra\n";
				cout<<"5. Hien thi tat ca bai do\n";
				cout<<"6. Hien thi xe theo bai\n";
				cout<<"7. Liet ke xe theo loai\n";
				cout<<"8. Bao cao phi trung binh\n";
				cout<<"9. Thoat\n";
				cout<<"Chon: ";
				cin>>chon;
				if (chon == 1) {
                   int ma; char kt;
                   cout << "Ma bai: "; cin >> ma;
                   cout << "Kich thuoc (S/M/L): "; cin >> kt;
                   if (!co1)      { bai1 = bai_xe(ma, kt); co1 = true; }
                   else if (!co2) { bai2 = bai_xe(ma, kt); co2 = true; }
                   else           { bai3 = bai_xe(ma, kt); co3 = true; }
                   cout << "Da tao bai " << ma << "\n";
                }
                else if (chon == 2) {
                   int ma, gio, tg; string loai;
                   cout << "Ma xe: "; cin >> ma;
                   cout << "Loai (Car/Motorcycle/Bicycle): "; cin >> loai;
                   cout << "Gio vao (0-23): "; cin >> gio;
                   cout << "Thoi luong (1-23): "; cin >> tg;
                   phuong_tien v(ma, loai, gio, tg);
                   bool ok = false;
                   if (co1 && !ok) ok = bai1.them(v);
                   if (co2 && !ok) ok = bai2.them(v);
                   if (co3 && !ok) ok = bai3.them(v);
                   if (ok) cout << "Da them xe " << ma << " | Phi: $" << fixed << setprecision(2) << v.tinh_phi() << "\n";
                   else    cout << "Tat ca bai da day!\n";
                }
                else if (chon == 3) {
                   int ma;
                   cout << "Ma bai can xoa: "; cin >> ma;
                   if (co1 && bai1.layMaBai() == ma) {
                        if (co2) { bai1 = bai2; if (co3) { bai2 = bai3; co3 = false; } else co2 = false; }
                        else co1 = false;
                            cout << "Da xoa bai " << ma << "\n";
                    }
                   else if (co2 && bai2.layMaBai() == ma) {
                        if (co3) { bai2 = bai3; co3 = false; } else co2 = false;
                             cout << "Da xoa bai " << ma << "\n";
                    }
                   else if (co3 && bai3.layMaBai() == ma) {
                        co3 = false;
                        cout << "Da xoa bai " << ma << "\n";
                    }
                }
                else if (chon == 4) {
                   int ma;
                   cout << "Ma xe can lay ra: "; cin >> ma;
                   bool ok = false;
                   if (co1 && !ok) ok = bai1.xoa(ma);
                   if (co2 && !ok) ok = bai2.xoa(ma);
                   if (co3 && !ok) ok = bai3.xoa(ma);
                   cout << (ok ? "Da lay xe ra\n" : "Khong tim thay xe\n");
                }
                else if (chon == 5) {
                   if (co1) bai1.hien_thi();
                   if (co2) bai2.hien_thi();
                   if (co3) bai3.hien_thi();
                }
                else if (chon == 6) {
                   int ma;
                   cout << "Ma bai: "; cin >> ma;
                   if (co1 && bai1.layMaBai() == ma) bai1.hien_thi();
                   else if (co2 && bai2.layMaBai() == ma) bai2.hien_thi();
                   else if (co3 && bai3.layMaBai() == ma) bai3.hien_thi();
                }
               else if (chon == 7) {
                   string loai;
                   cout << "Loai xe: "; cin >> loai;
                   int dem; double tong;
                   if (co1 && bai1.co_loai(loai, dem, tong)) bai1.hien_thi();
                   if (co2 && bai2.co_loai(loai, dem, tong)) bai2.hien_thi();
                   if (co3 && bai3.co_loai(loai, dem, tong)) bai3.hien_thi();
                }
               else if (chon == 8) {
                   string loai_arr[3] = {"Car", "Motorcycle", "Bicycle"};
                   for (int t = 0; t < 3; ++t) {
                       int dem = 0; double tong = 0;
                       int d; double s;
                       if (co1) { bai1.co_loai(loai_arr[t], d, s); dem += d; tong += s; }
                       if (co2) { bai2.co_loai(loai_arr[t], d, s); dem += d; tong += s; }
                       if (co3) { bai3.co_loai(loai_arr[t], d, s); dem += d; tong += s; }
                       cout << loai_arr[t] << ": ";
                       if (dem == 0) cout << "khong co xe\n";
                       else cout << dem << " xe | TB: $" << fixed << setprecision(2) << tong / dem << "\n";
                    }
                }
               else if (chon == 9) break;
            }
       }
};
int main() {
    giao_dien sys;
    sys.runMenu();
    return 0;
};
	
