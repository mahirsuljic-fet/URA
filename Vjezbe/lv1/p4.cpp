#include <iostream>

void frame_count(int n)
{
  std::cout << "Frame " << n << std::endl;
  char take_some_stack_space[512];
  frame_count(n + 1);
}

int main(int argc, char* argv[])
{
  frame_count(0);

  return 0;
}
