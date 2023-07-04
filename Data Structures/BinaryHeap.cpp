#include <iostream>
#include <conio.h>
using namespace std;

// Run Successfully !

// Minimum Order Binary Heap Tree
// _______________________________

void minBH(int *pq, int i, int data)
{
   int lc, t, rc;
   t = pq[i];
   lc = 2 * i;  // left node
   rc = lc + 1; // right node

   while (lc <= data)
   {
      if (lc < data && pq[rc] < pq[lc])
         lc = rc;
      if (t < pq[lc])
         break;
      else if (t >= pq[lc])
      {
         pq[lc / 2] = pq[lc];
         lc = 2 * lc;
      }
      else{
         break;
         
      }
   }
   pq[lc / 2] = t;
}
void creation(int *pq, int n)
{ // root node creation with i/2 index
   int k;
   for (k = n / 2; k >= 1; k--)
   {
      minBH(pq, k, n);
   }
}
int main()
{
   int n, i;
   cout << "Enter number of elements of an array\n";
   cout << "=====================================\n";
   cin >> n;
   int a[30];
   for (i = 1; i <= n; i++)
   {
      cout << "Enter element"
           << " " << (i) << endl;
      cout << "===============\n";
      cin >> a[i];
   }
   creation(a, n);
   cout << "Your Minimum Order Binary Heap Tree is ready :\n";
   cout << "==============================================\n";
   for (i = 1; i <= n; i++)
   {
      cout <<" "<< a[i]<<"\n"<<"/ "<<"\\"<< endl;
      
   }
   
}