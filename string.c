#include<stdio.h>
#include<string.h>
void find_prefix(char string[]);
void find_suffix(char string[]);
void substring(char string[], int,int);
int main()
{
    char string[20];
    int i,j;
    printf("\n Enter a string \t");
    gets(string);
    printf("\n Prefix: ");
    find_prefix(string);
    printf("\n Suffix: ");
    find_suffix(string);
    printf("\nEnter i and j for substring: \t");
    scanf("%d %d", &i,&j);
    substring(string,i,j);
    return 0;
}
void find_prefix(char string[])
{
    int i,j;
    char prefix[20];
    for(i=strlen(string); i>=0; i--)
    {
        for(j=0;j<i;j++)
        {
            prefix[j]=string[j];
        }
    prefix[j]='\0';
    printf("\n %s",prefix);
    }

}
void find_suffix(char string[])
{
    int i,j,k;
    char suffix[20];
    for(i=0; i<=strlen(string);i++)
    {
        k=i;
        for(j=0; j<strlen(string);j++)
        {
            suffix[j]=string[k];
            k++;

        }
        suffix[j]='\0';
        printf("\n %s", suffix);

    }
}
void substring(char string[], int x,int y)
{
    char substr[10];
    int k=0;
    for(int i=x-1; i<y; i++)
    {
        substr[k]=string[i];
        k++;

    }
    substr[k]='\0';
    printf("\n Substring: %s", substr);
}
