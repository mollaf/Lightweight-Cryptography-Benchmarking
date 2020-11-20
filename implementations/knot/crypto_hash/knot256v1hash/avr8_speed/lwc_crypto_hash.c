#include "lwc_crypto_hash.h"
#include "api.h"


hash_ctx lwc_hash_ctx = {
	"knot256v1hash",
	"avr8_speed",
	CRYPTO_BYTES,
	crypto_hash,
};

