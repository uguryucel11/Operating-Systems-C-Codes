#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int pipe(int pipedes[2]);

    //int open_1(const char *pathname, int flags);
    //int open_2(const char *pathname, int flags, mode_t mode);
    int pipefds[2];
    int returnstatus;
    char writemessages[2][20]={"Hi", "Hello"};
    char readmessage[20];
    returnstatus = pipe(pipefds);
    if (returnstatus == -1)
    {
        printf("Oooopss!! There is an error");
    }

    printf("Writing to pipe - Message 1 is %s\n", writemessages[0]);
    write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
    read(pipefds[0], readmessage, sizeof(readmessage));
    printf("Reading from pipe – Message 1 is %s\n", readmessage);
    printf("Writing to pipe - Message 2 is %s\n", writemessages[0]);
    write(pipefds[1], writemessages[1], sizeof(writemessages[0]));
    read(pipefds[0], readmessage, sizeof(readmessage));
    printf("Reading from pipe – Message 2 is %s\n", readmessage);








    return 0;
}
