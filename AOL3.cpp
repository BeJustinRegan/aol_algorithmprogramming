#include<stdio.h>
#include<string.h>

typedef struct{
    char head1[100];
    char head2[100];
    char head3[100];
    char head4[100];
    char head5[100];
    char head6[100];
    char head7[100];
    char head8[100];
    char head9[100];
}header;

struct dataHouse{
    char location1[100];
    char location2[100];
    long long price;
    int room;
    int bathrooms;
    int carparks;
    char type[100];
    int area;
    char furnish[100];
}data[4000];

int main(){
    FILE *fp; 
	fp = fopen("file.csv", "r"); 
	header head;
    fscanf(fp, "%99[^,],%99[^,],%99[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", &head.head1, &head.head2,
																			&head.head3, &head.head4, 
																			&head.head5, &head.head6, 
																			&head.head7, &head.head8, &head.head9);
        
    int idx = 0;                

    do{
        fscanf(fp, "%99[^,],%99[^,],%lld,%d,%d,%d,%99[^,],%d,%s\n",
        &data[idx].location1,
        &data[idx].location2,
        &data[idx].price,
        &data[idx].room,
        &data[idx].bathrooms,
        &data[idx].carparks,
        &data[idx].type,
        &data[idx].area,
        &data[idx].furnish);
        idx++;
    }while(!feof(fp));
    
    fclose(fp);
    
    for(int i = 0;i<idx-1;i++){
        for(int j = 0;j<idx-1-i;j++){
            struct dataHouse temp;
            if(strcmp(data[j].location1,data[j+1].location1) > 0){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
    for(int i = 0;i<idx;i++){
            printf("%s      |%s       |%lld       |%d       |%d       |%d       |%s       |%d       |%s\n",
                data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathrooms, data[i].carparks, data[i].type, data[i].area, data[i].furnish);
	}
	return 0;
}
