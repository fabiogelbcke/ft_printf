#include "libft.h"

char *ft_itox(long int n)
{
  int size;
  char *hex;
  int i;
  long int cpy;

  size = 1;
  i = 1;
  cpy = n;
  while (cpy / 16 > 0)
    {
      size++;
      cpy = cpy / 16;
    }
  hex = (char *)malloc(sizeof(char) * (size + 1));
  hex[size--] = '\0';
  while (n / 16 > 0)
    {
      hex[size--] = 48 + (n - 16 * (n / 16));
      if ((n - 16 * (n / 16)) > 9)
        hex[size + 1] += 39;
      n = n / 16;
    }
  hex[size] = (n <= 9) ? 48 + n : 87 + n;
  return hex;
}
