// Text_Binary.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <assert.h>

using namespace std;

typedef struct stpoints {
	int px;
	int py;
} ptstype;

int main(void)
{
	int n1 = 1, n2 = 12345678;
	ofstream txtfile1, txtfile2;
	ofstream binfile1, binfile2;

	txtfile1.open("T1.txt", ios::out);
	txtfile2.open("T2.txt", ios::out);

	binfile1.open("B1.bin", ios::out | ios::binary);
	binfile2.open("B2.bin", ios::out | ios::binary);

	if (txtfile1.is_open()) {
		txtfile1 << n1;
		txtfile1.close();
	}
	if (txtfile2.is_open()) {
		txtfile2 << n2;
		txtfile2.close();
	}
	if (binfile1.is_open()) {
		binfile1.write((const char *) &n1, sizeof(int));
		binfile1.close();
	}
	if (binfile2.is_open()) {
		binfile2.write((const char *)&n2, sizeof(int));
		binfile2.close();
	}

	// =============================================
	ofstream binfile3w;
	ifstream binfile3r;
	ptstype ptx = { 1, 3 };
	char buffer[100];
	ptstype *pptx = NULL;

	binfile3w.open("B3.bin", ios::out | ios::binary);

	if (binfile3w.is_open()) {
		binfile3w.write((const char *)&ptx, sizeof(ptx));
		binfile3w.close();
	}

	binfile3r.open("B3.bin", ios::in | ios::binary);

	if (binfile3r.is_open()) {
		binfile3r.read(buffer, sizeof(ptstype));
		pptx = (ptstype *)buffer;
		cout << "ptx.px = " << pptx->px << "  ptx.py = " << pptx->py << endl;
		binfile3r.close();
	}
	
	return 0;
}
