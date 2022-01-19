#include<stdio.h>
#include<conio.h>
int jobid=0;
struct node
{
int data;
int priority;
int jobid;
};
struct queue
{
struct node array[30];
int count;
};
int parent(int index)
{
return (index-1)/2;
}
int leftChild(int index)
{
return index*2+1;
}
int rightChild(int index)
{
return index*2+2;
}
void swapNodeData(struct queue*tree,int index1,int index2)
{
int temp;
temp = tree->array[index1].data;
tree->array[index1].data = tree->array[index2].data ;
tree->array[index2].data = temp;
temp = tree->array[index1].priority;
tree->array[index1].priority = tree->array[index2].priority ;
tree->array[index2].priority = temp;
}
void reheapUp(struct queue *tree)
{
int curIndex = tree->count-1, parent = (curIndex-1)/2 ;
while( tree->array[curIndex].priority > tree->array[parent].priority && curIndex>0)
{
swapNodeData(tree,curIndex,parent);
curIndex = parent;
parent = (curIndex-1)/2 ;
}
}
void insertHeap(struct queue *tree,int data,int priority)
{
    tree->array[tree->count].data=data;
    tree->array[tree->count].priority=priority;
    tree->count++;
    reheapUp(tree);
}
void reheapDown(struct queue *tree)
{
int curIndex = 0,child;
while(( leftChild(curIndex) < tree->count && tree->array[curIndex].priority <=  tree->array[leftChild(curIndex)].priority ) || ( rightChild(curIndex) < tree->count && tree->array[curIndex].priority < tree->array[rightChild(curIndex)].priority )  )
{
if(( tree->array[leftChild(curIndex)].priority >=tree->array[rightChild(curIndex)].priority ))
child = leftChild(curIndex);
else
        child = rightChild(curIndex);
swapNodeData(tree,curIndex,child) ;
curIndex = child;
}
}
int deleteElement(struct queue *tree)
{
    swapNodeData(tree,0,tree->count-1);
    tree->count--;
    reheapDown(tree);
    return tree->count;
}
void viewNode(struct queue*tree,int index)
{
   printf("\n\t\t %d = JOB %d = PRIORITY",tree->array[index].data,tree->array[index].priority);
}
void printHeap(struct queue*tree)
{
    int index,jobid=0;
    printf("\n \tJOB COUNT---------DATA---------PRIORITY");
    for(index=0;index<tree->count;index++)
    {
        jobid+=1;
    printf("\n \t %d \t\t %d \t\t %d ", jobid,tree->array[index].data,tree->array[index].priority);
    }
}
int main()
{
    struct queue tree;
    tree.count=0;
    int n,data,priority,jobid=0;
    x:
        printf("\n\n\n\t\t\tCPU SCHEDULING (JOB ALLOCATION BASED ON PRIORITY)\n\n\n");
    printf("\n\t\t\t 1. INSERT NEW JOB \n\t\t\t 2. EXECUTE HIGHEST PRIORITY JOB \n\t\t\t 3. VIEW HIGHEST PRIORITY JOB \n\t\t\t 4. SHOW ALL JOBS \n\t\t\t 5. END SCHEDULING \n\t\t\t");
    printf("\n\n \t\t\t\t CHOOSE AN OPTION : ");
    scanf("%d",&n);
    while(n!=5)
    {
    switch(n)
    {
    case 1:
        printf("\n\tEnter a data for the JOB  : ");
        scanf("%d",&data);
        printf("\n\tEnter its priority  : ");
        scanf("%d",&priority);
        insertHeap(&tree,data,priority);
        goto x;
        break;
    case 2:
        viewNode(&tree,deleteElement(&tree));
        goto x;
        break;
    case 3:
        viewNode(&tree,0);
        goto x;
         break;
    case 4:
        printHeap(&tree);
        goto x;
        break;
    default:
    printf("\n\t\t\t\tinvalid option!");
    goto x;
    break;
    }
}
}
