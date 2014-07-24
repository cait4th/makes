#include "System.h"
#include "common.h"
//#include <list>

std::list<CBydo*> BydoList;

CSystem::CSystem(void) : Time(0), Width(800), Height(600),Pos(0){
	for(int i=0; i<600; i++)
	{
		for(int j=0; j<800; j++)
		{
			Bydo[i][j] = new CBydo(j,i,Brack);
			Bydo[i][j]->Num = Pos;
			Pos++;
		}
	}	
	dir[0] = 1;
	dir[1] = -1;
	dir[2] = -800;
	dir[3] = -800-1;
	dir[4] = -800-2;
	dir[5] = 800;
	dir[6] = 800+1;
	dir[7] = 800+2;
	//Bydo[400][300]->ChangeColorId(White);
}


CSystem::~CSystem(void)
{
}

void CSystem::Run(){
	if (CheckHitKey(KEY_INPUT_Z))
	{
		Bydo[400][300]->ChangeColorId(White);
	}
	if (Time%3==0)
	{
		Update();
	}
	for (int i=0; i<600; i++)
	{
		for (int j=0; j<800; j++)
		{
			if (Bydo[i][j]->Alive)
			{
				Bydo[i][j]->Draw();
			}
		}
	}
	Time++;
}

void CSystem::Update(){
	for(int i=1; i<599; i++)
	{
		for(int j=1; j<799; j++)
		{
			Bydo[i][j]->Around = 0;
			for(int k=0; k<8; k++)
			{
				//Bydo[i][j]->Around += GetBydoPos(Bydo[i][j]->Num)->Alive;
			}
			Bydo[i][j]->CheckAlive(Bydo[i][j]->Around);
		}
	}
}

CBydo* CSystem::GetBydoPos(int num){
	for(int i=0; i<600; i++)
	{
		for(int j=0; j<800; j++)
		{
			if (Bydo[i][j]->Num==num)
			{
				return Bydo[i][j];
			}
		}
	}
	return NULL;
}