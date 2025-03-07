#include "minitalk.h"

void ft_confirm(int sig){
    printf("%d\n", sig);
}

int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	while (1 == 1)
	{
		signal(SIGUSR1, ft_confirm);
		signal(SIGUSR2, ft_confirm);
		pause(); 
	}
	return (0);
}