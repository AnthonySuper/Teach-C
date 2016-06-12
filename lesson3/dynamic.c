#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **names;
    size_t num_names;
} NameList;

void add_name(NameList *list, char *name) {
    list->num_names++;
    list->names = realloc(list->names, sizeof(char*) * list->num_names);
    list->names[list->num_names - 1] = name;
}

void add_name_copy(NameList *list, char *name) {
    size_t size;
    size = strlen(name) + 1;
    char *ours = malloc(sizeof(char) * size);
    strcpy(ours, name);
    add_name(list, ours);
}

void print_names(NameList *list) {
    int i = 0;
    for(i = 0; i < list->num_names; i++) {
        printf("Got name: %s\n",list->names[i]);
    }
}

void write_to_file(NameList *list, FILE *fp) {
    int i = 0;
    for(i = 0; i < list->num_names; i++) {
        fprintf(fp, "%s", list->names[i]);
    }
}

void swap_name_order(NameList *list, int first, int second) {
    char *temp = list->names[first];
    list->names[first] = list->names[second];
    list->names[second] = temp;
}

int main() {
    NameList list;
    list.num_names = 0;
    list.names = NULL;
    char name_buffer[100];
    char *result;
    int name_index = 0;
    FILE *read;
    FILE *write;
    read = fopen("/tmp/names.txt", "r");
    write = fopen("/tmp/new_names.txt", "w");
    if(read == NULL || write == NULL) {
        perror("Could not open file");
        return -1;
    }
    do {
        result = fgets(name_buffer, 100, read);
        if(result != NULL) {
            add_name_copy(&list, result);
        }
    } while(result != NULL);
    swap_name_order(&list, 0, 2);
    print_names(&list);
    write_to_file(&list, write);
    return 0;
}

