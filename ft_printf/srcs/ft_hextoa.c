#include "ft_printf.h"

static int	count_size(unsigned int n)
{
	int	ans;

	ans = 0;
	while (n <= 0)
	{
		ans++;
		n = n * -1;
	}
	while (n != 0)
	{
		n /= 16;
		ans++;
	}
	return (ans);
}

static void	make_ans(unsigned int n, char *ans, int len,char *tr_list)
{
	ans[len] = '\0';
	while (0 < len)
	{
		ans[len - 1] = tr_list[n % 16];
		n /= 16;
		len--;
	}
}

static char	*min_zero()
{
	char	*ans;

  ans = calloc(sizeof(char *),1);
  if (ans == NULL)
    return (NULL);
  ans[0] = '0'; 
	return (ans);
}

char	*ft_hextoa(unsigned int n,char * tr_list)
{
	char	*ans;
	int		len;
  //char *tr_list;

	if ( n == 0)
	{
		ans = min_zero();
	}
	else
	{
    //tr_list = "0123456789abcdef";
		len = count_size(n);
		ans = (char *)malloc(sizeof(char) * (len + 1));
		if (!ans)
			return (NULL);
		make_ans(n, ans, len,tr_list);
	}
	return (ans);
}