#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>
#include <ShellApi.h> 
#define swap(x,y) {int t = a; a = b; b = t;}
int main(void){

	int rebro_count = 0;
	int node_count = 0;
	int a = 0, b = 0;
	int link[255];
	for (int i = 0; i < 255; i++)
		link[i] = -1;

	FILE *S1;
	S1 = fopen("S1.txt", "w");
	fprintf(S1, "%s\n", "graph My_graph {");

		while(scanf("%d-%d", &a, &b) != 0){
			fprintf(S1, "%d -- %d;\n", a,b);
			rebro_count++;
		
			if(link[a]*link[b] < 0){
				if (a < b)
					swap(a,b);
				link[a] = link[b];
				node_count++;
			}
			else if ((link[a]*link[b] == 1)&&(link[a] != 1)){
				link[a] = link[b] = rebro_count;
				node_count += 2;
			}
			else{
				if (a < b)
					swap(a,b);
				int find = link[a];
				for (int i = 0; i < 255; i++){
					if(link[i] == find){
						link[i] = link[b];
					}
				}
			}
		}

	fprintf(S1, "%s", "}");
	fclose(S1);

	int is_tree = 1;
	for(int i = 1; i <255; i++){
		if((link[i] != -1)&&(link[i] != 1))
			is_tree = 0;
		}

	if ((node_count -(rebro_count)) != 1)
		is_tree = 0;

	if (is_tree)
		printf("%s", "Граф - дерево");
	else
		printf("%s", "Граф - не дерево");

	system("dot C:/Users/serad/Documents/univer/FLAT/DZ2/S1.txt -Tbmp -o S1.bmp");
	ShellExecuteA(GetDesktopWindow(),"open","C:/Users/serad/Documents/univer/FLAT/DZ2/S1.bmp",NULL,NULL,SW_SHOW);

	return 0;
}		