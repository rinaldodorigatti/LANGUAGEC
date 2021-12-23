#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    returnContent();
    replaceExt();
    replaceExt2();
    searchString();
    
    const char *t_lower = "ALIM";
    const char *t_upper = "alim";
    printf("%s\n", to_lower(t_lower));
    printf("%s\n", to_upper(t_upper));
    
    // structUnion();
    structGiveYour();
    
    
    return EXIT_SUCCESS;
}

