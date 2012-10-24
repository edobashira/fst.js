function StdVectorFst() {
  this.ptr = _StdVectorFst_Create();
  StdVectorFst.prototype.__cache__[this.ptr] = this;
  this.__class__ = StdVectorFst;
}

StdVectorFst.prototype.__cache__ = {};
Module['StdVectorFst'] = StdVectorFst;

StdVectorFst.prototype['__destroy__'] = function() {
    _StdVectorFst_Free(this.ptr);
}

StdVectorFst.prototype['AddState'] = function() {
    return _StdVectorFst_AddState(this.ptr);
}

StdVectorFst.prototype['AddArc'] = function(state, ilabel, olabel, weight, nextstate) {
    return _StdVectorFst_AddArc(this.ptr, ilabel, olabel, weight, nextstate);
}

StdVectorFst.prototype['SetFinal'] = function(state, weight) {
    return _StdVectorFst_SetFinal (this.ptr, state, weight);
}

StdVectorFst.prototype['Final'] = function(state) {
    return _StdVectorFst_Final (this.ptr, state);
}

StdVectorFst.prototype['NumStates'] = function() {
    return _StdVectorFst_NumStates(this.ptr);
}


StdVectorFst.prototype['Start'] = function() {
    return _StdVectorFst_Start (this.ptr);
}

StdVectorFst.prototype['SetStart'] = function(state) {
    return _StdVectorFst_SetStart (this.ptr, state);
}

