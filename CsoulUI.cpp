#include "CsoulUI.h"

CsoulUI::CsoulUI(std::string title, std::string ver)
{
  std::cout << "[CsoulUI]: Initializing " << title << " " << ver << std::endl;
  m_commandMap["HELP"] = [](std::string s) { return; };
  m_commandMap["SOULSLEEP"] = [](std::string s) { return; };
}

std::string CsoulUI::getTitle()
{
  return m_title;
}

std::string CsoulUI::getVersion()
{
  return m_ver;
}

std::string CsoulUI::help()
{
  std::string res = "[CsoulUI]: A List of Commands:\n";
  for (auto v : m_commandMap)
    res += v.first + "\n";
  return res;
}

void CsoulUI::createCommand(std::string s, std::function<void(std::string)> f)
{
  if (m_commandMap[s])
    std::cout << "[CsoulUI]: WARNING! Command " << s << " is being overwritten!";
  m_commandMap[s] = f;
}

void CsoulUI::listen()
{
  std::string command;
  std::getline(std::cin, command);
  int temp = command.find(' ');
  if (temp != -1)
    respond(command.substr(0, temp), command.substr(temp + 1));
  else 
    respond(command, "");
}

void CsoulUI::respond(std::string command, std::string args)
{
  if (command == "HELP") std::cout << help() << std::endl;
  else if (command == "SOULSLEEP") return;
  else if (!m_commandMap[command]) 
    std::cout << "[CsoulUI]: ERROR! Command " << command << " not recognized." << std::endl;
  else
  {
    std::cout << "[CsoulUI]: ";
    m_commandMap[command](args);
    std::cout << std::endl;
  }
  listen();
}
