#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;


Node* taoNode(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}


void themCuoi(int x) {
    Node *p = taoNode(x);
    if (head == NULL) {
        head = p;
        p->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = p;
    p->next = head;
}


void taoDanhSach() {
    int n, x;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &x);
        themCuoi(x);
    }
}


void inDanhSach() {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node *temp = head;
    printf("Danh sach: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}


int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}


void kiemTraSNT() {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node *temp = head;
    int pos = 1, found = 0;

    printf("Vi tri cac so nguyen to: ");
    do {
        if (laSoNguyenTo(temp->data)) {
            printf("%d ", pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    if (!found) printf("Khong co so nguyen to nao!");
    printf("\n");
}


void xoaViTri(int k) {
    if (head == NULL) return;

    Node *temp = head, *prev = NULL;


    if (k == 1) {
       
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }


        Node *last = head;
        while (last->next != head) last = last->next;

        last->next = head->next;
        Node *del = head;
        head = head->next;
        free(del);
        return;
    }


    int pos = 1;
    do {
        prev = temp;
        temp = temp->next;
        pos++;
    } while (temp != head && pos < k);

    if (pos == k) {
        prev->next = temp->next;
        free(temp);
    }
}


void kiemTraVitri5() {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node *temp = head;
    int pos = 1;

    do {
        if (pos == 5) {
            if (temp->data == 0) {
                xoaViTri(5);
                printf("Da xoa vi tri 5 vi gia tri bang 0.\n");
            } else {
                printf("Vi tri 5 khong phai la so 0.\n");
            }
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Danh sach khong du 5 phan tu.\n");
}


void xoaSoAm() {
    if (head == NULL) return;

    int pos = 1;
    Node *temp = head;
    do {
        if (temp->data < 0) {
            xoaViTri(pos);
            pos = 1;
            temp = head;
            continue;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Da xoa tat ca so am.\n");
}


void sapXepTangDan() {
    if (head == NULL) return;

    Node *i = head, *j;
    do {
        j = i->next;
        while (j != head) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    } while (i->next != head);
    printf("Da sap xep tang dan.\n");
}


void sapXepAmTruocDuongSau() {
    if (head == NULL) return;


    int a[1000], b[1000], na = 0, nb = 0;
    Node *temp = head;

    do {
        if (temp->data < 0)
            a[na++] = temp->data;
        else
            b[nb++] = temp->data;
        temp = temp->next;
    } while (temp != head);


    for (int i = 0; i < na - 1; i++)
        for (int j = i + 1; j < na; j++)
            if (a[i] < a[j]) {
                int t = a[i]; a[i] = a[j]; a[j] = t;
            }


    for (int i = 0; i < nb - 1; i++)
        for (int j = i + 1; j < nb; j++)
            if (b[i] > b[j]) {
                int t = b[i]; b[i] = b[j]; b[j] = t;
            }


    temp = head;
    int i = 0, j = 0;

    while (i < na) {
        temp->data = a[i++];
        temp = temp->next;
    }
    while (j < nb) {
        temp->data = b[j++];
        temp = temp->next;
    }

    printf("Da sap xep: So am truoc (giam dan), so duong sau (tang dan).\n");
}


void menu() {
    int chon;
    do {
        printf("\n                                    =============================================\n");
        printf("                                    |       CHUONG TRINH QUAN LY SO NGUYEN      |\n");
        printf("                                    =============================================\n");
        printf("                                    | 1. Tao danh sach                          |\n");
        printf("                                    | 2. Kiem tra so nguyen to trong danh sach  |\n");
        printf("                                    | 3. Kiem tra vi tri thu 5 va xoa neu = 0   |\n");
        printf("                                    | 4. Xoa tat ca so am                       |\n");
        printf("                                    | 5. Sap xep tang dan                       |\n");
        printf("                                    | 6. Am truoc (giam dan), duong sau (tang)  |\n");
        printf("                                    | 7. In danh sach                           |\n");
        printf("                                    | 0. Thoat                                  |\n");
        printf("                                    =============================================\n");
        printf("                                    Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: taoDanhSach(); break;
            case 2: kiemTraSNT(); break;
            case 3: kiemTraVitri5(); break;
            case 4: xoaSoAm(); break;
            case 5: sapXepTangDan(); break;
            case 6: sapXepAmTruocDuongSau(); break;
            case 7: inDanhSach(); break;
            case 0: printf("Thoat chuong trinh!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }

    } while (chon != 0);
}

int main() {
    menu();
    return 0;
}

