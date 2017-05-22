#ifndef __SoftmaxLayer__
#define __SoftmaxLayer__

using namespace std;

namespace Layers {

class SoftmaxLayer : public layer {
private:
  int* input_shape;
  int* output_shape;   
  char* prev, next;
  char* class_names;
  
  
public:
  SoftmaxLayer (
    const int* input_shape;
    const int* output_shape;
    const char* prev;
    const char* next;
    const char* class_names;
) {};
  
  void get_largest_10(vector<float> probs,int (&largest)[10]){};
  void forwardProp(const vector<float> input, vector<float> &output) {};
}

} 
