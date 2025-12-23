// #include <stdio.h>
// int main(){
// int mat[3][3]={
//   {1,2,3},
//   {4,5,6},
//   {7,8,9}
// };
// int scol=0,srow=0,ecol=2,erow=2;
// int arr[3][3],col=0,row=0;
// while(scol<=ecol && srow<=erow){
//   for(int i=scol;i<=ecol;i++){
//     arr[row++][col++]=mat[srow][i];
//   }
//   for(int j=srow+1;j<=erow;j++){
//     arr[row++][col++]=mat[j][ecol];
//   }
//   for (int k=ecol-1; k>=scol; k--)
//   {
//    arr[row++][col++]=mat[erow][k];
//   }
//   for(int i=erow-1;i>=srow+1;i--){
//     arr[row++][col++]=mat[i][scol];
//   }
//   srow++;scol++;ecol--;erow--;
// }
// for(int i=0;i<row;i++){
//   for(int j=0;j<col;j++){
//     printf("%d ",arr[i][j]);
//   }
//   printf("\n");
// }
// return 0;
// }
#include <stdio.h>
int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int srow = 0, scol = 0, erow = 2, ecol = 2;
    int arr[9];  
    int index = 0;
    while (srow <= erow && scol <= ecol) {
        for (int i = scol; i <= ecol; i++)
            arr[index++] = mat[srow][i];
        for (int i = srow + 1; i <= erow; i++)
            arr[index++] = mat[i][ecol];
        if (srow < erow) {
            for (int i = ecol - 1; i >= scol; i--)
                arr[index++] = mat[erow][i];
        }
        if (scol < ecol) {
            for (int i = erow - 1; i > srow; i--)
                arr[index++] = mat[i][scol];
        }
        srow++;
        erow--;
        scol++;
        ecol--;
    }
    printf("Spiral order: ");
    for (int i = 0; i < index; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
