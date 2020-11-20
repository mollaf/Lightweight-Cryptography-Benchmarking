/*
 * Copyright (C) 2020 Southern Storm Software, Pty Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef LWCRYPTO_PYJAMASK_MASKED_H
#define LWCRYPTO_PYJAMASK_MASKED_H

#include "aead-common.h"

/**
 * \file pyjamask-masked.h
 * \brief Pyjamask authenticated encryption algorithm (masked version).
 *
 * Pyjamask AEAD is a family of authenticated encryption algorithms that are
 * built around the Pyjamask-128 and Pyjamask-96 block ciphers in OCB mode.
 * Pyjamask-128-AEAD has a 128-bit key, a 96-bit nonce, and a 128-bit
 * authentication tag.  Pyjamask-96-AEAD has a 128-bit key, a 64-bit nonce,
 * and a 96-bit authentication tag.
 *
 * References: https://pyjamask-cipher.github.io/
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Size of the key for Pyjamask-128-AEAD-Masked.
 */
#define PYJAMASK_128_MASKED_KEY_SIZE 16

/**
 * \brief Size of the authentication tag for Pyjamask-128-AEAD-Masked.
 */
#define PYJAMASK_128_MASKED_TAG_SIZE 16

/**
 * \brief Size of the nonce for Pyjamask-128-AEAD-Masked.
 */
#define PYJAMASK_128_MASKED_NONCE_SIZE 12

/**
 * \brief Size of the key for Pyjamask-96-AEAD-Masked-Masked.
 */
#define PYJAMASK_96_MASKED_KEY_SIZE 16

/**
 * \brief Size of the authentication tag for Pyjamask-96-AEAD-Masked.
 */
#define PYJAMASK_96_MASKED_TAG_SIZE 12

/**
 * \brief Size of the nonce for Pyjamask-96-AEAD-Masked.
 */
#define PYJAMASK_96_MASKED_NONCE_SIZE 8

/**
 * \brief Meta-information block for Pyjamask-128-AEAD-Masked cipher.
 */
extern aead_cipher_t const pyjamask_masked_128_cipher;

/**
 * \brief Meta-information block for Pyjamask-96-AEAD-Masked cipher.
 */
extern aead_cipher_t const pyjamask_masked_96_cipher;

/**
 * \brief Encrypts and authenticates a packet with Pyjamask-128-AEAD-Masked.
 *
 * \param c Buffer to receive the output.
 * \param clen On exit, set to the length of the output which includes
 * the ciphertext and the 16 byte authentication tag.
 * \param m Buffer that contains the plaintext message to encrypt.
 * \param mlen Length of the plaintext message in bytes.
 * \param ad Buffer that contains associated data to authenticate
 * along with the packet but which does not need to be encrypted.
 * \param adlen Length of the associated data in bytes.
 * \param nsec Secret nonce - not used by this algorithm.
 * \param npub Points to the public nonce for the packet which must
 * be 12 bytes in length.
 * \param k Points to the 16 bytes of the key to use to encrypt the packet.
 *
 * \return 0 on success, or a negative value if there was an error in
 * the parameters.
 *
 * \sa pyjamask_masked_128_aead_decrypt()
 */
int pyjamask_masked_128_aead_encrypt
    (unsigned char *c, unsigned long long *clen,
     const unsigned char *m, unsigned long long mlen,
     const unsigned char *ad, unsigned long long adlen,
     const unsigned char *nsec,
     const unsigned char *npub,
     const unsigned char *k);

/**
 * \brief Decrypts and authenticates a packet with Pyjamask-128-AEAD-Masked.
 *
 * \param m Buffer to receive the plaintext message on output.
 * \param mlen Receives the length of the plaintext message on output.
 * \param nsec Secret nonce - not used by this algorithm.
 * \param c Buffer that contains the ciphertext and authentication
 * tag to decrypt.
 * \param clen Length of the input data in bytes, which includes the
 * ciphertext and the 16 byte authentication tag.
 * \param ad Buffer that contains associated data to authenticate
 * along with the packet but which does not need to be encrypted.
 * \param adlen Length of the associated data in bytes.
 * \param npub Points to the public nonce for the packet which must
 * be 12 bytes in length.
 * \param k Points to the 16 bytes of the key to use to decrypt the packet.
 *
 * \return 0 on success, -1 if the authentication tag was incorrect,
 * or some other negative number if there was an error in the parameters.
 *
 * \sa pyjamask_masked_128_aead_encrypt()
 */
int pyjamask_masked_128_aead_decrypt
    (unsigned char *m, unsigned long long *mlen,
     unsigned char *nsec,
     const unsigned char *c, unsigned long long clen,
     const unsigned char *ad, unsigned long long adlen,
     const unsigned char *npub,
     const unsigned char *k);

/**
 * \brief Encrypts and authenticates a packet with Pyjamask-96-AEAD-Masked.
 *
 * \param c Buffer to receive the output.
 * \param clen On exit, set to the length of the output which includes
 * the ciphertext and the 12 byte authentication tag.
 * \param m Buffer that contains the plaintext message to encrypt.
 * \param mlen Length of the plaintext message in bytes.
 * \param ad Buffer that contains associated data to authenticate
 * along with the packet but which does not need to be encrypted.
 * \param adlen Length of the associated data in bytes.
 * \param nsec Secret nonce - not used by this algorithm.
 * \param npub Points to the public nonce for the packet which must
 * be 8 bytes in length.
 * \param k Points to the 16 bytes of the key to use to encrypt the packet.
 *
 * \return 0 on success, or a negative value if there was an error in
 * the parameters.
 *
 * \sa pyjamask_masked_96_aead_decrypt()
 */
int pyjamask_masked_96_aead_encrypt
    (unsigned char *c, unsigned long long *clen,
     const unsigned char *m, unsigned long long mlen,
     const unsigned char *ad, unsigned long long adlen,
     const unsigned char *nsec,
     const unsigned char *npub,
     const unsigned char *k);

/**
 * \brief Decrypts and authenticates a packet with Pyjamask-96-AEAD-Masked.
 *
 * \param m Buffer to receive the plaintext message on output.
 * \param mlen Receives the length of the plaintext message on output.
 * \param nsec Secret nonce - not used by this algorithm.
 * \param c Buffer that contains the ciphertext and authentication
 * tag to decrypt.
 * \param clen Length of the input data in bytes, which includes the
 * ciphertext and the 12 byte authentication tag.
 * \param ad Buffer that contains associated data to authenticate
 * along with the packet but which does not need to be encrypted.
 * \param adlen Length of the associated data in bytes.
 * \param npub Points to the public nonce for the packet which must
 * be 8 bytes in length.
 * \param k Points to the 16 bytes of the key to use to decrypt the packet.
 *
 * \return 0 on success, -1 if the authentication tag was incorrect,
 * or some other negative number if there was an error in the parameters.
 *
 * \sa pyjamask_masked_96_aead_encrypt()
 */
int pyjamask_masked_96_aead_decrypt
    (unsigned char *m, unsigned long long *mlen,
     unsigned char *nsec,
     const unsigned char *c, unsigned long long clen,
     const unsigned char *ad, unsigned long long adlen,
     const unsigned char *npub,
     const unsigned char *k);

#ifdef __cplusplus
}
#endif

#endif
