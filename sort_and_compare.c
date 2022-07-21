#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int list[100000],temp[100000];      // Array on for storing list another for shorted one
void shory_list(int n);             // which compares all algorithms
/*all shorting techniques*/
int Partition(int a[],int start,int end);
void sort_list(int n);
void Array(int a[],int n);
void swap(int *a,int *b);
void Heap_Sort(int a[],int n);
void Build_heap(int a[],int n);
void Heapify(int a[],int i,int n);
void Quick_Sort(int a[],int start,int end);
void merge_sort(int a[],int i,int n);
void merge(int a[],int start,int x,int n);
void shell(int a[],int n);
void bubble(int a[],int n);
void Insertion(int a[],int n);
void Selection(int a[],int n);
void Copy(int n);                // replaces all element of list into temp
void start_d();                 // starting design
void end_d();                   // ending design

// ---------------- MAIN FUNCTION ---------------- //

int main()
{   // set the console
    system("mode 900");

    // clear the screen
    system("cls");
    int i,n,k,j,l;
    
    A: 
    //---------- main Menu ------------//
         start_d();
         printf("  Select the option from the given list for perform the task  ");
         end_d();
    printf("\n\n\t\t\t\t 1.Adding list");
    printf("\n\t\t\t\t 2.Short and compare");
    printf("\n\t\t\t\t 3.Display");
    printf("\n\t\t\t\t 4.Exit\n\n");
    printf("\n\n\t\t\t Enter chosen option:");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
        {   B:
            printf("\n\t\t\t\tEnter number of elements : ");
            scanf("%d",&n);
            fflush(stdin);
            start_d();
            printf("  Select the option from the given list for perform the task  ");
            end_d();


            /* Different inserting method*/


            printf("\n\t\t\t\t 1.randomly");
            printf("\n\t\t\t\t 2.In Inverse sorted Manner");
            printf("\n\t\t\t\t 3.In sorted Manner");
            printf("\n\t\t\t\t 4.Add manually");
            printf("\n\n\t\t\t enter your option: ");
            scanf("%d",&k);
            fflush(stdin);
            switch(k)
            {
                case 1:
                {srand(time(0));
                   for(i=1;i<=n;i++)
                   {j=rand()%(n*10);
                    list[i]=j;}
                }break;
                case 2:
                    {j=n;
                    for(i=0;i<n;i++)list[i]=j-i;
                    }break;
                case 3:
                    {
                    for(i=0;i<=n;i++)list[i]=i+1;
                    }break;
                case 4:
                    {
                        printf("\n\t\t\t\tAdd data manually");
                        for(i=0;i<n;i++){
                        printf("\n\t\t\tenter %d th element : ",i+1);
                        scanf("%d",&list[i]);
                        }break;
                    }

            }
        }goto A;

        case 2:
            {  C: system("cls");
             for(i=1;i<=150;i++)
             printf("%c",176);
             printf("\n\n\n\t");
                printf("\n\n\n\n\t\t\tHave you added data then press 1 otherwise press 0 for adding new data\n\n\t\t\t::");
                scanf("%d",&k);
                if(k==1)
                sort_list(n);   // short and compare
                else if(k==0)
                    goto B;
                else {printf("\n\t\t\t Enter valid input ");
                    goto C;}
            }
            goto A;
        case 3:
            {                           // printing both list shorted and unsorted
                printf("\n\n\n\n\t\t Unsorted Array \t\t\t Sorted Array \n\n");
                Copy(n);
                merge_sort(temp,0,n-1);
             for(i=0;i<n;i++)
             {
                  printf("\n\t\t %d \t\t\t\t\t  %d ",list[i],temp[i]);
             }

             printf("\n\n\n\t\t\t Press any key or enter for Main Menu  !! ");
            printf("\n\n\t");
                for(i=1;i<=150;i++)
                printf("%c",176);
                char temp_input; 
                scanf("%c",&temp_input);
             goto A;
            }
        case 4:
            {
    start_d();
    printf("  Thank You!! have a great day ");
    end_d();
    printf("\n\n\n\t");
    for(i=1;i<=150;i++)
    printf("%c",176);


    }
}
}


// --------------- All Sortnig Technics handler function ------------- // 


