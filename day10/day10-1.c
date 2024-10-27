#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 학생 삽입 (노드 생성) O
// 전체 학생 출력 O
// 학생 삭제 O


struct NODE {
    int score;
    char name[100];
    struct NODE* link;
};

struct NODE* head = NULL;

struct NODE* create_node(char* name, int score) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));

    new_node->score = score;
    strcpy_s(new_node->name, sizeof(new_node->name), name);
    
    new_node->link = NULL;

    return new_node;
}

struct NODE* last_node() {
    struct NODE* cur = head;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    return cur;
}

void insert_node_last(struct NODE* new_node) {
    if (head == NULL) {
        head = new_node;
    }
    else {
        struct NODE* last = last_node();
        last->link = new_node;
    }
}

void print_nodes() {
    struct NODE* cur = head;
    while (cur != NULL) {
        printf("이름: %s, 점수: %d\n", cur->name, cur->score);
        cur = cur->link;
    }
}

struct NODE* find_node(int value) {
    struct NODE* cur = head->link;
    while (cur != NULL) {
        if (cur->name == value) return cur;

        cur = cur->link;
    }
    return NULL;
}

int delete_node(char* name) {
    struct NODE* prev = NULL;
    struct NODE* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                head = cur->link;
            }
            else {
                prev->link = cur->link;
            }
            free(cur);
            printf("%s 학생이 제거됨\n", name);
            return 1;
        }
        prev = cur;
        cur = cur->link;
    }
    return 0;
}

void sort_node() {
    int tempScore;
    int tempName[100];

    struct NODE* i = head;

    while (i->link != NULL) {
        for (struct NODE* j = head; j->link != NULL; j = j->link) {
            if (j->score > j->link->score) {
                // 점수 변경
                tempScore = j->score;
                j->score = j->link->score;
                j->link->score = tempScore;

                // 이름 변경
                strcpy_s(tempName, sizeof(tempName), j->name);
                strcpy_s(j->name, sizeof(j->name), j->link->name);
                strcpy_s(j->link->name, sizeof(j->link->name), tempName);
            }
        }

        i = i->link;
    }
}


    int main(void) {
        int input;

        char name[100];
        int score;

        while (1) {
            printf("\n1. 학생 성적 입력 \n2. 학생 정보 제거 \n3. 프로그램 종료 \n");
            printf("입력: ");
            scanf_s("%d", &input);

            switch (input) {
            case 1:
                printf("이름: ");
                scanf_s("%s", name, sizeof(name));

                printf("점수: ");
                scanf_s("%d", &score);

                insert_node_last(create_node(name, score));
                break;
            case 2:
                printf("제거할 학생: ");
                scanf_s("%s", name, sizeof(name));
                delete_node(name);
                break;
            case 3:
                sort_node();
                printf("\nㅡㅡㅡㅡ\n");
                print_nodes();
                exit(0);
            }
        }

    print_nodes();
    
}
