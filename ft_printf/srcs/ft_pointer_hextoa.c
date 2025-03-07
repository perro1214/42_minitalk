#include "ft_printf.h"

static int	pointer_count_size(size_t n)
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

static void	pointer_make_ans(size_t n, char *ans, int len,char *tr_list)
{
	ans[len] = '\0';
	while (0 < len)
	{
		ans[len - 1] = tr_list[n % 16];
		n /= 16;
		len--;
	}
}

static char	*pointer_min_zero()
{
	char	*ans;

  ans = calloc(sizeof(char *),1);
  if (ans == NULL)
    return (NULL);
  ans[0] = '0'; 
	return (ans);
}

char	*ft_pointer_hextoa(size_t n,char * tr_list)
{
	char	*ans;
	int		len;
  //char *tr_list;

	if ( n == 0)
	{
		ans = pointer_min_zero();
	}
	else
	{
    //tr_list = "0123456789abcdef";
		len = pointer_count_size(n);
		ans = (char *)malloc(sizeof(char) * (len + 1));
		if (!ans)
			return (NULL);
		pointer_make_ans(n, ans, len,tr_list);
	}
	return (ans);
}