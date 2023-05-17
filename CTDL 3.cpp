//hotel TEAM 19

#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include <string.h>
using namespace std;

//CLASS

class hotel
{
	int room_no;
	char name[30];
	char address[50];
	char phone[10];
	int dayin;
	int monthin;
	int yearin;
	int dayout;
	int monthout;
	int yearout;
public:

	void main_menu();		//hien thi menu
	void add();			//Dat phong
	void display(); 		//Hien thi ho so khach hang
	void rooms();			//Hien thi cac phong da duoc dat
	void edit();			//Chinh sua( them, xoa,...) ho so khach hang
	int check(int);			//Kiem tra tinh trang phong
	void modify(int);		//Chinh sua ho so
	void delete_rec(int);		//xoa ho so
	void bill();                 //hoa don
	void login();			//Dang nhap
	void empty_rooms();		//in phong trong
	void statistical(); 		//Thong ke
     };
    //END CLASS


// MAIN MENU
void hotel::main_menu()
{

int choice=998999;
while(choice!=7)
{

    system("cls");
	cout<<"\n\t\t\t\t*************************";
	cout<<"\n\t\t\t\t Team19 HOTEL MANAGEMENT ";
	cout<<"\n\t\t\t\t      * MAIN MENU *";
	cout<<"\n\t\t\t\t*************************";
	cout<<"\n\n\n\t\t\t1.Dat mot phong";
	cout<<"\n\t\t\t2.Ho so khach hang";
	cout<<"\n\t\t\t3.Phong da dat";
	cout<<"\n\t\t\t4.Chinh sua ";
	cout<<"\n\t\t\t5.Phong trong";
	cout<<"\n\t\t\t6.Thong ke";
	cout<<"\n\t\t\t7.thoat";
	cout<<"\n\n\t\t\tNhap lua chon cua ban: ";
	cin>>choice;

switch(choice)
{
	
	case 1:	add();
	break;
	
	case 2: display();
	break;
	
	case 3: rooms();
	break;
	
	case 4:	edit();
	break;
	
	case 5:	empty_rooms();
	break;
	
	case 6:	statistical();
	break;
	
	case 7: break;
	
	default:
	{
		cout<<"\n\n\t\t\tChon sai.....!!!";
		cout<<"\n\t\t\tNhan phim bat ki de tiep tuc....!!";
		getch();
	}
}
}
}


//HAM CHO VIEC DAT PHONG

void hotel::add()
{

    system("cls");
	int r,flag;
	ofstream fout("Record.dat",ios::app);	
	cout<<"\n Enter Customer Details";
	cout<<"\n ----------------------";
	cout<<"\n\n Phong so: ";
	cout<<"\n Tong: 50 phong";
	cout<<"\n 1 - 30: Phong don";
	cout<<"\n 31 - 45: Phong doi";
	cout<<"\n 46 - 50: Phong V.I.P";
	cout <<"\n Nhap so phong khach hang muon thue :- "<<endl;
	cin>>r;
	flag=check(r);
	if(flag)
		cout<<"\n Xin loi!!!! Phong da duoc dat truoc do!";
	else
	{	
		room_no=r;
		cout<<" Ten: ";
		cin>>name;
		cout<<" Dia chi: ";
		cin>>address;
		cout<<" So dien thoai: ";
		cin>>phone;
		cout<<" Ngay den: ";
		cin>>dayin;
		cout<<" Thang den: ";
		cin>>monthin;
		cout<<" Nam den: ";
		cin>>yearin;
		cout<<" Ngay di: ";
		cin>>dayout;
		cout<<" Thang di: ";
		cin>>monthout;
		cout<<" Nam di: ";
		cin>>yearout;
		fout.write((char*)this,sizeof(hotel));
		cout<<"\n Dat phong thanh cong...!!!";
}
	cout<<"\n Nhan phim bat ki de tiep tuc.....!!";
	getch();
	fout.close();
}

