#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>


uint32_t readFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    uint32_t readValue;
    if (fread(&readValue, sizeof(uint32_t), 1, file)!=1){
		fprintf(stderr, "Error: Unable to read 4 bytes from file! %s\n", filename);	
		exit(EXIT_FAILURE);
	}
    
	fclose(file);

    return ( ntohl(readValue));
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *file1 = argv[1];
    const char *file2 = argv[2];

    uint32_t num1 = readFile(file1);
    uint32_t num2 = readFile(file2);

    uint32_t result = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, result, result);

    return EXIT_SUCCESS;
}

