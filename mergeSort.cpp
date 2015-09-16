#include <iostream>

using namespace std;

int inver = 0;

void mmerge(int arr[], int arrAux[], int lo, int mid, int hi)
{
    int k;
    for(k = lo; k <= hi; k++)
        arrAux[k] = arr[k];
    int i = lo, j = mid+1;
    for(k = lo; k <= hi; k++)
    {
        if(i > mid)         arr[k] = arrAux[j++];
        else if(j > hi)     arr[k] = arrAux[i++];
        else if(arrAux[i] > arrAux[j]){
            arr[k] = arrAux[j++];
            inver += k - lo;
        }else{
            arr[k] = arrAux[i++];
        }
    }
}

void ssort(int arr[], int arrAux[], int lo, int hi)
{
    if(lo >= hi) return;
    int mid = (lo + hi)/2;
    ssort(arr, arrAux, lo, mid);
    ssort(arr, arrAux, mid+1, hi);
    mmerge(arr, arrAux, lo, mid, hi);
}

void mergeSort(int arr[], int n)
{
    int arrAux[n];
    ssort(arr, arrAux, 0, n-1);
}

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[] = {2, 43, 5, 23, 632, 75, 12, 9, 32, 25};
    print(arr, 10);
    mergeSort(arr, 10);
    print(arr, 10);

    return 0;
}
