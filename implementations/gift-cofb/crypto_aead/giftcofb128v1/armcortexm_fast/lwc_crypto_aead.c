#include "lwc_crypto_aead.h"
#include "api.h"


aead_ctx lwc_aead_cipher = {
	"giftcofb128v1",
	"armcortexm_fast",
	CRYPTO_KEYBYTES,
	CRYPTO_NPUBBYTES,
	CRYPTO_ABYTES,
	crypto_aead_encrypt,
	crypto_aead_decrypt
};

