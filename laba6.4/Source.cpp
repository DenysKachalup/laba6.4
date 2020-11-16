#include<iostream>
#include<ctime>
#include<Windows.h>

using namespace std;
void print(int c[], const int size)
{
	
	for (int i = 0; i < size; i++)
		cout<<"  " << c[i];
}
void Creat(int c[], const int size)
{
	int b;
	cout << "Масив: ";
	for (int i = 0; i < size; i++)
	{

		b = false;
		b = (-36) + rand() % (25 - (-36) + 1);

		if (b < 0)
		{
			if (b % 2 == 0)
			{
				while (b % 2 == 0)
				{
					b = (-36) + rand() % (25 - (-36) + 1);

				}
				c[i] = b;
			}
			else
				c[i] = b;
		}
		else
			c[i] = b;

		cout << " " << c[i];

	}
}

int DoMin(int c[], const int size,int i,int s,int &k)
{

	if (c[i] < s) {
		s = c[i];
		k = i;
	}
	
	if (i < size - 1) {
		
		return DoMin(c, size, i + 1, s, k);
	}
	else
		return  s;


}
int SumDoMin(int c[], const int size, int min, int i, int suma, int k)
{
	if (c[i] > min)

		suma += c[i];
		
	if (i !=k)
		return SumDoMin(c, size, min, i + 1, suma,k);
	else
		return suma;

	
	

}
void SorPar(int c[], const int size, int par[], const int k, int j)//сортування на парні
{
	for (int i = 0; i < size; i++) {
        
		if (i % 2== 0)            
		{
			par[j] = c[i];
			j++;
		}
	}
}
void SorNepar(int c[], const int size, int nepar [], const int k, int j)//сортування на непарні
{
	for (int i = 0; i < size; i++) {
		if (i % 2 != 0)
		{
			nepar[j] = c[i];
			j++;
		}
	}
}
void Sort(int par[], const int size)//сортування за збільшенням парних чисел
{
	for (int i = 1; i < size; i++) {
		int k = 0;
		for (int j = 0; j < size - i; j++)
			if (par[j] > par[j + 1])
			{
				int tmp = par[j];
				par[j] = par[j + 1];
				par[j + 1] = tmp;
				k = 1;
			}
		if (k == 0)
			return;
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	cout << "Введіть кількість елементів масиву: ";
	int n; cin >> n;
	int* c = new int[n];

	int q = 0;
	
	Creat(c, n);

	cout << endl;
	int min = DoMin(c, n, 0, 0, q);

	cout<<"Мінімальне число: "<< min << endl;
	
	cout<<"Сума чисел до мінімального значення: "<<SumDoMin(c, n, min,0,0,q)<<endl;
	
	if (n % 2 != 0)
		n --;
	int s = n/2;
	int k=n-s;

	int* nepar = new int[k];
	int* par = new int[k];

	SorPar(c, n,par,k,0);//cортування на парні
	SorNepar(c, n, nepar, k, 0);//сортування на непарні
	
	Sort(par, k);//сортування за зростанням непарних чисел
	cout << "Парні індекси: ";
	print(par, k);
	cout << endl;
	Sort(nepar, k);//сортування за зростанням непарних чисел
	cout << "Не парні індекси: ";
	print(nepar, k);
	cout << endl;


	delete[] par;
	delete [] nepar;
	delete[] c;

	return 0;
}