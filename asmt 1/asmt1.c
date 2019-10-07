#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* declare global var's, including total cycles, total instruction count, and clock cycle rate */
int instructionClasses;
float machineFreq;
float *CPI;
float *instructionCountOfClass;
float cpiResult;
float ExecutionTime;
float totalNumbCycles;
float totalNumbinstr;
float MIPS;
/*********************************************************/
void enterParam()
{
    /* declare local var's and initialize*/

    /* prompt for # instruction classes & clock cycle rate of machine */

    /* for each instruction class, prompt for CPI of class and instruction count */
    /* update values in appropriate glocal var's */

    printf("%s\n","Enter the number of instruction classes: ");
    scanf("%d",&instructionClasses);
    printf("%s\n","Enter the frequency of the machine (GHz): ");
    scanf("%f",&machineFreq);
    CPI= (float *) malloc(instructionClasses);
    instructionCountOfClass= (float *) malloc(instructionClasses);
    for (int i=1;i<=instructionClasses;i++){
        float temp;
        printf("%s%d%s\n","Enter CPI of class ", i,": ");
        scanf("%f", &temp);
        CPI[i-1]=temp;
        printf("%s%d%s\n","Enter instruction count of class ", i," (billions): ");
        scanf("%f", &temp);
        instructionCountOfClass[i-1]=temp;
    }

    return;
}

/*********************************************************/
void calcCPI()
{
/* declare local var's */

/* Calculate Average CPI and print result */
    totalNumbCycles=0;
    totalNumbinstr=0;
    for (int i=0;i<instructionClasses;i++){
            totalNumbCycles+=CPI[i]*instructionCountOfClass[i];
            totalNumbinstr+=instructionCountOfClass[i];
    }
    cpiResult=totalNumbCycles/totalNumbinstr;


return;
}

/*********************************************************/
void calcExecutionTime()
{
/* declare local var's */

/* Calculate Execution time and print result */


ExecutionTime=totalNumbCycles/machineFreq;

return;
}

/*********************************************************/
void calcMIPS()
{
/* declare local var's */

/* Calculate MIPS and print result */

MIPS=totalNumbinstr*1000/(ExecutionTime);

return;
}


/*********************************************************/
int main()
{
    /* declare local var's */

    /* until user chooses to quit, print menu,
    select choice via switch statement and call appropriate function*/
    bool inLoop=true;
    while(inLoop){
        printf("%s\n","Measuring Performance:" );
        printf("%s\n","---------------------- " );
        printf("%s\n","1) Enter parameters" );
        printf("%s\n","2) Calculate CPI of a sequence " );
        printf("%s\n","3) Calculate Execution time of a sequence " );
        printf("%s\n","4) Calculate MIPS of a sequence " );
        printf("%s\n","5) Exit program " );
        printf("%s\n","" );
        printf("%s","Enter selection: " );
        int selection;
        scanf("%d",&selection);
        switch(selection){
            case 1:
                enterParam();
                printf("\n");
                break;
            case 2:
                calcCPI();
                printf("%s%.2f\n","The average CPI of the sequence is: ",cpiResult);
                printf("\n");
                break;
            case 3:
                calcExecutionTime();
                printf("%s%.2f%s\n","The execution time of the sequence is: ",ExecutionTime," sec ");
                printf("\n");
                break;
            case 4:
                calcMIPS();
                printf("%s%.2f\n","The total MIPS of the sequence is: ",MIPS);

                printf("\n");
                break;
            case 5:
                inLoop=false;
                break;
            default:
                printf("%s\n","Invalid" );
                printf("\n");

        }
    }

    return 0;
}
