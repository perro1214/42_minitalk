
#include "ft_printf.h"

char *tr_hex(size_t number) {
    char *tr_list = "0123456789abcdef";
    return ft_hextoa((unsigned int)number,tr_list);
}