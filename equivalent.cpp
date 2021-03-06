/*given an unsorted array of integers design a algorithm and implement it using a program to check whether two element exist such 
 *that their sum is equivalent to the given key
 */
#include<iostream>
#include<vector>
using namespace std;

class EquivalentSum{
private:
   vector<int>arr,brr;
   int l;
public:
    EquivalentSum(){
   l=0;
   }
   void inputVector(){
      cout<<"Input the size of the array : ";
	  cin>>l;
	  int temp;
      cout<<"Input Elements into the array :\n";
      for(int i=0;i<l;i++){
	    cin>>temp;
		arr.push_back(temp);
		brr.push_back(0);
      }
   }
   void sortMerge(){
      sortAndMerge(0,l-1);
   }
   void sortAndMerge(int i,int j){
    if(i<j){
	  int mid=i+(j-i)/2;
	  sortAndMerge(i,mid);
	  sortAndMerge(mid+1,j);
	  merge(i,mid,j);
	}
   }
   void merge(int i,int mid,int j){
     int k=i,m=i,n=mid+1;
	 while(m<=mid&&n<=j){
        if(arr[m]<arr[n])
	     brr[k++]=arr[m++];	
		  else
		  brr[k++]=arr[n++];
	 }
	 while(m<=mid)
	   brr[k++]=arr[m++];
     while(n<=j)
	  brr[k++]=arr[n++];
     for(int a=i;a<k;a++)
	  arr[a]=brr[a];
	 }
	 void display(){
	  cout<<" Sorted array : ";
	  for(int i=0;i<l;i++)
	    cout<<arr[i]<<" ";
	 }
    bool isEquivalentKey(int key){
     int i=0,j=l-1;
     while(i<j){
      if(arr[i]+arr[j]==key)
        return 1;
      else if(arr[i]+arr[j]>key)
        j--;
      else 
       i++; 
      }
      return 0;
    }
};
int main(){
  EquivalentSum *m=new EquivalentSum();
  m->inputVector();
  m->sortMerge();
  int ch,num;
  while(1){
   cout<<"\npress 1 to continue or press 0 to exit :";
   cin>>ch;
   if(ch==0)break;
   cout<<"Enter a number to find whether a pair exits whose sum is equivalent to the  number :";
   cin>>num;
    if(m->isEquivalentKey(num)){
     cout<<"pair exists"<<endl;
    }
    else{
      cout<<"pair does not exit"<<endl;
    }
  }
  return 0;
}