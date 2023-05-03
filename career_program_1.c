#include<stdio.h>

int stack[50];  // Stack declaration //
int top = -1;   // Top for stack  //

void push(int value) // Stack operation of push //
{
    stack[++top] = value; // Adds new element into stack //
}

void pop()  // Stack operation of pop //
{
    stack[top--];  // Removes the topmost element in stack(LIFO) //
}

int main()
{
    int my_array[50];  // User input array declaration //
    int size;           // variable to store size of user array //
    int final_array[50]; // Final array declaration //
    printf("Type the size of the array\n");  // Taking the input into the user array //
    scanf("%d", &size);
    printf("Now type the elements\n");
    for(int i =0; i< size; i++)
    {
        scanf("%d", &my_array[i]);
    }
    for(int num = size-1; num >= 0; num--)  // Driver code //
    {                                                       // Loop starts from last element of user array to the first //
        while(stack[top] < my_array[num] && top != -1)      // This is more of a if condition that pops elements if the array element is bigger than stacks element //
        {
            pop();  
        }
        if(top != -1)
            final_array[num] = stack[top];                  // Putting the value into the final array here. //
        else
            final_array[num] = -1;                          // If stack is empty then the next greater element is -1 //
        
        push(my_array[num]);                                // Pushing the value into the stack //
    }
    int num = 0;
    while(num<size)             // Just prints out the final array to display the answer //
    {
        printf("%d\t",final_array[num]);
        num++;
    }
}
// The time complexity of the code is still O(n) and not O(n^2) even though there is a while loop nested.
// This is because the while loop is conditional and acts like more of a "if" statement than a loop.
// while loop only triggers if the value in stack is less than that of the new element. hence
// at worst case it may trigger "n" times or the size of array times. hence the time complexity will be
// 2n at worst. hence the asymptotic notation will be O(n) only.