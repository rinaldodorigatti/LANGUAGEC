#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <spawn.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#include "methodes.h"


int appels = 0;


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

void getPosixCommand(void)
{
    pid_t pid;
    char *cmd = "ls -l 2>&1 >>fichier_ls.txt";
    char *argv[] = {"sh", "-c", cmd, NULL};
    int status;
    
    FILE *fp;
    if ((fp = fopen("fichier_ls.txt", "a+")) != NULL) {
        fprintf(fp, "Run command %s\n", cmd);
        status = posix_spawn(&pid, "/bin/sh", NULL, NULL, argv, environ);
        
        if (status == 0) {
            fprintf(fp, "Child pid: %i\n", pid);
            if (waitpid(pid, &status, 0) != -1) {
                fprintf(fp, "Child exited with status: %i\n", status);
            } else {
                perror("waitpid");
            }
        } else {
            fprintf(fp, "posix_spawn: %s\n", strerror(status));
        }
    } else {
        fprintf(fp, "posix_spawn: %s\n", strerror(status));
    }
    fprintf(fp, "-----------------------------------------------------------------\n");
    
    fclose(fp);
}

void getDiviseur(void)
{
    int a,b;
    printf("Donner moi deux nombres : ");
    scanf("%d %d", &a, &b);
    
    int min = (a < b) ? a : b;
    
    for (int i = 2; i <= min; ++i) {
        if (a % i == 0 && b % i == 0) {
            printf("Le plus petit diviseur entre %d et %d est %d\n", a, b, i);
            break;
        }
    }
}

int returnNumber(int a)
{
    int b, total;
    b = 10;
    total = a * b;
    return total;
}

int getNumbers(int a, int b)
{
    int g = (a < b) ? a : b;
    
    for (int i = 2; i <= g; ++i) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 0;
}

void startGetNumbers(void)
{
    int a,b;
    printf("Donner moi deux nombres : ");
    scanf("%d %d", &a, &b);
    
    int resultat = getNumbers(a, b);
    
    if (resultat != 0) {
        printf("Le plus petit diviseur entre %d et %d est %d\n", a, b, resultat);
    }
}


void incrementeAppels(void)
{
    ++appels;
}


void appelincrementeAppels(void)
{
    incrementeAppels();
    incrementeAppels();
    printf("La valeur de la variable 'appels' est : %d\n", appels);
}

int compteur(void)
{
    static int n;
    return ++n;
}

void getCompteur(void)
{
    compteur();
    printf("n = %d\n", compteur());
    compteur();
    printf("n = %d\n", compteur());
    
    int total;
    total = (compteur() -1) + 10;
    printf("total = %d\n", total);
}


void triangle(void)
{
    int nombre = 5;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < nombre; j++)
            printf("*");
        printf("\n");
    }
}

void getFgets(void)
{
    char name[100];
    
    char *ptr = NULL;

    while ((ptr = fgets(name, 100, stdin)) != NULL)
    {
        if (*ptr == '\n') {
            break;
        }
    }
    printf("Your name is : %s\n", name);
}


void array01(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t n = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
}

int getArray(int a[10])
{
    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
    return *a;
}

int findElement(int arr[], int lon, int key)
{
    int i;
    for (i = 0; i < lon; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void callfindElement(void)
{
    int arr[] = {1, 4, 6, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 4;
    int position = findElement(arr, n, key);
    
    if (position == -1) {
        printf("Element NOT Found");
    } else {
        printf("Element Found at Position: %d", position + 1 );
    }
}


int insertSorted(int arr[], int n, int key, int capacity)
{
    if (n >= capacity) {
        return n;
    }
    arr[n] = key;
    return (n + 1);
}

void getArray02(void)
{
    int arr[20] = {1, 8, 5, 0, 3, 2};
    int capacity = sizeof(arr) / sizeof(arr[0]);
    int n = 3;
    int i;
    int key = 11;
    
    printf("\nBefore insertion : ");
    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    
    n = insertSorted(arr, 3, key, capacity);
    
    printf("\nAfter insertion : ");
    
    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
}


int deleteElement(int arr[], int n, int key)
{
    int pos = findElement(arr, n, key);
    printf("\nPOS : %d", pos);
    if (pos == -1) {
        printf("\nElement %d not found\n", arr[pos]);
        return n;
    }
    int i;
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

void getArray04(void)
{
    int i;
    int arr[] = {1, 5, 9, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("\nSIZE : %d", size);
    int key = 3;
    
    printf("\nBefore deletion : ");
    
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    size = deleteElement(arr, size, key);
    
    printf("\nAfter deletion : ");
    
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}


void getArray06(void)
{
    int array[100], position, c, n;

   printf("Enter number of elements in array : ");
   scanf("%d", &n);

   printf("Enter %d elements : ", n);

   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);

   printf("Enter the location where you wish to delete element : ");
   scanf("%d", &position);

   if (position >= n + 1)
      printf("Deletion not possible.\n");
   else
   {
      for (c = position - 1; c < n - 1; c++)
         array[c] = array[c+1];

      printf("Resultant array:\n");

      for (c = 0; c < n - 1; c++)
         printf("%d\n", array[c]);
   }
}