#include<stdio.h>
#include<string.h>

void cover_page();
void search_name();
void search_ID();
void edit( int d);
void deletename(int d);
void deleteid(int d);
void deletescore(int d);
void all_record();
void success();
void fail();
void Add_record();

char name [100][30]= {"Kim_Sousdey", "Sochea_vortey","Soeum_PanhaPiseth","Chim_Panha","Thearat_Suthida","Tem_Limheang", "Dorn_Vannak","Kong_BunSak","Chhorn_PanhaRith","Noem_Visal","Him_Sophanin"};
char ID [100][5]= {"M001","M002","M003","M004","M005","M006","M007","M008","M009","M010","M011"};
float score[100][5]= {{6,8,9,3,6},{5,1,8,4,2},{4,6,7,8,7},{10,6,6,7,3},{1,9,1,1,3},{1,5,4,6,1},{3,10,9,10,3},{4,8,3,4,9},{3,3,5,1,4},{2,3,9,2,7},{7,7,10,1,3}};
char subject[5][30]={"Advanced_Microsoft_Excel","Fundamental_of Programming","HTML_and_CSS","IoT","Japanese_Level1"};
int student_count = 11;
int option;
int sub_option;
int control=0;
int i,j,k;

int main(){

    cover_page();
    printf("\n Please Choose Your Option:\n");
    printf("1. Search student by name \n");
    printf("2. Search student by ID \n");
    printf("3. Show all students record \n");
    printf("4. Show only successful student \n");
    printf("5. Show all fail student \n");
    printf("6. Add new student record \n");
    printf("Other to exit the program \n");
    printf("Option :");
    scanf("%d",&option);


        if(option==1){
          search_name();
        }
        else if(option==2){
            search_ID();
        }
        else if (option==3){
            all_record();
        }
        else if (option==4){
            success();
        }
        else if (option==5){
            fail();
        }
        else if (option==6){

            Add_record();

        }
        else{

        }

}

void  cover_page(){
    char title[]= ("Welcome to our school scoring system");

    int length,i;
    length = sizeof(title);
    for(i=1;i<length+4;i++){
        printf("*");
    }
    printf("\n*");
    for(i=1;i<length+2;i++){
            printf(" ");
    }
    printf("*\n");
    printf("* ");
    printf("%s",title);
    printf(" *");
    printf("\n*");
    for(i=1;i<length+2;i++){
        printf(" ");
    }
    printf("*\n");

    for(i=1;i<length+4;i++){
        printf("*");
    }


}

void search_name() {
    char input_name[50];
    int sub_option;

    printf("Please input student's name: ");
    scanf("%s", input_name);

    for (int i = 0; i < student_count; i++) {
        if (strcasecmp(input_name, name[i]) == 0) {
            printf("\nName: %s \n", name[i]);
            printf("ID: %s \n", ID[i]);

            for (int k = 0; k < 5; k++) {
                printf("Subject's name: %s \n", subject[k]);
                printf("Score: %.2f \n", score[i][k]);
            }

            printf("\nPlease Choose Your Option:\n");
            printf("1. Edit Record\n");
            printf("2. Delete Record\n");
            printf("3. Go to main Page\n");
            printf("Option: ");
            scanf("%d", &sub_option);

            if (sub_option == 1) {
                edit(i);
            } else if (sub_option == 2) {
                deletename(i);
                deleteid(i);
                deletescore(i);

                for (int i=0; i<10; i++){
                       printf("Name: %s\nID: %s\n",name[i],ID[i]);
                       for (j=0;j<5;j++){
                        printf("Subject: %s\n",subject[j]);
                        printf("Score: %.2f\n",score[i][j]);
                       }

                }

            } else {
                cover_page();
                printf("\n Please Choose Your Option:\n");
                printf("1. Search student by name \n");
                printf("2. Search student by ID \n");
                printf("3. Show all students record \n");
                printf("4. Show only successful student \n");
                printf("5. Show all fail student \n");
                printf("6. Add new student record \n");
                printf("Other to exit the program \n");
                printf("Option :");
                scanf("%d",&option);


                    if(option==1){
                      search_name();
                    }
                    else if(option==2){
                        search_ID();
                    }
                    else if (option==3){
                        all_record();
                    }
                    else if (option==4){
                        success();
                    }
                    else if (option==5){
                        fail();
                    }
                    else if (option==6){

                        Add_record();

                    }
                    else{

                    }
            }

            return; // Exit function after finding the record
        }

    }

    // If the loop completes without finding a match
    printf("There's no record.\n");
    printf("Please choose an option:\n");
    printf("1. Search again.\n");
    printf("2. Go to main page.\n");
    printf("Option: ");
    scanf("%d", &sub_option);

    if (sub_option == 1) {
        search_name();
    } else {
        cover_page();
        printf("\n Please Choose Your Option:\n");
                printf("1. Search student by name \n");
                printf("2. Search student by ID \n");
                printf("3. Show all students record \n");
                printf("4. Show only successful student \n");
                printf("5. Show all fail student \n");
                printf("6. Add new student record \n");
                printf("Other to exit the program \n");
                printf("Option :");
                scanf("%d",&option);


                    if(option==1){
                      search_name();
                    }
                    else if(option==2){
                        search_ID();
                    }
                    else if (option==3){
                        all_record();
                    }
                    else if (option==4){
                        success();
                    }
                    else if (option==5){
                        fail();
                    }
                    else if (option==6){

                        Add_record();

                    }
                    else{

                    }

    }
}



