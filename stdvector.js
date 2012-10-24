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

StdVectorFst.prototype['Final'] = function(arg0) {
    return _StdVectorFst_Final (this.ptr, arg0);
}

StdVectorFst.prototype['NumStates'] = function() {
    return _StdVectorFst_NumStates(this.ptr);
}


