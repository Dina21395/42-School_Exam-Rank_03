#include "get_next_line.h"

char * ft_str_dup(char * str)
{
     int i =0;
     char * line;
     while(str[i]!='\0')
        i++;
    line=malloc(sizeof(char)*(i+1));
    if(!line)
        return(NULL);
    i =0;
    while(str[i]!='\0')
    {
        line[i]=str[i];
        i++;
    }
    line[i]='\0';
    return(line);


}
char *get_next_line(int fd)
{

    int i =0;
    char line[50000];
    static int position;
    static int num_of_bytes;
    static char buffer[BUFFER_SIZE];
    if(fd<0 || BUFFER_SIZE <=0)
        return(NULL);
    while(1)
    {
        if(position >=num_of_bytes)
        {
             num_of_bytes=read(fd,buffer,BUFFER_SIZE);
             position =0;
             if(num_of_bytes<=0)
                break;
        }
        if(line[i]=='\n')
            break;
        line[i]=buffer[position++];
        i++;
    }
    line[i]='\0';
    if(i ==0)
        return(NULL);
    return(ft_str_dup(line));
}
/*int main()
{
    int fd;
    fd=open("file.txt", O_RDONLY);
    printf("%s",get_next_line(fd));

    return 0;
}*/
