#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp;
    FILE* fpOut;

    bool err = fopen_s(&fp, "AiPic.bmp", "rb");
    err = fopen_s(&fpOut, "AiPic_bin.bmp", "wb");
    if (err != 0) {
        printf("Error opening input file!\n");
        return 1;
    }
   
    unsigned char head[54];

    fread(head, sizeof(unsigned char), 54, fp);
    fwrite(head, sizeof(unsigned char), 54, fpOut);

    const int threshold = 128;

    unsigned char row[3072];

    for (int i = 0; i < 1024; i++) {
        fread(row, sizeof(unsigned char), 3072, fp);

        for (int j = 0; j < 1024; j++) {
            int index = j * 3;
            unsigned char B = row[index];
            unsigned char G = row[index + 1];
            unsigned char R = row[index + 2];

            int gray = (int)(0.299 * R + 0.587 * G + 0.114 * B);
            unsigned char binValue = (gray >= threshold) ? 255 : 0;
            row[index] = binValue;
            row[index + 1] = binValue;
            row[index + 2] = binValue;
        }

        fwrite(row, sizeof(unsigned char), 3072, fpOut);
    }

    printf("Binarization completed!\n");
    return 0;
}
