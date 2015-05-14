#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <time.h>
#include <string.h>
#include "gm.h"

int main() {
	
	gm_pubkey_t *pubkey;
	gm_prvkey_t *privkey;

	printf("Generating 2048 bit key\n");

	// Generate 2048 bit keys
	gm_keygen(2048, &pubkey, &privkey, &gm_get_rand_devurandom);


	gm_ciphertext_t *encrypted = gm_enc_bit(0, pubkey, 1, gm_get_rand_devurandom);

	char *hex = gm_ciphertext_to_hex(encrypted);

	printf("Ciphertext is %ld bits long.\n", strlen(hex)*4);

	return 0;
}