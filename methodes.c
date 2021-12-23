#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <ctype.h>
#include "methodes.h"


void memoireCmp(void)
{
    int array1[2] = {14};
    int array2[2] = {15};
    
    size_t size = 2;
    
    int *g;
    g = (int*)malloc(sizeof(int*));
    
    *g = memcmp(array1, array2, size);
    if (*g == 0) {
        printf("Execution de memoireCmp() : ");
        printf("Equals\n");
    } else if (*g == -1) {
        printf("Execution de memoireCmp() : ");
        printf("array1 plus petit\n");
    } else {
        printf("Execution de memoireCmp() : ");
        printf("array1 plus grand\n");
    }
    
    free(g);
}


void trouve(void)
{
    const char texte[38] = "La chaine de charactère ou on cherche";
    const char se[3] = "ou";
    char *ret;
    ret = strstr(texte, se);
    
    if (ret == NULL) {
        printf("Execution de trouve() : ");
        printf("Objet pas trouvé\n");
    } else {
        printf("Execution de trouve() : ");
        printf("Objet trouvé\n");
    }
}

void useAssert(void)
{
    int zuzu;
    
    printf("Give a number : ");
    scanf("%d", &zuzu);
    assert(zuzu <= 10);
    printf("zuzu : %d\n", zuzu);
}

void charCopy(void)
{
    char chaine[5] = {'A', 'B', 'C', 'D'};
    
    printf("\nExecution de charCopy() : ");
    printf("%s\n", chaine);
    printf("Lettre chaine[0] : ");
    printf("%c\n", chaine[0]);
    printf("Size of chain : ");
    printf("%d\n", sizeof(chaine)-1);
    
    char chaine2[5];
    int len = 5;
    memcpy(chaine2, chaine, len);
    
    for (int h = 0; h < sizeof(chaine2); h++) {
        printf("%c ", chaine2[h]);
    }
    
}

void intCopy(void)
{
    // enlever la ligne : int copy[20]; et activer celles en bleus
    printf("\nExecution de intCopy() : ");
    int array [20] = {54, 85, 20, 63, 21};
    // int * copy;
    int copy[20];
    int length = 20;
       
    // copy = (int*)malloc(sizeof(int*));
    memcpy(copy, array, length);
        
    for(int f = 0; f < 5; f++) {
        printf( "%d ", copy[f]);
    }
    printf("\n");
        
    // free(copy);
}

void setMem(void)
{
    int array[5] = {54, 85, 20, 63, 21};
    size_t size = 5;
    size_t setMem = 20;
    int length;

    for( length = 0; length < 5; length++) {
        printf("%d ", array[length]);
    }
    printf("\n");

    memset(array, 0, setMem);

    for(length = 0; length < 5; length++) {
        printf("%d  ", array[length]);
    }
    printf("\n");
}

void fullName(void)
{
    char *first_name = (char*)malloc(40);
    char *last_name = (char*)malloc(40);
    char *full_name;
    size_t fullsize;
    
    strncpy(first_name, "Rinaldo", 8);
    strncpy(last_name, "Dorigatti", 10);
    fullsize = (strlen(first_name) + 1) + (strlen(last_name) + 1);
    
    full_name = (char*)malloc(sizeof(fullsize));
    
    strncpy(full_name, first_name, 8);
    strncat(full_name, " ", 2);
    strncat(full_name, last_name, 10);
    
    fprintf(stdout, "%s\n", full_name);
    
    free(first_name);
    free(last_name);
    free(full_name);
    
}

void stringSearch(void)
{
    char *source = "Le language C est cool";
    char *destination;
    char *pointer;
    int len = strlen(source);
    
    destination = (char*)malloc(sizeof(char) * (len+1));
    strncpy(destination, source, len);
    
    while (pointer = strchr(destination, 'a')) {
        *pointer = 'A';
    }
    
    printf( "Result : %s\n", destination );
    
    free(destination);
    free(pointer);
    
}

void login(void)
{
    char name[40];
    char pass[40];
    
    printf("Please give your name : ");
    scanf("%s", name);
    
    printf("Please give your password : ");
    scanf("%s", pass);
    
    if (strcmp(name, "bond") == 0 && strcmp(pass, "007") == 0) {
        printf( "You are connected\n" );
    } else {
        printf( "You are NOT connected\n" );
    }
}

int compareChar(char a[5], char b[5])
{
    int compare = strcoll(a, b);
    return compare;
}

void returnContent(void)
{
    char *chaine;
    chaine = (char*)malloc(sizeof(char*));
    strncpy(chaine, "spyg007", 7);
    
    char *rejected;
    rejected = (char*)malloc(sizeof(char*));
    strncpy(rejected, "1234567890", 10);

    char *rejected2;
    rejected2 = (char*)malloc(sizeof(char*));
    strncpy(rejected2, "abcdefghijklmnopqrstuvwxyz", 26);
    
    int g = strcspn(chaine, rejected);
    printf("Lettre G : %d\n", g);
    
    char key[g + 1];
    strncpy(key, chaine, g);
    int code = atoi(chaine + g);
    printf("Key:  %s - Code: %d\n", key, code);
    
    int h = strspn(chaine, rejected2);
    printf("Lettre H : %d\n", h);
    
    char key1[h + 1];
    strncpy(key1, chaine, h);
    // char *code1 = chaine + h;
    char *code1;
    code1 = (char*)malloc(sizeof(char*) + 17);
    strncpy(code1, (chaine + h), 17);
    printf("Key1: %s - Code: %s\n", key1, code1);
    
    free(chaine);
    free(rejected);
    free(rejected2);
    free(code1);
    
}

