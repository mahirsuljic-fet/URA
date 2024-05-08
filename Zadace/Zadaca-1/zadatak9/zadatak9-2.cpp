#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Vrijeme izvrsenja: ~155000ms (shakespeare1_4.txt)
// Kompleksnost: O(n^2)
// (unosimo n elemanata, kompleksnost od upper_bound je O(logn),
// a od insert je O(n) pa je ukupna kompleksnost O(n^2 + nlogn), odnosno O(n^2))

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
    {
      auto it = std::upper_bound(words.begin(), words.end(), word);
      words.insert(it, word);
    }
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
