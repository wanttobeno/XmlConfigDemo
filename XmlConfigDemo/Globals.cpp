#include "Globals.h"

Globals* Globals::m_pInstance = 0;// initialize pointer

Globals* Globals::Instance () 
{
	if (m_pInstance == 0)  // is it the first call?
	{  
		m_pInstance = new Globals; // create sole instance
	}

	return m_pInstance; // address of sole instance
}

Globals::Globals()
{
	m_pConfig = new ConfigFile("config.xml", "AppSettingData");
}

Globals::~Globals()
{
	m_pConfig->Save();
	delete m_pConfig;
}

ConfigFile * Globals::GetConfig()
{
	return m_pConfig;
}