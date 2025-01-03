#include <stdio.h>

#include "../include/ioc.h"

int main()
{
    see_resolve_query_t q = {
	"IoC.Strategy"
    };
    see_resolve(&q);

    printf("%s\n", (char *) q.ctx);

    return 0;
}
