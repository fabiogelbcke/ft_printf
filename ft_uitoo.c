#include "libft.h"

uintmax_t ft_uitoo(uintmax_t n)
{
  uintmax_t oct;
  uintmax_t mult;

  oct = 0;
  mult = 1;
  while(n/8 > 0)
    {
      oct += mult * (n - 8 * (n / 8));
      n = n / 8;
      mult = mult * 10;
    }
  oct += mult * n;
  return oct;
}
