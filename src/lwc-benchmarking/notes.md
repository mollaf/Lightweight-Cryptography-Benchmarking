
- https://askubuntu.com/questions/689760/how-can-i-run-a-command-at-the-background-without-ampersand
- https://mywiki.wooledge.org/BashSheet#:~:text=An%20ampersand%20does%20the%20same,for%20the%20former%20to%20end.
- https://en.wikipedia.org/wiki/Udev
- 


- https://docs.platformio.org/en/latest/tutorials/core/unit_testing_blink.html
- https://docs.platformio.org/en/latest/faq.html#faq-udev-rules
- https://docs.platformio.org/en/latest/core/installation.html#id30
- https://docs.platformio.org/en/latest/core/installation.html#piocore-install-shell-commands
- https://community.platformio.org/t/error-25-inappropriate-ioctl-for-device/17439
- https://docs.platformio.org/en/latest/core/quickstart.html


------------

- https://www.cryptolux.org/index.php/FELICS
- https://www.cryptolux.org/index.php/FELICS_Block_Ciphers_Brief_Results
- https://csrc.nist.gov/Projects/lightweight-cryptography/round-2-candidates
- https://csrc.nist.gov/CSRC/media/Projects/Lightweight-Cryptography/documents/final-lwc-submission-requirements-august2018.pdf
- https://rweather.github.io/lightweight-crypto/



--- 

```bash
./build.sh --target uno --submission "ace" --primary --aead --experiment "timing" --impl "ref" --overwrite

# submissions       : ace ascon comet drygascon elephant estate forkae gift-cofb gimli grain128aead hyena isap knot lotus-locus mixfeed orange oribatida photon-beetle pyjamask _reference_ romulus saeaes saturnin skinny sparkle spix spoc spook subterranean sundae-gift tinyjambu wage xoodyak 

# gift-cofb lotus-locus photon-beetle sundae-gift

# mkrzero, uno, nano33ble, nano_every, nodemcuv2, chipkit_mx3


find . -name "*AEAD*-out.txt" | while read fn; do echo $fn, $(cat $fn | grep "Flash:") | sed 's/Flash: \[=* *\]//' | sed 's/(used/,/'; done > size-results.csv
```



algorithms

```bash
find -mindepth 4 -maxdepth 4 -type d | sort | while read fn; do echo $fn/$(cat $(dirname $fn)/primary 2> /dev/null; if [[ $? -eq "0" ]]; then echo "true"; fi); done > algorithms.csv

cat algorithms.csv | awk -F'/' '{ print "insert into algorithms (submission, algorithm, familiy, implementation, is_primary) value (\"" $2"\", \""$3"\", \""$4"\", \""$5"\", \""$6"\");" }' > algorithms.sql
```

---




