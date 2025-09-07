
void radixSort(int arr[], int n) {
    
    for(int i=1;i<=3;i++){
        vector<vector<int> >x(10);
        int divisor=pow(10,i-1);
        for(int j=0;j<n;j++){
            int rem=(arr[j]/divisor)%10;
            x[rem].push_back(arr[j]);
        }
        int index=0;
        for(int j=0;j<10;j++){
            for(int k=0;k<x[j].size();k++){
                arr[index]=x[j][k];
                index++;
            }
        }
    }
    
}