#include <stdio.h>
#include <string.h>
#include "BruteForce.h"

#define MAX_BUFFER 512

int main(int argc, char **argv) {
    char *FilePath;
    FILE *fp;

    char Text[MAX_BUFFER];
    char *Pattern;
    int PatternSize = 0;
    int Line = 0;

    if (argc < 3) {
        printf("Usage: %s <FilePath> <Pattern>\n", argv[0]);
        return 1;
    }

    FilePath = argv[1]; // 본문이 들어 있는 파일의 경로
    Pattern = argv[2]; // 패턴 문자열

    PatternSize = strlen(Pattern);

    if ((fp = fopen(FilePath, "r")) == NULL) {
        printf("Cannot open file:%s\n", FilePath);
        return 1;
    }

    // 파일을 처음부터 끝까지 한 줄씩 읽으며 BruteForce( ) 함수 호출
    while (fgets(Text, MAX_BUFFER, fp) != NULL) {
        int Position =
            BruteForce(Text, strlen(Text), 0, Pattern, PatternSize);

        Line++;

        if (Position >= 0) {
            printf("line:%d, column:%d : %s", Line, Position + 1, Text);
        }
    }

    fclose(fp);

    return 0;
}
