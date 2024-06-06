#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Tim
{
    std::string naziv;
    int bodovi;
    int primljeniGolovi;
    int postignutiGolovi;
};

template <typename It>
void sort_teams(It begin, It end)
{
  std::sort(begin, end, [](const Tim& lhs, const Tim& rhs) { return lhs.naziv < rhs.naziv; });
  std::stable_sort(begin, end, [](const Tim& lhs, const Tim& rhs) { return lhs.postignutiGolovi < rhs.postignutiGolovi; });
  std::stable_sort(begin, end, [](const Tim& lhs, const Tim& rhs) { return lhs.postignutiGolovi - lhs.primljeniGolovi < rhs.postignutiGolovi - rhs.primljeniGolovi; });
  std::stable_sort(begin, end, [](const Tim& lhs, const Tim& rhs) { return lhs.bodovi < rhs.bodovi; });
}

int main()
{
  std::vector<Tim> teams;

  teams.push_back({ "Tim1", 1, 4, 9 });
  teams.push_back({ "Tim2", 2, 5, 6 });
  teams.push_back({ "Tim3", 1, 2, 7 });
  teams.push_back({ "Tim4", 4, 5, 6 });
  teams.push_back({ "Tim5", 2, 4, 6 });
  teams.push_back({ "Tim6", 2, 4, 6 });

  auto print_teams = [&teams]() {
    for (const auto& team : teams)
      std::cout << team.naziv << "|" << team.bodovi << "|" << team.primljeniGolovi << "|" << team.postignutiGolovi << std::endl;
    std::cout << std::endl;
  };

  print_teams();
  sort_teams(teams.begin(), teams.end());
  print_teams();

  return 0;
}
