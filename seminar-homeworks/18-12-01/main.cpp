/* Существует ряд авиакомпаний. Каждая характеризуется
- название
- рейтинг
- флот
Каждый самолет
- название
- год выпуска
- кол-во пассажиров 
- дата капремонта
- отметка об эксплуатации*/

/*
 *  Вывести на экран все самолеты, которые не ремонтировались больше 10 лет
 *  Вывести по 2 самых старых в эксплуатации самолета у компании с самыми высокими рейтингами
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[10];
    int build_year;
    int pass;
    int repair_year;
    bool in_use;
} jets;

typedef struct{
   char name[10];
   float rate;
   int planes;
   jets plane[10];
} airlines;


int main(int argc, char *argv[])
{
    airlines company[20];
    int n = 0;
    int curr_year = 2018;
    
    do {
        printf("Input amount of airlines (0;20)\n");
        scanf("%d", &n);
    } while (n <= 0 || n >= 20);
    
    for (int i = 0; i < n; i++){
        printf("Enter name of the company\n");
        scanf("%s", company[i].name);
        do {
            printf("Enter %s's rate. [0; 10]\n", company[i].name);
            scanf("%f", &company[i].rate);
        } while (company[i].rate < 0 || company[i].rate > 10);
        printf("How many planes are there in %s\n", company[i].name);
        do {
            printf("Enter amount of %s's planes. (0; 10]\n", company[i].name);
            scanf("%d", &company[i].planes);
        } while (company[i].planes <= 0 || company[i].planes > 10);
        for (int j = 0; j < company[i].planes; j++){
            printf("Enter %d-th plane\n", j+1);
            printf("Enter name of the plane\n");
            scanf("%s",company[i].plane[j].name);
            
            do {
                printf("In which year it was buid? [1900; %d] \n", curr_year);
                scanf("%d", &company[i].plane[j].build_year);
            } while (company[i].plane[j].build_year < 1900 || company[i].plane[j].build_year > curr_year);
            
            do {
                printf("In which year it was repaired? [%d; %d]\n", company[i].plane[j].build_year, curr_year);
                scanf("%d", &company[i].plane[j].repair_year);
            } while (company[i].plane[j].repair_year < company[i].plane[j].build_year || company[i].plane[j].repair_year > curr_year);
            
            do {
                printf("How many passengers? [5, 500]\n");
                scanf("%d", &company[i].plane[j].pass);
            } while (company[i].plane[j].pass < 5 || company[i].plane[j].pass > 500);
            printf("Is it used nowdays? 0 - false, any other number - true\n");
            int flag = 0;
            scanf("%d", &flag);
            if (flag)
                company[i].plane[j].in_use = true;
            else
                company[i].plane[j].in_use = false;
            printf("\n");
        }
        printf("\n\n\n");
    }
    
    for (int i = 0; i < n; i++){
        bool flag = true;
        printf("Company %s. Not repaired last ten years:\n", company[i].name);
        for (int j = 0; j < company[i].planes; j++){
            if (company[i].plane[j].repair_year < curr_year - 10){
                printf("%s repaired in %d\n", company[i].plane[j].name, company[i].plane[j].repair_year);
                flag = false;
            }
        }
        if (flag)
            printf("No planes found\n");
    }
    

    int i_max = 0;
    for (int i = 1; i < n; i++){
        if (company[i].rate > company[i_max].rate)
            i_max = i; 
    }
    
    //for (int i = 0; i < company[i_max].planes; i++)
        //printf("%s built in %d\n", company[i_max].plane[i].name, company[i_max].plane[i].build_year);

    for (int i = 0; i < company[i_max].planes; i++)
        for (int j = 0; j < company[i_max].planes-1; j++){
            if (company[i_max].plane[j].build_year > company[i_max].plane[j+1].build_year){
//                char name[10];
                char str[80];
                strcpy(str, company[i_max].plane[j].name);
                strcpy(company[i_max].plane[j].name, company[i_max].plane[j+1].name);
                strcpy(company[i_max].plane[j+1].name, str);
                
                int buf;
//                int build_year;
                buf = company[i_max].plane[j].build_year;
                company[i_max].plane[j].build_year = company[i_max].plane[j+1].build_year;
                company[i_max].plane[j+1].build_year = buf;
                
//                int pass;
                buf = company[i_max].plane[j].pass;
                company[i_max].plane[j].pass = company[i_max].plane[j+1].pass;
                company[i_max].plane[j+1].pass = buf;
                
//                int repair_year;
                buf = company[i_max].plane[j].repair_year;
                company[i_max].plane[j].repair_year = company[i_max].plane[j+1].repair_year;
                company[i_max].plane[j+1].repair_year = buf;
                
//                bool in_use;
                if (company[i_max].plane[j].in_use != company[i_max].plane[j+1].in_use){
                    company[i_max].plane[j].in_use = !company[i_max].plane[j].in_use;
                    company[i_max].plane[j+1].in_use = !company[i_max].plane[j+1].in_use;
                }
            }
        }
    //for (int i = 0; i < company[i_max].planes; i++)
       // printf("%s built in %d\n", company[i_max].plane[i].name, company[i_max].plane[i].build_year);
    
    printf("\nCompany %s has rate = %3.2f, oldest planes in use:\n", company[i_max].name, company[i_max].rate);
    int flag = 2;
    for (int i = 0; i < company[i_max].planes; i++){
        if (company[i_max].plane[i].in_use && flag){
            printf("%s built in %d\n", company[i_max].plane[i].name, company[i_max].plane[i].build_year);
            flag--;
        }
    }
    if (flag == 2){
        printf("No planes in use\n");
    }
    
    return 0;
}
