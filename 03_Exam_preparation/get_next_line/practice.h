
#ifndef PRACTICE_H
# define PRACTICE_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif // !BUFFER_SIZE

char *practice(int fd);

#endif // !PRACTICE_H
