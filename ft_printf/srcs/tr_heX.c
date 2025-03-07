#include "ft_printf.h"

char *tr_heX(size_t number) {
    char *tr_list = "0123456789ABCDEF";
    return ft_hextoa((unsigned int)number, tr_list);
}