#include <stdio.h>

struct num_container {
    int num; //标准输入的数值
    unsigned times;//数组被输入的次数
};
typedef struct num_container num_container;

/**
 * 把一个数放入num_container数组
 * @param x 输入的值
 * @param num_of_container container的数量
 * @param p 传入container数组的首元素地址
 * @return 若x被输入新的container,则返回1，反之返回0
 */
int input_num(int x, int num_of_container, num_container *p) {
    for (int i = 0; i < num_of_container; ++i, ++p) {
        if (x == p->num) {
            p->times += 1;
            return 0;
        }
    }
    p->num = x;
    (p->times)++;
    return 1;

}

void print_num(num_container *p) {
    printf("%d %u\n", p->num, p->times);
}

int main() {
    unsigned int N;
    scanf("%u", &N);
    num_container numContainer[N];
    for (int i = 0; i < N; ++i) {
        numContainer[i].times = 0;
    }
    int x, num_of_container = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &x);
        num_of_container += input_num(x, num_of_container, numContainer);
    }
    num_container *end_p = numContainer + num_of_container, *ptr = numContainer + 1;
    num_container *p[num_of_container];
    p[0] = numContainer;
    for (; ptr < end_p; ptr++) {
        if (ptr->times > p[0]->times) {
            p[0] = ptr;
        }
    }
    unsigned int cnt = 1;//cnt记录times最大的数的个数,p[0]指向了一个，因此初始化为1
    for (ptr = p[0] + 1; ptr < end_p; ptr++) {
        if (ptr->times == p[0]->times) {
            p[cnt] = ptr;
            cnt++;
        }
    }
    //对指针冒泡排序（升序排成员变量times）
    for (int i = 0; i < cnt - 1; ++i) {
        for (int j = 0; j < cnt - i - 1; ++j) {
            if (p[j]->num > p[j + 1]->num) {
                num_container *tmp;
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < cnt; ++i) {
        print_num(p[i]);
    }
    return 0;
}
