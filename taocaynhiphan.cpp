#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
//// t?o 1 node 
struct node
{
	int data;
	struct node *pleft;
	struct node *pright;
};
typedef node* tree;
/// kh?i t?o tree 
void init(tree &t)
{
	t = NULL;
}
// them node 
void insert(tree &t, int x)
{
	if (t == NULL)// n?u cây r?ng thì ....
	{
		node *p = new node;
		p->data = x;
		p->pleft = p->pright = NULL;
		t = p;
	}
	else
	{
		if (t->data > x)
		{
			insert(t->pleft, x);
		}
		else if (t->data < x)
		{
			insert(t->pright, x);
		}
	}
}
// t?o cây 
void createtree(tree &t)
{
	
	int n, x;
	
	cin >> n;
	t = NULL;
	for (int i = 0; i < n; i++){
		//nhap random
		//int random = rand()%30;
		cin >> x;
		insert(t,x);
		//insert(t, random);
	}
}
// duy?t cây có 6 hàm duy?t cây o day tui làm 1 thuj n?u các b?n mun xem k? honm thì xem o part 1 nha 
void nlr(tree t)
{
	if (t != NULL)
	{
		cout << t->data << "    ";
		nlr(t->pleft);
		nlr(t->pright);
	}
}
void nrl(tree t)
{
	if (t != NULL)
	{
		cout << t->data << "    ";
		nrl(t->pright);
		nrl(t->pleft);
	}
}
void lnr(tree t )
{
	if (t != NULL)
	{
		lnr(t->pleft);
		cout << t->data << "    ";
		lnr(t->pright);
	}

}
void lrn(tree t )
{
	if (t != NULL)
	{
		lrn(t->pright);
		lrn(t->pleft);
		cout << t->data << "    ";
		
	}
}
void rnl(tree t)
{
	if(t!=NULL)
	{
		rnl(t->pright);
		
		cout << t->data << "    ";
		rnl(t->pleft);

	}
}
void rln(tree t)
{

	if (t != NULL)
	{
		rln(t->pright);
		rln(t->pleft);
		cout << t->data << "    ";
	}
}

// tìm node 
node* search(tree t, int x)// tr? v? 1 node  có th? tr? v? tre false cung dk
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		if (t->data > x)
		{
			search(t->pleft, x);
		}
		else if (t->data < x)
		{
			search(t->pright, x);
		}
		else
		{
			return t;
		}
	}
}

void timphantuthemangtrainhatcayconphai(tree &p, tree &q)
{
	if (q->pleft != NULL)
	{
		timphantuthemangtrainhatcayconphai(p, q->pleft);
	}
	else
	{
		p->data = q->data;
		p = q;
		q=q->pright;
	}
}

// xóa 1 node là lá 
void timphantuthemangphainhatcaycontrai(tree &p, tree &q)
{
	if (q->pright != NULL)
	{
		timphantuthemangphainhatcaycontrai(p, q->pright);
	}
	else
	{
		p->data = q->data;
		p = q;
		q = q->pleft;
	}



}
void xoanode(tree &t, int x)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (t->data > x)
		{
			xoanode(t->pleft, x);
		}
		else if(t->data<x)
		{
			xoanode(t->pright, x);
		}
		else
		{
			node *p = t;
			if (t->pleft == NULL)
			{
				t = t->pright;
			}
			else if(t->pright==NULL)
			{
				t = t->pleft;
			}
			else
			{

				// cách 1 tìm ph?n t? trái nh?t cây con ph?i 
				//timphantuthemangtrainhatcayconphai(p, t->pright);
				//cách 2 tìm pahn62 t? th? m?ng ph?i nh?t cây con trái
				timphantuthemangphainhatcaycontrai(p, t->pleft);
			}

			delete p;
       }
   }

}

////////////////Thêm 1 ph?n t? 
void them(tree &t, int x)
{
	if (t == NULL)
	{
		node *p = new node;
		p->data = x;
		p->pleft = p->pright=NULL;
		t = p;
	}
	else
	{
		if (t->data > x)
		{
			them(t->pleft, x);
		}
		else if(t->data<x)
		{
			them(t->pright, x);
		}
		else
		{
			node *l = new node;
			if (t->pleft == NULL)
			{
				t->data = x;
				t = t->pright;
				
			}
			else if(t->pright==NULL)
			{
				t->data = x;
				t = t->pleft;
			}
			

		}
	}

}



int main()
{
	tree t;
	createtree(t);
////	nhap du lieu tu file
//	t = NULL;
//	ifstream filein;
//	filein.open("INPUT.TXT", ios_base::in);
//	int n;
//	filein >> n;
//	for(int i=1;i<=n;i++){
//		int x;
//		filein >> x;
//		them(t, x);
////	}
	
	
	cout << "\nDuyet theo nlr: \n";
	nlr(t);
	int x;
	cout << "\nNhap node can tim : "; cin >> x;
	node *u = search(t, x);
	if (u == NULL)
	{
		cout << "\nKhong tim thay node xin kiem tra lai!";
	}
	else
	{
		cout << "\nNo de ban can tim co trong cay cam on!";
	}
int g;
	cout << "\nNhap phan tu ban muon xoa!"; cin >> g;
	xoanode(t, g);
	cout << "\nCay sau khi xoa!\n";
	nlr(t);


d: int h;
	cout << "\nNhap phan tu ban them!"; cin >> h;
	them(t, h);
	cout << "\nCay sau khi them!\n";
	nlr(t);
	goto d;
        system("pause");
	return 0;
}
