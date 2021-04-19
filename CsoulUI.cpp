#include "CsoulUI.h"

CsoulUI::CsoulUI(std::string title, std::string ver)
{
  std::cout << "[CsoulUI]: Initializing " << title << " " << ver << std::endl;
  
  // define defaults so that if they get overwritten we get a warning, and also so that we can have a nice description
  m_commandMap["HELP"] = std::make_pair("displays a list of commands", [](std::string s) { return; });
  m_commandMap["SOULSLEEP"] = std::make_pair("ends CsoulUI", [](std::string s) { return; });
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
    res += v.first + ": " + v.second.first + "\n";
  return res;
}

void CsoulUI::createCommand(std::string s, std::string info, std::function<void(std::string)> f)
{
  if (m_commandMap[s].second) // check if it already exists and simultaneously allocate the memory if it doesnt
    std::cout << "[CsoulUI]: WARNING! Command " << s << " is being overwritten!";
  m_commandMap[s] = std::make_pair(info, f);
}

void CsoulUI::listen()
{
  std::string command;
  std::getline(std::cin, command); // wait for and get user input
  int temp = command.find(' ');
  if (temp != -1)
    respond(command.substr(0, temp), command.substr(temp + 1));
  else 
    respond(command, "");
}

void CsoulUI::respond(std::string command, std::string args)
{
  if (command == "HELP") std::cout << help() << std::endl;
  else if (command == "SOULSLEEP") 
  {
    std::cout << "[CsoulUI]: Terminating " << m_title << " " << m_ver << std::endl;
    return; // break out of the listen-respond loop
  }
  else if (!m_commandMap[command].second) 
    std::cout << "[CsoulUI]: ERROR! Command " << command << " not recognized." << std::endl;
  else
  {
    std::cout << "[CsoulUI]: ";
    m_commandMap[command].second(args);
    std::cout << std::endl;
  }
  listen(); // loop, we keep listening and responding again and again
}
