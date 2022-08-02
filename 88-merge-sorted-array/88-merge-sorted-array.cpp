class Solution {
public:
    //Gap Method
    //T.C & S.C -> O(n * log(n)) & O(1)
    
     void merge(vector<int>& a, int m, vector<int>& b, int n) {
         
         for(int i = m, j = 0; i < m + n, j < n; i++, j++)
         {
             a[i] = b[j];
         }
         
         int gap = ceil((float)(m + n) / 2);
         int p1, p2;
         
         while(gap > 0)
         {
             p1 = 0;
             p2 = gap;
             
             while(p2 < m + n)
             {
                 if(a[p1] > a[p2])
                     swap(a[p1], a[p2]);
                 
                 p1++;
                 p2++;
             }
             
             if(gap == 1)
                 break;
             else
                 gap = ceil((float)(gap) / 2);
         }
    }
};
    /*
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        //TC-O(m+n),SC-O(1)
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0){
            if(a[i]>b[j]) a[k--]=a[i--];
            else a[k--]=b[j--];
        }
        
        //remaining elements if any in vector b
        while(j>=0) a[k--]=b[j--];
        
        //note that we don't need to do the above step for vector a because the elements are already 
        //sorted in place in vector a and we are returning vector a as the answer only
    }
    */