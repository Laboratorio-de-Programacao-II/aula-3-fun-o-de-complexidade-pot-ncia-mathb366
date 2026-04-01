#include <stdio.h>

long long pot(long long base, int exp) {
    long long resultado = 1;
    for (int i = 0; i < exp; i++)
        resultado *= base;
    return resultado;
}

long long pot_eficiente(long long base, int exp) {
    long long resultado =0 ;
    if(exp == 0){
        resultado = 1;
    }else if(exp%2 == 0){
        resultado = pot_eficiente(base, exp/2) * pot_eficiente(base, exp/2);
    }else if(exp%2 == 1){
        resultado = base * pot_eficiente(base, exp-1);
    }
    return resultado;
}

int main() {
    long long base;
    int exp;
    scanf("%lld %d", &base, &exp);

    long long r1 = pot(base, exp);
    long long r2 = pot_eficiente(base, exp);

    printf("%lld\n%lld\n", r1, r2);
    return 0;
}
