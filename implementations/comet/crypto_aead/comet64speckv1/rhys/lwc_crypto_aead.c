#include "lwc_crypto_aead.h"
#include "api.h"
#include "comet.h"


aead_ctx lwc_aead_cipher = {
	"comet64speckv1",
	"rhys",
	CRYPTO_KEYBYTES,
	CRYPTO_NPUBBYTES,
	CRYPTO_ABYTES,
	comet_64_speck_aead_encrypt,
	comet_64_speck_aead_decrypt
};

