#include   <stdio.h>
#include   <string.h>

int main(){
    char frase1[100];
    scanf("%[^\n]", frase1);
    char frase2[(strlen(frase1)*2)+1];
    int inicioFrase2 = 0;
    for (int i = 0; i < strlen(frase1); i++)
    {
        if (frase1[i] == ' ' || frase1[i] == '\0')
        {
            for (int j = inicioFrase2; j <= i; j++)
            {
                frase2[j] = frase1[j];
            }
            inicioFrase2 = i+1;
            for (int j = inicioFrase2; j <= i; j++)
            {
                frase2[j] = frase1[j];
            }
        }
    }
    for(int i = 0; i < frase2[i]; i++)
    {
        printf("%c", frase2[i]);
    }
    
    return 0;
}