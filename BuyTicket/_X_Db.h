#pragma once
#include <iostream>
#include <vector>
#include "_EM.h"
class _X_Db
{
public:
	_X_Db();
	
	std::vector<_EM> A_EM  ;
	std::vector<_EM> B_EM  ;
	std::vector<_EM> C_EM  ;
	std::vector<_EM> D_EM  ;
	std::vector<_EM> E_EM  ;
	std::vector<_EM> AB_EM ;
	std::vector<_EM> BC_EM ;
	std::vector<_EM> CD_EM ;
	std::vector<_EM> DE_EM ;
	std::vector<_EM> ABC_EM;
	std::vector<_EM> BCD_EM;
	std::vector<_EM> CDE_EM;


	std::vector<std::vector<_EM> > XDb_p;

};

