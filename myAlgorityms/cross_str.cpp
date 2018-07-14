#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static bool isInterleave(char* s1, char* s2, char* s3)
{
    int i, j;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);

    if (len1 + len2 != len3) {
        return false;
    }

    //初始化二维数组
    bool *table = (bool *)malloc((len1 + 1) * (len2 + 1) * sizeof(bool));
    //分配dp数组
    bool **dp = (bool **)malloc((len1 + 1) * sizeof(bool *));

    //将dp指向table
    for (i = 0; i < len1 + 1; i++) {
        dp[i] = &table[i * (len2 + 1)];
    }

    //初始化    
    dp[0][0] = true;

    //初始化边缘
    for (i = 1; i < len1 + 1; i++) {
        dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    }

    //初始化边缘
    for (i = 1; i < len2 + 1; i++) {
        dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
    }

    for (i = 1; i < len1 + 1; i++) {
        for (j = 1; j < len2 + 1; j++) {
            bool up = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
            bool left = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            //查看2个方向是否有一样的字母
            dp[i][j] = up || left;
        }
    }

    return dp[len1][len2];
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        fprintf(stderr, "Usage: ./test s1 s2 s3\n");
        exit(-1);
    }
    printf("%s\n", isInterleave(argv[1], argv[2], argv[3]) ? "true" : "false");
    return 0;
}