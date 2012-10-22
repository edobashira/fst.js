#!/bin/sh
cd openfst-src
find . -name "*.h" -print | xargs sed -i 's/std::tr1::/std::/g'
find . -name "*.cc" -print | xargs sed -i 's/std::tr1::/std::/g'
find . -name "*.h" -print | xargs sed -i 's/tr1\/unordered/unordered/g'
cd ..
