#include <iostream>
#include "C_Db.h"
#include <ctime>
#include <iomanip>
//#include <Windows.h>
#include "mTimer.h"
//#define DEBUG

#define STATION_NUM 7
#define CARRIAGE_NUM 8
#define SEAT_NUM 18

void delateSeat(C_Db* G, _EM& EM);
_EM* searchSeat(C_Db* G, int carriage, int seatT, int outset, int destination, int transferTime);
_EM* buyTickets(C_Db* G, int carriageT, int seatT, int outset, int destination, int transferTime, int people);
std::vector<_EM> buyTicketsPlus(C_Db* G, int carriageT, int seatT, int outset, int destination, int transferTime, int people);

/*����ȼ�*/
enum CARRIAGE_TYPE
{
	L1 = 1, L2
};

/*��ϯҪ��*/
enum SEAT_REQUIREMENT
{
	NONE, WINDOW, AISLE, CENTER
};

/*��λ����*/
enum SEAT_TYPE
{
	A, B, C, D, E, AB, BC, CD, DE, _ABC, BCD, CDE
};

/*����*/
enum PEOPLE_TYPE
{
	ONE = 1, TWO, THREE
};

int main()
{
	C_Db* G151 = new C_Db;

	//***********************�������ɲ�ͬ��Ʊ����������ݿ�*************************
	/*��վ���ݿ⣨��վ���� - 1 ����*/
	for (int i = 0; i < STATION_NUM; i++)
	{	/*������*/
		for (int j = 0; j < CARRIAGE_NUM; j++)
		{	/*ÿ�ڳ��������λ����*/
			for (int k = 0; k < SEAT_NUM; k++)
			{	/*���12����λ���A B C D E AB BC CD DE _ABC BCD CDE*/
				for (int n = 0; n < 12; n++)
				{

					//70%Ʊ���۳�
					//if (j == 0 || j > 5 && k > 6) 
					//{
					//	if (n == 0 || n == 2  && n < 5)
					//	{
					//		_EM EM(j, k, i, 6, n);
					//		/*����->��վ.����.��λ����*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//}	

					
					//80%Ʊ���۳�
					//if (j == 0 || j > 5 && k > 6) 
					//{
					//	if (n == 0 && n < 5)
					//	{
					//		_EM EM(j, k, i, 6, n);
					//		/*����->��վ.����.��λ����*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//}	

					//û������
					//if (j == 0 || j > 5 && k > 6 && n < 5)
					//{
					//	if (n == 0 || n == 2 || n == 4)
					//	{
					//		/*��iվ��6վ*/
					//		_EM EM(j, k, i, 6, n);
					//		/*����->��վ.����.��λ����*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//	else
					//	{
					//		_EM EM(j, k, i, 7, n);
					//		/*����->��վ.����.��λ����*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//}

					//��˫����AB����������
					if (j == 0 || j > 5 && k > 6 && n < 6)
					{
						if (n == 0 || n == 1 || n == 3 || n == 5)
						{
							_EM EM(j, k, i, 6, n);
							/*����->��վ.����.��λ����*/
							G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
						}
						else
						{
							_EM EM(j, k, i, 5, n);
							/*����->��վ.����.��λ����*/
							G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
						}
					}

					//��˫����AB����������
					//if (j == 0 || j > 5 && k > 6 && n < 6)
					//{
					//	if (n == 0 || n == 1 || n == 3 || n == 5)
					//	{
					//		_EM EM(j, k, i, 6, n);
					//		/*����->��վ.����.��λ����*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//	else
					//	{
					//		_EM EM(j, k, i, 5, n);
					//		/*����->��վ.����.��λ����*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//}

					//1.3�����ݿ�
					//4��3��C����վ0��վ1
					//if (i == 0 && j == 3 && k == 2 && n == 2)
					//{
					//	_EM EM(j, k, i, 1, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*4��7��A����1վ��3վ*/
					//else if (i == 1 && j == 3 && k == 6 && n == 0)
					//{
					//	_EM EM(j, k, i, 3, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*3��10��D����3վ��4վ*/
					//else if (i == 3 && j == 2 && k == 9 && n == 3)
					//{
					//	_EM EM(j, k, i, 4, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*2��13��E����3վ��6վ*/
					//else if (i == 3 && j == 1 && k == 12 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*5��7��C����4վ��6վ*/
					//else if (i == 4 && j == 4 && k == 6 && n == 2)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*6��6��B����0վ��2վ*/
					//else if (i == 0 && j == 5 && k == 5 && n == 1)
					//{
					//	_EM EM(j, k, i, 2, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					////5��6��E����2վ��6վ
					//else if (i == 2 && j == 4 && k == 5 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*���೵Ʊȫ��Ϊ6վ��7վ*/
					//else if (n < 5)
					//{
					//	_EM EM(j, k, 5, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}


					////1.3��70%�������ݿ�
					//if (i == 0 && j == 3 && k == 2 && n == 2)
					//{
					//	_EM EM(j, k, i, 1, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*4��7��A����1վ��3վ*/
					//else if (i == 1 && j == 3 && k == 6 && n == 0)
					//{
					//	_EM EM(j, k, i, 3, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*3��10��D����3վ��4վ*/
					//else if (i == 3 && j == 2 && k == 9 && n == 2)
					//{
					//	_EM EM(j, k, i, 4, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*2��13��E����3վ��6վ*/
					//else if (i == 3 && j == 1 && k == 12 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*5��7��C����4վ��6վ*/
					//else if (i == 4 && j == 4 && k == 6 && n == 2)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*6��6��B����0վ��2վ*/
					//else if (i == 0 && j == 5 && k == 5 && n == 0)
					//{
					//	_EM EM(j, k, i, 2, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					////5��6��E����2վ��6վ
					//else if (i == 2 && j == 4 && k == 5 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*���೵Ʊȫ��Ϊ6վ��7վ*/
					//else if (n == 1 || n == 3)
					//{
					//	_EM EM(j, k, 5, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}

					//1.3��80%�������ݿ�
					//if (i == 0 && j == 3 && k == 2 && n == 2)
					//{
					//	_EM EM(j, k, i, 1, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*4��7��A����1վ��3վ*/
					//else if (i == 1 && j == 3 && k == 6 && n == 0)
					//{
					//	_EM EM(j, k, i, 3, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*3��10��D����3վ��4վ*/
					//else if (i == 3 && j == 2 && k == 9 && n == 3)
					//{
					//	_EM EM(j, k, i, 4, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*2��13��E����3վ��6վ*/
					//else if (i == 3 && j == 1 && k == 12 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*5��7��C����4վ��6վ*/
					//else if (i == 4 && j == 4 && k == 6 && n == 2)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*6��6��B����0վ��2վ*/
					//else if (i == 0 && j == 5 && k == 5 && n == 3)
					//{
					//	_EM EM(j, k, i, 2, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					////5��6��E����2վ��6վ
					//else if (i == 2 && j == 4 && k == 5 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*������7��Ʊ���⣬��B��λ��Ʊ*/
					//else if ( n == 1)
					//{
					//	_EM EM(j, k, 5, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					
					//1.3��90%�������ݿ�
					//if (i == 0 && j == 3 && k == 2 && n == 2)
					//{
					//	_EM EM(j, k, i, 1, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*4��7��A����1վ��3վ*/
					//else if (i == 1 && j == 3 && k == 6 && n == 0)
					//{
					//	_EM EM(j, k, i, 3, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*3��10��D����3վ��4վ*/
					//else if (i == 3 && j == 2 && k == 9 && n == 3)
					//{
					//	_EM EM(j, k, i, 4, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*2��13��E����3վ��6վ*/
					//else if (i == 3 && j == 1 && k == 12 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*5��7��C����4վ��6վ*/
					//else if (i == 4 && j == 4 && k == 6 && n == 2)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*6��6��B����0վ��2վ*/
					//else if (i == 0 && j == 5 && k == 5 && n == 3)
					//{
					//	_EM EM(j, k, i, 2, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					//5��6��E����2վ��6վ
					//else if (i == 2 && j == 4 && k == 5 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*������7��Ʊ����ȫ��ûƱ*/
					//else if ( n == -1)
					//{
					//	_EM EM(j, k, 5, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
				}
			}
		}
	}

#ifdef DEBUG
	/*��ӡ��ϯ������*/
	for (int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < G151->SZ[i]; j++)
		{
			std::cout << G151->L_p[i][j] << " ";
		}
	}

	std::cout << std::endl;
	for (int i = 0; i < STATION_NUM; i++)
	{
		for (int j = 0; j < CARRIAGE_NUM; j++)
		{
			for (int k = 0; k < SEAT_NUM; k++)
			{
				for (int n = 0; n < 12; n++)
				{
					switch (n)
					{
					case 0:
						std::cout << "G151->SxDb_p[" << i << "].CaDb_p[" << j << "]._XDb.A_EM[" << k << "] ="
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].C << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].L << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].O << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].D << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].ST << std::endl;
						break;
					case 2:
						std::cout << "G151->SxDb_p[" << i << "].CaDb_p[" << j << "]._XDb.C_EM[" << k << "] ="
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].C << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].L << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].O << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].D << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].ST << std::endl;
						break;
					case 11:
						std::cout << "G151->SxDb_p[" << i << "].CaDb_p[" << j << "]._XDb.CDE_EM[" << k << "] ="
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].C << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].L << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].O << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].D << "	"
							<< G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n][k].ST << std::endl;
						break;
					default:
						break;
					}
				}
			}
		}
	}
