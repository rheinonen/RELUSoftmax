#ifndef __RELULayer__
#define __RELULayer__

using namespace std;

namespace Layers {

class RELULayer : public layer {
private:
  int* input_shape;
  int* output_shape;
  
  char* prev, next;
  
public:
  RELULayer (
    const int* input_shape;
    const int* output_shape;
    const char* prev;
    const char* next;
) {};

  void forwardProp(const vector<float> input, vector<float> &output) {};

}

} 
