#pragma once
#include "L1_Db.h"
#include "L2_Db.h"

class Sx_Db
{
public:
	Sx_Db();
	L2_Db L1_1_Db; //此为一等车厢
	L2_Db L2_2_Db;
	L2_Db L2_3_Db;
	L2_Db L2_4_Db;
	L2_Db L2_5_Db;
	L2_Db L2_6_Db;
	L2_Db L2_7_Db;
	L2_Db L2_8_Db;

	std::vector<L2_Db> CaDb_p;
};

