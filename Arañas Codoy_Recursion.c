#include <stdio.h>
int getQuotient(int A, int B, int quotient){
    if(A-B >= 0){
        quotient++;
        A -= B;
        return getQuotient(A,B,quotient);
    }else{
        return quotient;
    }
}

int gcd (int A, int B) {
    if(B == 0){
        return A;
    }else{
        return gcd(B, A%B);
    }
}

void mergeSort(int arr[], int first, int last){
    if(first < last){
        int mid = (first+last)/2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid+1, last);                   
        
        int tempArray[last-first+1];
        int i = first, j = mid+1, k = 0;

        while(i <= mid && j <= last){
            if(arr[i] < arr[j]){
                tempArray[k++] = arr[i++];             
            } else {
                tempArray[k++] = arr[j++];
            }
        }

        while(i <= mid){
            tempArray[k++] = arr[i++];
        }
                                                       
        while(j <= last){
            tempArray[k++] = arr[j++];
        }

        for(i = first; i <= last; i++){
            arr[i] = tempArray[i-first];
        }
    }
}

int binarySearch(int arr[], int first, int last, int target){
    if (first > last) {
        return 0;
    }
    int mid = (first+last)/2;                               
    if (target == arr[mid]){
        return 1;
    } else if (target < arr[mid]){
        binarySearch(arr, first, mid-1, target);
    } else {
        binarySearch(arr, mid+1, last, target);
    } 
}


int main() {
    int input, A, B, N;
    do {
        printf("\nEnter input numbers 1-3 (4 to exit): ");
        scanf ("%d", &input);
    switch(input){
        case 1:
            printf("CHOICE INPUT 1\n");
            printf("Input two positive integers:");
            do {
                scanf("%d %d",&A,&B);
            } while (A<=0 || B<=0);
            printf("%d\n", getQuotient(A, B, 0));
            break;
        case 2:
            printf("CHOICE INPUT 2\n");
            printf("Input two integers:");
            scanf("%d %d",&A,&B);
            if(A<0){
                A *= -1;
            }
            if (B<0) {
                B *= -1;
            }
            printf ("%d\n", gcd(A,B) == 1 ? 1 : 0);
            break;
        case 3:
        {
            do{
                printf("How many elements do you want to put in your array (2-20)?: ");
                scanf("%i", &A); 
            } while(A < 2 || A > 20);
            
            printf("Please input %i array elements:\n", A);
            int arr[A];
            for(int i = 0; i < A; i++) {
                scanf("%i", &arr[i]);
            }
            mergeSort(arr, 0, A-1);
            printf ("SORTED ARRAY:\n");
            for(int i = 0; i < A; i++) {
                printf("%i\t", arr[i]);
            }

            printf("\nEnter the integer that you want to verify: ");
            scanf("%d", &N);
            printf("%d", binarySearch(arr, 0, A-1, N));
            break;
        }
        case 4:
            printf("Exited.");
            break;
        default:
            //invalid
            break;
    }
    } while (input != 4);
    return 0;   
}

