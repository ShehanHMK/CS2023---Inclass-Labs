#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int l = 2*root+1;
   int r = 2*root+2;
   int largest;

   if(l<n && arr[l]>arr[root]){
        largest = l;
   }
   else{
        largest = root;
   }

   if(r<n && arr[r]>arr[largest]){
        largest = r;
   }

   if( largest != root){
      swap(arr[root], arr[largest]);
      heapify(arr,n,largest);
        
   }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
   // extracting elements from heap one by one

   for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{ 
   int size;
   cout<<"Enter the size of the array : "<<endl;
   cin>>size;
   int heap_arr[size];
   
   cout<<"Enter the elements of the array "<<endl;

   for(int i=0; i<size;i++){
      cin>>heap_arr[i];
   }
   cout<<endl;
  
   heapSort(heap_arr, size);
  
   cout << "Sorted array is : "<<endl;
   displayArray(heap_arr, size);
}