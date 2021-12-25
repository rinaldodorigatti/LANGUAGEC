#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "methodes.h"



int main(int argc, char** argv) {

    
    trouve();
    useAssert();
    memoireCmp();
    charCopy();
    intCopy();
    setMem();
    fullName();
    stringSearch();
    login();
    
    char varCompare01[5] = "ABCD";
    char varCompare02[5] = "ABCD";
    printf("LEN : %d\n", sizeof("ABCD"));
    int resultat = compareChar(varCompare01, varCompare02);
    int oo = strcmp(varCompare01, varCompare02);
    printf("oo = %d\n", oo);
    if (resultat < 0) {
        printf("varCompare01 < varCompare02 : %d\n", resultat);
    } else if (resultat == 0) {
        printf("varCompare01 == varCompare02 : %d\n", resultat);
    } else if (resultat > 0) {
        printf("varCompare01 > varCompare02 : %d\n", resultat);
    } else {
        printf("Beu Beu\n");
    }
    
    printf("strcoll : %d\n", strcoll("Ldap", "Ldap"));

    // returnContent();
    replaceExt();
    replaceExt2();
    searchString();
    
    const char *t_lower = "ALIM";
    const char *t_upper = "alim";
    printf("%s\n", to_lower(t_lower));
    printf("%s\n", to_upper(t_upper));
    
    // structUnion();
    // structGiveYour();

    getDateTime();
    // showCommands();
    // getPosixCommand();
    // getDiviseur();
    
    int gg = 10;
    printf("GG : %d\n", returnNumber(gg));
    
    // startGetNumbers();
    appelincrementeAppels();
    getCompteur();
    triangle();
    getFgets();
    // array01();
    
    // int z[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // getArray(z);
    
    callfindElement();
    getArray02();
    getArray04();
    // getArray06();
    charArray();
    structArray();
    charPointers();
    pointerArray();
    
    char tableau[3];
    char (*ptr)[3];
    
    tableau[0] = 'o';
    tableau[1] = 'p';
    tableau[2] = 'q';
    
    ptr = &tableau;
    
    appelTableau(ptr);
    
    newCharFunc();
    
    printf("------------------ PREMIER ---------------\n");
    
    char doubleTableau[4][10] = {"rinaldo", "dorigatti", "estavayer", "1470"};
    
    for (size_t o = 0; o < 4; o++) {
        printf("Phrase : %s\tlongueur : %zu\n", doubleTableau[o], strlen(doubleTableau[o]));
    }
    
    showDoubleArray(doubleTableau);
    
    
    
    return EXIT_SUCCESS;
}

