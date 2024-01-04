#include <stdio.h>
#include <string.h>

// 定义最大数的位数
#define MAX_DIGITS 1000
int compare;
// 函数声明
void add(char num1[], char num2[], char result[]);
void subtract(char num1[], char num2[], char result[]);
void multiply(char num1[], char num2[], char result[]);

int main() {
    // 第一组测试
    char num1[] = "12345678901234567890";
    char num2[] = "98765432109876543210";
    char result_add[MAX_DIGITS + 1], result_sub[MAX_DIGITS + 1], result_mul[2 * MAX_DIGITS + 1];

    add(num1, num2, result_add);
    subtract(num1, num2, result_sub);
    multiply(num1, num2, result_mul);

    printf("Test Case 1:\n");
    printf("Addition: %s\n", result_add);
    if(compare>0)printf("Subtraction: %s\n", result_sub);
    else printf("Subtraction: -%s\n", result_sub);
    printf("Multiplication: %s\n", result_mul);
    printf("\n");

    // 第二组测试
    char num3[] = "11223344556677889900";
    char num4[] = "99887766554433221100";
    char result_add2[MAX_DIGITS + 1], result_sub2[MAX_DIGITS + 1], result_mul2[2 * MAX_DIGITS + 1];

    add(num3, num4, result_add2);
    subtract(num3, num4, result_sub2);
    multiply(num3, num4, result_mul2);

    printf("Test Case 2:\n");
    printf("Addition: %s\n", result_add2);
    if(compare>0)printf("Subtraction: %s\n", result_sub2);
    else printf("Subtraction: -%s\n", result_sub2);
    printf("Multiplication: %s\n", result_mul2);

    return 0;
}


// 实现大数相加
void add(char num1[], char num2[], char result[]) {

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0;

    int maxLen = len1 > len2 ? len1 : len2;
    int sum[maxLen + 1];

    for (int i = 0; i <= maxLen; i++)
        sum[i] = 0;

    for (int i = 0; i < maxLen; i++) {
        int digit1 = i < len1 ? num1[len1 - 1 - i] - '0' : 0;
        int digit2 = i < len2 ? num2[len2 - 1 - i] - '0' : 0;

        int temp = digit1 + digit2 + carry;
        sum[i] = temp % 10;
        carry = temp / 10;
    }

    // 处理最后的进位
    while (carry > 0) {
        sum[maxLen] = carry % 10;
        carry /= 10;
        maxLen++;
    }

    // 将结果反向存储到result数组中
    int j = 0;
    for (int i = maxLen - 1; i >= 0; i--)
        result[j++] = sum[i] + '0';

    result[j] = '\0';
}




void subtract(char num1[], char num2[], char result[]) {
    int borrow = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    // 判断被减数和减数的大小关系
    compare = strcmp(num1, num2);
    if (len1 < len2 || (len1 == len2 && compare < 0)) {
        // 如果被减数小于减数，则交换它们，并输出负号
        char temp[MAX_DIGITS + 1];
        strcpy(temp, num1);
        strcpy(num1, num2);
        strcpy(num2, temp);
        int tempLen = len1;
        len1 = len2;
        len2 = tempLen;
    } else if (compare == 0) {
        // 如果两数相等，则结果为0
        result[0] = '0';
        result[1] = '\0';
        return;
    }

    // 执行相减操作
    for (int i = 0; i < len1; i++) {
        int digit1 = num1[len1 - 1 - i] - '0';
        int digit2 = i < len2 ? num2[len2 - 1 - i] - '0' : 0;

        int diff = digit1 - digit2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result[i] = diff + '0';
    }

    // 删除前导零
    int nonZeroIndex = len1 - 1;
    while (nonZeroIndex > 0 && result[nonZeroIndex] == '0') {
        nonZeroIndex--;
    }

    result[nonZeroIndex + 1] = '\0';
	
    // 反转字符串
    int start = 0, end = nonZeroIndex;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
}




// 实现大数相乘
void multiply(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int product[len1 + len2];

    // 初始化product数组
    for (int i = 0; i < len1 + len2; i++) {
        product[i] = 0;
    }

    // 逐位相乘
    for (int i = 0; i < len1; i++) {
        int carry = 0;
        int digit1 = num1[len1 - 1 - i] - '0';

        for (int j = 0; j < len2; j++) {
            int digit2 = num2[len2 - 1 - j] - '0';
            int sum = digit1 * digit2 + product[i + j] + carry;
            product[i + j] = sum % 10;
            carry = sum / 10;
        }

        if (carry > 0) {
            product[i + len2] += carry;
        }
    }

    // 转换为字符串
    int index = len1 + len2 - 1;
    while (index >= 0 && product[index] == 0) {
        index--;
    }

    if (index == -1) {
        result[0] = '0';
        result[1] = '\0';
    } else {
        int resultIndex = 0;
        while (index >= 0) {
            result[resultIndex++] = product[index] + '0';
            index--;
        }
        result[resultIndex] = '\0';
    }
}

