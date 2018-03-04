#include "Globals.h"
void PrintString(std::string  str)
{
	std::cout << str.c_str() << std::endl;
}


void PrintHistory(ConfigFile* pConfig)
{
	std::vector<std::string> listFileHistory;
	listFileHistory = pConfig->getArray("FileHistory");
	for_each(listFileHistory.begin(),listFileHistory.end(),PrintString);
}

int main()
{
	ConfigFile* pConfig = Globals::Instance()->GetConfig();

	if (pConfig->IsOpen())
	{
		PrintHistory(pConfig);
	}
	else
	{
		std::vector<std::string> listFileHistory;
		listFileHistory.push_back("D:\\ExcellentAlbum\\1.png");
		listFileHistory.push_back("D:\\ExcellentAlbum\\2.png");
		listFileHistory.push_back("D:\\ExcellentAlbum\\3.png");
		pConfig->setArray("FileHistory", listFileHistory);
		pConfig->setInteger("FileHistorySize",listFileHistory.size());
		pConfig->Save();
		PrintHistory(pConfig);
	}
	return 0;
}




