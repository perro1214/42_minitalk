#include "ft_printf.h"

int make_flag(char *itr, va_list ap) {
    if (!itr) return 0;
  if (*itr == 'c')
    return printchar(ap);
  else if (*itr == 's')
    return printstr(ap);
  else if (*itr == 'd' || *itr == 'i')
    return printint(ap);
  else if (*itr == 'x')
    return printhex(ap);
  else if (*itr == 'X')
    return printheX(ap);
  else if (*itr == '%')
    return write(1, "%", 1);
  else if (*itr == 'p')
    return printpointer(ap);
  else if (*itr == 'u')
    return printabsint(ap);
  return 0;
}

int ft_printf(const char *format, ...) {
  va_list ap;
  char *itr;
  int res = 0;

  va_start(ap, format);
  itr = (char *)format;
  if (!itr) {
    va_end(ap);
    return 0;
  }
  while (*itr) {
    if (*itr == '%') {
      itr++;
      res += make_flag(itr, ap);
        if(*itr)
            itr++;
        else
            break;
      continue;
    }else{
      res += ft_putchar_fd_int(*itr, 1);
      itr++;
    }
  }
  va_end(ap);
  return res;
}