void edit( int d){
    char right_name [30];
    float edit_score[5];
    printf("Please input the right name: ");
        scanf("%s",&right_name);

        for (i=0;i<5;i++){
           printf("Please input the right score of %s: ",subject[i]);
           scanf("%f", &edit_score[i]);
        }
        for (i=d;i<99;i++){

                 for(j=0;j<strlen(name[i]);j++){

                        name[i][j]=right_name[j];
                    }

                printf("Edit successfully.\n");
                printf("Name: %s\n",name[i]);
                printf("ID: %s\n",ID[i]);
                for (k=0;k<5;k++){
                    score[i][k]=edit_score[k];
                    printf("\nSubject's name: %s \n",subject[k]);
                    printf("Score: %.2f \n",score[i][k]);
                    for(j=0;j<50;j++){
                    printf("*");
                    }
                }
                break;

        }
}



void deletename(int d){
    for (int i=d; i<99; i++){

        for(int j=0; j<= strlen (name[(i+1)]); j++){
        name[i][j] = name[i+1][j];
        }

        if(i==98){
            break;
        }
    }
}
void deleteid(int d){

    for (int i=d; i<99; i++){

        for(int j=0; j<=strlen(ID[i+1]); j++){
        ID[i][j] = ID[i+1][j];
        }
        if(i==98){
            break;
        }
    }
}
void deletescore(int d){
    for (int i=d; i<99; i++){

        for(int j=0; j<5; j++){
        score[i][j] = score[i+1][j];
        }
        if(i==98){
            break;
        }
    }
}

void search_ID(){
    char input_ID[5];
    printf("Please input student's ID: ");
    scanf("%s",&input_ID);

    for ( int i=0;i<=student_count;i++){
         if(strcasecmp(input_ID,ID[i])==0){
            printf("\nName: %s \n", name[i]);
            printf("ID: %s \n", ID[i]);

            for (int k = 0; k < 5; k++) {
                printf("Subject's name: %s \n", subject[k]);
                printf("Score: %.2f \n", score[i][k]);
            }

            printf("\nPlease Choose Your Option:\n");
            printf("1. Edit Record\n");
            printf("2. Delete Record\n");
            printf("Other. Go to main Page\n");
            printf("Option: ");
            scanf("%d", &sub_option);

            if (sub_option == 1) {
                edit(i);
            } else if (sub_option == 2) {
                deletename(i);
                deleteid(i);
                deletescore(i);

                for (int i=0; i<10; i++){
                       printf("Name: %s\nID: %s\n",name[i],ID[i]);
                       for (j=0;j<5;j++){
                        printf("Subject: %s\n",subject[j]);
                        printf("Score: %.2f\n",score[i][j]);
                       }

                }

            } else {
                cover_page();
                printf("\n Please Choose Your Option:\n");
                printf("1. Search student by name \n");
                printf("2. Search student by ID \n");
                printf("3. Show all students record \n");
                printf("4. Show only successful student \n");
                printf("5. Show all fail student \n");
                printf("6. Add new student record \n");
                printf("Other to exit the program \n");
                printf("Option :");
                scanf("%d",&option);


                    if(option==1){
                      search_name();
                    }
                    else if(option==2){
                        search_ID();
                    }
                    else if (option==3){
                        all_record();
                    }
                    else if (option==4){
                        success();
                    }
                    else if (option==5){
                        fail();
                    }
                    else if (option==6){

                        Add_record();

                    }
                    else{

                    }
            }

            return; // Exit function after finding the record
        }
    }

    // If the loop completes without finding a match
    printf("There's no record.\n");
    printf("Please choose an option:\n");
    printf("1. Search again.\n");
    printf("2. Go to main page.\n");
    printf("Option: ");
    scanf("%d", &sub_option);

    if (sub_option == 1) {
        search_ID();
    } else {
        cover_page();
        printf("\n Please Choose Your Option:\n");
                printf("1. Search student by name \n");
                printf("2. Search student by ID \n");
                printf("3. Show all students record \n");
                printf("4. Show only successful student \n");
                printf("5. Show all fail student \n");
                printf("6. Add new student record \n");
                printf("Other to exit the program \n");
                printf("Option :");
                scanf("%d",&option);


                    if(option==1){
                      search_name();
                    }
                    else if(option==2){
                        search_ID();
                    }
                    else if (option==3){
                        all_record();
                    }
                    else if (option==4){
                        success();
                    }
                    else if (option==5){
                        fail();
                    }
                    else if (option==6){

                        Add_record();

                    }
                    else{
                    printf("\nThe program is exited.\n");

                    }

    }
}



