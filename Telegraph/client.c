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
#include <signal.h>
#define SRV_PORT 1400
#define CLNT_PORT 1398
#define BUF_SIZE 1000000



int s, i;

char* SRV_HOST = NULL;

void siginthandler()
{
	write(s, "Клиент выключен\n", 31);
	write(1, "Клиент выключен\n", 31);
	shutdown(s, 2);
	close(s);
	exit(0);
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Введите адрес сервера!\n");
        return 0;
	}
	SRV_HOST = argv[1];
	int from_len;
	char buf[BUF_SIZE];
    struct hostent* hp;
	struct sockaddr_in clnt_sin, srv_sin;
    signal(SIGINT, &siginthandler);
	s = socket(AF_INET, SOCK_STREAM, 0);
	memset((char*)&clnt_sin, '\0', sizeof(clnt_sin));  //инициализация
	clnt_sin.sin_family = AF_INET;
	clnt_sin.sin_addr.s_addr = INADDR_ANY;
	clnt_sin.sin_port = CLNT_PORT;
	if (bind(s, (struct sockaddr*) & clnt_sin, sizeof(clnt_sin)) < 0)
		exit(44);
	memset((char*)&srv_sin, '\0', sizeof(srv_sin));
	hp = gethostbyname(SRV_HOST);
	srv_sin.sin_family = AF_INET;
	memcpy((char*)&srv_sin.sin_addr, hp->h_addr, hp->h_length);
	srv_sin.sin_port = SRV_PORT;
	connect(s, (struct sockaddr*) & srv_sin, sizeof(srv_sin));
	while (1)
	{
		from_len = recv(s, buf, BUF_SIZE, 0);
		write(1, "Сервер > ", 15);
		write(1, buf, from_len - 1);
		printf("\n >> ");
		i = 0;
		buf[0] = ' ';
		while ((buf[i-1] != 10)||(buf[i] != '.'))
		{
			buf[++i] = getchar();
		}
		write(1, " >Прием\n", 13);
		write(s, buf, i+1);
	}
	shutdown(s, 2); //разрыв соединения
	close(s);
	exit(0);
}