void replaceExt(void)
{
    const char *origineFile = "folder/un.jpg.tutu";
    size_t size = strlen(origineFile) + 1;
    printf("Size_t : %zu\n", size);
    char *destinationFile = (char*)malloc(size);
    strncpy(destinationFile, origineFile, size);
    
    char *lastPos = strrchr(destinationFile, '.');
    printf("String : %s\n", lastPos);
    strncpy(lastPos, ".png", 5);
    
    puts(origineFile);
    puts(destinationFile);
    
    free(destinationFile);
    
}

void replaceExt2(void)
{
    
    const char *monTexte = "/bin/include/lib/test";
    size_t size = strlen(monTexte) + 1;
    
    char *destination = (char*)malloc(size);
    strncpy(destination, monTexte, size);
    
    char *lastPos = strrchr(destination, '/');
    printf("Last Pos : %s\n", lastPos);
    
    strncpy(lastPos, "/essa", 5);
    
    puts(monTexte);
    puts(destination);
    
    free(destination);
    
}

void searchString(void)
{
    
    char buf[50];
    int c;
    
    printf("Veuillez saisir une ligne de texte contenant le mot \"admin\" : ");
    
    while ((c = getchar()) != '\n' && c != EOF);
    
    scanf("%[^\n]s", buf);

    printf("Buffer => %s\n", buf);
    
    char *result = strstr(buf, "admin");
    
    if (result == NULL) {
        puts("Vous n'avez pas saisi le mot admin\n");
    } else {
        puts("BRAVO : Vous avez saisi le mot admin\n");
    }
    
}

char *to_lower(const char *ct)
{
    char *s = NULL;
    
    if (ct != NULL) {
        int i;
        s = malloc (sizeof (*s) * (strlen (ct) + 1));
        if (s != NULL) {
            for (i = 0; ct[i]; i++) {
                s[i] = tolower(ct[i]);
            }
            s[i] = '\0';
        }
    }
    
    return s;
}

char *to_upper(const char *ct)
{
    char *s = NULL;
    
    if (ct != NULL) {
        int i;
        s = malloc (sizeof (*s) * (strlen (ct) + 1));
        if (s != NULL) {
            for (i = 0; ct[i]; i++) {
                s[i] = toupper(ct[i]);
            }
            s[i] = '\0';
        }
    }
    
    return s;
}

void structUnion(void)
{
    struct test {
        int x, y;
    };
    
    union testU {
        int x, y;
    };
    
    struct test a = {1,2};
    printf("%d %d", a.x, a.y);
    
    union testU u;
    u.x = 3;
    u.y = 4;
    printf("%d %d", u.x, u.y);
    
}

void structGiveYour(void)
{
    struct student {
        int age;
        char name[20];
        char surname[20];
        float pay;
    };
    
    struct student g;
    
    printf("Please give your age : ");
    scanf("%d", &g.age);
    
    
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Please give your name : ");
    scanf("%[^\n]s", g.name);
   
    
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Please give your surname : ");
    scanf("%[^\n]s", g.surname);
    
    printf("Your age     : %d\n", g.age);
    printf("Your name    : %s\n", g.name);
    printf("Your surname : %s\n", g.surname);
    
    char flowers[10][20] = {"Rose", "Poppy", "Lily", "Tulip", "Marigold"};
    int total=sizeof(flowers)/sizeof(flowers[0]);
    for (int n = 0; n <total; n++)
    {
      printf("%s\n",flowers[n]);
    }
}


void showCommands(void)
{
    system("PGPASSWORD=lu48cie psql -U postgres dbha001 -c 'select * from banks;' >> fichier_ls.txt");
    
    FILE *fp;
    
    if ((fp = fopen("fichier_ls.txt", "a+")) != NULL) {
        fprintf(fp, "-----------------------------------------------\n");
    fclose(fp);
    } else {
        printf("Error file not found !\n");
        exit(1);
    }
    
}


void getDateTime(void)
{
    time_t now = time(NULL);
    
    if (now == -1) {
        printf("Erreur now\n");
    }
    
    struct tm *ptm = localtime(&now);
    
    if (ptm == NULL) {
        printf("Erreur ptm\n");
    }
    
    printf("Time is : %02d:%02d:%02d\n", ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
    printf("Time is : %02d/%02d/%02d\n", ptm->tm_mday, ptm->tm_mon, ptm->tm_year + 1900);
    
    FILE *fp;
    if ((fp = fopen("fichier_ls.txt", "a+")) != NULL) {
        fprintf(fp, "-----------------------------------------------\n");
        fprintf(fp, "UBP company\t\t   ");
        fprintf(fp,"%02d:%02d:%02d %02d/%02d/%02d\n", ptm->tm_hour, ptm->tm_min, ptm->tm_sec,
                ptm->tm_mday, ptm->tm_mon, ptm->tm_year + 1900);
        fprintf(fp, "-----------------------------------------------\n");
        fclose(fp);
    } else {
        printf("Error file not found !\n");
        exit(1);
    }
    
    
}