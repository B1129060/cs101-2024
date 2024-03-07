#include <stdio.h>

int main()
{
    FILE* fp;
    fp = fopen("a.bin", "wb+");
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(b), 1, fp);
    fwrite(c, sizeof(c), 1, fp);
    fseek(fp, 0, SEEK_SET);
    fread(a, sizeof(int), 3, fp);
    fread(b, sizeof(b), 1, fp);
    fread(c, sizeof(c), 1, fp);
    for(int i = 0; i < 3; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i = 0; i < 3; i++){
        printf("%c ", b[i]);
    }
    printf("\n");
    for(int i = 0; i < 3; i++){
        printf("%f ", c[i]);
    }
    fclose(fp);
    return 0;
}
