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
	char location1[100];
	char location2[100];
	long long price;
	int room;
	int bathrooms;
	int carparks;
	char type[100];
	int area;
	char furnish[100];
}dataHouse;


int main(){
	FILE *fp;
	fp = fopen("file.csv","r");
	header head;
	dataHouse data[4000];
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
	
	char searching[100];
	printf(">> "); 
	scanf("%s", &searching); getchar();
	
	if(strcmp(searching, "loc1") == 0 || strcmp(searching, "loc2") == 0 || strcmp(searching, "type") == 0 || strcmp(searching, "furnish") == 0){
		if(strcmp(searching, "loc1") == 0){
			int total[4000]; 
			int c = 0; 
			int count = 0;
			for(int i = 0;i<idx;i++){
				c = 1;
				if(strcmp(data[i].location1, "-1") != 0){
					for(int j = i+1;j<idx;j++){
						if(strcmp(data[i].location1, data[j].location1) == 0){
							c++;
							strcpy(data[j].location1, "-1");
						}
					}
					total[i] = c;
				}
			}

			for(int i = 0;i<idx;i++){
				if(strcmp(data[i].location1, "-1") != 0){
					printf("%s : %d\n", data[i].location1, total[i]);
				}
			}

			int max = 0;
			
			for(int i = 0;i<idx;i++){
				if(total[i] > max){
					max = total[i];
				}
			}
			
			int min = max;

			for(int i = 0;i<idx;i++){
				if(total[i] < min && total[i] != 0){
					min = total[i];
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == max){
					printf("Maximum Value: %s with frequency: %d\n", data[i].location1, max);
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == min && total[i] != 0){
					count = i;
				}
			}
			printf("Minimum Value: %s with frequency: %d\n", data[count].location1, min);
		}
		
		if(strcmp(searching, "loc2") == 0){
			int total[4000]; 
			int c = 0;
			for(int i = 0;i<idx;i++){
				c = 1;
				if(strcmp(data[i].location2, "-1") != 0){
					for(int j = i+1;j<idx;j++){
						if(strcmp(data[i].location2, data[j].location2) == 0){
							c++;
							strcpy(data[j].location2, "-1");
						}
					}
					total[i] = c;
				}
			}
			for(int i = 0;i<idx;i++){
				if(strcmp(data[i].location2, "-1") != 0){
					printf("%s : %d\n", data[i].location2, total[i]);
				}
			}
			
			int max = 0;
			
			for(int i = 0;i<idx;i++){
				if(total[i] > max){
					max = total[i];
				}
			}
			
			int min = max;
			for(int i = 0;i<idx;i++){
				if(total[i] < min && total[i] != 0){
					min = total[i];
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == max){
					printf("Maximum Value: %s with frequency: %d\n", data[i].location2, max);
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == min && total[i] != 0){
					printf("Minimum Value: %s with frequency: %d\n", data[i].location2, min);
				}
			}
		}
		
		if(strcmp(searching, "type") == 0){
			int total[4000];
			int c = 0;
			for(int i = 0;i<idx;i++){
				c = 1;
				if(strcmp(data[i].type, "-1") != 0){
					for(int j = i+1;j<idx;j++){
						if(strcmp(data[i].type, data[j].type) == 0){
							c++;
							strcpy(data[j].type, "-1");
						}
					}
					total[i] = c;
				}
			}
			for(int i = 0;i<idx;i++){
				if(strcmp(data[i].type, "-1") != 0){
					printf("%s : %d\n", data[i].type, total[i]);
				}
			}
			
			int max = 0;
			
			for(int i = 0;i<idx;i++){
				if(total[i] > max){
					max = total[i];
				}
			}
			
			int min = max;
			for(int i = 0;i<idx;i++){
				if(total[i] < min && total[i] != 0){
					min = total[i];
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == max){
					printf("Maximum Value: %s with frequency: %d\n", data[i].type, max);
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == min && total[i] != 0){
					printf("Minimum Value: %s with frequency: %d\n", data[i].type, min);
				}
			}
		}
		
		if(strcmp(searching, "furnish") == 0){
			int total[4000];
			int c = 0;
			for(int i=0;i<idx;i++){
				c = 1;
				if(strcmp(data[i].furnish, "-1") != 0){
					for(int j = i+1;j<idx;j++){
						if(strcmp(data[i].furnish, data[j].furnish) == 0){
							c++;
							strcpy(data[j].furnish, "-1");
						}
					}
					total[i] = c;
				}
			}
			for(int i = 0;i<idx;i++){
				if(strcmp(data[i].furnish, "-1") != 0){
					printf("%s : %d\n", data[i].furnish, total[i]);
				}
			}
			
			int max = 0;
			
			for(int i = 0;i<idx;i++){
				if(total[i] > max){
					max = total[i];
				}
			}
			
			int min = max;
			for(int i = 0;i<idx;i++){
				if(total[i] < min && total[i] != 0){
					min = total[i];
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == max){
					printf("Maximum Value: %s with frequency: %d\n", data[i].furnish, max);
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == min && total[i] != 0){
					printf("Minimum Value: %s with frequency: %d\n", data[i].furnish, min);
				}
			}
		}
	}
	
	if(strcmp(searching, "room") == 0 || strcmp(searching, "bathrooms") == 0 || strcmp(searching, "carparks") == 0){
		if(strcmp(searching, "room") == 0){
			int total[4000];
			int c = 0;
			for(int i = 0;i<idx;i++){
				c = 1;
				if(data[i].room != -1){
					for(int j = i+1;j<idx;j++){
						if(data[i].room == data[j].room){
							c++;
							data[j].room = -1;
						}
					}
					total[i] = c;
				}
			}
			for(int i = 0;i<idx;i++){
				if(data[i].room != -1){
					printf("Rumah Dengan Ruangan %d Ada %d\n", data[i].room, total[i]);
				}
			}
			
			int max = 0;
			
			for(int i =0 ;i<idx;i++){
				if(total[i] > max){
					max = total[i];
				}
			}
			
			int min = max;

			for(int i = 0;i<idx;i++){
				if(total[i] < min && total[i] != 0){
					min = total[i];
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == max){
					printf("Maximum Value: %d with frequency: %d\n", data[i].room, max);
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == min && total[i] != 0){
					printf("Minimum Value: %d with frequency: %d\n", data[i].room, min);
				}
			}
		}
		
		if(strcmp(searching, "bathrooms") == 0){
			int total[4000];
			int c = 0;
			for(int i = 0;i<idx;i++){
				c = 1;
				if(data[i].bathrooms != -1){
					for(int j = i+1;j<idx;j++){
						if(data[i].bathrooms == data[j].bathrooms){
							c++;
							data[j].bathrooms = -1;
						}
					}
					total[i] = c;
				}
			}
			for(int i = 0;i<idx;i++){
				if(data[i].bathrooms != -1){
					printf("Rumah Dengan Kamar Mandi %d Ada %d\n", data[i].bathrooms, total[i]);
				}
			}
			
			int max = 0;
			
			for(int i = 0;i<idx;i++){
				if(total[i]>max){
					max = total[i];
				}
			}
			
			int min = max;

			for(int i = 0;i<idx;i++){
				if(total[i] < min && total[i] != 0){
					min = total[i];
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == max){
					printf("Maximum Value: %d with frequency: %d\n", data[i].bathrooms, max);
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == min && total[i] != 0){
					printf("Minimum Value: %d with frequency: %d\n", data[i].bathrooms, min);
				}
			}
		}
		
		if(strcmp(searching, "carparks") == 0){
			int total[4000];
			int c = 0;
			for(int i = 0;i<idx;i++){
				c = 1;
				if(data[i].carparks != -1){
					for(int j = i+1;j<idx;j++){
						if(data[i].carparks == data[j].carparks){
							c++;
							data[j].carparks = -1;
						}
					}
					total[i] = c;
				}
			}
			for(int i = 0;i<idx;i++){
				if(data[i].carparks != -1){
					printf("Rumah Dengan Parkir Mobil %d Ada %d\n", data[i].carparks, total[i]);
				}
			}
			
			int max = 0;
			
			for(int i = 0;i<idx;i++){
				if(total[i] > max){
					max = total[i];
				}
			}
			
			int min = max;

			for(int i = 0;i<idx;i++){
				if(total[i] < min && total[i] != 0){
					min = total[i];
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == max){
					printf("Maximum Value: %d with frequency: %d\n", data[i].carparks, max);
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(total[i] == min && total[i] != 0){
					printf("Minimum Value: %d with frequency: %d\n", data[i].carparks, min);
				}
			}
		}
	}
	
	if(strcmp(searching, "area") == 0 || strcmp(searching, "price") == 0){
		if(strcmp(searching, "area") == 0){
			int max = 0;
			for(int i = 0;i<idx;i++){
					if(data[i].area > max){
						max = data[i].area;
					}
				}
				
			int min = max;

			for(int i = 0;i<idx;i++){
				if(data[i].area < min){
					min = data[i].area;
				}
			}
				
			for(int i = 0;i<idx;i++){
				if(data[i].area == max){
					printf("Maximum Value: %d\n", max);
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(data[i].area == min){
					printf("Minimum Value: %d\n", min);
				}
			}
			int sum;
			for(int i = 0;i<idx;i++){
				sum += data[i].area;
			}
			printf("Average Value: %d\n", sum/idx);
		}
		
		if(strcmp(searching, "price") == 0){
			int max = 0;
			for(int i = 0;i<idx;i++){
					if(data[i].price>max){
						max = data[i].price;
					}
				}
	
			int min = max;

			for(int i = 0;i<idx;i++){
				if(data[i].price<min){
					min = data[i].price;
				}
			}
				
			for(int i = 0;i<idx;i++){
				if(data[i].price == max){
					printf("Maximum Value: %d\n", max);
				}
			}
			
			for(int i = 0;i<idx;i++){
				if(data[i].price == min){
					printf("Minimum Value: %d\n", min);
					break;
				}
			}
			
			int sum;
			for(int i = 0;i<idx;i++){
				sum += data[i].price;
			}
			printf("Average Value: %d\n", sum/idx);
		}
	}
	return 0;
}
