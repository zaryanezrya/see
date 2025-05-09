#ifndef SEE_IOC_H
#define SEE_IOC_H

void resolve(const char *key, void *ctx);

typedef void (*resolve_strategy_t)(const char* key, void *ctx);

#endif
