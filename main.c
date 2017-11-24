//
//  main.c
//  sifresana2
//
//  Created by Matijs Lode on 24.11.17.
//  Copyright © 2017. g. Matijs Lode. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    if (argc==0) {
        printf("\nLietošana [input file] [output file] [key] \n");
        return 1;
    }
    if (argc !=4) {
        printf("\nKļūda, nepareizs arguments\n");
        return 1;
    }
    FILE* in_file;
    FILE* out_file;
    int keyCount = 0, enryptByte;
    in_file = fopen(argv[1], "rb");
    out_file = fopen(argv[2], "wb");
    if (in_file == NULL || out_file == NULL)
        perror ("Kļūda");
    else {
        printf("Loading...");
        while ((enryptByte = fgetc(in_file)) != EOF) {
            printf(".");
            fputc(enryptByte ^ argv[3][keyCount], out_file);
            keyCount++;
            if (keyCount == strlen(argv[3])) {
                keyCount = 0;
            }
        }
        printf("Done!");
        return (0);
    }
}
