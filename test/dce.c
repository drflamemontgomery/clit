#if defined(CLT_TEST_ENABLE) && defined(CLT_DCE_TEST) && CLT_DCE_TEST
#undef CLT_TEST_ENABLE
#endif

#include "clt-assert.h"
#include "clt.h"

static CLT_TEST(dce_remove) { CLT_ASSERT(false); }

CLT_MODULE(dce,
           CLT_REGISTER(dce_remove, "A test that should be removed by dce"));
