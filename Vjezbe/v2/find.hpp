#pragma once

namespace ura
{
template <typename It, typename E>
It find(It begin, It end, E element)
{
  for (It temp = begin; temp != end; ++temp)
    if (*temp == element)
      return temp;
  return end;
}

template <typename It, typename P>
It find_if(It begin, It end, P fn)
{
  for (It temp = begin; temp != end; ++temp)
    if (fn(*temp))
      return temp;
  return end;
}

// NE RADI ZA element < *begin
// ili sam pogresno prepisao ili nije dobro implementirano na vjezbama
// dodat cu nekad kasnije ispravku (svoju implementaciju)
template <typename It, typename E>
It binary_search(It begin, It end, E element)
{
  auto n = end - begin;
  if (n == 0) return end;
  auto middle = begin + n / 2;

  if (*middle == element)
    return middle;
  else if (*middle < element)
    return ura::binary_search(middle + 1, end, element);
  else if (*middle > element)
    return ura::binary_search(begin, middle, element);
  return end;
}

template <typename It, typename E>
It binary_search_iter(It begin, It end, E element)
{
  auto real_end = end;
  auto n = end - begin;
  auto middle = begin + n / 2;

  while (n != 0)
  {
    if (*middle == element)
      return middle;
    else if (*middle < element)
      begin = middle + 1;
    else if (*middle > element)
      end = middle;

    n = end - begin;
    middle = begin + n / 2;
  }

  return real_end;
}
}
