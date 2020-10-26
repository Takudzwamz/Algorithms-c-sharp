// Lecture2Algo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Prefix_Border_Array(string S, int* bp) {
	int n = S.length();
	bp[0] = 0;

	for (int i = 1; i < n; i++) {// i –длина рассматриваемого префикса
		int bpRight = bp[i - 1];// Позиция справа от предыдущей грани
		while (bpRight && (S[i] != S[bpRight])) bpRight = bp[bpRight - 1];
		// Длина на 1 больше, чем позиция
		if (S[i] == S[bpRight]) bp[i] = bpRight + 1;
		else bp[i] = 0;
	}

	for (int i = 0; i < n; i++) cout << bp[i] << "  ";
}

void Suffix_Border_Array(string S, int* bs) {
	int n = S.length();
	bs[n - 1] = 0;

	for (int i = n - 2; i >= 0; --i)
	{
		int bsLeft = bs[i + 1]; // Позиция с конца слева от предыдущей грани
		while (bsLeft && (S[i] != S[n - bsLeft - 1])) bsLeft = bs[n - bsLeft];
		// Длина на 1 больше, чем позиция
		if (S[i] == S[n - bsLeft - 1])
			bs[i] = bsLeft + 1;
		else bs[i] = 0;
	}
	for (int i = 0; i < n; i++) cout << bs[i] << "  ";
}

void Prefix_Border_ArrayM(string S, int* bp)
{
	int n = S.length();
	int* bpm = new int[n];
	bpm[0] = 0;
	bpm[n - 1] = bp[n - 1];
	for (int i = 1; i < n - 1; ++i)
	{ // Проверка совпадения следующих символов
		if (bp[i] && (S[bp[i]] == S[i + 1])) bpm[i] = bpm[bp[i] - 1];
		else bpm[i] = bp[i];

	}

	for (int i = 0; i < n; i++) cout << bpm[i] << "  ";
}

void BP_to_BPM(int* bp, int n)
{
	int* bpm = new int[n];
	bpm[0] = 0; bpm[n - 1] = bp[n - 1];
	for (int i = 1; i < n - 1; ++i)
	{
		// Проверка «совпадения следующих символов»
		if (bp[i] && (bp[i] + 1 == bp[i + 1])) bpm[i] = bpm[bp[i] - 1];
		else bpm[i] = bp[i];
	}
	for (int i = 0; i < n; i++) cout << bpm[i] << "  ";
}

void BPM_to_BP(int* bpm, int n)
{
	int* bp = new int[n];
	bp[n - 1] = bpm[n - 1]; bp[0] = 0;
	for (int i = n - 2; i > 0; --i) bp[i] = fmax(bp[i + 1] - 1, bpm[i]);
	for (int i = 0; i < n; i++) cout << bp[i] << "  ";
}


void BS_to_BSM(int* bs, int n)
{
	int* bsm = new int[n];
	bsm[n - 1] = 0; bsm[0] = bs[0];
	for (int i = n - 2; i > 0; --i)
	{
		// Проверка «совпадения предыдущих символов»
		if (bs[i] && (bs[i] + 1 == bs[i - 1])) bsm[i] = bsm[n - bs[i]];
		else bsm[i] = bs[i];
	}
	for (int i = 0; i < n; i++) cout << bsm[i] << "  ";
}

void BSM_to_BS(int* bsm, int n)
{
	int* bs = new int[n];
	bs[0] = bsm[0]; bs[n - 1] = 0;
	for (int i = 1; i < n - 1; ++i) bs[i] = fmax(bs[i - 1] - 1, bsm[i]);
	for (int i = 0; i < n; i++) cout << bsm[i] << "  ";
}

int main()
{
	ifstream inFile;
	inFile.open("Test.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1);//terminate with error
	}
	string S;
	inFile >> S;
	int sz = S.length();
	int* bp = new int[sz];
	int* bpm = new int[sz];
	int* bs = new int[sz];
	int* bsm = new int[sz];

	int n = S.length();
	cout << "String:  " << S << "\n";

	cout << "Prefix  border Array:";
	Prefix_Border_Array(S, bp);
	cout << "\n";

	cout << "Suffix  border Array:";
	Suffix_Border_Array(S, bp);
	cout << "\n";

	cout << "Prefix  border ArrayM:";
	Prefix_Border_ArrayM(S, bp);
	cout << "\n";

	cout << "BP_to_BPM:";
	BP_to_BPM(bp, n);
	cout << "\n";

	cout << "BPM_to_BP:";
	BPM_to_BP(bpm, n);
	cout << "\n";

	cout << "BS_to_BSM:";
	BS_to_BSM(bs, n);
	cout << "\n";

	cout << "BSM_to_BS:";
	BSM_to_BS(bsm, n);
	cout << "\n";
}




