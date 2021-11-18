
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <memory.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define SRV_PORT 1400
#define BUF_SIZE 1000000
#define TXT_QUEST "Привет, напишите\n"

#include <signal.h>

int s, s_new, i;

void siginthandler()
{
	write(s_new, "Сервер выкл\n", 23);
	write(1, "Сервер выкл\n", 23);
	shutdown(s_new, 2);
	close(s_new); exit(0);
}
int main()
{
	int len;
	char buf[BUF_SIZE];
	struct sockaddr_in sin, from_sin;
	signal(SIGINT, &siginthandler);
	s = socket(AF_INET, SOCK_STREAM, 0);
	memset((char*)&sin, '\0', sizeof(sin)); //инициализация
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = SRV_PORT;
	bind(s, (struct sockaddr*) & sin, sizeof(sin));
	listen(s, 3); //ожидание подключения клиента
	len = sizeof(from_sin);
	s_new = accept(s, (struct sockaddr*) &from_sin, &len);
    write(s_new, TXT_QUEST, sizeof(TXT_QUEST));
	while(1)
	{
		len = read(s_new, buf, BUF_SIZE);
        	write(1, "Клиент > ", 15);
		write(1, buf, len - 1);
		printf("\n >> ");
		i = 0;
		buf[0] = ' ';
		while ((buf[i-1] != 10)||(buf[i] != '.'))
		{
			buf[++i] = getchar();
		}
		write(1, " >Прием\n", 13);
        write(s_new, buf, i+1);
	};
	shutdown(s_new, 2); //разрыв соединения
	close(s_new);
	 exit (0);
}
