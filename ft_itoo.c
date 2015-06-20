long int ft_itoo(long int n)
{
  long long int oct;
  long long int mult;

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
