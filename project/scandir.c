#include <dirent.h> 
#include <stdio.h> 
#include <string.h>
#define NORMAL_COLOR  "\x1B[0m"
#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"

void show_dir_content(char * path,int *a,int *b)
{
  	
  	DIR * d = opendir(path); 
  	if(d==NULL) return; 
  	struct dirent * dir;
  	while ((dir = readdir(d)) != NULL)
    	{
     		if(dir-> d_type != DT_DIR) 
		{
        		printf("%s%s\n",BLUE, dir->d_name);
			*a=*a+1;
		}
     		else if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ) 
      		{
			*b=*b+1;
        		printf("%s%s\n",GREEN, dir->d_name); 
        		char d_path[255]; 
        		sprintf(d_path, "%s/%s", path, dir->d_name);
        		show_dir_content(d_path,a,b); 
      		}
	}
    	closedir(d); 
}
void scan_s()
{
	system("date>>log.txt");
	int a=0,b=0;
	char arr[1024];
	printf("enter the path\n");
	scanf("%s",arr);
  	printf("%s\n", NORMAL_COLOR);
	show_dir_content(arr,&a,&b);
	printf("%sTotal	number of files:%d\n",GREEN,a);
	printf("%sTotal	number of folders:%d\n",BLUE,b);
	printf("%s\n", NORMAL_COLOR);
	
	//system("(echo Total number of files and folders are scanned)>>log.txt");
	//system("printf("%d %d",a,b)>>log.txt");
	return;
	
}