#endif // DEBUG

	clock_t startT, endT;

	int CarriageLevel = 0;
	do {
		std::cout << "�����복��ȼ� <һ�ȳ���: 1>��<���ȳ���: 2>" << std::endl;
		std::cin >> CarriageLevel;
	} while (CarriageLevel != L1 && CarriageLevel != L2);

	int people = 0;
	do {
		std::cout << "������˿����� <һ��:1>��<����:2>��<����:3>" << std::endl;
		std::cin >> people;
	} while (people < 1 || people > 3);

	int seatType = 0;
	int transfer = 0;
	if (people == 1) {
		do {
			std::cout << "�����뻻�˴��� <���:0>��<һ��:1>��<����:2>��<����:3>" << std::endl;
			std::cin >> transfer;
		} while (transfer < NONE || transfer > THREE);

		if (transfer == NONE)
		{
			switch (CarriageLevel)
			{
			case L1: {
				do {
					std::cout << "��������λҪ�� <��:0>��<����:1>��<������:2>" << std::endl;
					std::cin >> seatType;
				} while (seatType != NONE && seatType != WINDOW && seatType != AISLE);
			}break;

			case L2: {
				do {
					std::cout << "��������λҪ�� <��:0>��<����:1>��<������:2>��<�������м�:3>" << std::endl;
					std::cin >> seatType;
				} while (seatType != NONE && seatType != WINDOW && seatType != AISLE && seatType != CENTER);
			}break;
			default:
				break;
			}
		}
		else {
			seatType == NONE;
		}
	}
	else {
		seatType = NONE;
	}

	int outSet = 0;
	do {
		std::cout << "���������վ <������:0>��<̩��:1>��<���ݶ�:2>��" << "<���ݶ�:3>��<������:4>��<����:5>" << std::endl;
		std::cin >> outSet;
	} while (outSet < 0 || outSet > STATION_NUM - 1);

	int destination = 0;
	do {
		std::cout << "������Ŀ�ĵ� <̩��:1>��<���ݶ�:2>��<���ݶ�:3>��" << "<������:4>��<����:5>��<�Ͼ���:6>" << std::endl;
		std::cin >> destination;
	} while (destination < outSet || destination > STATION_NUM);

	std::vector<_EM> tic;
	MyTimer timer;
	//startT = clock();
	timer.start();
	tic = buyTicketsPlus(G151, CarriageLevel, seatType, outSet, destination, transfer, people);
	/*endT = clock();*/

	timer.stop();
	if (tic.size() != NULL)
	{
		for (int i = 0; i < tic.size(); i++)
		{
			std::cout << "������λ" << i + 1 << "Ϊ:" << tic[i].C + 1 << "��" << tic[i].L + 1 << "��";
			switch (tic[i].ST)
			{
			case A: std::cout << "A��	"; break;
			case B: std::cout << "B��	"; break;
			case C: std::cout << "C��	"; break;
			case D: std::cout << "D��	"; break;
			case E: std::cout << "E��	"; break;
			case AB: std::cout << "AB��	  "; break;
			case BC: std::cout << "BC��	  "; break;
			case CD: std::cout << "CD��	  "; break;
			case DE: std::cout << "DE��	  "; break;
			case _ABC: std::cout << "ABC��	"; break;
			case BCD: std::cout << "BCD��	"; break;
			case CDE: std::cout << "CDE��	"; break;
			default:
				break;
			}

			switch (tic[i].O)
			{
			case 0: std::cout << "������ -> "; break;
			case 1: std::cout << "̩  �� -> "; break;
			case 2: std::cout << "���ݶ� -> "; break;
			case 3: std::cout << "���ݶ� -> "; break;
			case 4: std::cout << "������ -> "; break;
			case 5: std::cout << "��  �� -> "; break;
			case 6: std::cout << "�Ͼ��� -> "; break;
			default:
				break;
			}

			switch (tic[i].D)
			{
			case 0: std::cout << "������  " ; break;
			case 1: std::cout << "̩  ��  " ; break;
			case 2: std::cout << "���ݶ�  " ; break;
			case 3: std::cout << "���ݶ�  " ; break;
			case 4: std::cout << "������  " ; break;
			case 5: std::cout << "��  ��  " ; break;
			case 6: std::cout << "�Ͼ���  " ; break;
			default:
				break;
			}

			if (CarriageLevel == 1) {
				std::cout << "<һ����>" << std::endl;
			}
			else {
				std::cout << "<������>" << std::endl;
			}
		}
	}
	else {
		std::cout << "��Ʊ" << std::endl;
	}
	std::cout << "��ѯ��ʱ:" << std::fixed << std::setprecision(20) << timer.elapse() << "us" << std::endl;

	getchar();
	getchar();
	return 0;
}

