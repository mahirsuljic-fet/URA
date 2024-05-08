#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

template <typename It, typename T>
bool binary_search(It begin, It end, const T& value)
{
  auto diff = end - begin;
  auto middle = begin + diff / 2;

  if (*middle == value) return true;
  if (diff <= 0) return false;
  if (*middle < value) return ::binary_search(middle + 1, end, value);
  if (*middle > value) return ::binary_search(begin, middle, value);
  return false;
}

int main()
{
  try
  {
    std::ifstream file("shakespeare/shakespeare.txt");
    if (!file) throw std::invalid_argument("Greska pri otvoranju fajla");

    std::vector<std::string> words;

    // pretvara sva velika slova u mala i izbacuje sve sto nije slovo
    auto str_to_lower_filter = [](const std::string& word) {
      std::string new_word;
      for (int i = 0; i < word.size(); ++i)
      {
        if (word[i] >= 'A' && word[i] <= 'Z')
          new_word += word[i] + 32;
        else if (word[i] >= 'a' && word[i] <= 'z')
          new_word += word[i];
      }
      return new_word;
    };

    std::string word;
    while (file >> word)
    {
      word = str_to_lower_filter(word);
      words.push_back(word);
    }

    std::sort(words.begin(), words.end());
    auto last = std::unique(words.begin(), words.end());
    words.erase(last, words.end());

    std::ostringstream oss;
    std::cout << "Unesite rijec: ";
    while (std::cin >> word)
    {
      oss.clear();
      oss.str("");
      word = str_to_lower_filter(word);
      auto start = std::chrono::system_clock::now();
      bool result = ::binary_search(words.begin(), words.end(), word);
      auto elapsed = std::chrono::system_clock::now() - start;
      oss << "Rijec \"" << word << "\"" << (result ? "" : " nije") << " pronadjena";
      std::cout << std::left << std::setw(40) << oss.str() << (result == std::binary_search(words.begin(), words.end(), word) ? " (T)" : " (F)") << std::endl;
      std::cout << "Proteklo vrijeme: " << elapsed.count() / 1000 << "us" << std::endl;
      std::cout << std::endl;
      std::cout << "Unesite rijec: ";
    }

    file.close();
  }
  catch (const std::exception& err)
  {
    std::cout << err.what() << std::endl;
  }

  return 0;
}
