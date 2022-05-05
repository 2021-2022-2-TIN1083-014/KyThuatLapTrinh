#include<iostream>
using namespace std;
//
struct node 
{
    int data;
    struct node * pNext;

};typedef struct node  NODE;
//
struct list
{
    NODE * pHead;
    NODE * pTail;
};typedef struct list LIST;
//
void khoitaodanhsach(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
//
NODE *khoitaonode(int x)
{
	NODE *p = new NODE; // cấp phát vùng nhớ cho NODE p
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // truyền giá trị x vào cho data
	p->pNext = NULL; // đầu tiên khai báo node thì node đó chưa có liên kết đến node nào hết ==> con trỏ của nó sẽ trỏ đến NULL
	return p; // trả về NODE p vừa khởi tạo
}
//thêm vào đầu danh sach liên kết 
void themvaodau(LIST &l, NODE * p)
{
    if(l.pHead == NULL)//danh sách rỗng
    {
        l.pHead=l.pTail=p;
    }
    else 
    {
        p -> pNext = l.pHead;
        l.pHead = p;
    }
}
//hàm thêm vào cuối danh sách liên kết 
void themvaocuoi(LIST &l, NODE * p)
{
    if(l.pHead == NULL)//danh sách rỗng
    {
        l.pHead=l.pTail=p;
    }
    else 
    {
       l.pTail -> pNext =p;
       l.pTail = p;
    }
}
//xóa phần tử đầu danh sách liên kết
void xoadau(LIST &l)
{
    if(l.pHead == NULL)
    {
        return ;
    }
    else 
    {
        //b1 tạo một cái node chứa node đầu hiện tại 
        NODE *g = l.pHead;
        l.pHead=l.pHead->pNext;//cập nhật phần tử tiếp theo làm node đầu danh sách liên kết
        delete g;
    }
}

//xóa phần tử cuối cùng danh sach liên kết
void xoacuoi(LIST &l)
{
    if(l.pHead == NULL)
    {
        return ;
    }//chỉ có một phần tử 
    if(l.pHead->pNext==NULL)
	{
		xoadau(l);
		return ;
	}
    else 
    {
       //duyệt danh sách để tìm thằng kế cuối danh sách liên kết
       for(NODE*k = l.pHead;k!=NULL;k=k->pNext)
       {
           
           if(k->pNext == l.pTail)//tìm được thằng kế cuối 
           {
               delete l.pTail;//xóa thằng cuối 
               k -> pNext = NULL;//cho phần tử cuối trỏ đến vùng nhớ NULL
               l.pTail = k;//cập nhật lại thằng phần tử cuối
           }
       }
    }
}
//xóa phần tử có khóa k bất kì
void xoanodebatki(LIST &l, int x)
{
    if(l.pHead->data == x)
    {
        xoadau(l);
        return ;

    }
    if(l.pTail->data == x)
    {
        xoacuoi(l);
        return ;
    }
    NODE*g =new NODE ;//node g là node nằm trước node cần xóa 
    for(NODE*k=l.pHead;k!=NULL;k=k->pNext)
    {
        if(k->data ==x )
        {  
        g->pNext =k->pNext;
        delete k;
        return ;
        }
        g=k;
    }
}
//thêm phần tử p vào sau node q
void themvaosaunodeq(LIST &l, NODE*p)
{
    int x; cout<<"Nhap gia tri node q:";
    cin>>x;
    NODE*q=khoitaonode(x);
    if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		themvaocuoi(l, p);
	}
	else
	{
		// duy?t t? d?u danh sách d?n cu?i danh sách d? tìm node q
		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
		{
			// n?u node q có t?n t?i thì....
			if (q->data == k->data)
			{
				NODE *h = khoitaonode(p->data); // kh?i t?o node h m?i d? thêm vào sau node q 
				NODE *g = k->pNext; // cho node g tr? d?n node n?m sau node q
				h->pNext = g; // Bu?c 1: T?o m?i liên k?t t? node h d?n node g <=> cung chính là t?o m?i liên k?t t? node h d?n node n?m sau node q
				k->pNext = h; // Bu?c 2: T?o m?i liên k?t t? node qf  d?n node h <=> chính là node k d?n node h
			}
   
		}
	}
}

//xuat danh sách liên kết
void xuatdanhsach(LIST l)
{
    for(NODE *k =l.pHead;k!=NULL;k=k->pNext)
    {
        cout<<k->data<<" ";
    }
}
//hàm chứa danh sách chức năng như menu
void Menu(LIST &l)
{
    int luachon ;
    
    while(true)
    {
        system("cls");
    cout<<"\n================Danh Sach Chuc Nang==============";
    cout<<"\n\n\t\t 1.Them phan tu vao danh sach lien ket ";
    cout<<"\n\n\t\t 2. Xuat danh sach lien ket ";
    cout<<"\n\n\t\t 3. Xoa phan tu dau danh sach lien ket";
    cout<<"\n\n\t\t 4. Xoa phan tu cuoi danh sach lien ket";
    cout<<"\n\n\t\t 5. Xoa node khoa k";
    cout<<"\n\n\t\t 6. Them node vao sau mot node q";
    cout<<"\n\n\t\t 0. Thoat\n";
    cout<<"Nhap lua chon cua ban:";
    cin>>luachon;
        if(luachon < 0 || luachon > 6)
        {
            cout<<"lua chon cua ban khong chinh xac";

        }
        else if(luachon == 1)
        {
            int x;
            cout<<"nhap phan tu :";
            cin>>x;
            NODE * p = khoitaonode(x);
            themvaocuoi(l,p);
        }
        else if(luachon == 2)
        {
            xuatdanhsach(l);
            system("pause");

        }
        else if(luachon == 3 )
        {
            xoadau(l);
            
        }
        else if(luachon == 4 )
        {
            xoacuoi(l);   
        }
        else if(luachon == 5)
        {
            int x;
            cout<<"nhap node can xoa :";
            cin>>x;
            xoanodebatki(l,x);
            
        }
        else if(luachon == 6)
        {
            int a;
            cout<<"nhap node gia tri node p can them :";
            cin>>a;
            NODE*p= khoitaonode(a);
            themvaosaunodeq(l,p);
            
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
 khoitaodanhsach(l);
 Menu(l);
    return 0;
}