void delateSeat(C_Db* G, _EM& EM)
{
	/*��ʼվ*/
	int S1 = EM.O;
	/*Ŀ�ĵ�*/
	int S2 = EM.D;
	/*����*/
	int Ca = EM.C;
	/*��λ*/
	int S = EM.ST;

	/*��������λ��ռ�ݵĳ�վ���ݿ�*/
	for (int i = S1; i < S2; i++)
	{
		/*����C�����޸������λ��ص����ݿ�*/
		for (int j = 0; j < G->SZ[S]; j++)
		{
			/*��λ���*/
			int sType = G->L_p[S][j];
			std::vector<_EM>& ST = G->SxDb_p[i].CaDb_p[Ca]._XDb.XDb_p[sType];

			/*������Ӧ������λ���ݿ�*/
			for (int n = 0; n < ST.size(); n++)
			{
				/*��������ݿ�ͬ����λ��ռ�ݷ�Χ�뱸ѡ��λ��ռ�ݷ�Χ�н���
				���ȴ���λ����ʼվС�ڱ�ѡ��λ�Ľ���վ�����Ҵ���λ�Ľ���վ���ڱ�ѡ��λ����ʼ��*/
				if (ST[n].L == EM.L && ((ST[n].O < S2 && ST[n].D >= S1) || (ST[n].O == S1 && ST[n].D == S2)))
				{
					/*ɾ����λ*/
					ST.erase(ST.begin() + n);
#ifdef DEBUG
					std::cout << "��ɾ�� "
						<< i << " ��վ���ݿ��� "
						<< Ca + 1 << " �� "
						<< EM.L << " �� ";
					switch (sType)
					{
					case A: std::cout << "A��" << std::endl; break;
					case B: std::cout << "B��" << std::endl; break;
					case C: std::cout << "C��" << std::endl; break;
					case D: std::cout << "D��" << std::endl; break;
					case E: std::cout << "E��" << std::endl; break;
					case AB: std::cout << "AB��" << std::endl; break;
					case BC: std::cout << "BC��" << std::endl; break;
					case CD: std::cout << "CD��" << std::endl; break;
					case DE: std::cout << "DE��" << std::endl; break;
					case _ABC: std::cout << "ABC��" << std::endl; break;
					case BCD: std::cout << "BCD��" << std::endl; break;
					case CDE: std::cout << "CDE��" << std::endl; break;
					default:
						break;
				}
#endif // DEBUG
			}
		}
	}
}
}

