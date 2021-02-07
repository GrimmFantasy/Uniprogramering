#include <stdio.h> 
#include <stdlib.h> 

void Merge(int L[], int l, int r, int m);
void MergeSort(int L[], int l, int r);
void printList(int L[], int size);

int main(void){ 
  int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 }; 
  int L_size = sizeof(L) / sizeof(L[0]); 
  	
  printf("Givet listen \n"); 
  printList(L, L_size); 
  
  MergeSort(L, 0, L_size - 1); 
  
  printf("Er den sorterede liste \n"); 
  printList(L, L_size); 
  return 0; 
} 

void Merge(int L[], int l, int r, int m){
  /* l med at kopiere de to dellister ind i to nye lister L1 og L2, så vi ikke sletter nogle elementer fra L når vi begynder at flette elementerne derind */
  int i = 0, 
      j = 0, 
      pos, 
      k = l;
  int L1[m - l + 1];
  int L2[r - m];

  for (pos = 0; pos < m - l + 1; pos++)
  {
    L1[pos] = L[pos+l];
  }
  
  for (pos = 0; pos < r - m; pos++)
  {
    L2[pos] = L[pos+(m+1)];
  }

  while(i < m-l+1 && j < r-m)
  {
    if (L1[i] < L2[j])
    {
      L[l+i+j] = L1[i];
      i++;
    }
    else
    {
      L[l+i+j]=L2[j];
      j++;
    }
    k++;
  }

  while (i < m-l+1)
  {
    L[k]=L1[i];
    k++;
    i++;
    //printf("m\n");
  }
  while(j < r-m)
  {
    //printf("t\n");

    L[k]=L2[j];
    k++;
    j++;
  }
  /* Herefter skal vi kopiere elementer fra L1 og L2 ind på pladserne i L mellem l og r men i sorteret rækkefølge */
	
}

void MergeSort(int L[], int l, int r){
  /* Udfyld her */
  int m;
  if (l < r)
  {
    m = l + (r-l)/2;

    MergeSort(L, l, m);
    MergeSort(L, m + 1, r);
    Merge(L, l, r, m);
    
  }
}

void printList(int L[], int size){ 
  int i; 
  for (i = 0; i < size; i++) 
    printf("%d ", L[i]); 
  printf("\n"); 
} 