#include"iostream"
#include"string"
#include"stdlib.h"
using namespace std;

struct SinhVien {
	
	string mahocphan;
	string tenhocphan;
	int sotinchi;
};//
typedef struct SinhVien sinhvien;
struct node {
	sinhvien *data;
	struct  node* link;
};
typedef struct node Node;
struct list {
	Node* pHead;
	Node* pTail;
};//
typedef struct list List;
void KhoiTaoList(List &l) {
	l.pHead = l.pTail = NULL;
}
void Input_ThongTin(sinhvien *sv) {
	cin.ignore();
	cout << "Nhap ten hoc phan \n";
	getline(cin,sv->tenhocphan);
	cout << "Nhap Ma hoc phan : ";
	getline(cin,sv->mahocphan )	;
	cout << "Nhap so tin chi : ";
	cin>>sv->sotinchi ;
}
Node *KhoiTaoNode() {
	sinhvien* sv = new sinhvien;
	Input_ThongTin(sv);
	Node* p = new Node;
	if (p == NULL) {
		cout << "full ram ko the tao them\n";
		return 0;
	}
	p->data = sv;
	p->link = NULL;
	return p;
}
void ThemVaoDauMotSinhVien(List &l, Node *p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail= p;
	}
	else {
		p->link = l.pHead;
		l.pHead = p;
	}
}
//hàm xóa phần tử đầu và phần tử cuối
void xoadau(List &l)
{
	if(l.pHead==NULL)
	{
		return ;
	}
	else 
	{
		Node*p=l.pHead;//node p là node để xóa 
		l.pHead=l.pHead->link;
		delete p;
	}
}
//xóa phần tử cuối cùng 
void xoacuoi(List &l)
{
	if(l.pHead==NULL)
	{
		return ;
	}
	else
	{
		for(Node*k=l.pHead;k!=NULL;k=k->link)
		{
			if(k->link==l.pTail)
			{
				delete l.pTail;//xóa phần tử cuối cùng 
               k->link=NULL;//cho phần tử kế cuối trỏ đến vùng nhớ null
				l.pTail=k;
				return ;
			}
		}
	}
}
//hàm xóa node sau node q
void xoasau(List &l,Node*q)
{// duyệt từ đầu đến cuối để tìm node q

	for(Node*k=l.pHead;k!=NULL;k=k->link)
	{
      if(k->data==q->data)
	  {
		 //tạo một node g là node chứa mối liên kết với node sau k hay q
		  Node*g=k->link; 
		  //cập nhật mối liên kết giữa node k hay q với g
		  k->link=g->link;
		  //xóa q cũng chính là g;
		  delete g;
		  return ;
	  }
	}
}
//ham xoa mot cai node co khoa k bat ki

void Show(List l) {
	for (Node* k = l.pHead; k != NULL; k = k->link) {
		cout << "ma hoc phan: " << k->data->mahocphan<<endl;
		cout << "ten hoc phan: " << k->data->tenhocphan<< endl;
		cout << "so tin chi: " << k->data->sotinchi << endl;
		cout << "==============================SV================\n";
	}
}
void ChucNang(List &l) {
	int n;
	cout << "======Danh Sach Chuc Nang=========\n";
	cout << "1 => Nhap 1 sinh vien moi .\n";
	cout << "2 => In danh sach sinh vien .\n ";
	cout << "3 => xoa phan tu dau tien.\n";
	cout << "4 => xoa phan tu cuoi cung.\n";
	cout << "5 => xoa phan tu sau node q.\n";
	cout << "0 =>Thoat chuong trinh\n";
	while (1){
		cout << "Nhap chuc nang ban  chon : ";
		cin >> n;
		if (n == 1) {
			cout << "Moi Ban nhap thong tin 1 sinh vien : \n";
			Node* p = KhoiTaoNode();
			ThemVaoDauMotSinhVien(l, p);
		}
		if (n == 2) {
			cout << "Danh Sach Sinh Vien : \n";
			Show(l);
		}
		if(n==3)
		{
			cout<<"xoa phan tu dau tien ";
			xoadau(l);
		}
		if(n==4)
		{
			cout<<"xoa phan tu cuoi ";
			xoacuoi(l);
		}
		if(n==5)
		{
		
			 int x;
			cout<<"nhap node q:";
			cin>>x;
			Node *q;
             xoasau(l,q);
		}
		
		if (n == 0) 
		{
			break;
		}
	
			}
}

//hàm in danh sách sinh vien 



int main() {
	List l;
	KhoiTaoList(l);
	ChucNang(l);
	system("pause");
	return 0;
}