_EM* searchSeat(C_Db* G, int carriage, int seatT, int outset, int destination, int transferTime)
{
	std::vector<_EM>& ST = G->SxDb_p[outset].CaDb_p[carriage]._XDb.XDb_p[seatT];
	if (ST.size() == 0)
	{
		return nullptr;
	}
	else {
		for (int n = 0; n < ST.size(); n++)
		{
			if (ST[n].O == outset && ST[n].D == destination)
			{
				return (_EM*)&ST[n];
			}
		}
	}
	return nullptr;
}

_EM* buyTickets(C_Db* G, int carriageT, int seatT, int outset, int destination, int transferTime, int people)
{
	_EM* S = new _EM;
	switch (carriageT)
	{
	case L1: {
		switch (people)
		{
		case ONE: {
			switch (seatT)
			{
			case NONE: {
				for (int i = 0; i < 4; i++)
				{
					S = searchSeat(G, 0, i, outset, destination, transferTime);
					if (S != nullptr)
					{
						return S;
					}
				}
				return nullptr;
			}break;

			case WINDOW: {
				S = searchSeat(G, 0, D, outset, destination, transferTime);
				if (S != nullptr)
				{
					return S;
				}
				else {
					S = searchSeat(G, 0, A, outset, destination, transferTime);
					if (S != nullptr)
					{
						return S;
					}
				}
				return nullptr;
			}break;

			case AISLE: {
				S = searchSeat(G, 0, B, outset, destination, transferTime);
				if (S != nullptr)
				{
					return S;
				}
				else {
					S = searchSeat(G, 0, C, outset, destination, transferTime);
					if (S != nullptr)
					{
						return S;
					}
				}
				return nullptr;
			}break;

			default:
				break;
			}
		}break;

		case TWO: {
			S = searchSeat(G, 0, AB, outset, destination, transferTime);
			if (S != nullptr)
			{
				return S;
			}
			else {
				S = searchSeat(G, 0, BC, outset, destination, transferTime);
				if (S != nullptr)
				{
					return S;
				}
				else {
					S = searchSeat(G, 0, CD, outset, destination, transferTime);
					if (S != nullptr)
					{
						return S;
					}
				}
			}
			return nullptr;
		}break;

		case THREE: {
			S = searchSeat(G, 0, _ABC, outset, destination, transferTime);
			if (S != nullptr)
			{
				return S;
			}
			else {
				S = searchSeat(G, 0, BCD, outset, destination, transferTime);
				if (S != nullptr)
				{
					return S;
				}
			}
			return nullptr;
		}break;

		default:
			break;
		}
	}break;

	case L2: {
		switch (people)
		{
		case ONE: {
			switch (seatT)
			{
			case NONE: {
				for (int i = 1; i < CARRIAGE_NUM; i++)
				{
					for (int j = 4; j >= 0; j--)
					{
						S = searchSeat(G, i, j, outset, destination, transferTime);
						if (S != nullptr)
						{
							return S;
						}
					}
				}
				return nullptr;
			}break;

			case WINDOW: {
				for (int i = 1; i < CARRIAGE_NUM; i++)
				{
					S = searchSeat(G, i, E, outset, destination, transferTime);
					if (S != nullptr)
					{
						return S;
					}
					else {
						S = searchSeat(G, i, A, outset, destination, transferTime);
						if (S != nullptr)
						{
							return S;
						}
					}
				}
				return nullptr;
			}break;

			case AISLE: {
				for (int i = 1; i < CARRIAGE_NUM; i++)
				{
					S = searchSeat(G, i, C, outset, destination, transferTime);
					if (S != nullptr)
					{
						return S;
					}
					else {
						S = searchSeat(G, i, D, outset, destination, transferTime);
						if (S != nullptr)
						{
							return S;
						}
					}
				}
				return nullptr;
			}break;

			case CENTER: {
				for (int i = 1; i < CARRIAGE_NUM; i++)
				{
					S = searchSeat(G, i, B, outset, destination, transferTime);
					if (S != nullptr)
					{
						return S;
					}
				}
				return nullptr;
			}break;
			default:
				break;
			}
		}break;

		case TWO: {
			for (int i = 1; i < CARRIAGE_NUM; i++)
			{
				S = searchSeat(G, i, AB, outset, destination, transferTime);
				if (S != nullptr)
				{
					return S;
				}
				else {
					S = searchSeat(G, i, BC, outset, destination, transferTime);
					if (S != nullptr)
					{
						return S;
					}
					else {
						S = searchSeat(G, i, CD, outset, destination, transferTime);
						if (S != nullptr)
						{
							return S;
						}
						else {
							S = searchSeat(G, i, DE, outset, destination, transferTime);
							if (S != nullptr)
							{
								return S;
							}
						}
					}
				}
			}
			return nullptr;
		}break;

		case THREE: {
			for (int i = 1; i < CARRIAGE_NUM; i++)
			{
				S = searchSeat(G, i, _ABC, outset, destination, transferTime);
				if (S != nullptr)
				{
					return S;
				}
				else
				{
					S = searchSeat(G, i, BCD, outset, destination, transferTime);
					if (S != nullptr)
					{
						return S;
					}
					else {
						S = searchSeat(G, i, CDE, outset, destination, transferTime);
						if (S != nullptr)
						{
							return S;
						}
					}
				}
			}
			return nullptr;
		}break;

		default:
			break;
		}
	}break;

	default:
		break;
	}
}

