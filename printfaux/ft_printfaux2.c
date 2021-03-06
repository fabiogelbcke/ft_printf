#include "../libft.h"
#include "ft_printf.h"

void ft_putwidecharfwpm(wint_t c, size_t *fwpm)
{
    char *wide;

    fwpm[1]++;
    printf("arrgh %lc", (wchar_t)c);
    wide = utf32to8(c);
    ft_putstr(wide);
}

void ft_putcharfwpm(char c, size_t *fwpm)
{
  size_t i;

  i = 1;
  while(i++ < fwpm[1])
    ft_putchar(' ');
  ft_putchar(c);
}

long int ft_modoulongfwpm(char c, long n, size_t *fwpm)
{
  if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
    {
      if (fwpm[3] == 1)
        {
          while (n > UCHAR_MAX)
            n -= 1 * UCHAR_MAX + 1;
          while (n < 0)
            n += 1 * UCHAR_MAX + 1;
        }
      else if (fwpm[3] == 2)
        {
          while(n > USHRT_MAX)
            n -= 1 * USHRT_MAX + 1;
          while (n < 0)
            n += USHRT_MAX + 1;
        }
      if (c == 'o')
        n = ft_itoo(n);
    }
  return n;
}

void ft_putlongfwpm(long int n, size_t *fwpm, char c)
{
  char * str;
  size_t i;

  n = ft_modoulongfwpm(c, n, fwpm);
  i = 0;
  printf("\n n = %ld", n);
  str = ft_litoa(n);
  printf("\nstr = %s\n", str);
  if (ft_strlen(str) < fwpm[1] && fwpm[2] < fwpm[1])
    while (i < fwpm[1] - ft_strlen(str) && i < fwpm[1] - fwpm[2])
      {
        ft_putchar(' ');
        i++;
      }
  i = 0;
  if (ft_strlen(str) < (size_t)fwpm[2])
    while ((unsigned)i++ < fwpm[2] - ft_strlen(str))
      ft_putchar('0');
  while (*str)
    {
      write(1, str, 1);
      str++;
    }
}

void ft_putlonglongfwpm(long long int n, size_t *fwpm)
{
  char * str;
  size_t i;

  i = 0;
  str = ft_llitoa(n);
  if (ft_strlen(str) < (size_t)fwpm[1] && fwpm[2] < fwpm[1])
    while ((size_t)i < fwpm[1] - ft_strlen(str) && i < fwpm[1] - fwpm[2])
      {
        ft_putchar(' ');
        i++;
      }
  i = 0;
  if (ft_strlen(str) < (size_t)fwpm[2])
    while ((size_t)i++ < fwpm[2] - ft_strlen(str))
      ft_putchar('0');
  while (*str)
    {
      write(1, str, 1);
      str++;
    }
}

void ft_putlong2fwpm(long int n, size_t *fwpm)
{
  char *str;
  char *str2;
  unsigned long int un;
  size_t i;
  if (n < 0)
    un = ULONG_MAX + 1 + n;
  else
    un = n;
  str = ft_litoa(un/10);
  str2 = ft_litoa(un - 10 * (un / 10));
  i = 0;
  while (i < fwpm[1] - fwpm[2] && (size_t)i < fwpm[1] - ft_strlen(str) - ft_strlen(str2))
    {
      i++;
      ft_putchar(' ');
    }
  i = 0;
  while ((size_t)i++ < fwpm[2] - ft_strlen(str) - ft_strlen(str2))
    ft_putchar('0');
  while(*str)
    {
      if (un > 10)
        write(1, str, 1);
      str++;
    }
  while(*str2)
    {
      write(1, str2, 1);
      str2++;
    }
}

void ft_puthexfwpm(long int n, char mod, size_t *fwpm)
{
  char *ptr;
  size_t i;
  char *str;

  i = 0;
  n = ft_modoulongfwpm('x', n, fwpm);
  str = ft_itox(n);
  if (ft_strlen(str) < (size_t)fwpm[1] && fwpm[2] < fwpm[1])
    while ((size_t)i < fwpm[1] - ft_strlen(str) && i < fwpm[1] - fwpm[2])
      {
        ft_putchar(' ');
        i++;
      }
  i = 0;
  if (ft_strlen(str) < (size_t)fwpm[2])
    while(i++ <fwpm[2] - ft_strlen(str))
      ft_putchar('0');
  if (mod == 'X')
    {
      ptr = str;
      while(*ptr)
        if (*ptr >= 97 && *ptr <= 103)
          *(ptr++) -= 32;
        else
          ptr++;
    }
  ft_putstr(str);
}

int changedifwpm(int n, size_t *fwpm)
{
  if (fwpm[3] == 2)
    {
      while (n > SHRT_MAX)
        n -= 2 * SHRT_MAX + 2;
      while (n < -1 * SHRT_MAX - 1)
        n += 2 * SHRT_MAX + 2;
    }
  if (fwpm[3] == 1)
    {
      while (n > SCHAR_MAX)
        n -= 2*SCHAR_MAX + 2;
      while (n < -1 * SCHAR_MAX -1)
        n += 2*SCHAR_MAX + 2;
    }
  return n;
}

void ft_putnbrfwpm(int n, size_t *fwpm)
{
  char *str;
  size_t i;

  n = changedifwpm(n, fwpm);
  i = 0;
  str = ft_itoa(n);
  if (ft_strlen(str) < fwpm[1] && fwpm[2] < fwpm[1])
    while (i < fwpm[1] - ft_strlen(str) && i < fwpm[1] - fwpm[2])
      {
        ft_putchar(' ');
        i++;
      }
  i = 0;
  if (ft_strlen(str) < fwpm[2])
    while(i++ <fwpm[2] - ft_strlen(str))
      ft_putchar('0');
  while (*str)
    {
      write(1, str, 1);
      str++;
    }
}

void ft_putstrfwpm(char *str, size_t *fwpm)
{
  size_t i;

  i = 0;
  if (fwpm[1] > ft_strlen(str))
    while (i++ < fwpm[1] - ft_strlen(str))
      ft_putchar(' ');
  ft_putstr(str);
}

void ft_putpfwpm(void *ptr, size_t *fwpm)
{
  size_t i;
  char *str;

  i = 0;
  str = ft_itox((long)ptr);
  while (i++ < fwpm[1] - ft_strlen(str) - 2)
    ft_putchar(' ');
  ft_putstr("0x");
  ft_putstr(str);
}
