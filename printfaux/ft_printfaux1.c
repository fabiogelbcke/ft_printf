#include "../libft.h"
#include "ft_printf.h"


void ft_putulonglongfwpm(char c, unsigned long long int n, size_t *fwpm)
{
  char *str;

  size_t i;
  
  i = 0;
  printf("\n n = %llo", n);
  if (c == 'o')
    n = ft_uitoo((uintmax_t)n);
  str = ft_uitoa((uintmax_t)n);
  printf("\nstr = %s\n", str);
  if (ft_strlen(str) < fwpm[1] && fwpm[2] < fwpm[1])
    while (i < fwpm[1] - ft_strlen(str) && i < fwpm[1] - fwpm[2])
      {
	ft_putchar(' ');
	i++;
      }
  i = 0;
  if (ft_strlen(str) < fwpm[2])
    while (i++ < fwpm[2] - ft_strlen(str))
      ft_putchar('0');
  while (*str)
    {
      write(1, str, 1);
      str++;
    }
}


void print_arg(char **strptr, va_list args, size_t *fwpm)
{
  //STILL GOTTA DO THE LONG CHAR THING
  if ((**strptr == 'i' || **strptr == 'd') && fwpm[3] == 4)
    ft_putlonglongfwpm(va_arg(args, long long int), fwpm);
  else if (**strptr == 'D' || ((**strptr == 'd' || **strptr == 'i') && fwpm[3] == 3))
    ft_putlongfwpm(va_arg(args, long int), fwpm, **strptr);
  else if (**strptr == 'd' || **strptr == 'i')
    ft_putnbrfwpm(va_arg(args, int), fwpm);
  else if (**strptr == 'U' || (**strptr == 'u' && fwpm[3] == 3))
    ft_putlong2fwpm(va_arg(args,long int), fwpm);
  else if ((**strptr == 'u' || **strptr == 'o') && (fwpm[3] == 4))
    ft_putulonglongfwpm(**strptr, va_arg(args, unsigned long long), fwpm);
  else if (**strptr == 'u')
    ft_putlongfwpm(UINT_MAX + va_arg(args,int) + 1, fwpm, **strptr);
  else if (**strptr == 's')
    ft_putstrfwpm(va_arg(args, char *), fwpm);
  else if (**strptr == 'O' || (**strptr == 'o' && fwpm[3] == 3))
    ft_putlongfwpm(ft_itoo(ULONG_MAX + va_arg(args, long int) + 1), fwpm, **strptr);
  else if (**strptr == 'o')
    ft_putlongfwpm(UINT_MAX + va_arg(args, int) + 1, fwpm, **strptr);
  else if (**strptr == 'x' || **strptr == 'X')
    ft_puthexfwpm(UINT_MAX + va_arg(args, int) + 1, **strptr, fwpm);
  else if (**strptr == 'C' || (**strptr == 'c' && fwpm[3] == 3))
    ft_putwidecharfwpm(va_arg(args, wchar_t), fwpm);
  else if (**strptr == 'c')
    ft_putcharfwpm((char)(UINT_MAX + va_arg(args, int) + 1), fwpm);
  else if(**strptr == 'p')
    ft_putpfwpm(va_arg(args, void*), fwpm);
  *strptr = *strptr + 1;
}