std::vector<_EM> buyTicketsPlus(C_Db* G, int carriageT, int seatT, int outset, int destination, int transferTime, int people)
{
	_EM* Sp;
	_EM S;
	std::vector<_EM> Ss;
	switch (people)
	{
	case 1: {
		switch (transferTime)
		{
			/*������*/
		case 0: {
			Sp = buyTickets(G, carriageT, seatT, outset, destination, transferTime, people);
			if (Sp != nullptr)
			{
				S = *Sp;
				Ss.push_back(S);
				delateSeat(G, *Sp);
				return Ss;
			}
		}break;

			/*����1��*/
		case 1: {
			/*��������վ���ݿ�*/
			_EM* seat1 = nullptr;
			_EM* seat2 = nullptr;

			int step1 = 1;
			while (outset + step1 < destination)
			{
				/*�������е���λ*/
				Sp = buyTickets(G, L2, NONE, outset, outset + step1, transferTime, people);
				if (Sp != nullptr)
				{
					seat1 = Sp;
				}
				/*���ҵ���Ʊ1���������Ʊ2*/

				if (seat1 != nullptr)
				{
					Sp = buyTickets(G, L2, NONE, outset + step1, destination, transferTime, people);
					if (Sp != nullptr)
					{
						seat2 = Sp;

						Ss.push_back(*seat1);
						Ss.push_back(*seat2);

						delateSeat(G, *seat1);
						delateSeat(G, *seat2);
						return Ss;
					}
				}
				/*��û�к��ʵ�Ʊ2�����Ʊ1*/
				if (seat2 == nullptr)
				{
					seat1 = nullptr;
					step1++;
				}
			}
		}break;

			/*����2��*/
		case 2: {
			/*��������վ���ݿ�*/
			_EM* seat1 = nullptr;
			_EM* seat2 = nullptr;
			_EM* seat3 = nullptr;

			int step1 = 1;
			int step2 = 1;
			while (outset + step1 < destination)
			{
				/*�������е���λ*/
				Sp = buyTickets(G, L2, NONE, outset, outset + step1, transferTime, people);
				if (Sp != nullptr)
				{
					seat1 = Sp;
					/*�ҵ���Ʊ1��������Ʊ2*/
					while (outset + step1 + step2 < destination)
					{
						Sp = buyTickets(G, L2, NONE, outset + step1, outset + step1 + step2, transferTime, people);
						if (Sp != nullptr)
						{
							seat2 = Sp;
							/*�ҵ���Ʊ2��������Ʊ3*/
							Sp = buyTickets(G, L2, NONE, outset + step1 + step2, destination, transferTime, people);
							if (Sp != nullptr)
							{
								seat3 = Sp;

								Ss.push_back(*seat1);
								Ss.push_back(*seat2);
								Ss.push_back(*seat3);

								delateSeat(G, *seat1);
								delateSeat(G, *seat2);
								delateSeat(G, *seat3);
								return Ss;
							}
							/*��û�к��ʵ�Ʊ3�����Ʊ2*/
							else
							{
								seat2 = nullptr;
								step2++;
							}
						}
						else {
							step2++;
						}
					}
					/*��û�к��ʵ�Ʊ2�����Ʊ1*/
					if (seat2 == nullptr)
					{
						seat1 = nullptr;
						step1++;
						//break;
					}
				}
				else {
					step1++;
				}

			}
		}break;

		case 3: {
			/*��������վ���ݿ�*/
			_EM* seat1 = nullptr;
			_EM* seat2 = nullptr;
			_EM* seat3 = nullptr;
			_EM* seat4 = nullptr;

			int step1 = 1;
			int step2 = 1;
			int step3 = 1;
			while (outset + step1 < destination)
			{
				/*�������е���λ*/
				Sp = buyTickets(G, L2, NONE, outset, outset + step1, transferTime, people);
				if (Sp != nullptr)
				{
					seat1 = Sp;
					/*�ҵ���Ʊ1��������Ʊ2*/
					while (outset + step1 + step2 < destination)
					{
						Sp = buyTickets(G, L2, NONE, outset + step1, outset + step1 + step2, transferTime, people);
						if (Sp != nullptr)
						{
							seat2 = Sp;
							/*�ҵ���Ʊ2��������Ʊ3*/
							while (outset + step1 + step2 + step3 < destination)
							{
								Sp = buyTickets(G, L2, NONE, outset + step1 + step2, outset + step1 + step2 + step3, transferTime, people);
								if (Sp != nullptr)
								{
									seat3 = Sp;
									/*�ҵ���Ʊ3��������Ʊ4*/
									Sp = buyTickets(G, L2, NONE, outset + step1 + step2 + step3, destination, transferTime, people);
									if (Sp != nullptr)
									{
										seat4 = Sp;
										Ss.push_back(*seat1);
										Ss.push_back(*seat2);
										Ss.push_back(*seat3);
										Ss.push_back(*seat4);

										delateSeat(G, *seat1);
										delateSeat(G, *seat2);
										delateSeat(G, *seat3);
										delateSeat(G, *seat4);
										return Ss;
									}
									/*��û�к��ʵ�Ʊ4�����Ʊ3*/
									else
									{
										seat3 = nullptr;
										step3++;
									}
								}
								else
								{
									step3++;
								}
							}
							/*��û�к��ʵ�Ʊ3�����Ʊ2*/
							if (seat3 == nullptr)
							{
								seat2 = nullptr;
								step2++;
								/*break;*/
							}
						}
						else {
							step2++;
						}
					}
					/*��û�к��ʵ�Ʊ2�����Ʊ1*/
					if (seat2 == nullptr)
					{
						seat1 = nullptr;
						step1++;
					}
				}
				else {
					step1++;
				}
			}
		}break;

		default:
			break;
		}
	}break;

		/*��ѯ������ʱ������������Ʊ������ֱ�����Ʊ*/
	case 2: {
		Sp = buyTickets(G, carriageT, seatT, outset, destination, transferTime, people);
		if (Sp != nullptr)
		{
			S = *Sp;
			Ss.push_back(S);
			delateSeat(G, *Sp);
			return Ss;
		}
		else {
			Sp = buyTickets(G, carriageT, seatT, outset, destination, transferTime, 1);
			if (Sp != nullptr)
			{
				S = *Sp;
				Ss.push_back(S);
				delateSeat(G, *Sp);

				Sp = buyTickets(G, carriageT, seatT, outset, destination, transferTime, 1);
				if (Sp != nullptr)
				{
					S = *Sp;
					Ss.push_back(S);
					delateSeat(G, *Sp);
					return Ss;
				}
			}
		}
	}break;

		/*��ѯ������ʱ������������Ʊ�������Թ���һ��˫����Ʊ��һ�ŵ���Ʊ����Ҳ��˫���������Թ������ŵ���Ʊ*/
	case 3: {
		Sp = buyTickets(G, carriageT, seatT, outset, destination, transferTime, people);
		if (Sp != nullptr)
		{
			S = *Sp;
			Ss.push_back(S);
			delateSeat(G, *Sp);
			return Ss;
		}
		else {
			Sp = buyTickets(G, carriageT, seatT, outset, destination, transferTime, 2);
			if (Sp != nullptr)
			{
				S = *Sp;
				Ss.push_back(S);
				delateSeat(G, *Sp);
				Sp = buyTickets(G, carriageT, seatT, outset, destination, transferTime, 1);
				if (Sp != nullptr)
				{
					S = *Sp;
					Ss.push_back(S);
					delateSeat(G, *Sp);
					return Ss;
				}
			}
			else {
				for (int i = 0; i < people; i++)
				{
					Sp = buyTickets(G, carriageT, seatT, outset, destination, transferTime, 1);
					if (Sp != nullptr)
					{
						S = *Sp;
						Ss.push_back(S);
						delateSeat(G, *Sp);
					}
				}
				return Ss;
			}
		}
	}break;

	default:
		break;
	}
	return Ss;
}
