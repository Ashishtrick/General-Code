 #include <iostream>
 using namespace std;
 
 bool Safetomove(int** arr,int x,int y,int n){
 	if(x<n && y<n && arr[x][y]==1){
 		return true;
	 }
	 return false;
 }
 bool Mouse_in_maze(int** arr,int x,int y,int n, int** solution_arr){
 	
 	if(x==n-1 && y == n-1)
 	{
 		solution_arr[x][y]=1;
 		return true;
	 }
 	
 	if(Safetomove(arr,x,y,n)){
 		solution_arr[x][y] = 1;
 		if(Mouse_in_maze(arr,x+1,y,n,solution_arr)){
 			return true;
		 }
		  if(Mouse_in_maze(arr,x,y+1,n,solution_arr)){
		 	return true;
		 }
		 solution_arr[x][y]=0;
		 return false;
		
	 }
	 return false;
 }
 int main()
 {
 	int n,x,y;
 	cin>>n;
 	cin>>x>>y;
 	
 	int** arr = new int*[n];
 	for(int i=0;i<n;i++){
 		arr[i] = new int[n];
	 }
	 for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 		cin>>arr[i][j];
		 }
	 }
	 	int** solution_arr = new int*[n];
 	for(int i=0;i<n;i++){
 		solution_arr[i] = new int[n];
 		for(int j=0;j<n;j++){
 			solution_arr[i][j]=0;
		 }
	 }
	 if(Mouse_in_maze(arr,x,y,n,solution_arr)){
	 	 for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++){
	 		cout<<solution_arr[i][j]<<" ";
		 }
		 cout<<endl;
	 }
	 }
	 return 0;
 }