void sort_list(int n)
{
    int i;
    double time[7];
    char name[7][25]={"Heap Sort","Quick Sort","Merge Sort","Shell Sort","Bubble Sort","Insertion Sort","Selection Sort"};
    clock_t start,end;
    for(i=0;i<7;i++)
    {

        if(i==0)
        {
            start = clock();
            Heap_Sort(temp,n);
            end = clock();
            time[i]=((double)(end-start));
        }
        if(i==1)
        {   Copy(n);
            start = clock();
            Quick_Sort(temp,0,n-1);
            end = clock();
            time[i]=((double)(end-start));
        }
        if(i==2)
        {   Copy(n);
            start = clock();
            merge_sort(temp,0,n-1);
            end = clock();
            time[i]=((double)(end-start));
        }
        if(i==3)
        {   Copy(n);
            start = clock();
            shell(temp,n);
            end = clock();
            time[i]=((double)(end-start));
        }
        if(i==4)
        {Copy(n);
            start = clock();
            bubble(temp,n);
            end = clock();
            time[i]=((double)(end-start));
        }
        if(i==5)
        {Copy(n);
            start = clock();
            Insertion(temp,n);
            end = clock();
            time[i]=((double)(end-start));
        }if(i==6)
        {   Copy(n);
            start = clock();
            Selection(temp,n);
            end = clock();
            time[i]=((double)(end-start));
        }
    } i=0;
    do
    {
        system("cls");
        printf("\n\n\n\n\n\t"); // menu
        for(i=1;i<=150;i++)
            printf("%c",176);
        printf("\n\n\n\t");
        for(i=1;i<=24;i++)
        {
            if(i<=12)
                printf(" ");
            else
                printf("%c",175);
        }
        printf("  Select technique for comparing with others  ");
        for(i=1;i<=24;i++)
        {
            if(i>=12)
                printf(" ");
            else
                printf("%c",174);
        }
        printf("\n\n");
        printf("\n\t\t\t 1. Heap  Sort");
        printf("\n\t\t\t 2. Quick  Sort");
        printf("\n\t\t\t 3. Merge  Sort");
        printf("\n\t\t\t 4. Shell  Sort");
        printf("\n\t\t\t 5. Bubble Sort ");
        printf("\n\t\t\t 6. Insertion Sort");
        printf("\n\t\t\t 7. Selection Sort");
        printf("\n\n\t");
        for(i=1;i<=150;i++)
            printf("%c",176);
        printf("\n\n\t\t\t Enter Your option :");
        scanf("%d",&i);
        switch (i)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            {
                int k,j;
                system("cls");
                printf("\n\n\n\t");
                for(k=1;k<=150;k++)
                        printf("%c",176);
                printf("\n\n\n\n\n");
                for(k=1;k<=44;k++)
                {
                    if(k<=30)
                        printf(" ");
                    else
                        printf("%c",175);
                }
                printf("  Compared result is given below  ");
                for(int k=1;k<=44;k++)
                {
                    if(k>=15)
                        printf(" ");
                    else
                        printf("%c",174);
                }
                printf("\n\n\n\n");
                for(j=0;j<7;j++)
                    {
                        printf("\n\t\t\t==>%s required time: %lf ",name[j],time[j]);
                    }
                    printf("\n\n\t\t\t Result::");
                    if((i-1)!=j)
                for(j=0;j<7;j++)
                {
                    if((i-1)!=j)
                    {
                        if(time[i]<time[j])
                            {printf("\n\n\t\t %s is less efficient than %s ",name[j],name[i-1]);
                            }
                        else if(time[i]>time[j])
                            printf("\n\n\t\t %s is more efficient than %s",name[j],name[i-1]);
                        else
                            printf("\n\n\t\t %s and %s are same efficient",name[j],name[i-1]);
                    }
                }
                printf("\n\n\n\n\n\n\t\t\t Press any key or enter for continue  !! \n\n\n\n\t");  // clear all data
                for(k=1;k<=150;k++)
                    printf("%c",176);
                char temp_input; 
                scanf("%c",&temp_input);
            }
            break;
            default:
            {
                i=0;
                system("cls");
                printf("\n\n\n\n\t\t\t Enter Valid Input form the list");
            }
            break;
        }
    }while(i==0);

}

