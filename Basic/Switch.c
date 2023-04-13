#include<stdio.h>

int main()
{
    int a;
    printf("Enter the number corresponding to your Favourite Anime \n");
    printf(" 1. Dragon Ball \n 2. Naruto \n 3. One Piece \n 4. Bleach \n 5. JJK \n 6. Demon Slayer \n 7. MHA \n 8. AOT \n 9. High School DxD \n 0. If you don't watch anime \n");
    scanf("%d",&a);

    switch (a)
    {
    case 1 :
        printf("Great Fights");
        break;
    case 2 :
        printf("Dattebayo");
        break;
    case 3 :
        printf("Ore wa Rufi! Kaizoku O ni Naru Otoko Da!");
        break;
    case 4 :
        printf("Ban...Kai...");
        break;
    case 5 :
        printf("Jennifer Lawrence");
        break;
    case 6 :
        printf("Nezuko Chan");
        break;
    case 7 :
        printf("you are Quirkless");
        break;
    case 8 :
        printf("It was all my doing");
        break;
    case 9 :
        printf("Nice PlOOt");
        // break;
    case 0 :
        printf("Give up on your dreams and die");
        break;

    default:
        printf("Enter the correct number.");
        break;
    }
    return 0;
}