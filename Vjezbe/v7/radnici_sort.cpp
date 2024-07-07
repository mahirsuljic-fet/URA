#include <algorithm>
#include <string>
#include <vector>

struct Radnik
{
    std::string ime;
    std::string prezime;
    double plata;
};

int main()
{
  std::vector<Radnik> radnici;

  // ucitamo radnike ...

  std::sort(radnici.begin(), radnici.end(), [](const auto& lhs, const auto& rhs) { return lhs.ime > rhs.ime; });
  std::stable_sort(radnici.begin(), radnici.end(), [](const auto& lhs, const auto& rhs) { return lhs.prezime > rhs.prezime; });
  std::stable_sort(radnici.begin(), radnici.end(), [](const auto& lhs, const auto& rhs) { return lhs.plata > rhs.plata; });

  // radnici sortirani po plati pa prezimenu pa imenu

  return 0;
}
