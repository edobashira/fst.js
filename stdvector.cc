#include <iostream>
#include <fst/vector-fst.h>
#include <fst/compose.h>
#include <fst/determinize.h>

using namespace fst;
using namespace std;

extern "C" 
{

  StdVectorFst* __attribute__((used, noinline)) StdVectorFst_Create() {
    return new StdVectorFst();
  }

  void __attribute__((used, noinline)) StdVectorFst_Free(StdVectorFst* fst) {
    delete fst;
  }

  int __attribute__((used, noinline)) StdVectorFst_AddState(StdVectorFst* fst) {
    return fst->AddState();
  }

  void __attribute__((used, noinline)) StdVectorFst_AddArc(StdVectorFst* fst, int state, int ilabel, int olabel, float weight, int nextstate) {
    fst->AddArc(state, StdArc(ilabel, olabel, weight, nextstate));
  }

  void __attribute__((used, noinline)) StdVectorFst_SetStart(StdVectorFst* fst, int state) {
     fst->SetStart(state);
  }

  void __attribute__((used, noinline)) StdVectorFst_SetFinal(StdVectorFst* fst, int state, float weight) {
     fst->SetFinal(state, weight);
  }
  int __attribute__((used, noinline)) StdVectorFst_Start(StdVectorFst* fst) {
    return fst->Start();
  }

  float __attribute__((used, noinline)) StdVectorFst_Final(StdVectorFst* fst, int state) {
    return fst->Final(state).Value();
  }

  int __attribute__((used, noinline)) StdVectorFst_NumStates(StdVectorFst* fst) {
    return fst->NumStates();
  }

  StdVectorFst* __attribute__((used, noinline)) StdVectorFst_Determinize(StdVectorFst* fst) {
    StdVectorFst* ofst = new StdVectorFst();
    Determinize(*fst, ofst);
    return ofst;
  }
}


