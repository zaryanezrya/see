#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FAT POINTERS

typedef void* var;

struct Header {
  var type;
};

// IOC

typedef void (*ioc_strategy_t)(var ctx);
typedef void (*ioc_resolve_strategy_t)(const char* key, var ctx);

struct ioc_dependency {
  const char* key;
  ioc_strategy_t strategy;
};

void get_42(var ctx){
  *(int*)ctx = 42;
}

const struct ioc_dependency dependencies[] = {
  {"get_42", get_42}
};

void ioc_default_resolve_strategy(const char* key, var ctx){
  for (int i = 0; i < (sizeof(dependencies)/sizeof(struct ioc_dependency)); i++) {
    if(strcmp(key, dependencies[i].key) == 0){
      dependencies[i].strategy(ctx);
      return;
    }
  }
}

ioc_resolve_strategy_t ioc_resolve_strategy = ioc_default_resolve_strategy;

void resolve(const char* key, var ctx) {
  ioc_resolve_strategy(key, ctx);
}


// UTILS
#define asd resolve("new", args);


// ---
typedef void (*callable)(var ctx);


typedef struct {
  var ctx;
  callable enter;
  callable action;
  callable exit;
} managed_t;

void call_managed(managed_t *managed) {
  if (managed->enter) {
    managed->enter(managed->ctx);
  }
  if (managed->action) {
    managed->action(managed->ctx);
  }
  if (managed->exit) {
    managed->exit(managed->ctx);
  }
}

// ---

typedef struct {
  int value;
} managed_sum_ctx_t;

void enter_sum(var ctx) { ((managed_sum_ctx_t *)ctx)->value += 1; }

void action_sum(var ctx) { ((managed_sum_ctx_t *)ctx)->value += 1; }

void exit_sum(var ctx) { ((managed_sum_ctx_t *)ctx)->value += 1; }

int call_managed_sum(int initial_value) {
  managed_sum_ctx_t ctx = {.value = initial_value};

  managed_t managed = {
      .ctx = &ctx, .enter = enter_sum, .action = action_sum, .exit = exit_sum};
  call_managed(&managed);
  return ctx.value;
}

// --

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }

  printf("%i\n", call_managed_sum(42));

  int res = 0;
  resolve("get_42", &res);
  printf("%i", res);
  printf("\n\n\n");
  asd;

  return 0;
}
