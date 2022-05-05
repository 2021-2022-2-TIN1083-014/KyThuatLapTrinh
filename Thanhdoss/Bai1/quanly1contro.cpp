#include<iostream>
using namespace std;
//khai báo node 
struct node
{
    int data ;
    struct node*pNext;
};
typedef struct node NODE;
//khai bao danh sach lien ket
struct list
{
    NODE*pHead;
};typedef struct list LIST;
//khởi tạo danh sach liên kết
void khoitaodanhsach(LIST &l)
{
    l.pHead=NULL;
}
NODE*khoitaonode(int x)
{
  NODE*p=new NODE;
  if(p==NULL){
  cout<<"cap phat khong thanh cong ";
  return NULL;}
  else
  {
      p->data=x;
      p->pNext=NULL;
      return p;
  }
}
//hàm so sánh danh sach liên kết với giá trị a;
void sosanh(LIST &l)
{
    int a;
    cout<<"nhap so nguyen a dung de so sanh:";
    cin>>a;
    for(NODE*k=l.pHead;k!=NULL;k=k->pNext)
    {
        if(k->data>a)
        {
            cout<<k->data<<" ";
        }
    }
}
//hàm thêm vào đầu danh sách liên kết đơn 
void themvaodau(LIST &l,NODE*p)
{

    if(l.pHead==NULL)
    {
        l.pHead=p;
    }
    else
    {
        p->pNext=l.pHead;
        l.pHead=p;
    }
}
//xuất danh sách
void xuatdanhsach(LIST l)
{
  for(NODE*k=l.pHead;k!=NULL;k=k->pNext)
  {
      cout<<k->data<<" ";
  }
}
int main()
{
  LIST l;
  khoitaodanhsach(l);
  int x;
  do
  {
      cout<<"nhap so nguyen :";
      cin>>x;
      NODE*p=khoitaonode(x);
      themvaodau(l,p1);
  } while (x!=0);
  xuatdanhsach(l);
  sosanh(l);
    return 0;
}