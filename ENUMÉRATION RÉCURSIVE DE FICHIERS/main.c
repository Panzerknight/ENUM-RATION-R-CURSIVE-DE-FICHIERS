#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>


void listDirectories(char* base_path, const int root);

/**
 * Entry Point
 */
int main()
{
	//Path to start list sub-directories limit size 100
	char path[100];

	//The start directory
	printf("Entrer le répertoire de commencement: ");
	scanf("%s", path);

	listDirectories(path, 0);
}

/**
 * Recursive file fonction
 * 
 * @param base_path char
 * @param root int
 */
void listDirectories(char* base_path, const int root)
{
	int i;
	char path[1000];
	struct dirent* dp;
	DIR* dir = opendir(base_path);

	//If dir not exist pass
	if (!dir)
		return;

	//While readdir is not null
	while ((dp = readdir(dir)) != NULL)
	{
		//If the name is not . & not .. & is type dir print the name
		if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 && dp->d_type == DT_DIR)
		{
			for (i = 0; i < root; i++)
			{
				if (i % 2 == 0 || i == 0)
					printf("%c", 179);
				else
					printf(" ");

			}

			printf("%c%c%s\n", 195, 196, dp->d_name);

			strcpy(path, base_path);
			strcat(path, "/");
			strcat(path, dp->d_name);

			//The boucle for list sub directories
			listDirectories(path, root + 2);
		}
	}

	closedir(dir);
}