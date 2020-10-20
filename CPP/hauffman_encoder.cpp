#include<iostream>
using namespace std;
int parent(int i){return i/2;}
struct node
{
	char data;
	int freq;
	node *r,*l;
};
void heapify(node* a[],int n ,int i)
{
	int rchild = 2*i+1;
	int lchild = 2*i;
	int largest=i;
	if(rchild<=n && a[rchild]->freq < a[largest]->freq)
		largest=rchild;
	if(lchild<=n && a[lchild]->freq < a[largest]->freq)
		largest=lchild;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		heapify(a,n,largest);
	}
}
void buildheap(node* a[],int n)
{
	for(int i = n/2 ; i>0;i--)
	{
		heapify(a,n,i);
	}
}
node* extractmin(node* a[],int &n)
{
	node* val = a[1];
	a[1]=a[n];
	n--; 
	heapify(a,n,1);
	return val;
}
node* newn(int val, char ch)
{
	node *n=new node;
	n->data=ch;
	n->freq=val;
	n->r=NULL;
	n->l=NULL;
	return n;
}
void insert(node* a[],int &n,node* ins)
{
	n++;
	int i=n;
	while(i>1 && a[parent(i)]->freq > ins->freq)
		{
			a[i] = a[parent(i)];
			i=parent(i);
		}
	a[i]=ins;


}
void haufmann(node* a[],int n)
{
	while(n>1)
	{
		node *a1 = extractmin(a,n);
		node *a2 = extractmin(a,n);
		int val = a1->freq + a1->freq; 
		node *z=newn(val,'$');
		z->l = a1;
		z->r =a2;
		insert(a,n,z);
	}
}
void print(node *root,int arr[],int top)
{
	if(root->l!=NULL)
	{
		arr[top]=0;
		print(root->l,arr,top+1);
	}
	if(root->r!=NULL)
	{
		arr[top]=1;
		print(root->r,arr,top+1);
	}
	if(root->r==NULL && root->l==NULL)
	{
		cout<<root->data<<": ";
		for(int i=0;i<top;i++)
			cout<<arr[i];
		cout<<"\n";
	}
}
int main()
{
	int n;
	cin>>n;
	node** a = new node*[n+1];
	for(int i=1;i<=n;i++)
	{
		int freq;char ch;
		cin>>ch>>freq;
		a[i]= newn(freq,ch);
	}
	buildheap(a,n);
	haufmann(a,n);
	node* root = extractmin(a,n);
	int arr[n];
	int top=0;
	print(root,arr,top);
}