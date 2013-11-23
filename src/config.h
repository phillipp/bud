#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_

#include <stdint.h>

#include "openssl/ssl.h"
#include "parson.h"

#include "common.h"
#include "error.h"

typedef struct bud_context_s bud_context_t;
typedef struct bud_config_s bud_config_t;

struct bud_context_s {
  /* From config file */
  const char* hostname;
  const char* cert_file;
  const char* key_file;

  /* Various */
  SSL_CTX* ctx;
};

struct bud_config_s {
  /* Internal, just to keep stuff allocated */
  JSON_Value* json;

  /* Options from config file */
  uint16_t port;
  const char* host;

  int context_count;
  bud_context_t contexts[1];
};

bud_config_t* bud_config_cli_load(int argc, char** argv, bud_error_t* err);
bud_config_t* bud_config_load(const char* path, bud_error_t* err);
void bud_config_free(bud_config_t* config);

#endif  /* SRC_CONFIG_H_ */