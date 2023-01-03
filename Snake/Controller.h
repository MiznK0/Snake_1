#pragma once

class Controller
{
public:

	Controller();
	direction lastDirct();
	void setLastDirct(direction);
	direction ñheck();
	bool Esc();
	bool Enter();
	bool Up();
	bool Down();

private:

	direction last_dirct;
	bool EscReleased;
	bool EnterReleased;
	bool UpReleased;
	bool DownReleased;
};

