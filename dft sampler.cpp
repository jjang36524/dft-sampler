#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996)
#define PI 3.1415926535897932
double val[100100];
double xcomp[100100];
double ycomp[100100];
double ma[100100];
int main()
{
	cout << "파일명을 입력하세요 : ";
	char arr[100];
	cin >> arr;
	double flim;
	cout << "한계 주파수를 입력하세요";
	cin >> flim;
	freopen(arr, "r", stdin);
	int len, freq;
	cin >> len >> freq;
	int i;
	for (i = 0; i < len; i++)
	{
		cin >> val[i];
	}
	//getting input
	for (i = 0; i <= (len)/2; i++)
	{
		if (freq * i / (double)len > flim)
			break;
		int j;
		for (j = 0; j < len; j++)
		{
			xcomp[i] += val[j] * sin(i * PI * 2 * j / len);
			ycomp[i]+=val[j]* cos(i * PI * 2 * j / len);
		}
		ma[i] =sqrt(xcomp[i] * xcomp[i] + ycomp[i] * ycomp[i]);
	}
	for (i = 0; i <= (len ) / 2; i++)
	{
		if (ma[i] > 0.001)
		{
			cout << "진폭 : "<<ma[i]<<'\n';
			cout << "주파수 : " << i * freq / (double)len << '\n';
			cout << "위상 : " << atan2(xcomp[i], ycomp[i]) << '\n';
		}
	}

}