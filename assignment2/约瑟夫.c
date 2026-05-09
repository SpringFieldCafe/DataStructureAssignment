#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* createCircleList(int n) {
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 1; i <= n; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("内存分配失败！\n");
            exit(1);
        }

        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head;

    return head;
}

void josephus(int n, int m, int k) {
    Node *head = createCircleList(n);

    Node *p = head;
    Node *pre = head;

    while (pre->next != head) {
        pre = pre->next;
    }
    for (int i = 1; i < k; i++) {
        pre = p;
        p = p->next;
    }

    printf("出列顺序为：");

    int count = n;

    while (count > 0) {
        for (int i = 1; i < m; i++) {
            pre = p;
            p = p->next;
        }
        printf("%d", p->data);

        if (count > 1) {
            printf(" ");
        }
        Node *temp = p;
        pre->next = p->next;
        p = p->next;
        free(temp);

        count--;
    }

    printf("\n");
}

int main(){
int n, m, k;

    printf("请输入总人数 n：");
    scanf("%d", &n);

    printf("请输入报数值 m：");
    scanf("%d", &m);

    printf("请输入开始位置 k：");
    scanf("%d", &k);

    if (n <= 0 || m <= 0 || k <= 0 || k > n) {
        printf("输入数据不合法！\n");
        return 1;
    }

    josephus(n, m, k);

    return 0;
}