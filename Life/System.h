#pragma once

#include "Bydo.h"
#include <list>
class CSystem{
protected:
	int Time;
	int Width, Height;
	CBydo* Bydo[600][800];
	int Pos;
	int dir[8];
public:
	CSystem(void);
	~CSystem(void);
	void Update();
	void Run();
	CBydo* GetBydoPos(int num);
};

