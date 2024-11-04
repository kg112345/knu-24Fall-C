#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// 고객 CRUD
// 우선순위: 1.고객등급  2.주문량  3.포인트

enum Rank {
    DIAMOND = 1, PLATINUM, GOLD, SILVER
};

struct NODE {
    char name[100];
    enum Rank rank;
    int order_amount;
    int point;
    struct NODE* prev;
    struct NODE* next;
};

struct NODE* head = NULL;

struct NODE* create_node(char* name, enum Rank rank, int order_amount, int point) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));

    strcpy_s(new_node->name, sizeof(new_node->name), name);
    new_node->rank = rank;
    new_node->order_amount = order_amount;
    new_node->point = point;
    new_node->prev = new_node->next = NULL;
    
    return new_node;
}


void insert_node(struct NODE* new_node) {
    if (head == NULL) {
        head = new_node;
        return;
    }

    struct NODE* current = head;
    
    while (current != NULL) {
        if ((new_node->rank < current->rank) 
            || ((new_node->rank == current->rank) 
                && (new_node->order_amount > current->order_amount)) 
            || ((new_node->rank == current->rank) 
                && (new_node->order_amount == current->order_amount) 
                && (new_node->point > current->point))) {

            new_node->next = current;
            new_node->prev = current->prev;

            current->prev ? current->prev->next = new_node : 0;
            current->prev = new_node;
            (current == head) ? (head = new_node) : 0;

            return;
        }


        if (current->next == NULL) {
            break;
        }
        
        current = current->next;
    }

    current->next = new_node;
    new_node->prev = current;
}


void print_nodes() {
    struct NODE* current = head;

    printf("\nㅡㅡㅡㅡㅡㅡ(고객 List)ㅡㅡㅡㅡㅡㅡㅡ\n");

    while (current != NULL) {
        printf("이름: %s, 등급: %d, 전체 주문량: %d, 포인트: %d\n", current->name, current->rank, current->order_amount, current->point);

        current = current->next;
    }
}

void update_node(char* name, enum Rank rank, int order_amount, int point) {
    struct NODE* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->prev) {
                current->prev->next = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            }

            if (current == head) {
                head = current->next;
            }

            free(current);

            insert_node(create_node(name, rank, order_amount, point));

            printf("%s 정보 수정 완료!\n", name);
            return;
        }
        current = current->next;
    }
    printf("%s, 해당 고객 없음.\n", name);
}

void delete_node(char* name) {
    struct NODE* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->prev) {
                current->prev->next = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            }

            if (current == head) {
                head = current->next;
            }

            free(current);

            printf("%s 삭제 완료!\n", name);
            return;
        }
        current = current->next;
    }
    printf("해당 고객 없음.\n");
}

int main(void) {
    int choice, rank, order_amount, point;
    char name[100];

    while (1) {
        printf("\n\n1. 고객 추가\n2. 고객 삭제\n3. 고객 수정\n4. 고객 목록 출력\n5. 종료\n\n");
        printf("입력: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("이름: ");
            scanf_s("%s", name, sizeof(name));

            printf("등급: ");
            scanf_s("%d", &rank);

            printf("전체 주문량: ");
            scanf_s("%d", &order_amount);

            printf("포인트: ");
            scanf_s("%d", &point);

            insert_node(create_node(name, rank, order_amount, point));
            break;

        case 2:
            printf("삭제할 고객 이름: ");
            scanf_s("%s", name, sizeof(name));

            delete_node(name);
            break;

        case 3:
            printf("수정할 고객 이름: ");
            scanf_s("%s", name, sizeof(name));

            printf("등급 수정 (Diamond, Platinum, Gold, Silver = 1, 2, 3, 4): ");
            scanf_s("%d", &rank);

            printf("전체 주문량 수정: ");
            scanf_s("%d", &order_amount);

            printf("포인트 수정: ");
            scanf_s("%d", &point);

            update_node(name, rank, order_amount, point);
            break;

        case 4:
            print_nodes();
            break;

        case 5:
            exit(0);
        }
    }

    return 0;
}
