#include "CsoulUI.h"

CsoulUI::CsoulUI(std::string title, std::string ver)
{
	std::cout << "[CsoulUI]: Initializing " << title << " " << ver << std::endl;
}

std::string CsoulUI::help()
{
	std::string res = "A List of Commands:\n";
	for (auto v : m_commandMap)
		res += v.first + "\n";
}

void CsoulUI::createCommand(std::string s, std::function<void(std::string)> f)
{
	m_commandMap.insert(std::pair<std::string, std::function<void(std::string)>>(s, f));
}

void CsoulUI::listen()
{
	std::string command;
	std::cin.get();
	std::getline(std::cin, command);
	int temp = command.find(' ');
	if (temp != -1)
		respond(command.substr(0, temp), command.substr(temp));
	else 
		respond(command, "");
}

void CsoulUI::respond(std::string command, std::string args)
{
	m_commandMap[command](args);
}
