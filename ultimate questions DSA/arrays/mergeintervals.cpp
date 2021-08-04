#include<bits/stdc++.h>
using  namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr,int rowsize) {
        
        int k=0;
        vector<vector<int>> res;

        for(int i=0;i<rowsize;i++)
        {   
             cout<<i<<"This is value of i "<<endl;
          for(int j=i+1;j<rowsize;j++)
          {    
               vector<int> row;
             if(arr[j][0]<=arr[i][1] && arr[i][1]<=arr[j][1])
             {
                     int mini = min(arr[i][0],arr[j][0]);
                     row.push_back(mini);
                     row.push_back(arr[j][1]);
                     i++;
                     break;
                     
             }

             else
             {     cout<<"the value of i is:"<<i<<endl;
                   row.push_back(arr[i][0]);
                   row.push_back(arr[i][1]);
                   cout<<arr[2][0]<<" "<<endl;
                  //  cout<<row[0]<<" "<<endl;
                  //  cout<<row[1]<<" "<<endl;
             }
                  res.push_back(row);
          }
           
        }
         
      return res;  
    }
};
int main(){

  

  vector<vector<int>> matrix; 
  int rowsize;
  cout<<"enter the row size:";
  cin>>rowsize;

	for(int i=0;i<rowsize;++i) { 
		//Create a vector  
		vector<int> row; 
		for(int j=0;j<2;++j){ 
			int value; 
			cin >> value; 
			row.push_back(value); 
		} 
		//Push the row in matrix 
		matrix.push_back(row); 
	} 

  Solution pappu;

   
           
  vector<vector<int>> v1= pappu.merge(matrix,rowsize);

  for(int i=0;i<rowsize;i++){
     for(int j=0;j<2;j++){
        cout<<v1[i][j]<<" ";
     }
      cout<<endl;
  }
  
   
	
	return 0; 
}
   
