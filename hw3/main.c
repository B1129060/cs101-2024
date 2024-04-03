#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int receipt_id;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[5][7];
    char filename[17];
} lotto_record_t;

void lotteryNumberGenerator(int n[5][7], int num);
void lotteryGenerator(const lotto_record_t* , int);
void output(const lotto_record_t*);
void checkLottery();

int main() {
    int num = 3;
    int lottery[5][7] = { 0 };
    lotto_record_t lotto = {
        .receipt_id = 0,
        .receipt_price = 0,
    };
    FILE* fp;
    printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩：");
    scanf("%d", &num);
    if (!num) {
        checkLottery();
        return 0;
    }
   
    if ((fp = fopen("record.bin", "rb+")) == NULL) {
        lotto.receipt_id = 1;
        fp = fopen("record.bin", "wb+");
    }
    else {
        fseek(fp, -(4), SEEK_END);
        fread(&lotto.receipt_id, sizeof(int), 1, fp);
        lotto.receipt_id++;
    }
    lotteryGenerator(&lotto, num);
    fwrite(&lotto.receipt_id, sizeof(int), 1, fp);
    fwrite(&lotto.receipt_price, sizeof(int), 1, fp);
    fwrite(lotto.receipt_time, sizeof(char), 24, fp);
    fwrite(&lotto.lotto_set, sizeof(int), num * 7, fp);
    fwrite(&lotto.receipt_id, sizeof(int), 1, fp);
    fclose(fp);

    output(&lotto);
    
    printf("已為您購買的%d組樂透彩組合輸出至 %s", num, lotto.filename);
    return 0;
}

void lotteryNumberGenerator(int n[5][7], int num) {
    srand(1);
    char numBoard[70] = { 0 };
    for (int i = 0; i < num; i++) {
        memset(numBoard, 0, 70);
        for (int j = 0; j < 7; j++) {
            int Rand = (rand() % 69) + 1;
            while (numBoard[Rand]) {
                Rand = (rand() % 69) + 1;
            }
            numBoard[Rand]++;
            n[i][j] = Rand;
        }
    }
}

void lotteryGenerator(lotto_record_t *lotto, int num){
    lotto->receipt_price = num * 100;
    time_t curtime;
    time(&curtime);
    strcpy(lotto->receipt_time, ctime(&curtime));
    strncpy(&lotto->receipt_time[8], &lotto->receipt_time[9], 15);
    lotto->receipt_time[23] = '\0';
    strcpy(lotto->filename, "lotto[00000].txt\0");
    if (!(lotto->receipt_id / 10)) {
        lotto->filename[10] = lotto->receipt_id + '0';
    }
    else {
        int i = 10;
        int j = lotto->receipt_id;
        do 
        {
            lotto->filename[i] = (j % 10) - '0';
            i--;
            j /= 10;
        } while (j);
    }
    srand(time(0));
    char numBoard[70] = { 0 };
    for (int i = 0; i < num; i++) {
        memset(numBoard, 0, 70);
        for (int j = 0; j < 7; j++) {
            int Rand = (rand() % 69) + 1;
            while (numBoard[Rand]) {
                Rand = (rand() % 69) + 1;
            }
            numBoard[Rand]++;
            lotto->lotto_set[i][j] = Rand;
        }
    }
}

void output(lotto_record_t *lotto){
    FILE* fp;
    fp = fopen(lotto->filename, "w+");
    fprintf(fp, "======== lotto649 =========\n");
    fprintf(fp, "=======+ NO.%05d +========\n", lotto->receipt_id);
    fprintf(fp, "= %s =\n", lotto->receipt_time);
    int num = lotto->receipt_price / 100;
    for (int i = 1; i <= num; i++) {
        fprintf(fp, "[%d]: %02d %02d %02d %02d %02d %02d %02d\n", i, lotto->lotto_set[i - 1][0], lotto->lotto_set[i - 1][1], lotto->lotto_set[i - 1][2], lotto->lotto_set[i - 1][3], lotto->lotto_set[i - 1][4], lotto->lotto_set[i - 1][5], lotto->lotto_set[i - 1][6]);
    }
    for (int i = num + 1; i <= 5; i++) {
        fprintf(fp, "[%d]: __ __ __ __ __ __ __\n", i);
    }
    fprintf(fp, "======== csie@CGU =========\n");
    fclose(fp);
}

void checkLottery(){
    int num[3] = { -1, -1, -1 };
    char c = 0;
    int n = 0;
    int a = 0;
    char t[32] = { "" };
    int set[7] = { 0 };
    int fend = 0;
    printf("請輸入中獎號碼 (最多三個)：");
    do {
        scanf("%d", &num[n]);
        n++;
        c = fgetc(stdin);
    } while (c != '\n');
    
    FILE* fp;
    fp = fopen("record.bin", "r+"); 
    fseek(fp, 0, SEEK_END);
    fend = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    int i = 0;
    printf("以下為中獎彩券：\n");

    while (ftell(fp) < fend) { 
        i = 0;
        fread(&n, sizeof(int), 1, fp);
        fread(&a, sizeof(int), 1, fp); 
        fread(t, sizeof(char), 24, fp);
        for (int j= 0; j < (a / 100); j++) {
            fread(&set[0], 7 * sizeof(int), 1, fp);
            for (int k = 0; k < 7; k++) {
                if (set[k] == num[0] || set[k] == num[1] || set[k] == num[2]) {
                    if (!i) {
                        printf("彩券 No. %d\n", n);
                        printf("售出時間：%s\n", t);
                        i++;
                    }
                    printf("號碼：");
                    for (int l = 0; l < 7; l++) {
                        printf("%02d ", set[l]);
                    }
                    printf("\n");
                    break;
                }
            }
            
        }
        fread(&n, sizeof(int), 1, fp);
    }
    return 0;
}
