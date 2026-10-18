#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int random,guess;
    int no_of_guess = 0;
    srand(time(NULL));

    printf("Wellcome to the world of Gusseng game\n");
    random = rand() % 100 + 1; //generating between 0 to 100
    do{
        printf("Please enter your Guess between(1 to 100): ");
        scanf("%d", &guess);
        no_of_guess++;
        if(guess < random){
            printf("The Number is larger.\n");
        }else if(guess > random){
            printf("Guess is a smaller number\n");
        }else {
            printf("Congratulations  !!!  You have successfully guessed the Number in %d attempts.",no_of_guess);
        }
    }while(guess != random);
    printf("\n Bye Bye, Thanks for paying");
    printf("\nDeveloped By: Ayush Mondal");
    return 0;
}