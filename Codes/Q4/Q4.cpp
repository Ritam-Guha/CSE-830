#include <iostream>

uint64_t count_times(uint64_t diff){
    uint64_t val = diff;
    uint64_t count = 0;

    while(val){
        val &= val-1;
        ++count;
    }

    return count;
}

int main()
{
  uint64_t T, G, N, count;
  uint64_t diff;
  std::cin >> T;
  while(T--){
        std::cin >> N >> G;
        diff = N-G;
        count = count_times(diff);
        std::cout << count << std::endl;
  }
}