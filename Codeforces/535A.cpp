#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    char number[3];
    int tam;
    scanf("%s", number);
    //Os numeros estao entre 0 e 99 ( 0 <= number <= 99)
    tam = strlen(number);
    if(tam == 1){
        if(number[0] == '0'){
            printf("zero\n");
        }
        else if(number[0] == '1'){
            printf("one\n");
        }
        else if(number[0] == '2'){
            printf("two\n");
        }
        else if(number[0] == '3'){
            printf("three\n");
        }
        else if(number[0] == '4'){
            printf("four\n");
        }
        else if(number[0] == '5'){
            printf("five\n");
        }
        else if(number[0] == '6'){
            printf("six\n");
        }
        else if(number[0] == '7'){
            printf("seven\n");
        }
        else if(number[0] == '8'){
            printf("eight\n");
        }
        else if(number[0] == '9'){
            printf("nine\n");
        }
    }
    else{
        if(number[0] == '1'){
            if(number[1] == '0'){
                printf("ten\n");
            }
            else if(number[1] == '1'){
                printf("eleven\n");
            }
            else if(number[1] == '2'){
                printf("twelve\n");
            }
            else if(number[1] == '3'){
                printf("thirteen\n");
            }
            else if(number[1] == '4'){
                printf("fourteen\n");
            }
            else if(number[1] == '5'){
                printf("fifteen\n");
            }
            else if(number[1] == '6'){
                printf("sixteen\n");
            }
            else if(number[1] == '7'){
                printf("seventeen\n");
            }
            else if(number[1] == '8'){
                printf("eighteen\n");
            }
            else if(number[1] == '9'){
                printf("nineteen\n");
            }
        }
        else if(number[0] == '2'){
            if(number[1] == '0'){
                printf("twenty\n");
            }
            else if(number[1] == '1'){
                printf("twenty-one\n");
            }
            else if(number[1] == '2'){
                printf("twenty-two\n");
            }
            else if(number[1] == '3'){
                printf("twenty-three\n");
            }
            else if(number[1] == '4'){
                printf("twenty-four\n");
            }
            else if(number[1] == '5'){
                printf("twenty-five\n");
            }
            else if(number[1] == '6'){
                printf("twenty-six\n");
            }
            else if(number[1] == '7'){
                printf("twenty-seven\n");
            }
            else if(number[1] == '8'){
                printf("twenty-eight\n");
            }
            else if(number[1] == '9'){
                printf("twenty-nine\n");
            }
        }
        else if(number[0] == '3'){
            if(number[1] == '0'){
                printf("thirty\n");
            }
            else if(number[1] == '1'){
                printf("thirty-one\n");
            }
            else if(number[1] == '2'){
                printf("thirty-two\n");
            }
            else if(number[1] == '3'){
                printf("thirty-three\n");
            }
            else if(number[1] == '4'){
                printf("thirty-four\n");
            }
            else if(number[1] == '5'){
                printf("thirty-five\n");
            }
            else if(number[1] == '6'){
                printf("thirty-six\n");
            }
            else if(number[1] == '7'){
                printf("thirty-seven\n");
            }
            else if(number[1] == '8'){
                printf("thirty-eight\n");
            }
            else if(number[1] == '9'){
                printf("thirty-nine\n");
            }
        }
        else if(number[0] == '4'){
            if(number[1] == '0'){
                printf("forty\n");
            }
            else if(number[1] == '1'){
                printf("forty-one\n");
            }
            else if(number[1] == '2'){
                printf("forty-two\n");
            }
            else if(number[1] == '3'){
                printf("forty-three\n");
            }
            else if(number[1] == '4'){
                printf("forty-four\n");
            }
            else if(number[1] == '5'){
                printf("forty-five\n");
            }
            else if(number[1] == '6'){
                printf("forty-six\n");
            }
            else if(number[1] == '7'){
                printf("forty-seven\n");
            }
            else if(number[1] == '8'){
                printf("forty-eight\n");
            }
            else if(number[1] == '9'){
                printf("forty-nine\n");
            }
        }
        else if(number[0] == '5'){
            if(number[1] == '0'){
                printf("fifty\n");
            }
            else if(number[1] == '1'){
                printf("fifty-one\n");
            }
            else if(number[1] == '2'){
                printf("fifty-two\n");
            }
            else if(number[1] == '3'){
                printf("fifty-three\n");
            }
            else if(number[1] == '4'){
                printf("fifty-four\n");
            }
            else if(number[1] == '5'){
                printf("fifty-five\n");
            }
            else if(number[1] == '6'){
                printf("fifty-six\n");
            }
            else if(number[1] == '7'){
                printf("fifty-seven\n");
            }
            else if(number[1] == '8'){
                printf("fifty-eight\n");
            }
            else if(number[1] == '9'){
                printf("fifty-nine\n");
            }
        }
        else if(number[0] == '6'){
            if(number[1] == '0'){
                printf("sixty\n");
            }
            else if(number[1] == '1'){
                printf("sixty-one\n");
            }
            else if(number[1] == '2'){
                printf("sixty-two\n");
            }
            else if(number[1] == '3'){
                printf("sixty-three\n");
            }
            else if(number[1] == '4'){
                printf("sixty-four\n");
            }
            else if(number[1] == '5'){
                printf("sixty-five\n");
            }
            else if(number[1] == '6'){
                printf("sixty-six\n");
            }
            else if(number[1] == '7'){
                printf("sixty-seven\n");
            }
            else if(number[1] == '8'){
                printf("sixty-eight\n");
            }
            else if(number[1] == '9'){
                printf("sixty-nine\n");
            }
        }
         else if(number[0] == '7'){
            if(number[1] == '0'){
                printf("seventy\n");
            }
            else if(number[1] == '1'){
                printf("seventy-one\n");
            }
            else if(number[1] == '2'){
                printf("seventy-two\n");
            }
            else if(number[1] == '3'){
                printf("seventy-three\n");
            }
            else if(number[1] == '4'){
                printf("seventy-four\n");
            }
            else if(number[1] == '5'){
                printf("seventy-five\n");
            }
            else if(number[1] == '6'){
                printf("seventy-six\n");
            }
            else if(number[1] == '7'){
                printf("seventy-seven\n");
            }
            else if(number[1] == '8'){
                printf("seventy-eight\n");
            }
            else if(number[1] == '9'){
                printf("seventy-nine\n");
            }
        }
         else if(number[0] == '8'){
            if(number[1] == '0'){
                printf("eighty\n");
            }
            else if(number[1] == '1'){
                printf("eighty-one\n");
            }
            else if(number[1] == '2'){
                printf("eighty-two\n");
            }
            else if(number[1] == '3'){
                printf("eighty-three\n");
            }
            else if(number[1] == '4'){
                printf("eighty-four\n");
            }
            else if(number[1] == '5'){
                printf("eighty-five\n");
            }
            else if(number[1] == '6'){
                printf("eighty-six\n");
            }
            else if(number[1] == '7'){
                printf("eighty-seven\n");
            }
            else if(number[1] == '8'){
                printf("eighty-eight\n");
            }
            else if(number[1] == '9'){
                printf("eighty-nine\n");
            }
        }
        else if(number[0] == '9'){
            if(number[1] == '0'){
                printf("ninety\n");
            }
            else if(number[1] == '1'){
                printf("ninety-one\n");
            }
            else if(number[1] == '2'){
                printf("ninety-two\n");
            }
            else if(number[1] == '3'){
                printf("ninety-three\n");
            }
            else if(number[1] == '4'){
                printf("ninety-four\n");
            }
            else if(number[1] == '5'){
                printf("ninety-five\n");
            }
            else if(number[1] == '6'){
                printf("ninety-six\n");
            }
            else if(number[1] == '7'){
                printf("ninety-seven\n");
            }
            else if(number[1] == '8'){
                printf("ninety-eight\n");
            }
            else if(number[1] == '9'){
                printf("ninety-nine\n");
            }
        }
    }

    return 0;
}
