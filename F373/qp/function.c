#include "main.h"
#define DUMP(func, call) \
    printf("\r\n%s: func = %p, called by = %p\n\r", __FUNCTION__, func, call)
    void __attribute__((__no_instrument_function__))
     __cyg_profile_func_enter(void *this_func, void *call_site)
{
        DUMP(this_func, call_site);
}
void __attribute__((__no_instrument_function__))
        __cyg_profile_func_exit(void *this_func, void *call_site)
{
        DUMP(this_func, call_site);
}
