#include <algorithm>
#include <string>
#include <vector>

struct Radnik
{
    std::string ime;
    std::string prezime;
    double plata;
};

// sortirati Radnike prema kriterijumu
// - po plati
// - po prezimenu
// - po imenu

int main()
{
  std::vector<Radnik> radnici;
  // ucitamo radnike
  std::sort(radnici.begin(), radnici.end(),
    [](const auto& lhs, const auto& rhs) { return lhs.ime < rhs.ime; });
  std::stable_sort(radnici.begin(), radnici.end(),
    [](const auto& lhs, const auto& rhs) {
      return lhs.prezime < rhs.prezime;
    });
  std::sable_sort(begin(), end(), int() < int(5));
  std::stable_sort(radnici.begin(), radnici.end(),
    [](const auto& lhs, const auto& rhs) {
      return lhs.plata > rhs.plata;
    });
}
