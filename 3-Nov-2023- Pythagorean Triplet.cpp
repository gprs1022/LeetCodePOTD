class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    unordered_map<long long, bool> mp;
	    for(int i=0;i<n;i++){
	        mp[arr[i]*arr[i]]= true;
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	           long long sum= arr[i]* arr[i] +arr[j]*arr[j];
	           if(mp[sum]){
	               return true;
	           }
	        }
	    }
	    return false;
	}
};
