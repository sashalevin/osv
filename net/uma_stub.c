#include <stdint.h>
#include "param.h"
#include "netport.h"
#include "uma_stub.h"

void * uma_zalloc_arg(uma_zone_t zone, void *udata, int flags)
{
    return NULL;
}

void * uma_zalloc(uma_zone_t zone, int flags)
{
    return uma_zalloc_arg(zone, NULL, flags);
}

void uma_zfree_arg(uma_zone_t zone, void *item, void *udata)
{

}

void uma_zfree(uma_zone_t zone, void *item)
{
    uma_zfree_arg(zone, item, NULL);
}

void zone_drain_wait(uma_zone_t zone, int waitok)
{

}

void zone_drain(uma_zone_t zone)
{
    zone_drain_wait(zone, M_NOWAIT);
}

int uma_zone_set_max(uma_zone_t zone, int nitems)
{
    return 1;
}

uma_zone_t uma_zcreate(const char *name, size_t size, uma_ctor ctor,
            uma_dtor dtor, uma_init uminit, uma_fini fini,
            int align, u_int32_t flags)
{
    return NULL;
}


uma_zone_t uma_zsecond_create(char *name, uma_ctor ctor, uma_dtor dtor,
            uma_init zinit, uma_fini zfini, uma_zone_t master)
{
    return NULL;
}


void uma_zone_set_allocf(uma_zone_t zone, uma_alloc allocf)
{

}

int uma_zone_exhausted(uma_zone_t zone)
{
    return 1;
}

int uma_zone_exhausted_nolock(uma_zone_t zone)
{
    return 1;
}

u_int32_t *uma_find_refcnt(uma_zone_t zone, void *item)
{
    return NULL;
}