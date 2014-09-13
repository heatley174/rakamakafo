// lab 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");
	double x4, x3, x2, x1,z1,z2,z3,z4, k,k1,k2, R, one=0, two=0, three=0, four=0;
	cout << "Программа считает уравнение методом итераций " << "\n";
	cout << "Наша матрица " << "\n";
	double e = 0.0005;
	double f[] = { -0.79, 0.31, 0, -0.72 };
	double g[] = { 0.56, -1, -1.31, 0.85 };
	double h[] = { 0.11, 0, -1.08, 0.78 };
	double o[] = { 0.08, 0.09, 0.33, -0.79 };
	for (int i = 0; i < 4; i++)
	{
		cout << f[i] << " ";
		cout << g[i] << " ";
		cout << h[i] << " ";
		cout << o[i] << " " << "\n";
	}
	double a[] = { 0, -0.25287, -0.37931, 0.08046 };
	double b[] = { 0.45, 0, -0.23, 0.07 };
	double c[] = { 0.10185, 0, 0, 0.72222 };
	double d[] = { 0.10127, 0.11392, 0.41772, 0 };
	cout << "матрица после диагонального преобладания " << "\n";
	for (int i = 0; i < 4; i++)
	{
		cout << a[i] << " ";
		cout << b[i] << " ";
		cout << c[i] << " ";
		cout << d[i] << " " << "\n";
	}
	cout << "проверяю на сходимость... " << "\n";
	for (int i = 0; i < 4; i++)
	{
		one = abs(a[i]) + one;
		two = abs(b[i]) + two;
		three = abs(c[i]) + three;
		four = abs(d[i]) + four;
	}
	if ( one>1 & two>1 & three>1 & four>1)
		cout << " не сходится! " << "\n";
	else cout << " сходится! " << "\n";
	/*cout << one << "\n";
	cout << two << "\n";
	cout << three << "\n";
	cout << four << "\n";*/
	k2=max(one, two);
	k1 = max(three, four);
	k = max(k2,k1);
	/*cout << k << "\n";*/
	double p[] = {0.93103, -0.33, 0.78704, -2.1519};
	//k = ((log10(e) + log10(1 - 0.82407) - log10(p[0])) / log10(0.82407) )- 1;
	/*R = (((log10(1 - three) + log10(e) - log10(p[0])) / log10(three)))-1;
	cout <<"ЧИСЛО ИТЕРАЦИЙ = "<< R << "\n";*/
	
	double x[100];
	double y[100];
	double z[100];
	double v[100];
	x[0] = p[0]; y[0] = p[1]; z[0] = p[2]; v[0] = p[3];
	for (int i = 0;; i++)
	{
		x[i+1] = a[1] * y[i] + a[2] * z[i] + a[3] * v[i] + p[0];
		y[i+1] = b[0] * x[i] + b[2] * z[i] + b[3] * v[i] + p[1];
		z[i+1] = c[0] * x[i] + c[2] * v[i] + p[2];
		v[i+1] = d[0] * x[i] + d[2] * y[i] + d[3] * z[i] + p[3];
		if ((abs(x[i + 1] - x[i])<e) & (abs(y[i + 1] - y[i])<e) & (abs (z[i + 1] - z[i])<e) & (abs (v[i + 1] - v[i])<e))
		{
			cout << "4 знака элементов равны = " << x[i] << "  " << y[i] << "  " << z[i] << "  " << v[i] << "\n";
			cout << x[i + 1] << "  " << y[i + 1] << "  " << z[i + 1] << "  " << v[i + 1] << "\n";
			break;
		}
			
	}
	/*for (int i = 40; i < 41; i++)
	{
		cout << x[i] << " ";
		cout << y[i] << " ";
		cout << z[i] << " ";
		cout << v[i] << "\n";
	}*/
	
	/*system("pause");*/
	return 0;
}

