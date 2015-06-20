#include "libft.h"

void ft_putlong(long int n)
{
  char *str;

  str = ft_litoa(n);
  while (*str)
    {
      write(1, str, 1);
      str++;
    }
}
