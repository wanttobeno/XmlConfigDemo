#pragma once

#include "ConfigFile.h"

class Globals
{
public:
	static Globals* Instance();
	virtual ~Globals();
	 ConfigFile * GetConfig();
protected:
	Globals();
private:
	//Singleton instance of class
	static Globals* m_pInstance;

	ConfigFile * m_pConfig;

};
