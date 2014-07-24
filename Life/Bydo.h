#pragma once

class CBydo{
protected:
	int ColorId;
	int X,Y;
public:
	int Num;
	CBydo(int x,int y, int id);
	void Draw();
	~CBydo(void);
	bool Alive;
	int Around;
	void ChangeColorId(int id);
	void CheckAlive(int around);
	int GetId();
};

