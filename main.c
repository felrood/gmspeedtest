#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <time.h>
#include "gm.h"

#define NUM 1000

int main() {
	
	gm_pubkey_t *pubkey;
	gm_prvkey_t *privkey;
	gm_ciphertext_t ciphertext1[NUM];

	printf("Generating 2048 bit key\n");

	// Generate 2048 bit keys
	gm_keygen(2048, &pubkey, &privkey, &gm_get_rand_devurandom);

	printf("Allocating memory\n");

	size_t i = 0;
	for(i=0; i<NUM; i++) {
		mpz_init(ciphertext1[i].c);
	}


	// Do the encryptions
	printf("Doing %d encryptions\n", NUM);
	clock_t start = clock(), diff;

	for(i=0; i<NUM; i++) {
		gm_enc_bit(&ciphertext1[i], pubkey, (i % 2), &gm_get_rand_devurandom);
	}

	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Done %d encryptions in %d miliseconds\n", NUM, msec);

	printf("Doing %d decryptions\n", NUM);
	start = clock();

	int res = -1;
	for(i=0; i<NUM; i++) {
		res = gm_dec_bit(privkey, &ciphertext1[i]);
		if (res != (i%2)) {
			printf("Result: %d (ERROR)\n", res);
		}
	}

	diff = clock() - start;
	msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Done %d decryptions in %d miliseconds\n", NUM, msec);
	return 0;
}