#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

/*int main()
{

	char *test = setlocale (LC_ALL, "");

	char c;
	int i = 45;
	wchar_t rend;
	srand(time(NULL));
	write(1, "\e[0;32m", 8);
	while(i)
	{
		rend = ((int)(rand() % 123)) + 1;

		if(4 < ((int)(rand() % 10)) + 1)
		{
			printf("        ");
			if(i == 1)
			{
				printf("\n");
				i = 46;
			}
			i--;
		}
		if (ft_isprint(rend))
		{
			printf("       %C", rend);
			if(i == 1)
			{
				printf("\n");
				i = 46;
			}
			i--;
		}
	}
//	sleep(1);
}*/

int main(void)
{
	setlocale (LC_ALL, "");
	char c;
	char i = 0;


		printf("%d\n" , ft_printf("ft_printf : %042.D", 12));
		printf("%d\n" , printf("no_printf : %042.D", 12));

}