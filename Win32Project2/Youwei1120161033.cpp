// Win32Project2.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
using namespace std;
using std::cout;
int main(int argc, _TCHAR* argv[])
{
	string line,word;
	ifstream finput;
	vector<string> words;
	int nums = 0, totalchar = 0,totalcharwithoutc = 0;
	if (finput)
	{
		int temp = 1;
		string fname="test.txt";
		std::cout << "reading the file text.txt:\n";
		//cin >> fname;
		finput.open(fname);
		std::cout << "=============================The origin Text begin==============================\n";
		while (getline(finput, line))
		{
			std::cout << line << endl;//��������
			char word2[100];
			int Tcharisspace = 1;//�Ǳ����,��Ϊ��ǰ�������͵ı��
			int i = 0,j=0;
			int n = line.size();
				for (auto c : line){//��ɵ���
					j++; totalchar++;
					if ((c == '-'&&Tcharisspace == 0) || isalpha(c)) {//���ʹ����� word,ʶ�����-�ĺϳɴ�		
						totalcharwithoutc++;
						Tcharisspace = 0;
						word2[i] = c;
						i++;
					if (j == n){//����ĩβ���������⴦��
						word2[i] = '\0';
						nums++;
						words.push_back(word2);
						i = 0;
					}
				}
				else if ((ispunct(c) || isspace(c)) && c != '-'&&Tcharisspace==0) { //����ĩβʶ��
					Tcharisspace = 1; 
					word2[i] = '\0';
					nums++;
					words.push_back(word2);
					i = 0;
				}
			}
		}
		std::cout << "=============================The origin Text end================================\n";
		finput.close();
	}

	set < string > iset(words.cbegin(),words.cend());
	cout << "the words list are below:" << endl;
	int countthe = 0;
	for (auto c : words)
	{
		if (c == "the") countthe++;

	}
	{int m = 1;
		for (auto c : iset)
		{ 
			if (m % 4 == 0) cout  << c << "\n";
			else if (m % 4 == 1) cout << "\t" << c << "\t";
			else cout << c << "\t";
			m++;
		}
	}
	cout <<endl<< "the number of \"the\" is " << countthe<<endl;
	cout << "totoal char(include the space and column):" << totalchar<<endl;
	cout << "total character(only alpha and the '-'):" << totalcharwithoutc << endl;
	cout << "the total words:" << nums << endl;
	cout << "different words:" << iset.size() << endl;
	getchar();
	getchar();
	return 0;
}