//KET THUC HAM DAT PHONG


//HAM CHO VIEC HIEN THI MOT HO SO KHACH HANG CU THE

void hotel::display()
{
	system("cls");
	ifstream fin("Record.dat",ios::in);
	int r,flag;
	cout<<"\n Nhap so phong de biet thong tin khach hang tai do :- "<<endl;
	cin>>r;
	flag=0;
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			system("cls");
			cout<<"\n Customer Details";
			cout<<"\n ----------------";
			cout<<"\n\n Phong so: "<<room_no;
			cout<<"\n Ten: "<<name;
			cout<<"\n Dia chi: "<<address;
			cout<<"\n So dien thoai: "<<phone;
			cout<<"\n Ngay den: "<<dayin;
			cout<<"\n Thang den: "<<monthin;
			cout<<"\n Nam den: "<<yearin;
			cout<<"\n Ngay di: "<<dayout;
			cout<<"\n Thang di: "<<monthout;
			cout<<"\n Nam di: "<<yearout;
			flag=1;
			break;
		}
	}
	if(flag==0)
	    cout<<"\n Phong khong duoc tim thay hoac chua co ai dat....!!";
	    
	cout<<"\n\n Nhan phim bat ki de tiep tuc....!!";
	getch();
	fin.close();
}


//HAM IN HO SO KHACH HANG THEO PHONG
void hotel::rooms()
{
	system("cls");
	ifstream fin("Record.dat",ios::in);
	cout<<"\n\t\t\t    Danh sach phong da duoc dat";
	cout<<"\n\t\t\t    ----------------------";
	cout<<"\n\n Phong \t\tTen\tDia chi\t\tSo dien thoai\t\tNgay den\t\t\tNgay di\n";
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		cout<<"\n\n "<<room_no<<"\t\t"<<name;
		cout<<"\t\t"<<address<<"\t\t"<<phone;
		cout<<"\t\t"<<dayin<<"."<<monthin<<"."<<yearin;
		cout<<"\t\t\t"<<dayout<<"."<<monthout<<"."<<yearout;
	}
	cout<<"\n\n\n\t\t\tNhan phim bat ki de tiep tuc.....!!";
	getch();
	fin.close();
}

//HAM CHO VIEC CHINH SUA VA TINH HOA DON

void hotel::edit()
{
	system("cls");
	int choice,r;
	cout<<"\n Chinh sua va tinh hoa don";
	cout<<"\n ---------";
	cout<<"\n\n 1. Sua doi ho so khach hang";
	cout<<"\n 2. Xoa ho so khach hang";
	cout<<"\n 3. Tinh hoa don";
	cout<<"\n Nhap lua chon cua ban: ";
	cin>>choice;
	system("cls");
	cout<<"\n Nhap so phong: " ;
	cin>>r;
	switch(choice)
	{
	
		case 1:	modify(r);
		break;
		
		case 2:	delete_rec(r);
		break;
		
		case 3: bill();
		break;
	
	    default: cout<<"\n Chon sai.....!!";
	}
	cout<<"\n Nhan phim bat ki de tiep tuc....!!!";
	getch();
	}
	
int hotel::check(int r)
	{
		int flag=0;
		ifstream fin("Record.dat",ios::in);
		while(!fin.eof())
		{
			fin.read((char*)this,sizeof(hotel));
			if(room_no==r)
			{
				flag=1;
				break;
			}
		}
		fin.close();
		return(flag);

}

void hotel::empty_rooms()
{
	int flg;
	system("cls");
	cout<<"\n\t\t\t    Danh sach phong chua duoc dat";
	cout<<"\n\t\t\t    ----------------------";
	cout<<"\n\n Phong \n";
	for(int p =1; p<=50; p++)
	{
		flg=check(p);
		if (flg != 1)
			cout<<"\n\n "<<p;
	}
	cout<<"\n\n\n\t\t\tNhan phim bat ki de tiep tuc.....!!";
	getch();
}
//FUNCTION TO MODIFY CUSTOMERS RECORD

