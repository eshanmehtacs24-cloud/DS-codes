#include <stdio.h>

#define MAX 50

struct employee {
    int key;        // 4-digit employee key
    int empId;      // employee ID
    char name[20];  // employee name
};

struct employee hashTable[MAX];
int m;

/* Initialize hash table */
void initHashTable() {
    int i;
    for (i = 0; i < m; i++) {
        hashTable[i].key = -1;   // -1 indicates empty slot
    }
}

/* Hash function */
int hashFunction(int key) {
    return key % m;
}

/* Insert record using Linear Probing */
void insert(int key, int empId, char name[]) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index].key != -1) {
        index = (index + 1) % m;

        if (index == startIndex) {
            printf("Hash table is full\n");
            return;
        }
    }

    hashTable[index].key = key;
    hashTable[index].empId = empId;
    sprintf(hashTable[index].name, "%s", name);
}

/* Display hash table */
void display() {
    int i;
    printf("\nHash Table Contents:\n");
    printf("Address\tKey\tEmpID\tName\n");
    for (i = 0; i < m; i++) {
        if (hashTable[i].key != -1)
            printf("%d\t%d\t%d\t%s\n", i, hashTable[i].key,
                   hashTable[i].empId, hashTable[i].name);
        else
            printf("%d\t--\t--\t--\n", i);
    }
}

int main() {
    int n, i, key, empId;
    char name[20];

    printf("Enter number of memory locations (m): ");
    scanf("%d", &m);

    initHashTable();

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter 4-digit Key: ");
        scanf("%d", &key);

        printf("Enter Employee ID: ");
        scanf("%d", &empId);

        printf("Enter Employee Name: ");
        scanf("%s", name);

        insert(key, empId, name);
    }

    display();
    return 0;
}