void all_record(){

        for (i=0;i<student_count;i++){
            if( control==0){
                printf("\n");
                printf("Name: %s \n",name[i]);
                printf("ID: %s \n",ID[i]);
                for (k=0;k<5;k++){
                printf("\n");
                printf("Subject's name: %s \n",subject[k]);
                printf("Score: %.2f \n",score[i][k]);

                }
                printf("\n");
                for (k=0;k<=50;k++){
                    printf("*");
                }
                printf("\n");
            }

        }

    printf("\nPlease choose an option:\n");
    printf("1. Go to main page.\n");
    printf("other. Exit the program.\n");
    printf("Option: ");
    scanf("%d", &sub_option);

    if (sub_option == 1) {
        cover_page();
        printf("\n Please Choose Your Option:\n");
                printf("1. Search student by name \n");
                printf("2. Search student by ID \n");
                printf("3. Show all students record \n");
                printf("4. Show only successful student \n");
                printf("5. Show all fail student \n");
                printf("6. Add new student record \n");
                printf("Other to exit the program \n");
                printf("Option :");
                scanf("%d",&option);


                    if(option==1){
                      search_name();
                    }
                    else if(option==2){
                        search_ID();
                    }
                    else if (option==3){
                        all_record();
                    }
                    else if (option==4){
                        success();
                    }
                    else if (option==5){
                        fail();
                    }
                    else if (option==6){

                        Add_record();

                    }
                    else{

                    }
    }
    else {

    }

}

void success(){

    int size=0;
    float sum=0;
    float avg;
    float Each_totalscore[11];
    float Each_avgscore[11];
    for (int i=0;i<student_count;i++){
        for(int k=0;k<=4;k++){
            Each_totalscore[i]+= score[i][k];
        }

    }
    for (int i=0;i<student_count;i++){

            Each_avgscore[i]= Each_totalscore[i]/5;

        //printf("student %d average score: %.2f\n",i+1,Each_avgscore[i]);

    }

    for (i=0;i<student_count;i++){
        for(k=0;k<=4;k++){
            sum+= score[i][k];
        }
    }

    for (i=0;i<student_count;i++){
        for(k=0;k<=4;k++){
            size+=1;
        }
    }

    avg=sum/size;

    printf("Average score to pass:%.2f\n",avg);
    printf("Passing Students:\n");

    for (int i = 0; i <student_count; i++) {
        if ( Each_avgscore[i]>= avg) {
            printf("Name: %s\n",name[i]);
            printf("ID: %s\n",ID[i]);
            for (k=0;k<5;k++){
                printf("Subject's name: %s \n",subject[k]);
                printf("Score: %.2f \n",score[i][k]);

            }
            for (j=0;j<=50;j++){
                printf("*");
       }
    printf("\n");

        }

    }

    printf("\nPlease choose an option:\n");
    printf("1. Go to main page.\n");
    printf("other. Exit the program.\n");
    printf("Option: ");
    scanf("%d", &sub_option);

    if (sub_option == 1) {
        cover_page();
        printf("\n Please Choose Your Option:\n");
                printf("1. Search student by name \n");
                printf("2. Search student by ID \n");
                printf("3. Show all students record \n");
                printf("4. Show only successful student \n");
                printf("5. Show all fail student \n");
                printf("6. Add new student record \n");
                printf("Other to exit the program \n");
                printf("Option :");
                scanf("%d",&option);


                    if(option==1){
                      search_name();
                    }
                    else if(option==2){
                        search_ID();
                    }
                    else if (option==3){
                        all_record();
                    }
                    else if (option==4){
                        success();
                    }
                    else if (option==5){
                        fail();
                    }
                    else if (option==6){

                        Add_record();

                    }
                    else{

                    }
    }
    else {

    }

}

