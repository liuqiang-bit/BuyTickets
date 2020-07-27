#pragma once
#include "Sx_Db.h"
class C_Db
{

public:
	C_Db();

	Sx_Db S1_Db ;
	Sx_Db S2_Db ;
	Sx_Db S3_Db ;
	Sx_Db S4_Db ;
	Sx_Db S5_Db ;
	Sx_Db S6_Db ;
	Sx_Db S7_Db ;
	Sx_Db S8_Db ;
	Sx_Db S9_Db ;
	Sx_Db S10_Db;
	Sx_Db S11_Db;
	Sx_Db S12_Db;

	std::vector<Sx_Db> SxDb_p;

	int AL[3] = { 0,5,9 };
	int BL[5] = { 1,5,6,9,10 };
	int CL[6] = { 2,6,7,9,10,11 };
	int DL[5] = { 3,7,8,10,11 };
	int EL[3] = { 4,8,11 };
	int ABL[6] = { 0,1,5,6,9,10 };
	int BCL[8] = { 1,2,5,6,7,9,10,11 };
	int CDL[8] = { 2,3,6,7,8,9,10,11 };
	int DEL[6] = { 3,4,7,8,10,11 };
	int ABCL[9] = { 0,1,2,5,6,7,9,10,11 };
	int BCDL[10] = { 1,2,3,5,6,7,8,9,10,11 };
	int CDEL[8] = { 2,3,4,6,7,8,9,10 };

	int SZ[12] = { 3,5,6,5,3,6,8,8,6,9,10,8};
	std::vector<int*> L_p;
};