- small computing devices 
    - RFID tags, industrial controllers, sensor nodes and smart cards
    - a wide range of new **security** and **privacy concerns**
    - in many conventional cryptographic standards,, the tradeoff between and **security**, **performance** and **resource** requirements was optimized for **deskotp and server environment** 
    - tailored for resource-contrained devices
    - 2013, NIST initiated a initiated a lightweight cryptograpy project
    - 2015, NIST held firt Lightweight Cryptography Workshop
    - 2016, second workshop
    - 2017, NIST published NISTIR 8114 Report on Lightweight Cryptography and
        - announced that decided to create a portfolio of lightweight alogtithms through and open process.
    - 2017, NIST published the draft whitpaper Profiles for the Lightweight Cryptography
        - portföye ilk dahil edilmek üzere önerilen fonksiyonaliteler hakkında geri bildirim istemek.
    - 2019, Jan, submission paketlerinin NIST tarafından teslim alınması
    - 2019, Feb, NIST tarafından alınan paketlerin tamlık açısından gözden geçirilmesi
    - A complete written specification of the algorithms 
        - **shall** be included, consisting of all necessary **mathematical operations**, **equations**, **tables**, and **diagrams** that are needed to implement the algorithms. 
        - **shall** also include a **design rationale**, and an explanation for all the **important design decisions** (with respect to **targeted constrained devices**) that have been made. 
        - **shall** explain the provenance of any **constants** or tables used in the algorithm.
    - For algorithms that have **tunable parameters**, the submission document **shall** specify **concrete values** for **these parameters**. 
        - The submission may **specify several parameter** sets that allow the selection of a **range of possible security/performance tradeoffs**. 
        - The submitter **shall** provide an analysis of how the **security** and performance of the algorithms depend on these **parameters**.
    - The submission package 
        - **shall** include a statement of the **expected security strength** of **each variant** of the submission, along with a supporting rationale. 
        - **shall** include a statement that summarizes the **known cryptanalytic attacks** on the variants of the submission, and provide estimates of the **complexity of these attacks**.
        - **shall** include a statement that lists and describes the **advantages and limitations of the cryptosystem** in terms of **security**, **performance**, and **implementation costs** (e.g., **estimates for required RAM, ROM, or gate equivalents**).
    - It **shall not contain any optimizations** that will **make it more difficult to understand the details of the algorithm**.
    - The source code **shall** be **accompanied by a set of test vectors** that will be generated by the submitter. 
    - Information on how the **source code and the test vectors should be compiled together** to form the source code package can be found in Section 3.5.
    - The following requirements have some similarities with the call of 
        - **Competition for Authenticated Encryption: Security, Applicability, and Robustness (CAESAR)** (https://competitions.cr.yp.to/caesar-call.html) and 
        - **eBACS: ECRYPT Benchmarking of Cryptographic Systems** (https://bench.cr.yp.to/), for which the unified **SUPERCOP benchmarking suite** was developed. 
- AEAD algorithm should be ensure
    - the **confidentiality of the plaintexts** (under **adaptive chosen-plaintext attacks**)
    - the **integrity of the ciphertexts** (under **adaptive forgery attempts**)
    - The four inputs are a 
        - variable-length **plaintext**, 
        - variable-length **associated data**, 
        - fixed-length **nonce**, and 
        - fixed-length **key**.
    - The output is a variable-length **ciphertext**.

- **Authenticated decryption**, also known as **decryption-verification**, **shall** be supported: it shall be possible to **recover the plaintext** from a **valid ciphertext** (i.e., a **ciphertext** that corresponds to the **plaintext** for a given **associated data**, **nonce**, and **key**), given **associated data**, **nonce** and **key**. 

    - Plaintext **shall not** be returned by the **decryption-verification process** if the **ciphertext is invalid**.




- AEAD algorithms are expected to maintain security as long as the **nonce is unique (not repeated under the same key)**. 

- Any **security loss** when the **nonce is not unique shall be documented**, and algorithms that do not lose all security with repeated nonces may advertise this as a feature.



- An AEAD algorithm **shall not specify key lengths that are smaller than 128 bits**. 

- **Cryptanalytic attacks** on the AEAD algorithm **shall require at least $2^{112}$ computations** on a **classical computer** in a **single-key setting**. 

- If a **key size larger than 128 bits** is supported, it is recommended that at least one recommended parameter set has a key size of 256 bits, and that its resistance against **cryptanalytical attacks is at least $2^{224}$ computations** on a **classical computer** in a **single-key setting**.



- AEAD algorithms shall **accept all byte-string inputs** that satisfy the input length requirements. 

- The family **shall** include one *primary* member that has a key length of at least 128 bits, a **nonce length** of at least 96 bits, and a tag length of at least 64 bits. 

- The **limits on the input sizes** (**plaintext**, **associated data**, and the **amount of data** that can be processed under one **key**) for this member **shall not** be **smaller than $2^{50}-1$ bytes**.



- A **hash function** is a function with **one byte-string input** and **one byte-string output**. 
- The **input** is a **variable-length message**. The **output** is a **fixed-length hash value**.

- It should be **computationally infeasible to find a collision or a (second) preimage** for this hash function. 
- The hash function should also be **resistant against length extension attacks**.
    - For example, if part of the message is a secret key that is unknown to the attacker, it should be infeasible for this attacker to **construct a hash value corresponding to a different message that contains the same secret key**. 


- The submitters are allowed to submit a **family of hash functions**, where members of the family may vary in **external parameters** (e.g., **maximum message length**, **output size**), or in **internal parameters** (e.g., **number of rounds**, or **state size**). 
- The **family** **shall** include at most **10 members**.




- **Cryptanalytic attacks** on the hash function **shall** require **at least $2^{112}$ computations** on a - **classical computer**. 
- The hash function **shall not** specify **output sizes** that are **smaller than 256 bits**.
- Hash functions **shall** **accept all byte-string inputs** that meet the specified maximum length of messages. 
- Submissions shall include justification for any length limits.
- The family **shall** include **one primary member** that has an **output size of at least 256 bits**. 
- The limit on the message size for this member **shall not** be **smaller than $2^{50} - 1$ bytes**.

--

- aead 
    - `api.h`
        ```c
        #define CRYPTO_KEYBYTES 32
        #define CRYPTO_NSECBYTES 0
        #define CRYPTO_NPUBBYTES 12
        #define CRYPTO_ABYTES 16
        #define CRYPTO_NOOVERLAP 1
        ```
        - the **key** is **32 bytes**, 
        - the **nonce** is **12 bytes**, and that 
        - the **ciphertext** is at most **16 bytes** longer than the **plaintext**.
            - A **typical AEAD algorithm** has a **constant gap between plaintext length and ciphertext length**,      
            - but the requirement here is to have a **constant limit on the gap**.
        -  `CRYPTO_NOOVERLAP` is an **optional definition in SUPERCOP API** and indicates whether the **implementation can handle overlapping input and output buffers**.
            - the implementation is **not expected** to **handle overlapping input and output buffers**
            - if `CRYPTO_NOOVERLAP` is **not defined**, the SUPERCOP framework assumes that **inputs and outputs can overlap**, and returns an error if this behavior is not supported.
    -  `encrypt.c`
        ```c
        #include "crypto_aead.h"
        
        int crypto_aead_encrypt(
            unsigned char *c,unsigned long long *clen,
            const unsigned char *m,unsigned long long mlen,
            const unsigned char *ad,unsigned long long adlen,
            const unsigned char *nsec,
            const unsigned char *npub,
            const unsigned char *k
        )
        {
            // ...
            // ... the code for the cipher implementation goes here,
            // ... generating a ciphertext c[0],c[1],...,c[*clen-1]
            // ... from a plaintext m[0],m[1],...,m[mlen-1]
            // ... and associated data ad[0],ad[1],...,ad[adlen-1]
            // ... and nonce npub[0],npub[1],...
            // ... and secret key k[0],k[1],...
            // ... the implementation shall not use nsec
            // ...
            return 0;
        }

        int crypto_aead_decrypt(
            unsigned char *m,unsigned long long *mlen,
            unsigned char *nsec,
            const unsigned char *c,unsigned long long clen,
            const unsigned char *ad,unsigned long long adlen,
            const unsigned char *npub,
            const unsigned char *k
        )
        {
            // ...
            // ... the code for the AEAD implementation goes here,
            // ... generating a plaintext m[0],m[1],...,m[*mlen-1]
            // ... and secret message number nsec[0],nsec[1],...
            // ... from a ciphertext c[0],c[1],...,c[clen-1]
            // ... and associated data ad[0],ad[1],...,ad[adlen-1]
            // ... and nonce number npub[0],npub[1],...
            // ... and secret key k[0],k[1],...
            // ...
            return 0;
        }
        ```

        - The outputs of `crypto_aead_encrypt` and `crypto_aead_decrypt` 
            - **shall** be **determined entirely by the inputs listed above** (except that the parameter **`nsec` is kept for compatibility with SUPERCOP and will not be used**) and 
            - **shall not** be affected by **any randomness or other hidden inputs**.
        -  The `crypto_aead_decrypt` function shall **return -1 if the ciphertext is not valid**.
        - The `crypto_aead_encrypt` and `crypto_aead_decrypt` functions may **return other negative numbers to indicate other failures** (e.g., **memory-allocation failures**).
- hash
    - `api.h`
        ```c
        #define CRYPTO_BYTES 32
        ```
    - `hash.c`
        ```c
        #include "crypto_hash.h"4
        
        int crypto_hash(
            unsigned char *out,
            const unsigned char *in,
            unsigned long long inlen
        )
        {
            // ...
            // ... the code for the hash function implementation goes here
            // ... generating a hash value out[0],out[1],...,out[CRYPTO_BYTES-1]
            // ... from a message in[0],in[1],...,in[in-1]
            // ...
            return0;
        }
        ```

        - To **ensure compatibility with the SUPERCOP**, the implementation of `crypto_hash` **shall handle overlapping input and output buffers**.
        - The output of crypto_hash 
            - **shall be determined entirely by the message input** and 
            - **shall not be affected by any randomness or other hidden inputs**.




----




