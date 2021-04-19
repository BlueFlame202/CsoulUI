#include <iostream>

#include "CsoulUI.h"

int main() 
{
  CsoulUI c("TESTING", "1.0.0");
  c.createCommand("PRINT", [](std::string s) { std::cout << s; });
  c.listen();
}