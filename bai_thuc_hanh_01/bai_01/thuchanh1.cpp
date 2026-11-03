#include<iostream>
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
		phuong_tien(int ma, string loai, int gio, int tg, double phi){
			maxe = ma;
			loaixe = loai;
			giovao = gio;
			tgdo = tg;
			phiDoXe = phi;
		}
		int layMaXe() const{
			return maxe;
		}
		string layLoaiXe() const{
			return loaixe;
		}
		double tinh_phi(){
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
		}
		int layMaBai() const{
			return mabai;
		}
		bool them(phuong_tien v){
			int cap = (kicthuoc == 'S')?1:(kichthuoc == 'M')?2:3;
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
			if(co1 && pt1.layMaXe == ma_xe) return true;
			if(co2 && pt2.layMaXe == ma_xe) return true;
			if(co3 && pt3.layMaXe == ma_xe) return true;
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
		bool co_loai(string loai, int& dem, double& tong) const{
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
		giao_dien();
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
				if(chon == 1){
					
				}
			}
		}
};
int main(){
	phuong_tien phuongtien(101, "Motorcycle", 7, 5, 0);
	phuongtien.tinh_phi();
	phuongtien.hienthi();
	return 0;
}
