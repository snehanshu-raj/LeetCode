class Solution{
public:
	void merge(int a[], int b[], int n, int m) {
	    
	   // int i, j;
	   // for(i = 0; i < n; i++)
	   // {
	   //     if(a[i] > b[0])
	   //     {
	   //         swap(a[i], b[0]);
	            
	   //         j = 0;
	   //         while(j + 1 < m and b[j] > b[j + 1])
	   //         {
	   //             swap(b[j], b[j + 1]);
	   //             j++;
	   //         }
	   //     }
	   // }
	   
	   int i = n - 1;
	   int j = 0;
	   
	   while(i >= 0 and j < m)
	   {
	       if(a[i] >= b[j])
	       {
	           swap(a[i], b[j]);
	           i--;
	           j++;
	       }
	       else
	        break;
	   }
	   
	   sort(a, a + n);
	   sort(b, b + m);
	}
};