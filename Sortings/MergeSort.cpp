class Solution {
  public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        
        vector<int>x;
        int i=l,j=mid+1;
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                x.push_back(arr[i]);
                i++;
            }else{
                x.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            x.push_back(arr[i]);
            i++;
        }
        while(j<=r){
            x.push_back(arr[j]);
            j++;
        }
        int idx=0;
        for(int k=l;k<=r;k++){
            arr[k]=x[idx];
            idx++;
        }
        
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r) return;
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
    }
};