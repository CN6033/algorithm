#include <stdio.h>

typedef struct node
{
	int value;
	struct node* left;
	struct node* right;
}node;


void print_tree_by_level(node* root)
{
	if(root == 0){return;}
	
	/*单层节点数不能超过99(100 - 1)个。*/
	const int size = 100;
	node* queue[size];
	/*curr指向当前节点的队列下标*/
	int curr = 0;
	/*n指向即下一个将插入节点的队列下标*/
	int n = 0;
	
	queue[n++] = root;
	/*将节点的子节点按照先左后右的顺序入队，然后该节点出队。*/
	for(;;){
		if(curr == n){//END
			break;
		}
		
		if(queue[curr]->left){
			queue[n++] = queue[curr]->left;//PUSH
		}
		
		if(queue[curr]->right){
			queue[n++] = queue[curr]->right;//PUSH
		}
		printf("%d\t", queue[curr]->value);
		++curr;//POP
		
		if(curr >=size){curr = curr%size;}
		if(n >=size){n = n%size;}
	}
	
}

int main()
{
	node arr[7];
	arr[0].value = 0;
	arr[0].left = &arr[1];
	arr[0].right = &arr[2];
	
	arr[1].value = 1;
	arr[1].left = &arr[3];
	arr[1].right = &arr[4];
	
	arr[2].value = 2;
	arr[2].left = &arr[5];
	arr[2].right = &arr[6];
	
	arr[3].value = 3;
	arr[3].left = 0;
	arr[3].right = 0;
	
	arr[4].value = 4;
	arr[4].left = 0;
	arr[4].right = 0;
	
	arr[5].value = 5;
	arr[5].left = 0;
	arr[5].right = 0;
	
	arr[6].value = 6;
	arr[6].left = 0;
	arr[6].right = 0;
	
	print_tree_by_level(arr);
}
