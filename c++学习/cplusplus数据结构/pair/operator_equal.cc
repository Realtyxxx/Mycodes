// pair:: operator= example
#include <iostream>
#include <string>

int main() {
  std::pair<std::string, int> planet, homeplanet;

  planet = std::make_pair("Earth", 6371);

  homeplanet = planet;

  std::cout << "Home planet: " << homeplanet.first << '\n';
  std::cout << "Planet size: " << homeplanet.second << '\n';
  return 0;
}