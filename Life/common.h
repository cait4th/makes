#pragma once
#include "DxLib.h"
#include "Bydo.h"


enum{
	Red,Green,Blue,Brack,White,
};

static int GetColorId(int id){
	switch(id){
	case Red:
		return GetColor(255,0,0);
		break;
	case White:
		return GetColor(255,255,255);
	default:
		return GetColor(0,0,0);
		break;
	}
	return GetColor(0,0,0);
}