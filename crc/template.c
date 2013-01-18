/* 
 * INSTRUCTIONS
 *
 * Refer to INSTRUCTIONS.txt for full instructions and examples.
 */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>

#include <assert.h>
#include <ctype.h>
#include <err.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "crc32.h"

#define CPU_CORE_NUM 4
#define CPU_CORE_NUM_MAX 16

int get_cpu_core_num() {
    return CPU_CORE_NUM; // hard code the cpu number function
}

char input_end = false;
pthread_mutex_t input_m;
pthread_mutex_t output_m;

int get_stdin_input(char *file_name) {

    if (input_end == 1) return false;

    if(fgets(file_name, BUFSIZ, stdin) == NULL) {
        input_end = true;
        return false;
    }

    size_t n = strlen(file_name);
    if (n > 0) file_name[n-1] = '\0';  // remove the new line in string

    return true;
}

void *crc_fun(void *a) {

    char file_name[BUFSIZ];
    char buff[BUFSIZ];
    char rc;
    uint32_t crc = ~0U;
    int n;

    while(true) {
        // Get file name from input
        pthread_mutex_lock(&input_m);
        rc = get_stdin_input(file_name);
        pthread_mutex_unlock(&input_m);
        if (rc == false) return NULL;

        // Open the file
        FILE *fp;
        fp = fopen(file_name, "rb");
        if (fp == NULL) continue;

        // Read a chunk of file and caculate the CRC
        while ((n = fread(buff, 1, BUFSIZ, fp)) > 0) {
            crc = crc32_raw(buff, n, crc);
        }
        fclose(fp);

        // Output the result
        pthread_mutex_lock(&output_m);
        printf("%s: %x\n", file_name, crc);
        pthread_mutex_unlock(&output_m);
    }
    return NULL;
}

int
main(void)
{
    pthread_t th[CPU_CORE_NUM_MAX];

    pthread_mutex_init(&input_m, NULL);
    pthread_mutex_init(&output_m, NULL);

    int cpu_num = get_cpu_core_num();
    for (int i = 0; i < cpu_num; i++)
        pthread_create(th+i, NULL, crc_fun, NULL);

    void *status;
    for (int i = 0; i < cpu_num; i++)
        pthread_join(th[i], &status);

    return 0;
}