//void success(){
//    int student_count= 11;
//    int size= student_count*5;
//    float sum=0;
//    float avg;
//    float Each_totalscore[100];
//    float Each_avgscore[100];
//    for (i=0;i<student_count;i++){
//        for(k=0;k<=4;k++){
//            Each_totalscore[i]+= score[i][k];
//        }
//
//    }
//    for (i=0;i<student_count;i++){
//
//            Each_avgscore[i]= Each_totalscore[i]/5;
//    }
//
//    for (i=0;i<student_count;i++){
//        for(k=0;k<=4;k++){
//            sum+= score[i][k];
//        }
//    }
//
//    avg=sum/size;
//
//    printf("Average score to pass:%.2f\n",avg);
//    printf("Passing Students:\n");
//
//    for (int i = 0; i <student_count; i++) {
//        if ( Each_avgscore[i]>= avg) {
//            printf("Name: %s\n",name[i]);
//            printf("ID: %s\n",ID[i]);
//            for (k=0;k<5;k++){
//                printf("Subject's name: %s \n",subject[k]);
//                printf("Score: %.2f \n",score[i][k]);
//
//            }
//            for (j=0;j<=50;j++){
//                printf("*");
//       }
//    printf("\n");
//
//        }
//    }
//}

void fail(){
    int size= student_count*5;
    float sum=0;
    float avg;
    float Each_totalscore[100];
    float Each_avgscore[100];
    for (i=0;i<student_count;i++){
        for(k=0;k<=4;k++){
            Each_totalscore[i]+= score[i][k];
        }

    }
    for (i=0;i<student_count;i++){

        Each_avgscore[i]= Each_totalscore[i]/5;
    }

    for (i=0;i<student_count;i++){
        for(k=0;k<=4;k++){
            sum+= score[i][k];
        }
    }

    avg=sum/size;

    printf("Average score to pass:%.2f\n",avg);
    printf("Fail Students:\n");

    for (i = 0; i <student_count; i++) {
        if ( Each_avgscore[i]<= avg) {
            printf("Name: %s\n",name[i]);
            printf("ID: %s\n",ID[i]);
            for (k=0;k<5;k++){
                printf("Subject's name: %s \n",subject[k]);
                printf("Score:%.2f \n",score[i][k]);

            }
            for (j=0;j<=50;j++){
                printf("*");
       }
    printf("\n");

        }

    }
    printf("\nPlease choose an option:\n");
    printf("1. Go to main page.\n");
    printf("other. Exit the program.\n");
    printf("Option: ");
    scanf("%d", &sub_option);

    if (sub_option == 1) {
        cover_page();
        printf("\n Please Choose Your Option:\n");
                printf("1. Search student by name \n");
                printf("2. Search student by ID \n");
                printf("3. Show all students record \n");
                printf("4. Show only successful student \n");
                printf("5. Show all fail student \n");
                printf("6. Add new student record \n");
                printf("Other to exit the program \n");
                printf("Option :");
                scanf("%d",&option);


                    if(option==1){
                      search_name();
                    }
                    else if(option==2){
                        search_ID();
                    }
                    else if (option==3){
                        all_record();
                    }
                    else if (option==4){
                        success();
                    }
                    else if (option==5){
                        fail();
                    }
                    else if (option==6){

                        Add_record();

                    }
                    else{

                    }
    }
    else {

    }
}

void Add_record(){

    int temp3;
    char a[30];
    float student_score[100];

    for( i=0; i<=99;i++){

        if(strlen(name[i])==0){
            printf("Input name: ");
            scanf("%s",&a);
        for (k=0;k<5;k++){
                printf("Please input score of subject %s: ",subject[k]);
                scanf("%f",&student_score[k]);
            }
            for(j =0; j<strlen(a);j++){
                name[i][j]=a[j];
            }

            for(k=0;k<3;k++){
                ID[i][k]= ID[i-1][k];
            }

            temp3 = ID[i-1][strlen(ID[i-1])-1]-'0';
            temp3 = temp3+1;

            ID[i][3]=temp3 +'0';

           for(j = 0; j <5; j++){
                score[i][j] = student_score[j];
            }

            student_count++;
            break;
        }
    }

    for( i = 0; i < student_count; i++){
                printf("Name: %s \nID:%s\n",name[i],ID[i]);
                for (j=0;j<5;j++){
                    printf("Subject's name: %s \n",subject[j]);
                    printf("Score: %.2f \n",score[i][j]);
                }
            }


            printf("\nPlease choose an option:\n");
    printf("1. Go to main page.\n");
    printf("other. Exit the program.\n");
    printf("Option: ");
    scanf("%d", &sub_option);

    if (sub_option == 1) {
        cover_page();
        printf("\n Please Choose Your Option:\n");
                printf("1. Search student by name \n");
                printf("2. Search student by ID \n");
                printf("3. Show all students record \n");
                printf("4. Show only successful student \n");
                printf("5. Show all fail student \n");
                printf("6. Add new student record \n");
                printf("Other to exit the program \n");
                printf("Option :");
                scanf("%d",&option);


                    if(option==1){
                      search_name();
                    }
                    else if(option==2){
                        search_ID();
                    }
                    else if (option==3){
                        all_record();
                    }
                    else if (option==4){
                        success();
                    }
                    else if (option==5){
                        fail();
                    }
                    else if (option==6){

                        Add_record();

                    }
                    else{

                    }
    }
    else {

    }
}























