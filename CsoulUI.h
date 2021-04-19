#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include <functional>

class CsoulUI
{
private:
  std::string m_title;
  std::string m_ver;

  std::unordered_map<std::string, std::function<void(std::string)>> m_commandMap;

public:
  CsoulUI(std::string title, std::string ver);

  std::string getTitle();
  std::string getVersion();

  std::string help();

  void createCommand(std::string s, std::function<void(std::string)> f);

  void listen();
  void respond(std::string command, std::string args);
};