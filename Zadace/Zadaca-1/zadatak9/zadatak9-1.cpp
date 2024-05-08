#include <algorithm>
#include <chrono>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// Vrijeme izvrsenja: ~180ms (shakespeare1_4.txt)
// Kompleksnost: O(nlogn)
// (unos je O(n), sort je O(nlogn), pa je ukupna kompleksnost O(n + nlogn), odnosno O(nlogn))

int main()
{
  try
  {
    std::ifstream file("shakespeare/shakespeare1_4.txt");
    if (!file) throw std::invalid_argument("Greska pri otvoranju fajla");

    std::vector<std::string> words;
    std::string word;

    std::cout << "Ucitavanje rijeci..." << std::endl;
    auto start = std::chrono::system_clock::now();
    while (file >> word)
      words.push_back(word);

    std::sort(words.begin(), words.end());
    auto elapsed = std::chrono::system_clock::now() - start;

    std::cout << "Vrijeme izvrsenja: " << elapsed.count() / 1000000 << "ms" << std::endl;

    file.close();
  }
  catch (const std::exception& err)
  {
    std::cout << err.what() << std::endl;
  }

  return 0;
}