// ---------------- Screen Graphics ------------------------//
void start_d()
{   int i;
    system("cls");
    printf("\n\n\n\n\n\t"); // menu
    for(i=1;i<=150;i++)
    printf("%c",176);
    printf("\n\n\n\t");
    for(i=1;i<=44;i++)
    {
        if(i<=26)
            printf(" ");
        else
            printf("%c",175);
    }
}
void end_d()
{   int i;
    for(i=1;i<=44;i++)
    {
        if(i>=21)
            printf(" ");
        else
            printf("%c",174);
    }
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}



// ---------------- Heap Sorrt ------------------------//

void Heapify(int a[],int i,int n)   // a-array elements,i-parant node which are checked is grater or not from child nodes,n length of array
{
    int left,right,x;  // x- index of leargest element among parant and child node , temp - temporary element
    left=(2*i)+1;   // left child
    right=2*(i+1);  // right child
    if((left<n) && (a[left]>a[i]))
        x=left;
    else
        x=i;
    if(right<n && a[right]>a[x])
        x=right;
    if(i!=x)
    {
        swap(&a[x],&a[i]);
        Heapify(a,x,n);
    }
}

void Build_heap(int a[],int n)  // Array of elements , n leangth
{
    int i;
    for(i=(n/2);i>0;i--)
        Heapify(a,i-1,n);
}

void Heap_Sort(int a[],int n)
{

    int i,temp,heapsize=n-1;    // heap size is size of Heap array
    Build_heap(a,n);
    for(i=n-1;i>0;i--)
    {
        swap(&a[0],&a[i]);
        Heapify(a,0,heapsize);
        heapsize=heapsize-1;
    }
}


// ---------------- Quick Sorrt ------------------------//


void Quick_Sort(int a[],int start,int end)   // Quick sort algo && a-array of elements, start- starting index , end - ending index
{
    int x; // x-Partition
    if(start<end)
    {
        x=Partition(a,start,end);
        Quick_Sort(a,start,x-1);
        Quick_Sort(a,x+1,end);
    }
}

int Partition(int a[],int start,int end)    // Partition algo && a-array of elements, start- starting index , end - ending index
{
    int x,j,i;
    x=a[end];
    j=start-1;
    for(i=start; i<end; i++)
    {
        if(a[i]<x)
        {
            j++;
            swap(&a[j],&a[i]);
        }
    }
    j++;
    swap(&a[j],&a[end]);
    return(j);
}


// ---------------- Merge Sorrt ------------------------//


void merge_sort(int a[], int i, int n)  // a-array elements,i-starting index,n last index
{
    int x; // x-middle
    if(i<n)
    {
        x=(i+n)/2;
        merge_sort(a,i,x);
        merge_sort(a,x+1,n);
        merge(a,i,x,n);
    }
}

void merge(int a[],int start,int x,int n)    // a-array elements,start-starting index,n last index,x-middle
{
    int b[n+1],i=start,j=x+1,k=start;    // b is temporary Array i,k,j--> for loops
    for(;i<=n;i++)
        b[i]=a[i];
    i=k;
    while(i<=x&&j<=n)
    {
        if(b[i]<=b[j])
        {
            a[k]=b[i];
            i++;
            k++;
        }
        else
        {
            a[k]=b[j];
            j++;
            k++;
        }
    }
    if(i<=x)
    {
        while(i<=x)
        {
            a[k]=b[i];
            i++;
            k++;
        }
    }
    else
    {
        while(j<=n)
        {
            a[k]=b[j];
            j++;
            k++;
        }
    }
}

// ---------------- Shell Sorrt ------------------------//

void shell(int a[],int n)
{
    int i,j,k;
    for(i=n/2;i>0;i=i/2)
    {
        for(j=i;j<n;j++)
        {
            for(k=j-i;k>=0;k=k-i)
            {
                if(a[k+i]>=a[k])
                    break;
                else
                    swap(&a[k],&a[k+i]);
            }
        }
    }
}

// ---------------- bubble Sorrt ------------------------//


void bubble(int a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
                swap(&a[j],&a[j+1]);
        }
    }
}

// ---------------- Insertion Sorrt ------------------------//


void Insertion(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while((j>=0)&&a[j]>temp)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}

// ---------------- Selection Sorrt ------------------------//

void Selection(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[k])
                k=j;
        }
        if(k!=i)
            swap(&a[k],&a[i]);
    }
}

void Copy(int n)
{
    int i=0;
    for(i=0;i<n;i++)
        {
            temp[i]=list[i];
        }
}