void hotel::modify(int r)
{
	long pos,flag=0;
	fstream file("Record.dat",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			cout<<"\n Nhap thong tin moi";
			cout<<"\n -----------------";
			cout<<"\n Ten: ";
			cin>>name;
			cout<<" Dia chi: ";
			cin>>address;
			cout<<" So dien thoai: ";
			cin>>phone;
			cout<<" Ngay den: ";
			cin>>dayin;
			cout<<" Thang den: ";
			cin>>monthin;
			cout<<" Nam den: ";
			cin>>yearin;
			cout<<" Ngay di: ";
			cin>>dayout;
			cout<<" Thang di: ";
			cin>>monthout;
			cout<<" Nam di: ";
			cin>>yearout;
			file.seekg(pos);
			file.write((char*)this,sizeof(hotel));
			cout<<"\n Ho so da duoc sua doi!";
			flag=1;
			break;
		}
	}
	if(flag==0)
	cout<<"\n Phong khong duoc tim thay hoac bo trong...!!";
	file.close();
}


//FUNCTION FOR DELETING RECORD

void hotel::delete_rec(int r)
{
	int flag=0;
	char ch;
	ifstream fin("Record.dat",ios::in);
	ofstream fout("temp.dat",ios::out);
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			cout<<"\n Ten: "<<name;
			cout<<"\n Dia Chi: "<<address;
			cout<<"\n So dien thoai: "<<phone;
			cout<<"\n\n Ban co muon xoa ho so(y/n): ";
			cin>>ch;
			if(ch=='n')
			fout.write((char*)this,sizeof(hotel));
			flag=1;
		}
		else
			fout.write((char*)this,sizeof(hotel));
	}
	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Khong tim thay hoac bo trong!";
	else
	{
		cout<<"\n Ban da xoa ho so thanh cong!";
		remove("Record.dat");
		rename("temp.dat","Record.dat");
	}
}


//FUNCTION FOR CUSTOMER`S BILL
void hotel::bill()
{
	system("cls");
	ifstream fin("Record.dat",ios::in);
	int r,flag,T=1;
	cout<<"\n Nhap so phong de tinh hoa don :- "<<endl;
	cin>>r;
	flag=0;
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			if(r>=1&&r<=30){
				T=T*(dayout-dayin+(yearout-yearin)*365+(monthout-monthin)*30)*2000;
				cout<<"Hoa don = "<< T;
				
			}
		    else if (r>=35&&r<=45){
		    	T=T*(dayin-dayout+(yearout-yearin)*365+(monthout-monthin)*30)*4000;
				cout<<"Hoa don = "<< T;
			}
		    else{
		    	T=T*(dayin-dayout+(yearout-yearin)*365+(monthout-monthin)*30)*9000;
				cout<<"Hoa don = "<< T;
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	    cout<<"\n Phong khong duoc tim thay hoac chua co ai dat....!!";
	    
	cout<<"\n\n Nhan phim bat ki de tiep tuc....!!";
	getch();
	fin.close();
  }
void hotel::statistical()
{
	system("cls");
	ifstream fin("Record.dat",ios::in);
	int r,flag,T=1,D=1,V=1,Tong = 0;
	cout<<"\n Thong ke                    :- "<<endl;
	cout<<"\n ----------------------------:- "<<endl;
	flag=0;
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));		
			if(room_no>=1&&room_no<=30){
				T=T*(dayout-dayin+(yearout-yearin)*365+(monthout-monthin)*30);	
			}
		    if (room_no>=35&&room_no<=45){
		    	D=D*(dayout-dayin+(yearout-yearin)*365+(monthout-monthin)*30);	
			}
		    if(room_no>=45&&room_no<=50) {
		    	V=V*(dayout-dayin+(yearout-yearin)*365+(monthout-monthin)*30);	
			}

	}
	T=T*2000;
	D=D*4000;
	V=V*9000;
	Tong= T+D+V;
	cout<<"\n\nLoai Phong\t\tTong Tien";
	cout<<"\n\nThuong\t\t"<<T;
	cout<<"\n\nDoi\t\t"<<D;
	cout<<"\n\nVip\t\t"<<V;
	cout<<"\n-----------------------------";
	cout<<"\t\t\t\t\t\t\tTong Thu: "<< Tong;	
	cout<<"\n\n Nhan phim bat ki de tiep tuc....!!";
	getch();
	fin.close();
  }


