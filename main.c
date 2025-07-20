#include<stdio.h>
#include<string.h>

int getlasttaskid() {
    FILE *file = fopen("task.txt", "r");

    if (file == NULL)
    {
        return 0;
    }

    int last_id = 0;                            
    char line[256];                             // its an array, temporary storage for reddong each and every line of the file

    while (fgets(line, sizeof(line), file))     // reads the file line by line unless theres nothing left to read
    {
        if (sscanf(line, "%d", &last_id) == 1)  // Checks if the current line starts with a number(like 1. task: Buy milk) and extracts that number.
        {                                       // sscanf scans the file, line is the storage for one line, %d looks for a number in line, &last_id stores that number.
            
        }
        
    }   
    fclose(file);
    return last_id;
    
}
    

int main(){

printf("This is a to-do app, you can use it by using the following commands: \n");
printf("Add a task : 'task add'\n");
printf("View tasks : 'task view'\n");
printf("Mark as complete : 'task completed'\n");
printf("To delete all the tasks : 'task delete all'\n");

char command[100];
char task[200];
int task_count = getlasttaskid();               // gets the next (continuity) number of files instead of starting all over again from 0,1.

while (1)
{
    printf("Enter a command (or type 'exit' to exit the program): ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0;           //after the use of fgets, it adds a newline \n, so this strcspn removes the newline \n

    
    if (strcmp(command, "task add")== 0)
    {
        task_count++;
        FILE *f1 = fopen("task.txt", "a");
        
        printf("Enter a task: \n");
        fgets(task, sizeof(task), stdin);
        task[strcspn(task, "\n")] = 0;            // removes the newline after the use of fgets for input from keyboard.
        fprintf(f1, "%d. task : %s\n", task_count, task);
        fclose(f1);
    }


    
    
    else if (strcmp(command, "task view") == 0)
    {
        FILE *f2 = fopen("task.txt", "r");
        
        char read[256];                            // as this logic reads the file line by line, this read array stores line 1, prints it and then move on to line 2
        if (f2 == NULL)
        {
            printf("No tasks found.");
        }
        else{
            
            while (fgets(read, sizeof(read), f2))      // while loop will continue looping till it reaches the last task, f2 is the file which itll read.
            {  
                printf("%s", read); 
            }
            fclose(f2);
        }
    }
    
    
    else if (strcmp(command, "task completed") == 0)
    {   
        int mark;
        char read2[256];
        
        FILE *f3 = fopen("task.txt", "r");
        printf("Enter the task you want to mark as completed: ");
        scanf("%d", &mark);
        getchar();                                // getchar() clears the Enter key press from the input buffer
        
        if (!f3)
        {
            printf("Error: Cannot open file.\n");
        }
        
        char tasks[100][256];                   // Stores upto 100 tasks (each 255 characters max)
        int total_tasks = 0;
        while (fgets(tasks[total_tasks], 256, f3) && total_tasks < 100) {    // reads all the tasks and store them in memory to so one can modify it later
        total_tasks++;                                                       // reads one line from the file into tasks[total_tasks].
            
        }

        fclose(f3);

        if (mark < 1 || mark > total_tasks)     // so that user cannot input the task number which is not present.
        {
            printf("Error: Task number invalid.\n");
            return 1;
            
        }

        char *task_line = tasks[mark - 1];  //so that if the user wants the third task to be appended (its actually a 2nd array as array start at 0)
        task_line[strcspn(task_line, "\n")] = '\0'; // removes newline \n
        strcat(task_line, " [COMPLETED]\n");         // STRCAT  appends (is a string function)
        
        f3 = fopen("task.txt", "w");
        for (int i = 0; i < total_tasks; i++) {
        fputs(tasks[i], f3);
        }
        fclose(f3);  
        
        printf("Task %d marked as completed!\n", mark);
      
    }
    
    else if (strcmp(command, "task delete all") == 0)
    {
        FILE *f4 = fopen("task.txt", "w");

        if (f4 == NULL)
        {
            printf("ERROR: There are no tasks already.\n");
        }
        else{                        // To delete all the tasks, simply open the file in "write" and then close it.
            fclose(f4);
            printf("All the tasks have been deleted!\n");
        }  
    }
    else if (strcmp(command, "exit") == 0)
    {
        printf("Exiting the program...");
        break;
    }

    
    else
    {
        printf("Invalid command. Enter correctly or enter a valid command.\n"); 
    }

}



    return 0;
}
