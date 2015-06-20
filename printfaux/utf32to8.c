#include "ft_printf.h"

char	*utf32to8(wint_t wint)
{
    char *str;

    printf("printf %lc \n", wint);

    str = malloc(5 * sizeof(char));
    if (wint <= 0x7F)
	{
	    str[0] = (char)wint;
	    str[1] = '\0';
	}
    else if (wint <= 0x7FF)
	{
	    str[0] = (((wint & 0x07c0) >> 6) + 0xc0);
	    str[1] = ((wint & 0x003F) + 0x80);
	    str[2] = '\0';
	}
    else if (wint <= 0xFFFF)
	{
	    str[0] = (((wint & 0xF000) >> 12) + 0xE0);
	    str[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
	    str[2] = ((wint & 0x003F) + 0x80);
	    str[3] = '\0';
	}
    else if (wint <= 0x10FFFF)
	{
	    str[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
	    str[1] = (((wint & 0x03F000) >> 12) + 0x80);
	    str[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
	    str[3] = ((wint & 0x003F) + 0x80);
	    str[4] = '\0';
	}
    printf("str = %s\n", str);
    return str;
}