//CLASS staff
class staff
{
    int id;
	char name[30];
	int password;

public:

	void staff_menu();		//hien thi menu
	void add_staff();			//Them nhan vien
	void staff_list();           //Danh sach nhan vien
	int check(int r);			//Kiem tra id nhan vien
	void delete_staff();		//xoa nhan vien
	int login();			//Dang nhap
     };

void staff::staff_menu()
{
int choice;
while(choice!=4)
{

  system("cls");
	cout<<"\n\t\t\t\t*************************";
	cout<<"\n\t\t\t\t Team19 STAFF MANAGEMENT ";
	cout<<"\n\t\t\t\t      * MAIN MENU *";
	cout<<"\n\t\t\t\t*************************";
	cout<<"\n\n\n\t\t\t1.Them 1 nhan vien";
	cout<<"\n\t\t\t2.Xoa 1 nhan vien";
	cout<<"\n\t\t\t3.In danh sach";
	cout<<"\n\t\t\t4.Thoat";
	cout<<"\n\n\t\t\tNhap lua chon cua ban: ";
	cin>>choice;
	switch(choice)
	{
	
	case 1:	add_staff();
	break;
	
	case 2: delete_staff();
	break;
	
	case 3: staff_list();
	break;
	
	case 4:break;
	default:
	{
	cout<<"\n\n\t\t\tChon sai.....!!!";
	cout<<"\n\t\t\tNhan phim bat ki de tiep tuc....!!";
	getch();
	}
	}
	}
}

void staff::add_staff()
{
	system("cls");
	int r,flag;
	ofstream fout("Staff.dat",ios::app);
	cout<<"\n Them nhan vien";
	cout <<"\n Nhap ID : "<<endl;
	cin>>r;
	flag=check(r);
	if(flag)
		cout<<"\n Xin loi!!!! ID da duoc dung truoc do!";
	else
	{
		id=r;
		cout<<" Ten: ";
		cin>>name;
		cout<<" Pasword: ";
		cin>>password;
		fout.write((char*)this,sizeof(staff));
		cout<<"\n Them thanh cong...!!!";
	}
	cout<<"\n Nhan phim bat ki de tiep tuc.....!!";
	getch();
	fout.close();
}

void staff::staff_list()
{
	system("cls");
	ifstream fin("Staff.dat",ios::in);
	cout<<"\n\t\t\t    Danh sach nhan vien   ";
	cout<<"\n\t\t\t    ----------------------";
	cout<<"\n\n ID\t\tTen\t\tPassword\n";
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(staff));
		cout<<"\n\n "<<id<<"\t\t"<<name;
		cout<<"\t\t"<<password;
	}
	cout<<"\n\n\n\t\t\tNhan phim bat ki de tiep tuc.....!!";
	getch();
	fin.close();
}

int staff::check(int r)
{
	int flag=0;
	ifstream fin("Staff.dat",ios::in);
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(staff));
		if(id==r)
		{
			flag=1;
			break;
		}
	}
	fin.close();
	return(flag);
}

