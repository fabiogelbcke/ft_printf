#include "ft_printf.h"

void ft_printf(char *str, ...)
{
  va_list args;
  char *ptr;
  size_t fwpm[4];
  int mult;

  fwpm[0] = 0; //flags
  fwpm[1] = 0; //width
  fwpm[2] = 0; //precision
  fwpm[3] = 0; //modifiers
  mult = 1;
  va_start(args, str);
  while (*str)
    {
      if (*str != '%')
	ft_putchar(*(str++));
      else if (*(str + 1) == '%')
	{
	  str += 2;
	  ft_putchar('%');
	}
      else
	{
	  ptr = ++str;
	  while (*str == '0' || *str == '#' || *str == '+' || *str == '-' || *str == ' ')
	    {
	      if (*str == '0')
		fwpm[0] += 1;
	      if (*str == '#')
		fwpm[0] += 2;
	      if (*str == '+')
		fwpm[0] += 4;
	      if (*str == '-')
		fwpm[0] += 8;
	      if(*str == ' ')
		fwpm[0] += 16;
	      str++;
	    }
	  //width
	  if (*str == '*' || (*str >= '0' &&*str <='9'))
	    {
	      if (*str == '*')
		*str = *str;
	      else
		fwpm[1] = ft_atoi(str);
	      while (*str == '*' || (*str >= '0' &&*str <='9'))
		str++;
	    }
	  mult = 1;
	  if (*str == '.')
	    {
	      //precision
	      str++;
	      fwpm[2] = ft_atoi(str);
	      while (*str == '*' || (*str >= '0' &&*str <='9'))
		str++;
	    }
	  if (ft_strrchr("hljz", *str))
	    {
	      //modifiers
	      if (*str == 'h' && *(str + 1) == 'h')
		{
		  fwpm[3] = 1;
		  str++;
		}
	      else if (*str == 'h')
		fwpm[3] = 2;
	      else if (*str == 'l' && *(str + 1) == 'l')
		{
		  fwpm[3] = 4;
		  str++;
		}
	      else if (*str == 'l')
		fwpm[3] = 3;
	      else if (*str == 'j')
		fwpm[3] = 5;
	      else if (*str == 'z')
		fwpm[3] = 6;
	      str++;
	    }
	  if (ft_strrchr("sSpdDioOuUxXcC", *str) != NULL)
	    {
	      print_arg(&str, args, fwpm);
	    }
	}
    }
  va_end(args);
}

int main(void)
{
  ft_printf("%lc",  9999);
  return(0);
}
