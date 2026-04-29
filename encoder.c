#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *base64_encoder(const unsigned char *text, size_t input_n);

const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main(int argc, char *argv[]) {
    
    if(argc != 2) {
        printf("Usage: ./%s <text_to_encode>\n", argv[0]);
        return 1;
    }

    const char *text = argv[1];

    char *encoded_text = base64_encoder((const unsigned char*)text, strlen(text));

    printf("Original text: %s\n", argv[1]);
    printf("Encoded text : %s\n", encoded_text);

    free(encoded_text);

    return 0;
}

char *base64_encoder(const unsigned char *text, size_t input_n) {
    size_t output_n = 4 * ((input_n + 2) / 3);

    char *encoded_data = malloc(output_n + 1);
    
    if (encoded_data == NULL) {
         return NULL;
    }

    for (size_t i = 0, j = 0; i < input_n; i += 3, j += 4) {
        unsigned char b1 = text[i];
        unsigned char b2 = (i + 1 < input_n) ? text[i + 1] : 0;
        unsigned char b3 = (i + 2 < input_n) ? text[i + 2] : 0;

        encoded_data[j] = base64_chars[(b1 >> 2) & 0x3F];
        encoded_data[j + 1] = base64_chars[((b1 & 0x03) << 4) | ((b2 >> 4) & 0x0F)];
        encoded_data[j + 2] = base64_chars[((b2 & 0x0F) << 2) | ((b3 >> 6) & 0x03)];
        encoded_data[j + 3] = base64_chars[b3 & 0x3F];
    }

    if (input_n % 3 == 1) {
        encoded_data[output_n - 1] = '=';
        encoded_data[output_n - 2] = '=';
    } else if (input_n % 3 == 2) {
        encoded_data[output_n - 1] = '=';
    }

    encoded_data[output_n] = '\0';
    return encoded_data;
}