void staff::delete_staff()
{
	system("cls");	
	cout<<"Xoa nhan vien";
	int r,flag=0;
	char ch;
	ifstream fin("Staff.dat",ios::in);
	ofstream fout("Temp.dat",ios::out);
	cout<<"\n Nhap id: \n";
	cin>>r;
	flag = check(r);
	if(flag)
		while(!fin.eof())
		{
			fin.read((char*)this,sizeof(staff));
			if(id==r)
			{
				cout<<"\n Ten: "<<name;
				cout<<"\n pasword "<<password;
				cout<<"\n\n Ban co muon xoa ho so(y/n): ";
				cin>>ch;
				if(ch=='n')
				fout.write((char*)this,sizeof(staff));
				flag=1;
			}
			else
				fout.write((char*)this,sizeof(staff));
		}
	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Khong tim thay !";
	else
	{
		cout<<"\n Ban da xoa thanh cong!";
		remove("Staff.dat");
		rename("Temp.dat","Staff.dat");
	}
}


int staff::login()
{
	system("cls");	
	cout<<"Dang nhap he thong quan ly khach san";	
	int r;
	int flag,FG=0;
	char n,p;
	cout<<"\n Nhap id: ";
	cin>>r;
	flag = check(r);
	ifstream fin("Staff.dat",ios::in);
	if (flag)
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(staff));
		if(id ==r)
		{
			cout<<"\n Ten: "<< name;
			cout<<"\n Mat khau: ";
			cin >> p;
		if (p==password){
			FG =1;
		}
		}
	}
	fin.close();
	cout << "n";
	return(FG);
}

int main()
{
	hotel h;
	staff s;
	system("cls");
	cout<<"\n\t\t\t****************************************";
	cout<<"\n\t\t\t DE TAI: THIET KE CAU TRUC DU LIEU \n\t\t\t          THUAT TOAN VA XAY DUNG \n\t\t\t       CHUONG TRINH QUAN LY KHACH SAN ";
	cout<<"\n\t\t\t****************************************";
	cout<<"\n";
	cout<<"\t\t\t Team 19:\n\n";
	cout<<"\t\t Do Manh Thang\t\t 20139091\n";
	cout<<"\t\t Nguyen Thi Thao\t 20139090\n";
	cout<<"\t\t Phan Quyet Thang\t 20139050\n";
	cout<<"\n\n\n\n\n\t\t\tNhap phim bat ki de tiep tuc....!!";
	getch();
	int a;
	while(a!=3)
	{
	  system("cls");
		cout<<"\n\t\t\t\t*************************";
		cout<<"\n\t\t\t\t Team19: HOTEL MANAGEMENT ";
		cout<<"\n\t\t\t\t      * LOGIN *          ";
		cout<<"\n\t\t\t\t*************************";
		cout<<"\n\n\n\t\t\t1. Dang nhap he thong quan ly nhan vien";
		cout<<"\n\n\n\t\t\t2. Dang nhap he thong quan ly khach san ";
		cin>>a;
switch(a)
{
	case 1:{
		int password=9999999, dem=-1;
	while(password!=999)
	{
	dem = dem +1;
	  system("cls");
		cout<<"\n\t\t\t\t*************************";
		cout<<"\n\t\t\t\t Team19: HOTEL MANAGEMENT ";
		cout<<"\n\t\t\t\t      * LOGIN *          ";
		cout<<"\n\t\t\t\t*************************";
		cout<<"\n\n\n\t\t\tBan da nhap sai "<< dem <<" lan";
		cout<<"\n\n\n\t\t\tNhap mat khau (Nhap sai khong qua 3 lan): ";
		cout<<"(Nhap 999 de thoat)";
			if (dem ==3){
			password=999;
			break;
		}
		cin>>password;
		if (password==123456)
		{
			s.staff_menu();
			break;
		}
		
	};
	break;
	}
	case 2: {
		int FG=s.login();
		if (FG==0){
			h.main_menu();
		}
		break;
	}
	
	case 3:
	break;
	default:
	{
	cout<<"\n\n\t\t\tChon sai.....!!!";
	cout<<"\n\t\t\tNhan phim bat ki de tiep tuc....!!";
	getch();
	}
}		
}
return 0;
}

//END OF MAIN PROGRAM
