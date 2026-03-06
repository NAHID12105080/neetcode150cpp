

// class Solution {
//   public:
//     int minMeetingRooms(vector<int> &start, vector<int> &end) {
//         // code here
//         map<int,int>mp;
        
//         int n=start.size();
        
//         for(int i=0;i<n;i++){
//             mp[start[i]]++;
//             mp[end[i]]--;
            
//         }
//             int overlap=0;
//             int maxValue=0;
//         for(auto &[u,v]:mp){
//             overlap+=v;
            
//             if(overlap>maxValue){
//                 maxValue=overlap;
//             }
//         }
//         return maxValue;
//     }
// };
