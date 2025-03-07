#include "ft_printf.h"

int printchar(va_list ap) {
  char ch1 = va_arg(ap, int);
  return ft_putchar_fd_int(ch1, 1);
}

int printstr(va_list ap) {
  char *str = va_arg(ap, char *);
  return ft_putstr_fd_int(str, 1);
}

int printint(va_list ap) {
  int number = va_arg(ap, int);
  return ft_putnbr_fd_int(number, 1);
}

int printpointer(va_list ap) {
  void *ptr = va_arg(ap, void *);
  uintptr_t address = (uintptr_t)ptr;
  int result;
  if (address == 0) {
      result = write(1, "(nil)", 5);
      return result;
  }
  result = write(1, "0x", 2);
  char *ans_str = tr_pointer(address);
  if (!ans_str)
    return 0;
  result += ft_putstr_fd_int(ans_str, 1);
  free(ans_str);
  return result;
}

int printabsint(va_list ap) {
  unsigned int number = va_arg(ap, unsigned int);
  return ft_putabsnbr_fd_int(number, 1);
}