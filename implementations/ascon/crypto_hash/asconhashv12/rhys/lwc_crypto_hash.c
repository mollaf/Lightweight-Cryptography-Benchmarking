#include "lwc_crypto_hash.h"
#include "api.h"
#include "ascon128.h"

hash_ctx lwc_hash_ctx = {
	"asconhashv12",
	"ryhs",
	CRYPTO_BYTES,
	ascon_hash,
};

