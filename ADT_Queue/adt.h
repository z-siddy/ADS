// ADT Queue task for ADS lecture of Vilnius University
// By Žygimantas Sideravičius ISI

#include <string>

using namespace std;
const int MAX_Q = 10; // The maximum count of elements in queue

//adt::ADTQueue

namespace adt{
  template<typename T>
  class ADTQueue{
    private:
      T _el[MAX_Q]; //element arr
      int _front;
      int _end;
      int _count;
    public:
      ADTQueue(){ _front = 0; _end = MAX_Q-1; _count = 0; }; //default c-tor
      // GET methods
      bool empty() const{
        return _count == 0;
      };
      int size() const{
        return _count;
      };
      // Operation methods
      void enqueue(const T &el){
        if(_count == MAX_Q)
          throw string("ERROR: QUEUE IS FILLED!");
        else{
          _end = (_end+1)%MAX_Q;
          _el[_end] = el;
          ++_count;
        }
      };
      void dequeue(){
        if(empty())
          throw string("ERROR: QUEUE IS EMPTY!");
        else{
          _front = (_front+1)%MAX_Q;
          --_count;
        }
      };
      void frontEl(T &front){
        if (empty())
          throw string("ERROR: QUEUE IS EMPTY!");
        else
          front = _el[_front];
      };
  };
}


