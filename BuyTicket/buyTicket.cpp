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

/*车厢等级*/
enum CARRIAGE_TYPE
{
	L1 = 1, L2
};

/*坐席要求*/
enum SEAT_REQUIREMENT
{
	NONE, WINDOW, AISLE, CENTER
};

/*座位类型*/
enum SEAT_TYPE
{
	A, B, C, D, E, AB, BC, CD, DE, _ABC, BCD, CDE
};

/*人数*/
enum PEOPLE_TYPE
{
	ONE = 1, TWO, THREE
};

int main()
{
	C_Db* G151 = new C_Db;

	//***********************用以生成不同车票出售情况数据库*************************
	/*车站数据库（车站个数 - 1 个）*/
	for (int i = 0; i < STATION_NUM; i++)
	{	/*车厢数*/
		for (int j = 0; j < CARRIAGE_NUM; j++)
		{	/*每节车厢最大座位排数*/
			for (int k = 0; k < SEAT_NUM; k++)
			{	/*最多12种座位类别：A B C D E AB BC CD DE _ABC BCD CDE*/
				for (int n = 0; n < 12; n++)
				{

					//70%票已售出
					//if (j == 0 || j > 5 && k > 6) 
					//{
					//	if (n == 0 || n == 2  && n < 5)
					//	{
					//		_EM EM(j, k, i, 6, n);
					//		/*高铁->车站.车厢.座位类型*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//}	

					
					//80%票已售出
					//if (j == 0 || j > 5 && k > 6) 
					//{
					//	if (n == 0 && n < 5)
					//	{
					//		_EM EM(j, k, i, 6, n);
					//		/*高铁->车站.车厢.座位类型*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//}	

					//没有连座
					//if (j == 0 || j > 5 && k > 6 && n < 5)
					//{
					//	if (n == 0 || n == 2 || n == 4)
					//	{
					//		/*从i站到6站*/
					//		_EM EM(j, k, i, 6, n);
					//		/*高铁->车站.车厢.座位类型*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//	else
					//	{
					//		_EM EM(j, k, i, 7, n);
					//		/*高铁->车站.车厢.座位类型*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//}

					//有双连座AB，无三连坐
					if (j == 0 || j > 5 && k > 6 && n < 6)
					{
						if (n == 0 || n == 1 || n == 3 || n == 5)
						{
							_EM EM(j, k, i, 6, n);
							/*高铁->车站.车厢.座位类型*/
							G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
						}
						else
						{
							_EM EM(j, k, i, 5, n);
							/*高铁->车站.车厢.座位类型*/
							G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
						}
					}

					//有双连座AB，无三连坐
					//if (j == 0 || j > 5 && k > 6 && n < 6)
					//{
					//	if (n == 0 || n == 1 || n == 3 || n == 5)
					//	{
					//		_EM EM(j, k, i, 6, n);
					//		/*高铁->车站.车厢.座位类型*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//	else
					//	{
					//		_EM EM(j, k, i, 5, n);
					//		/*高铁->车站.车厢.座位类型*/
					//		G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//	}
					//}

					//1.3问数据库
					//4车3排C座从站0到站1
					//if (i == 0 && j == 3 && k == 2 && n == 2)
					//{
					//	_EM EM(j, k, i, 1, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*4车7排A座从1站到3站*/
					//else if (i == 1 && j == 3 && k == 6 && n == 0)
					//{
					//	_EM EM(j, k, i, 3, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*3车10排D座从3站到4站*/
					//else if (i == 3 && j == 2 && k == 9 && n == 3)
					//{
					//	_EM EM(j, k, i, 4, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*2车13排E座从3站到6站*/
					//else if (i == 3 && j == 1 && k == 12 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*5车7排C座从4站到6站*/
					//else if (i == 4 && j == 4 && k == 6 && n == 2)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*6车6排B座从0站到2站*/
					//else if (i == 0 && j == 5 && k == 5 && n == 1)
					//{
					//	_EM EM(j, k, i, 2, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					////5车6排E座从2站到6站
					//else if (i == 2 && j == 4 && k == 5 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*其余车票全部为6站到7站*/
					//else if (n < 5)
					//{
					//	_EM EM(j, k, 5, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}


					////1.3问70%已售数据库
					//if (i == 0 && j == 3 && k == 2 && n == 2)
					//{
					//	_EM EM(j, k, i, 1, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*4车7排A座从1站到3站*/
					//else if (i == 1 && j == 3 && k == 6 && n == 0)
					//{
					//	_EM EM(j, k, i, 3, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*3车10排D座从3站到4站*/
					//else if (i == 3 && j == 2 && k == 9 && n == 2)
					//{
					//	_EM EM(j, k, i, 4, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*2车13排E座从3站到6站*/
					//else if (i == 3 && j == 1 && k == 12 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*5车7排C座从4站到6站*/
					//else if (i == 4 && j == 4 && k == 6 && n == 2)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*6车6排B座从0站到2站*/
					//else if (i == 0 && j == 5 && k == 5 && n == 0)
					//{
					//	_EM EM(j, k, i, 2, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					////5车6排E座从2站到6站
					//else if (i == 2 && j == 4 && k == 5 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*其余车票全部为6站到7站*/
					//else if (n == 1 || n == 3)
					//{
					//	_EM EM(j, k, 5, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}

					//1.3问80%已售数据库
					//if (i == 0 && j == 3 && k == 2 && n == 2)
					//{
					//	_EM EM(j, k, i, 1, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*4车7排A座从1站到3站*/
					//else if (i == 1 && j == 3 && k == 6 && n == 0)
					//{
					//	_EM EM(j, k, i, 3, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*3车10排D座从3站到4站*/
					//else if (i == 3 && j == 2 && k == 9 && n == 3)
					//{
					//	_EM EM(j, k, i, 4, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*2车13排E座从3站到6站*/
					//else if (i == 3 && j == 1 && k == 12 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*5车7排C座从4站到6站*/
					//else if (i == 4 && j == 4 && k == 6 && n == 2)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*6车6排B座从0站到2站*/
					//else if (i == 0 && j == 5 && k == 5 && n == 3)
					//{
					//	_EM EM(j, k, i, 2, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					////5车6排E座从2站到6站
					//else if (i == 2 && j == 4 && k == 5 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*除以上7张票以外，仅B座位有票*/
					//else if ( n == 1)
					//{
					//	_EM EM(j, k, 5, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					
					//1.3问90%已售数据库
					//if (i == 0 && j == 3 && k == 2 && n == 2)
					//{
					//	_EM EM(j, k, i, 1, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*4车7排A座从1站到3站*/
					//else if (i == 1 && j == 3 && k == 6 && n == 0)
					//{
					//	_EM EM(j, k, i, 3, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*3车10排D座从3站到4站*/
					//else if (i == 3 && j == 2 && k == 9 && n == 3)
					//{
					//	_EM EM(j, k, i, 4, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*2车13排E座从3站到6站*/
					//else if (i == 3 && j == 1 && k == 12 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*5车7排C座从4站到6站*/
					//else if (i == 4 && j == 4 && k == 6 && n == 2)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*6车6排B座从0站到2站*/
					//else if (i == 0 && j == 5 && k == 5 && n == 3)
					//{
					//	_EM EM(j, k, i, 2, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					//5车6排E座从2站到6站
					//else if (i == 2 && j == 4 && k == 5 && n == 4)
					//{
					//	_EM EM(j, k, i, 6, n);
					//	G151->SxDb_p[i].CaDb_p[j]._XDb.XDb_p[n].push_back(EM);
					//}
					///*除以上7张票以外全部没票*/
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
	/*打印坐席关联表*/
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
		std::cout << "请输入车厢等级 <一等车厢: 1>、<二等车厢: 2>" << std::endl;
		std::cin >> CarriageLevel;
	} while (CarriageLevel != L1 && CarriageLevel != L2);

	int people = 0;
	do {
		std::cout << "请输入乘客数量 <一人:1>、<两人:2>、<三人:3>" << std::endl;
		std::cin >> people;
	} while (people < 1 || people > 3);

	int seatType = 0;
	int transfer = 0;
	if (people == 1) {
		do {
			std::cout << "请输入换乘次数 <零次:0>、<一次:1>、<两次:2>、<三次:3>" << std::endl;
			std::cin >> transfer;
		} while (transfer < NONE || transfer > THREE);

		if (transfer == NONE)
		{
			switch (CarriageLevel)
			{
			case L1: {
				do {
					std::cout << "请输入座位要求 <无:0>、<靠窗:1>、<靠过道:2>" << std::endl;
					std::cin >> seatType;
				} while (seatType != NONE && seatType != WINDOW && seatType != AISLE);
			}break;

			case L2: {
				do {
					std::cout << "请输入座位要求 <无:0>、<靠窗:1>、<靠过道:2>、<三连坐中间:3>" << std::endl;
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
		std::cout << "请输入出发站 <济南西:0>、<泰安:1>、<滕州东:2>、" << "<徐州东:3>、<蚌埠南:4>、<滁州:5>" << std::endl;
		std::cin >> outSet;
	} while (outSet < 0 || outSet > STATION_NUM - 1);

	int destination = 0;
	do {
		std::cout << "请输入目的地 <泰安:1>、<滕州东:2>、<徐州东:3>、" << "<蚌埠南:4>、<滁州:5>、<南京南:6>" << std::endl;
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
			std::cout << "您的座位" << i + 1 << "为:" << tic[i].C + 1 << "车" << tic[i].L + 1 << "排";
			switch (tic[i].ST)
			{
			case A: std::cout << "A座	"; break;
			case B: std::cout << "B座	"; break;
			case C: std::cout << "C座	"; break;
			case D: std::cout << "D座	"; break;
			case E: std::cout << "E座	"; break;
			case AB: std::cout << "AB座	  "; break;
			case BC: std::cout << "BC座	  "; break;
			case CD: std::cout << "CD座	  "; break;
			case DE: std::cout << "DE座	  "; break;
			case _ABC: std::cout << "ABC座	"; break;
			case BCD: std::cout << "BCD座	"; break;
			case CDE: std::cout << "CDE座	"; break;
			default:
				break;
			}

			switch (tic[i].O)
			{
			case 0: std::cout << "济南西 -> "; break;
			case 1: std::cout << "泰  安 -> "; break;
			case 2: std::cout << "滕州东 -> "; break;
			case 3: std::cout << "徐州东 -> "; break;
			case 4: std::cout << "蚌埠南 -> "; break;
			case 5: std::cout << "滁  州 -> "; break;
			case 6: std::cout << "南京南 -> "; break;
			default:
				break;
			}

			switch (tic[i].D)
			{
			case 0: std::cout << "济南西  " ; break;
			case 1: std::cout << "泰  安  " ; break;
			case 2: std::cout << "滕州东  " ; break;
			case 3: std::cout << "徐州东  " ; break;
			case 4: std::cout << "蚌埠南  " ; break;
			case 5: std::cout << "滁  州  " ; break;
			case 6: std::cout << "南京南  " ; break;
			default:
				break;
			}

			if (CarriageLevel == 1) {
				std::cout << "<一等座>" << std::endl;
			}
			else {
				std::cout << "<二等座>" << std::endl;
			}
		}
	}
	else {
		std::cout << "无票" << std::endl;
	}
	std::cout << "查询耗时:" << std::fixed << std::setprecision(20) << timer.elapse() << "us" << std::endl;

	getchar();
	getchar();
	return 0;
}

void delateSeat(C_Db* G, _EM& EM)
{
	/*起始站*/
	int S1 = EM.O;
	/*目的地*/
	int S2 = EM.D;
	/*车厢*/
	int Ca = EM.C;
	/*座位*/
	int S = EM.ST;

	/*遍历此座位被占据的车站数据库*/
	for (int i = S1; i < S2; i++)
	{
		/*遍历C车厢修改与此座位相关的数据库*/
		for (int j = 0; j < G->SZ[S]; j++)
		{
			/*座位类别*/
			int sType = G->L_p[S][j];
			std::vector<_EM>& ST = G->SxDb_p[i].CaDb_p[Ca]._XDb.XDb_p[sType];

			/*遍历相应类型座位数据库*/
			for (int n = 0; n < ST.size(); n++)
			{
				/*若相关数据库同排座位的占据范围与备选座位的占据范围有交集
				（既此座位的起始站小于备选座位的结束站，并且此座位的结束站大于被选座位的起始）*/
				if (ST[n].L == EM.L && ((ST[n].O < S2 && ST[n].D >= S1) || (ST[n].O == S1 && ST[n].D == S2)))
				{
					/*删除座位*/
					ST.erase(ST.begin() + n);
#ifdef DEBUG
					std::cout << "已删除 "
						<< i << " 车站数据库中 "
						<< Ca + 1 << " 车 "
						<< EM.L << " 排 ";
					switch (sType)
					{
					case A: std::cout << "A座" << std::endl; break;
					case B: std::cout << "B座" << std::endl; break;
					case C: std::cout << "C座" << std::endl; break;
					case D: std::cout << "D座" << std::endl; break;
					case E: std::cout << "E座" << std::endl; break;
					case AB: std::cout << "AB座" << std::endl; break;
					case BC: std::cout << "BC座" << std::endl; break;
					case CD: std::cout << "CD座" << std::endl; break;
					case DE: std::cout << "DE座" << std::endl; break;
					case _ABC: std::cout << "ABC座" << std::endl; break;
					case BCD: std::cout << "BCD座" << std::endl; break;
					case CDE: std::cout << "CDE座" << std::endl; break;
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
			/*不换乘*/
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

			/*换乘1次*/
		case 1: {
			/*遍历各车站数据库*/
			_EM* seat1 = nullptr;
			_EM* seat2 = nullptr;

			int step1 = 1;
			while (outset + step1 < destination)
			{
				/*车厢所有单座位*/
				Sp = buyTickets(G, L2, NONE, outset, outset + step1, transferTime, people);
				if (Sp != nullptr)
				{
					seat1 = Sp;
				}
				/*若找到了票1，则继续找票2*/

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
				/*若没有合适的票2，则否定票1*/
				if (seat2 == nullptr)
				{
					seat1 = nullptr;
					step1++;
				}
			}
		}break;

			/*换乘2次*/
		case 2: {
			/*遍历各车站数据库*/
			_EM* seat1 = nullptr;
			_EM* seat2 = nullptr;
			_EM* seat3 = nullptr;

			int step1 = 1;
			int step2 = 1;
			while (outset + step1 < destination)
			{
				/*车厢所有单座位*/
				Sp = buyTickets(G, L2, NONE, outset, outset + step1, transferTime, people);
				if (Sp != nullptr)
				{
					seat1 = Sp;
					/*找到了票1，继续找票2*/
					while (outset + step1 + step2 < destination)
					{
						Sp = buyTickets(G, L2, NONE, outset + step1, outset + step1 + step2, transferTime, people);
						if (Sp != nullptr)
						{
							seat2 = Sp;
							/*找到了票2，继续找票3*/
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
							/*若没有合适的票3，则否定票2*/
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
					/*若没有合适的票2，则否定票1*/
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
			/*遍历各车站数据库*/
			_EM* seat1 = nullptr;
			_EM* seat2 = nullptr;
			_EM* seat3 = nullptr;
			_EM* seat4 = nullptr;

			int step1 = 1;
			int step2 = 1;
			int step3 = 1;
			while (outset + step1 < destination)
			{
				/*车厢所有单座位*/
				Sp = buyTickets(G, L2, NONE, outset, outset + step1, transferTime, people);
				if (Sp != nullptr)
				{
					seat1 = Sp;
					/*找到了票1，继续找票2*/
					while (outset + step1 + step2 < destination)
					{
						Sp = buyTickets(G, L2, NONE, outset + step1, outset + step1 + step2, transferTime, people);
						if (Sp != nullptr)
						{
							seat2 = Sp;
							/*找到了票2，继续找票3*/
							while (outset + step1 + step2 + step3 < destination)
							{
								Sp = buyTickets(G, L2, NONE, outset + step1 + step2, outset + step1 + step2 + step3, transferTime, people);
								if (Sp != nullptr)
								{
									seat3 = Sp;
									/*找到了票3，继续找票4*/
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
									/*若没有合适的票4，则否定票3*/
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
							/*若没有合适的票3，则否定票2*/
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
					/*若没有合适的票2，则否定票1*/
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

		/*查询两连座时，有则购买连座票，否则分别购买单人票*/
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

		/*查询三连座时，有则购买连座票，否则尝试购买一张双连座票和一张单人票，若也无双连座则购买尝试购买三张单人票*/
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
