#include <stdio.h>
#include <stdlib.h>
int len(char * str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0';i++)
    {
        len++;
    }
    return len;
}

char *compressedString(char *word)
{
    char *ptr = (char *)malloc(sizeof(char) * (len(word)+3));
    printf("%d\n",len(word));
    int c = 0;
    int count = 0;
    char current = word[0];
    int a = 0;
    while (word[c] != '\0')
    {
        // printf("word: %c, c: %d, current: %c, count: %d\n", word[c], c, current, count);
        if (current == word[c])
        {
            count++;
        }
        if (current != word[c] || count > 9)
        {
            current = word[c];
            count = 1;
        }

        
        if (current != word[c + 1] || count+1 > 9)
        {
            // ptr = (char *)realloc(ptr, sizeof(char) * (a + 1));
            ptr[a] = count + '0';
            a++;
            ptr[a] = current;
            a++;
            
        }

        c++;
    }
    ptr[a] = '\0';
    return ptr;
}
int main()
{
    char str[] = "abcde";
    printf("%s", compressedString(str));
}