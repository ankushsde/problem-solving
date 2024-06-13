// leetcode daily challange 

// using sorting
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
         int res = 0;
     sort(seats.begin(), seats.end());
     sort(students.begin(), students.end());
      
     
     for(int i =0 ; i< seats.size(); i++){
          res+= abs(seats[i]-students[i]);
     }
     
     return res;
    }
};

// better way O(n)

#include <bits/stdc++.h>
using namespace std;

 int minMovesToSeat(vector<int>& seats, vector<int>& students) {
     int maxPosition = 100;
     int res = 0;
     vector<int> seatCount(maxPosition + 1, 0);
     vector<int> studentsCount(maxPosition + 1, 0);
     
     for( auto seat: seats){
         seatCount[seat]++;
     }
     for( auto student: students){
         studentsCount[student]++;
     }
     int moves = 0;
     int seatIndex = 1, studentIndex = 1;
     while(seatIndex <= maxPosition && studentIndex<< maxPosition ){
         
         while(seatIndex <= maxPosition && seatCount[seatIndex]==0){
             seatIndex++;
         }
         while(studentIndex <=maxPosition && studentsCount[studentIndex]==0){
             studentIndex++;
         }
         if(seatIndex <= maxPosition && studentIndex<=maxPosition){
           int minCount = std::min(seatCount[seatIndex],studentsCount[studentIndex]);

                // Calculate the moves for the current position
                moves += minCount * std::abs(seatIndex - studentIndex);

                // Decrease the count of seats and students matched
                seatCount[seatIndex] -= minCount;
                studentsCount[studentIndex] -= minCount;
         }
     }
     
     return moves;
 }

int main()
{
    vector<int> seats = {2,2,6,6};
    vector<int> students = {1,3,2,6};
     cout<< "answer: "<<  minMovesToSeat(seats, students )<<endl;
    return 0;
}

