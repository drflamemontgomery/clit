#ifndef CLT_H
#define CLT_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "clt-internal.h"

typedef void (*clt_test_cb)(void);
typedef struct {
  clt_test_cb cb;
  const char *name;
  const char *description;
  const char *file;

  int flags;
} clt_test_info_t;

#define CLT_SHOULD_FAIL 1
#define CLT_SHOULD_IGNORE 2

#define CLT_DATA CLT_DATA_SECTION
#define CLT_HELPER CLT_TEXT_SECTION
#define CLT_TEST(NAME) CLT_TEXT_SECTION void clt_test_##NAME ()

#define CLT_INCLUDE_MODULE(MODULE)                                            \
  extern const clt_test_info_t clt_module_##MODULE[] CLT_MODULE_SECTION;                            \
  extern const size_t clt_module_##MODULE##_len CLT_MODULE_SECTION

#define CLT_MODULE(MODULE, ...)                                               \
  const clt_test_info_t clt_module_##MODULE[] CLT_MODULE_SECTION = {__VA_ARGS__};                   \
  const size_t clt_module_##MODULE##_len CLT_MODULE_SECTION =                                        \
      sizeof(clt_module_##MODULE) / sizeof(*clt_module_##MODULE)

#define CLT_REGISTER(NAME, DESCRIPTION, ...)                                  \
  (clt_test_info_t) {                                                         \
    .cb = clt_test_##NAME, .name = #NAME, .description = DESCRIPTION,       \
    .file = __FILE__, .flags = 0 __VA_OPT__(|) __VA_ARGS__,                    \
  }

#endif
