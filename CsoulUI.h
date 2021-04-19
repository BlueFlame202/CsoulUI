#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include <functional>

class CsoulUI
{
private:
  std::string m_title; // title of the program using CSoulUI (primary program)
  std::string m_ver; // version of the primary program

  std::unordered_map<std::string, std::pair<std::string, std::function<void(std::string)>>> m_commandMap; // stores function names, info and corresponding functions

public:
  CsoulUI(std::string title, std::string ver);

  std::string getTitle();
  std::string getVersion();

  std::string help();

  void createCommand(std::string s, std::string info, std::function<void(std::string)> f);

  void listen();
  void respond(std::string command, std::string args);
};