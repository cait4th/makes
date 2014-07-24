#include "Bydo.h"
#include "DxLib.h"
#include "common.h"


CBydo::CBydo(int x,int y, int id) : X(x), Y(y), ColorId(id), Alive(false),Around(0){

}


CBydo::~CBydo(void)
{
}

void CBydo::Draw(){
	DrawPixel(X,Y,GetColorId(ColorId));
}

void CBydo::ChangeColorId(int id){
	ColorId = id;
	Alive = true;
}

int CBydo::GetId(){
	return ColorId;
}

void CBydo::CheckAlive(int around){
	if (around<2 || around>3)
	{
		Alive = false;
	}
	if (around==3)
	{
		ChangeColorId(White);
	}
}