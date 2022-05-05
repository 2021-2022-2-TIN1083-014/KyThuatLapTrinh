#include<iostream>
#include<string>
using namespace std;
struct sinhvien
{
    string mahocphan;
    string tenhocphan;
    int sotinchi;
};typedef struct sinhvien sv;
//
struct node
{
    sv data;
	struct node *pNext; 	 
};
typedef struct node NODE;

//
struct list
{ 
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
//
void KhoiTaoDSLK(LIST &l)
{

    l.pHead   = NULL;
	l.pTail = NULL;
}
NODE *KhoiTaoNode(sv x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data  = x; 
	p->pNext = NULL;
	return p;
}
//
void ThemVaoDau(LIST &l, NODE *p)
{
	//danh sách liên kết rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}


void ThemVaoCuoi(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p; 
	}
}
//xóa phần tử đầu danh sach liên kết
void xoaphantudau(LIST &l)
{

	if(l.pHead==NULL)
	{
		return ;
	}
	else
	{
		NODE*p=l.pHead;//lấy con trỏ giữ vị trí node đầu hiện tại ,node này sẽ bị xóa
		//nếu ta không lấy con trỏ này thì khi ta cập nhật thằng pHead đến tk tiếp theo thì thằng pHead cần xóa sẽ không có dể xóa
        l.pHead=l.pHead->pNext;
		delete p;
	}
}
//
void xoacuoi(LIST &l)
{
	if(l.pHead==NULL)
	{
		return ;
	}//trường hợp danh sách chỉ có một phần tử 
	if(l.pHead->pNext==NULL)
	{
		xoaphantudau(l);
		return ;
	}
	else
	{
		for(NODE*k=l.pHead;k!=NULL;k=k->pNext)
		{
			if(k->pNext==l.pTail)//tức là k là thằng kế cuối 
			{
				delete l.pTail;//xóa phần tử cuối cùng 
               k->pNext=NULL;//cho phần tử kế cuối trỏ đến vùng nhớ null
				l.pTail=k;
				return ;
			}
		}
	}
}//xoa sau 

void XuatDanhSach(LIST l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout<<"-----------------Sinhvien-----------------"<<endl;
		cout<<"mahocphan:"<<k->data.mahocphan <<" "<<"\n";
        cout<<"tenhocphan:"<<k->data.tenhocphan<<" "<<"\n";
        cout<<"sotinchi:"<<k->data.sotinchi<<" "<<"\n";
  
	}
}


// menu
void Menu(LIST &l)
{
	int luachon;
	while (true)
	{   
	    system("cls");
		cout << "\n\n\t\t========== Menu ==========";
		cout << "\n\t1. Them node vao danh sach";
		cout << "\n\t2. Xuat danh sach lien ket don";
		cout << "\n\t3. Xoa phan tu dau tien ";
		cout << "\n\t4. Xoa phan tu cuoi ";
		
		cout << "\n\t0. Thoat";
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon < 0 || luachon > 4)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai !";
		}
		else if (luachon == 1)
		{
			sv x;
			cin.ignore();
	        cout << "Nhap ten hoc phan:";
          	getline(cin,x.tenhocphan);
	        cout << "Nhap Ma hoc phan : ";
          	getline(cin,x.mahocphan )	;
         	cout << "Nhap so tin chi : ";
	        cin>>x.sotinchi;
			NODE *p = KhoiTaoNode(x); 
			ThemVaoCuoi(l, p); // thêm node vào cu?i danh sách
		}
		else if (luachon == 2)
		{
			XuatDanhSach(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			xoaphantudau(l);
		}
		else if (luachon == 4)
		{
			xoacuoi(l);
		}
	
		else
		{
			break; 
		}
	}
}

int main()
{
	LIST l;
	KhoiTaoDSLK(l);
	Menu(l);
	return 0;
}