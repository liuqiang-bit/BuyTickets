#include "_X_Db.h"

_X_Db::_X_Db()
{
	XDb_p.push_back(A_EM);		//0		0					0				0
	XDb_p.push_back(B_EM);		//1			1				1	1			1	1
	XDb_p.push_back(C_EM);		//2				2				2	2		2	2	2
	XDb_p.push_back(D_EM);		//3					3				3	3		3	3
	XDb_p.push_back(E_EM);		//4						4				4			4
	XDb_p.push_back(AB_EM);		//5		5	5				5	5			5	5
	XDb_p.push_back(BC_EM);		//6			6	6			6	6	6		6	6	6
	XDb_p.push_back(CD_EM);		//7				7	7			7	7	7	7	7	7
	XDb_p.push_back(DE_EM);		//8					8	8			8	8		8	8
	XDb_p.push_back(ABC_EM);	//9		9	9	9			9	9	9		9	9	9
	XDb_p.push_back(BCD_EM);	//10		10	10	10		10	10	10	10	10	10	10
	XDb_p.push_back(CDE_EM);	//11			11	11	11		11	11	11	11	11	11

}
