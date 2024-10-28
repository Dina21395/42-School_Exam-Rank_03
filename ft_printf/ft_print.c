#include <unistd.h>
#include <stdarg.h>
void ft_str(char * str , int *l)
{
    int i = 0;
    if(!str)
        {
            *l+=write(1,"(null)",6);
            return;
        }
    while(str[i]!='\0')
    {
        *l+=write(1,&str[i],1);
        i++;
    }

}
void ft_num(long long number , int numbase , int *l)
{
    char arr[16]="0123456789abcdef";
    if(number == -2147483648)
    {
        *l+=write(1,"-2147483648",11);
        return;
    }
    if(number < 0)
    {
        *l+=write(1,"-",1);
        number = number * -1;
    }

    if(number >=numbase)
        ft_num(number/numbase,numbase,l);
    *l+=write(1,&arr[number%numbase],1);

}

int ft_printf(const char *format, ... )
{
    int i =0;
    int len =0;
    va_list args;
    va_start(args , format);
    while(format[i]!='\0')
    {
        if(format[i]=='%' && format[i])
        {
            i++;
            if(format[i]=='s')
                ft_str(va_arg(args , char *),&len);
            else if (format[i]=='x')
                ft_num(va_arg(args ,unsigned int),16,&len);
            else if(format[i]=='d')
                ft_num(va_arg(args ,int),10,&len);
        }
        else
        len+= write(1,&format[i],1);
        i++;
    }
    va_end(args);
    return(len);

}
/*int main()
{
     ft_printf("%s\n", "toto");
      ft_printf("Magic %s is %d", "number", -2147483648);
      ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    
    return(0);
}*/
