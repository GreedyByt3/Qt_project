

#include <stdio.h>
#include <stdlib.h>


#define IMG_ROWS 5
#define IMG_COLS 5
#define KERNEL_DIM 2 //kernel size

    unsigned char imgIn[IMG_ROWS][IMG_COLS]; //grayscale values array
    unsigned char imgOut[IMG_ROWS][IMG_COLS];

//Kernel initialization
    int kernel[KERNEL_DIM][KERNEL_DIM] = {
            {1,1},
            {1,1}
    };

    int image[3][3] = {
            {0, 1, 0},
            {0, 1, 1},
            {1, 0, 0}
    };

    int main()
    {

        //fill the img matrix
        /**for(int idxRow = 0; idxRow < IMG_ROWS; idxRow++){
            for(int idxCol = 0; idxCol < IMG_COLS; idxCol++){
                imgIn[idxRow][idxCol] = img[idxRow*IMG_COLS + idxCol];
                imgOut[idxRow][idxCol] = 0;
            }
        }*/

        int max;
        int offset = KERNEL_DIM/2;
        //Iterates over the image ignoring the borders
        for(int idxRow = offset; idxRow < IMG_ROWS - offset; idxRow++){
            for(int idxCol = offset; idxCol < IMG_COLS - offset; idxCol++){
                max = 0;
                //Iterates over the kernel
                for(int krnRow = -offset; krnRow < offset + 1; krnRow++){
                    for(int krnCol = -offset; krnCol < offset + 1; krnCol++){
                        //Max value under the kernel
                        if(kernel[offset + krnRow][offset + krnCol]*
                           image[idxRow + krnRow][idxCol + krnCol] > max)        {
                            max = image[idxRow + krnRow][idxCol + krnCol];
                        }
                    }
                }

                imgOut[idxRow][idxCol] = max;
            }
        }

        /**FILE *fp = fopen("ps_dil.log", "w");

        for(int idxRow = 0; idxRow < IMG_ROWS; idxRow++){
            for(int idxCol = 0; idxCol < IMG_COLS; idxCol++){
                fprintf(fp, "%d ", imgOut[idxRow][idxCol]);
            }
        }

        fclose(fp);*/

        for(int i = 0; i < IMG_ROWS; i++){
            for(int j = 0; j < IMG_COLS; j++){
                printf("%d, ", imgOut[i][j]);
            }
            printf("\n");
        }

        return 0;
    }
