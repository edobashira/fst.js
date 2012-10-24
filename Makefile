EMSCRIPTEN_ROOT=$(shell python find_emscripten.py)
#EMCC=$(EMSCRIPTEN_ROOT)/em++
EMCC=em++
SRCDIR=openfst-src

#$(SRCDIR)/src/script/libfstscript.bc:
#	cd $(SRCDIR)/src/script; $(EMCC) -o libfstscript.bc -I../include/ arcsort.cc compile.cc concat.cc convert.cc determinize.cc draw.cc epsnormalize.cc equivalent.cc info.cc  invert.cc  minimize.cc project.cc push.cc randgen.cc  replace.cc  reweight.cc   script-impl.cc        shortest-path.cc  text-io.cc  union.cc   weight-class.cc closure.cc  compose.cc  connect.cc  decode.cc   difference.cc   encode.cc  equal.cc  fst-class.cc   intersect.cc map.cc  print.cc prune.cc randequivalent.cc  relabel.cc  reverse.cc  rmepsilon.cc  shortest-distance.cc  synchronize.cc topsort.cc  verify.cc

fstbind.cpp:
	bindings_generator.py fstbind fst.h

fst.html: ${SRCDIR} libfst.bc fst.cc
	em++ -I${SRCDIR}/src/include/ fst.cc -v  libfst.bc -o fst.html

fst.js: ${SRCDIR} libfst.bc fst.cc
	em++ -I${SRCDIR}/src/include/ fst.cc -v -O2 libfst.bc -o fst.js

libfst.bc:
	cd $(SRCDIR)/src/lib; $(EMCC) -o ../../../libfst.bc compat.cc flags.cc fst.cc properties.cc symbol-table.cc symbol-table-ops.cc util.cc -I../include/ `

$(SRCDIR): | openfst-src.tar.gz
	mkdir -p $(SRCDIR)
	tar -zxf openfst-src.tar.gz -C $(SRCDIR) --strip=1
	patch -p0 -i openfst.patch 

openfst-src.tar.gz:
	curl "http://www.openfst.org/twiki/pub/FST/FstDownload/openfst-1.3.2.tar.gz" -o openfst-src.tar.gz

clean:
	rm -f fst.js libfst.bc

clobber: clean
	rm -rf $(SRCDIR)
	rm -f openfst-src.tar.gz

