#include "ft_printf.h"

static int all_zero(char *a) {
  if (!a)
      return 1;
  while (*a != '\0') {
    if (*a != '0') {
      return 0;
    }
    a++;
  }
  return 1;
}

int printhex(va_list ap) {
  size_t number = va_arg(ap, size_t);
  char *ans_str = tr_hex(number);
  if (!ans_str)
    return 0;
  int result;
  if (all_zero(ans_str)) {
    result = ft_putstr_fd_int("0", 1);
  } else {
    result = ft_putstr_fd_int(ans_str, 1);
  }
  free(ans_str);

  return result;
}

int printheX(va_list ap) {
  size_t number = va_arg(ap, size_t);
  char *ans_str = tr_heX(number);
    if(!ans_str)
        return 0;
  int result;
    if (all_zero(ans_str)) {
        free(ans_str);
        result = ft_putstr_fd_int("0", 1);
    } else {
      result = ft_putstr_fd_int(ans_str, 1);
      free(ans_str);
    }
  return result;
}