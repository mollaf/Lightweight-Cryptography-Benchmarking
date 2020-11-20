#include "lwc_crypto_hash.h"
#include "api.h"
#include "saturnin.h"

hash_ctx lwc_hash_ctx = {
	"saturninhashv2",
	"ryhs",
	CRYPTO_BYTES,
	saturnin_hash,
};

