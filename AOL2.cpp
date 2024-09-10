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

typedef struct{
    char location1[50];
    char location2[50];
    char price[30];
    char room[10];
    char bathrooms[10];
    char carparks[10];
    char type[100];
    char area[10];
    char furnish[100];
}dataHouse;


int main(){
    FILE *fp;
	fp = fopen("file.csv", "r");
    header head;
    dataHouse data[4000];
    fscanf(fp, "%99[^,],%99[^,],%99[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", &head.head1, &head.head2, 
																			&head.head3, &head.head4, 
																			&head.head5, &head.head6,
																			&head.head7, &head.head8, &head.head9);
        
    int idx = 0;

    do{
        fscanf(fp, "%99[^,],%99[^,],%99[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",
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
    
    char search[100],category[100];
	scanf("%s in %s", search, category);
	
	if(strcmp(category,"loc1") == 0){
		for(int i = 0;i<idx;i++){
			if(strstr(data[i].location1,search)){
				printf("%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s\n",
					data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathrooms, data[i].carparks, data[i].type, data[i].area, data[i].furnish);
			}
		}
	}
	
	if(strcmp(category,"loc2") == 0){
		for(int i = 0;i<idx;i++){
			if(strstr(data[i].location2,search)){
				printf("%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s\n",
					data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathrooms, data[i].carparks, data[i].type, data[i].area, data[i].furnish);
			}
		}
	}
	
	if(strcmp(category,"type") == 0){
		for(int i = 0;i<idx;i++){
			if(strstr(data[i].type,search)){
				printf("%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s\n",
					data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathrooms, data[i].carparks, data[i].type, data[i].area, data[i].furnish);
			}
		}
	}
	
	if(strcmp(category,"furnish") == 0){
		for(int i = 0;i<idx;i++){
			if(strstr(data[i].furnish,search)){
				printf("%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s\n",
					data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathrooms, data[i].carparks, data[i].type, data[i].area, data[i].furnish);
			}
		}
	}
	
	if(strcmp(category,"room") == 0){
		for(int i = 0;i<idx;i++){
			if(strcmp(search,data[i].room) == 0){
				printf("%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s\n",
					data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathrooms, data[i].carparks, data[i].type, data[i].area, data[i].furnish);
			}
		}
	}
	
	if(strcmp(category,"bathroom") == 0){
		for(int i = 0;i<idx;i++){
			if(strcmp(search,data[i].bathrooms) == 0){
				printf("%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s\n",
					data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathrooms, data[i].carparks, data[i].type, data[i].area, data[i].furnish);
			}
		}
	}
	
	if(strcmp(category,"carparks") == 0){
		for(int i = 0;i<idx;i++){
			if(strcmp(search,data[i].carparks) == 0){
				printf("%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s\n",
					data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathrooms, data[i].carparks, data[i].type, data[i].area, data[i].furnish);
			}
		}
	}
	
	if(strcmp(category,"area") == 0){
		for(int i = 0;i<idx;i++){
			if(strcmp(search,data[i].area) == 0){
				printf("%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s      |%s\n",
					data[i].location1, data[i].location2, data[i].price, data[i].room, data[i].bathrooms, data[i].carparks, data[i].type, data[i].area, data[i].furnish);
			}
		}
	}
	return 0;
}
