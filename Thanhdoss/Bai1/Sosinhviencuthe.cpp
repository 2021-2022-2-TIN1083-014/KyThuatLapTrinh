#include<iostream>
#include<string>
using namespace std;
//
struct sv
{
    string mahocphan;
    string tenhocphan;
    int sotinchi;
};
//
struct node 
{
    sv data;
    struct node *pNext;
};typedef struct node NODE;
//
struct list 
{
    NODE*pHead;
    NODE*pTail;
};typedef struct list LIST ;
//
void khoitaodanhsach(LIST &l)
{
   l.pHead=NULL;
   l.pTail=NULL;
}
//
NODE*khoitaonode(sv x)
{  
    NODE *p=new NODE;
    if(p==NULL){
        cout<<"khoi tao vung nho chua thanh cong";
        return NULL;
    }
    else 
    {
        p->pNext=NULL;
        p->data=x;
        return p;
    }
}
//
void themvaodau(LIST &l, NODE*p)
{
	if(l.pHead==NULL)
	{
		l.pHead=l.pTail=p;
	}
	else 
	{
		p->pNext=l.pHead;
		l.pHead=p;
	
	}
}
//xuat danh sach 

void xuatdanhsach(LIST l)
{
    for(NODE*k=l.pHead;k!=NULL;k=k->pNext)
    {
        cout<<k->data.mahocphan<<"\n";
        cout<<k->data.tenhocphan<<"\n";
        cout<<k->data.sotinchi<<"\n";
        cout << "==============================SV================\n";
    }
}
int main()
{
    LIST l;
    khoitaodanhsach(l);
    sv x;
    int n;
    cout<<"nhap vao danh sach sinh vien can them :";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"nhap vao mahocphan:";
        cin.ignore();
        getline(cin,x.mahocphan);
        cout<<"nhap vao tenhocphan:";
        getline(cin,x.tenhocphan);
        cout<<"nhap vao sotinchi:";
        cin>>x.sotinchi;
        NODE*p=khoitaonode(x);
        themvaodau(l,p);

    }
    xuatdanhsach(l);
    return 0;
}