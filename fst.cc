#include <iostream>
#include <fst/vector-fst.h>
#include <fst/compose.h>
#include <fst/determinize.h>

using namespace fst;
using namespace std;

extern "C" 
{

__attribute__((used)) StdVectorFst* StdVectorFst_Create() {
    return new StdVectorFst();
  }

  void StdVectorFst_Free(StdVectorFst* fst) {
    delete fst;
  }

  int StdVectorFst_AddState(StdVectorFst* fst) {
    return fst->AddState();
  }

  void StdVectorFst_AddArc(StdVectorFst* fst, int state, int ilabel, int olabel, float weight, int nextstate) {
    fst->AddArc(state, StdArc(ilabel, olabel, weight, nextstate));
  }

  void StdVectorFst_SetStart(StdVectorFst* fst, int state) {
     fst->SetStart(state);
  }

  void StdVectorFst_SetFinal(StdVectorFst* fst, int state, float weight) {
     fst->SetFinal(state, weight);
  }
  int StdVectorFst_Start(StdVectorFst* fst) {
    return fst->Start();
  }

  float StdVectorFst_Final(StdVectorFst* fst, int state) {
    return fst->Final(state).Value();
  }

  int StdVectorFst_NumStates(StdVectorFst* fst) {
    return fst->NumStates();
  }

  StdVectorFst* StdVectorFst_Determinize(StdVectorFst* fst) {
    StdVectorFst* ofst = new StdVectorFst();
    Determinize(*fst, ofst);
    return ofst;
  }

}

int main() {
  StdVectorFst* fst = StdVectorFst_Create();
  StdVectorFst_AddState(fst);
  StdVectorFst_AddState(fst);
  StdVectorFst_AddArc(fst, 0, 0, 0, 0, 1);
  StdVectorFst_SetStart(fst, 0);
  StdVectorFst_SetFinal(fst, 0, 0.0f);
  cout << StdVectorFst_NumStates(fst) << endl;
  StdVectorFst* ofst =  StdVectorFst_Determinize(fst);
  StdVectorFst_Free(fst);
  StdVectorFst_Free(ofst);
  return 0;
}
