#include <stdio.h>
#include <stdlib.h>
int main(void){

	int rebro_count = 0;
	int node_count = 0;
	int is_connected[255];
	for (int i = 0; i < 255; i++)
		is_connected[i] = -1;

	int a = 0, b = 0;
	scanf("%d-%d", &a, &b);
	rebro_count++;
	node_count += 2;
	is_connected[a] = 1;
	is_connected[b] = 1;
	FILE *S1;
	S1 = fopen("S1.txt", "w");
	fprintf(S1, "%s\n", "graph My_graph {");
	fprintf(S1, "%d -- %d;\n", a,b);
	do{
		scanf("%d-%d", &a, &b);
		fprintf(S1, "%d -- %d;\n", a,b);
		rebro_count++;
		if (((is_connected[a] == -1)&(is_connected[b] == -1)))
			node_count += 2;
		if (((is_connected[a] == -1)&(is_connected[b] != -1)))
			node_count += 1;
		if (((is_connected[a] != -1)&(is_connected[b] == -1)))
			node_count += 1;
		if (((is_connected[a] != -1)&(is_connected[b] != -1)))
			node_count += 0;
		//----------------------------------------------------
		if((is_connected[a] == 1)&(is_connected[b] == 1))
			is_connected[a] = is_connected[b] = 1;
		else{
			if (is_connected[a] != -1){
				int find = is_connected[b];
				//printf("%d", find);
				for (int i = 0; i < 255; i++)
					if(is_connected[i] == find)
						is_connected[i] = is_connected[a] ;
						//printf("%d", i);
			}
			if (is_connected[b] != -1){
				int find = is_connected[a];
				for (int i = 0; i < 255; i++)
					if(is_connected[i] == find)
						is_connected[i] = is_connected[b];
			}
			if ((is_connected[a] == -1)&(is_connected[b] == -1)){
				is_connected[a] = is_connected[b] = rebro_count;
			}
			//--------------------------------------------------

		}
			

	} while(getchar() != 's');
	fprintf(S1, "%s", "}");
	fclose(S1);
	int is_tree = 1;
	if ((node_count+1 -(rebro_count) != 1))
		is_tree = 0;
	for (int i = 1; i < node_count; i++){
		if(is_connected[i] != 1)
			is_tree = 0;
		//printf("%d", is_connected[i]);
	}
	if (is_tree)
		printf("%s", "Граф - дерево");
	else
		printf("%s", "Граф - не дерево");
	//printf("%d,%d", node_count,rebro_count);
	system("dot C:/Users/serad/Documents/univer/FLAT/DZ2/S1.txt -Tbmp -o S1.bmp");
	//system("rundll32 C:/Program Files/Windows Photo Viewer/PhotoViewer.dll, ImageView_Fullscreen C:/Users/serad/Documents/univer/FLAT/DZ2/S1.bmp");
	return 0;
}		